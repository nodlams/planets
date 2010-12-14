#ifndef GRAVITY_H
#define GRAVITY_H

//gravitational constant
#define GRAVITY_G 0.1f

class BodyContainer;

class Gravity {

public:
	Gravity();
	~Gravity();

	/*
	 * calculate and apply the gravitational force using the given positions, placing the result of the calculation for each
	 * item in the velocity array
	 */
	void applyForce(BodyContainer &bodies);
	void applyForceSSE(BodyContainer &bodies);
};

#endif // GRAVITY_H
