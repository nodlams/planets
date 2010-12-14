#include "velocity_verlet_integrator.h"

VelocityVerletIntegrator::VelocityVerletIntegrator(float dt)
: m_dt(dt), m_dtdt(dt*dt), m_lastStep(-1), m_lastTime(0.0)
{
}

VelocityVerletIntegrator::~VelocityVerletIntegrator()
{
}

void VelocityVerletIntegrator::advanceSimulation(BodyContainer &bodies, unsigned int numSteps)
{
	for (int i=0; i<numSteps; ++i)
	{
		calculateNextStep(bodies);
		m_lastStep++;
		m_lastTime += m_dt;
	}
}

