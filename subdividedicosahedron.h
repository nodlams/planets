#ifndef SUBDIVIDEDICOSAHEDRON_H
#define SUBDIVIDEDICOSAHEDRON_H

//golden ratio. Used to define initial icosahedron.
#include <boost/numeric/ublas/vector.hpp>
#include <vector>
typedef boost::numeric::ublas::vector<float> bvect;

#define TAO = 1.61803399;
class SubdividedIcosahedron {

public:
	SubdividedIcosahedron(float radius, float centrePoint, unsigned int divisionsPerSide)
		: m_radius(radius), m_centrePoint(centrePoint), m_divisionsPerFace(divisionsPerSide)
	{
		generateInitialIcoPoints();
		generateInitialIcoIndices();
		subdivideFaces(divisionsPerSide);//do divisions here.
		projectPointsOntoSphere(radius);
	}
	~SubdividedIcosahedron(){}
	
	const std::vector<bvect> &getPoints() { return m_icoPoints; }
	const std::vector<int> &getTriangleIndices() { return m_icoIndices; }
	
protected:
	void generateInitialIcoPoints();
	void generateInitialIcoIndices();
	void subdivideFaces(unsigned int divisionsPerSide);
	void projectPointsOntoSphere(float radius);
	bvect make_bvect(float x, float y, float z);
	void addTriangleIndices(int i1, int i2, int i3, std::vector<int> &vect)
	{
		vect.push_back(i1);
		vect.push_back(i2);
		vect.push_back(i3);
	}
	float m_centrePoint;
	float m_radius;
	unsigned int m_divisionsPerFace;

	std::vector<bvect> m_icoPoints;
	std::vector<int> m_icoIndices;
};

#endif // SUBDIVIDEDICOSAHEDRON_H
