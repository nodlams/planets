#ifndef VECTOR_H
#define VECTOR_H

/*
 * Class representing a vector, attempting to keep this a POD class so that it can be passed directly to OpenGL.
 */
template <typename TYPE, unsigned int NUMITEMS>
class Vector {

public:
	TYPE val[NUMITEMS];
};

namespace Vector
{
	/*
	 * Initialise a single vector with data in a provided array. Ensure that the array contains enough data to fill the vect.
	 */
	template<typename TYPE, unsigned int NUMITEMS>
	inline Vector<TYPE,NUMITEMS>	*init(Vector<TYPE,NUMITEMS> *vec, TYPE *data)
	{
		for (int i=0; i<NUMITEMS; ++i)
		{
			vec->val[i] = data[i];
		}
	}

	template<typename TYPE, unsigned int NUMITEMS>
	inline void initArray(Vector<TYPE, NUMITEMS> *base, unsigned int count, TYPE *data)
	{
		
	}
}

typedef Vector<float, 3> Vec3;
typedef Vector<float, 4> Vec4;

#endif // VECTOR_H
