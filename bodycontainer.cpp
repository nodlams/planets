#include "bodycontainer.h"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>

typedef boost::mt19937 base_generator_type;

BodyContainer::BodyContainer()
: m_size(0), m_currentAccel(0), m_nextAccel(1), m_nextFreePos(0)
{
}

BodyContainer::~BodyContainer()
{
}

void BodyContainer::grow(unsigned int numItems)
{
	m_acceleration[0].grow(numItems);
	m_acceleration[1].grow(numItems);	
	m_positions.grow(numItems);
	m_velocities.grow(numItems);
	m_masses.grow(numItems);
	m_recipMasses.grow(numItems);
	m_colour.grow(numItems);
}

void BodyContainer::addBody(float *pos, float *vel, float *colour, float mass)
{
	m_acceleration[0].set(m_nextFreePos, 0.0f);
	m_acceleration[1].set(m_nextFreePos, 0.0f);	
	m_positions.set(m_nextFreePos, pos);
	m_velocities.set(m_nextFreePos, vel);
	m_colour.set(m_nextFreePos, colour);
	m_masses.set(m_nextFreePos, mass);
	m_recipMasses.set(m_nextFreePos, 1.0f/mass);
	m_nextFreePos++;
	m_size++;
}

void BodyContainer::generateRandomBodies(unsigned int numBodies)
{
	base_generator_type generator(42u);
	boost::uniform_real<> pos_dist(-500.0,500.0);
	boost::uniform_real<> mass_dist(1000.0, 100000.0);
	boost::uniform_real<> vel_dist(-5.0, 5.0);
	boost::uniform_real<> col_dist(0.0, 1.0);
	boost::variate_generator<base_generator_type &, boost::uniform_real<> > posGen(generator, pos_dist);
	boost::variate_generator<base_generator_type &, boost::uniform_real<> > massGen(generator, mass_dist);
	boost::variate_generator<base_generator_type &, boost::uniform_real<> > velGen(generator, vel_dist);
	boost::variate_generator<base_generator_type &, boost::uniform_real<> > colGen(generator, col_dist);
	
	float zeroVect[4] = {0.0f, 0.0f, 0.0f, 0.0f};
	float zeroMass = 0.0f;
	
	m_acceleration[0] = vec3f(zeroVect, numBodies);
	m_acceleration[1] = vec3f(zeroVect, numBodies);
	m_masses = vec1f(&zeroMass, numBodies);
	m_recipMasses = vec1f(&zeroMass, numBodies);
	m_velocities = vec3f(zeroVect, numBodies);
	m_positions = vec3f(zeroVect, numBodies);
	m_colour = vec3f(zeroVect, numBodies);

	for (int i=0; i<numBodies; ++i)
	{
		float pos = 0.0;
		float *bpos = m_positions.get(i);
		for (int j=0; j<vec3f::VECTWORKSIZE; ++j)
			*(bpos++) = posGen();
	}
	
/*	for (int i=0; i<numBodies; ++i)
	{
		float *bvel = m_velocities.get(i);
		for (int j=0; j<vec3f::VECTWORKSIZE; ++j)
			*(bvel++) = velGen();			
	}*/
	
	for (int i=0; i<numBodies; ++i)
	{
		float *bcol = m_colour.get(i);
		for (int j=0; j<vec3f::VECTWORKSIZE; ++j)
			*(bcol++) = colGen();					
	}

	for (int i=0; i<numBodies; ++i)
	{
		float mass = massGen();
		float *bmass = m_masses.get(i);	
		float *brecipmass = m_recipMasses.get(i);
		*bmass = mass;
		*brecipmass = 1.0f / mass;
	}
	
	m_size = numBodies;
	m_nextFreePos += numBodies;
}