#ifndef VELOCITYVERLETINTEGRATOR_H
#define VELOCITYVERLETINTEGRATOR_H

#include "gravity.h"
#include "datavector.h"
#include "bodycontainer.h"

class VelocityVerletIntegrator {

public:
	VelocityVerletIntegrator(float dt=0.05);
	~VelocityVerletIntegrator();

	void advanceSimulation(BodyContainer &bodies, unsigned int numSteps);
	
	inline float getTimeInterval() { return m_dt; }
	inline void setTimeInterval(float dt) { m_dt = dt; } 
	inline unsigned int lastStep() { return m_lastStep; }
	inline float lastTime() { return m_lastTime; }
protected:
	inline void calculateNextStep(BodyContainer &bodies);
	
	float m_dt;
	float m_dtdt;
	unsigned int m_lastStep;
	float m_lastTime;
	Gravity m_gravity;
};

void VelocityVerletIntegrator::calculateNextStep(BodyContainer &bodies)
{
	vec3f &positions = bodies.getPositions();
	vec3f &accelCurrent = bodies.getCurrentAcceleration();
	vec3f &accelNext = bodies.getNextAcceleration();
	vec3f &velocities = bodies.getVelocities();
	unsigned int numBodies = bodies.size();
	
	float dtdto2 = m_dtdt * 0.5;
	
	//calculate new positions
	float tmpVel[vec3f::VECTWORKSIZE];
	float tmpAccel[vec3f::VECTWORKSIZE];
	for (int j=0; j<numBodies; ++j)
	{
		float *pos = positions.get(j);
		velocities.get(j, tmpVel);
		accelCurrent.get(j, tmpAccel);
		
		vec3f::multiply(tmpVel, m_dt);
		vec3f::multiply(tmpAccel, dtdto2);
		vec3f::add(tmpVel, tmpAccel);
		vec3f::add(pos, tmpVel);
	}
	
	//calculate new forces
	m_gravity.applyForce(bodies);
	
	float dto2 = m_dt*0.5;
	//calculate new velocities
	float tmpForce[vec3f::VECTWORKSIZE];
	
	for (int j=0; j<numBodies; ++j)
	{
		float *vel = velocities.get(j);
		float *accel2 = accelNext.get(j);

		accelCurrent.get(j, tmpForce);
		vec3f::add(tmpForce, accel2);
		vec3f::multiply(tmpForce, dto2);
		
		vec3f::add(vel, tmpForce);
	}
	
	//flip the accel buffers next becomes current and vica-versa
	bodies.flipAccelerationBuffers();
}

#endif // VELOCITYVERLETINTEGRATOR_H
