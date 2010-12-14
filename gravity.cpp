#include "gravity.h"
#include "datavector.h"
#include "bodycontainer.h"

Gravity::Gravity()
{
}

Gravity::~Gravity()
{
}

void Gravity::applyForce(BodyContainer &bodies)
{
	vec1f &masses = bodies.getMasses();
	vec1f &recipmasses = bodies.getRecipMasses();
	vec3f &positions = bodies.getPositions();
	vec3f &velocities = bodies.getVelocities();
	vec3f &accels = bodies.getNextAcceleration();
	float vec12[vec3f::VECTWORKSIZE];	
	float tmpForce[vec3f::VECTWORKSIZE];
	
	const unsigned int size = positions.size();
	for (int data1 = 0; data1 < size; ++ data1)
	{
		const float mass1 = *masses.get(data1);
		const float recipmass1 = *recipmasses.get(data1);
		float *accel1 = accels.get(data1);
		float *r1 = positions.get(data1);

		for (int data2 = data1+1; data2 < size; ++data2)
		{
			const float mass2 = *masses.get(data2);
			float *accel2 = accels.get(data2);
			
			positions.get(data2, vec12);
			vec3f::subtract(vec12, r1);
			const float distLen2 = vec3f::innerProduct(vec12,vec12);
			const float distLen = sqrtf(distLen2);
			
			const float forceMagnitude = GRAVITY_G * ((mass1 * mass2) / distLen2);
			vec3f::divide(vec12, distLen);
			vec3f::multiply(vec12, forceMagnitude);
			
			vec3f::add(accel1, vec12);
			vec3f::subtract(accel2, vec12);
		}
		
		vec3f::multiply(accel1, recipmass1);
	}
}

/*void Gravity::applyForceSSE(BodyContainer &bodies)
{
	vec1f &masses = bodies.getMasses();
	vec3f &positions = bodies.getPositions();
	vec3f &velocities = bodies.getVelocities();
	vec3f &accels = bodies.getNextAcceleration();
	
	const unsigned int size = bodies.size();
	__m128 gravConst = _mm_set_ps1(GRAVITY_G);
//	printf("about to loop\n");
	for (int i=0; i<vec3f::VECTSIZE; ++i)
	{
		__m128 *r1 = (__m128 *) &positions.get(i,0);
		__m128 *accel1 = (__m128 *) &accels.get(i,0);
//		printf("vectitem: %d\n", i);
		for (int data1 = 0; data1 < size; ++ data1)
		{
//			printf("data1: %d\n", data1);
			__m128 mass1 = _mm_set_ps1(masses.get(0, data1));
			
			__m128 *r2 = (__m128 *) &positions.get(i, data1*4+4);
			__m128 *accel2 = (__m128 *) &accels.get(i, data1*4+4);
			
			for (int data2 = data1+1; data2 < size; ++data2)
			{
//				printf("data2: %d\n", data2);
				__m128 mass2 = _mm_set_ps1(masses.get(0, data2));
			
				__m128 dist = _mm_sub_ps(*r2,*r1);
				__m128 massprod = _mm_mul_ps(mass1, mass2);
				__m128 dist2 = _mm_mul_ps(dist, dist);
				__m128 mod = _mm_div_ps(massprod,dist2);
				__m128 scaledmod = _mm_mul_ps(gravConst, mod);
				
				*accel1 = _mm_add_ps(*accel1, scaledmod);
				*accel2 = _mm_sub_ps(*accel2, scaledmod);
				
				accel2++;
				r2++;
			}	
			accel1++;
			r1++;
		}
	}
}*/
