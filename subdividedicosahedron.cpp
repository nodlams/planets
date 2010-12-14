#include "subdividedicosahedron.h"
#include <stdio.h>
#include <math.h>

bvect SubdividedIcosahedron::make_bvect(float x, float y, float z)
{
	bvect vec(3);
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
	return vec;
}

void addTriangleIndices(int i1, int i2, int i3, std::vector<int> &vect)
{
	vect.push_back(i1);
	vect.push_back(i2);
	vect.push_back(i3);
}

void SubdividedIcosahedron::generateInitialIcoPoints()
{
	
/*float tao = 1.61803399;
float[][] _handles = {{1,tao,0},{-1,tao,0},{1,-tao,0},{-1,-tao,0},
                      {0,1,tao},{0,-1,tao},{0,1,-tao},{0,-1,-tao},
                      {tao,0,1},{-tao,0,1},{tao,0,-1},{-tao,0,-1}};*/
	float tao = 1.61803399;		  
	//12 vertices, 20 faces
	m_icoPoints.reserve(12);
	
	m_icoPoints.push_back(make_bvect(1,tao,0));
	m_icoPoints.push_back(make_bvect(-1,tao,0));
	m_icoPoints.push_back(make_bvect(1,-tao,0));	
	m_icoPoints.push_back(make_bvect(-1,-tao,0));
	
	m_icoPoints.push_back(make_bvect(0,1,tao));
	m_icoPoints.push_back(make_bvect(0,-1,tao));
	m_icoPoints.push_back(make_bvect(0,1,-tao));
	m_icoPoints.push_back(make_bvect(0,-1,-tao));
	
	m_icoPoints.push_back(make_bvect(tao,0,1));
	m_icoPoints.push_back(make_bvect(-tao,0,1));
	m_icoPoints.push_back(make_bvect(tao,0,-1));
	m_icoPoints.push_back(make_bvect(-tao,0,-1));
}

void SubdividedIcosahedron::generateInitialIcoIndices()
{
	m_icoIndices.reserve(60);
	
	addTriangleIndices(0,1,4, m_icoIndices);
	addTriangleIndices(1,9,4, m_icoIndices);	
	addTriangleIndices(4,9,5, m_icoIndices);	
	addTriangleIndices(5,9,3, m_icoIndices);	
	
	addTriangleIndices(2,3,7, m_icoIndices);
	addTriangleIndices(3,2,5, m_icoIndices);	
	addTriangleIndices(7,10,2, m_icoIndices);	
	addTriangleIndices(0,8,10, m_icoIndices);	
		
	addTriangleIndices(0,4,8, m_icoIndices);
	addTriangleIndices(8,2,10, m_icoIndices);	
	addTriangleIndices(8,4,5, m_icoIndices);	
	addTriangleIndices(8,5,2, m_icoIndices);	
		
	addTriangleIndices(1,0,6, m_icoIndices);
	addTriangleIndices(11,1,6, m_icoIndices);	
	addTriangleIndices(3,9,11, m_icoIndices);	
	addTriangleIndices(6,10,7, m_icoIndices);	
	
	addTriangleIndices(3,11,7, m_icoIndices);
	addTriangleIndices(11,6,7, m_icoIndices);	
	addTriangleIndices(6,0,10, m_icoIndices);	
	addTriangleIndices(9,1,11, m_icoIndices);		
}

void SubdividedIcosahedron::subdivideFaces(unsigned int divisionsPerSide)
{
	//create a new array and spread the existing points/indices correctly.
	//numfaces is the current number of triangles.
	int numFaces = m_icoIndices.size() / 3;
	float d = float(divisionsPerSide);
	
	int numPointsPerFace = int(d * d * 0.5f + 1.5f * d + 1.0f);
	int newNumPoints =  numPointsPerFace * numFaces;
	int newNumFaces = (divisionsPerSide * divisionsPerSide) * numFaces;
	
	std::vector<bvect> newPoints(newNumPoints,bvect(3));
	std::vector<int> newInds;//(newNumPoints * 3,0);
	
	for (int f=0; f<numFaces; ++f)
	{
		bvect &v1 = m_icoPoints[m_icoIndices[f * 3]];
		bvect &v2 = m_icoPoints[m_icoIndices[f * 3 + 1]];
		bvect &v3 = m_icoPoints[m_icoIndices[f * 3 + 2]];
		
		int noff = numPointsPerFace * f;
		//put v1 at 0,
		newPoints[noff] = v1;
		
		//find triangle generating vects.
		bvect v2v1 = (v2 - v1);
		bvect v3v1 = (v3 - v1);
		float len = sqrtf(boost::numeric::ublas::inner_prod(v2v1,v2v1));
		float sublen = len / d;
		v2v1 /= len;
		v3v1 /= len;
		int vindex = 1;
		
		for (int i=1; i<=divisionsPerSide; ++i)
		{
			bvect left = v1 + v2v1 * float(i) * sublen;
			bvect right = v1 + v3v1 * float(i) * sublen;
			bvect ltor = right - left;
			ltor = ltor / sqrtf(inner_prod(ltor,ltor));
			for (int j=0; j<=i; ++j)
			{
				bvect acr = left + ltor * float(j) * sublen;
				newPoints[noff + vindex] = acr;
				vindex++;
			}
		}
	
		//generate indices
		int leadInd = 0;
		for (int i=1; i<=divisionsPerSide; ++i)
		{
			for (int j=0; j<i; ++j)
			{
				newInds.push_back(noff + leadInd);
				newInds.push_back(noff + leadInd + i);
				newInds.push_back(noff + leadInd + i + 1);
				if (j != (i-1))
				{
					newInds.push_back(noff + leadInd + i + 1);
					newInds.push_back(noff + leadInd + 1);
					newInds.push_back(noff + leadInd);
				}
				
				leadInd++;
			}
		}
	}
	m_icoPoints = newPoints;
	m_icoIndices = newInds;
}

void SubdividedIcosahedron::projectPointsOntoSphere(float radius)
{
	bvect centre(3);
	centre[0] = 0.0f; centre[1] = 0.0f; centre[2] = 0.0f;
	
	for (int i=0; i<m_icoPoints.size(); ++i)
	{
		bvect &p = m_icoPoints[i];
		bvect pToo = centre - p;
		pToo = pToo / sqrtf(inner_prod(pToo,pToo));
		pToo *= radius;
		p = pToo;
	}
}