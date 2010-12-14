#ifndef BODYCONTAINER_H
#define BODYCONTAINER_H

#include "datavector.h"

class BodyContainer {

public:
	BodyContainer();
	~BodyContainer();

	inline vec3f &getVelocities() { return m_velocities; }
	inline vec3f &getPositions() { return m_positions; }
	inline vec1f &getMasses() { return m_masses; }
	inline vec1f &getRecipMasses() { return m_recipMasses; }
	inline vec3f &getCurrentAcceleration() { return m_acceleration[m_currentAccel]; }
	inline vec3f &getNextAcceleration() { return m_acceleration[m_nextAccel]; }
	inline vec3f &getColours() { return m_colour; }
	
	inline void flipAccelerationBuffers();
	
	inline unsigned int size() { return m_size; }
	/* For testing: generate a bunch of bodies with random attributes */
	void generateRandomBodies(unsigned int numBodies);
	
	void addBody(float *pos, float *vel, float *colour, float mass);
	void grow(unsigned int numItems);
protected:
	//for VV integration, accel1 contains the current accel, accel2 contains the newly calculated one.
	vec3f m_acceleration[2];
	vec3f m_positions;
	vec3f m_velocities;
	vec1f m_masses;
	vec1f m_recipMasses;
	vec3f m_colour;
	
	unsigned int m_currentAccel;
	unsigned int m_nextAccel;
	unsigned int m_size;
	unsigned int m_nextFreePos;
};

void BodyContainer::flipAccelerationBuffers()
{
	const unsigned int tmp = m_currentAccel;
	m_currentAccel = m_nextAccel;
	m_nextAccel = m_currentAccel;
	
	//now clear the buffer.
	getNextAcceleration().resetData(0.0f);
}

#endif // BODYCONTAINER_H
