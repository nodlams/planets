#ifndef DATAVECTOR_H
#define DATAVECTOR_H

#include <vector>
#include <stdio.h>
#include <math.h>
#include <string.h>

using std::vector;

template<typename TYPE, unsigned int WORKINGSIZE, unsigned int SIZE, unsigned int NUMCLONES=1>
class DataVector {

public:
	/*
	 * create empty data vector
	 */
	DataVector()
	: m_size(0), m_maxSize(0)
	{
			m_data = NULL;
	}
	
	/*
	 * Init data vector from array of data
	 */
	DataVector(TYPE data[SIZE], unsigned int numcopies=1)
	: m_size(numcopies), m_maxSize(numcopies + numcopies/2)
	{
		m_data = new TYPE[m_maxSize*SIZE*NUMCLONES];
		TYPE *tmp = m_data;
		for (int i=0; i<numcopies; ++i)
		{
			for (int j=0; j<SIZE; ++j)
			{
				*(tmp++) = data[j];
			}
			clone(i);
		}
	}
	
	~DataVector()
	{
	}
	
	inline TYPE *basePtr()
	{
		return m_data;
	}
	
	inline TYPE *get(unsigned int itemIndex)
	{
		return &m_data[itemIndex * SIZE * NUMCLONES];
	}
	
	inline TYPE *get(unsigned int itemIndex, TYPE *outBuff)
	{
		TYPE *outBuff2 = outBuff;
		TYPE *data = get(itemIndex);
		for (int i=0; i<WORKINGSIZE; ++i)
			*(outBuff2++) = *(data++);
		return outBuff;
	}
	
	inline void set(unsigned int itemIndex, const TYPE *other)
	{
		TYPE *data = get(itemIndex);
		for (int i=0; i<WORKINGSIZE; ++i)
			*(data++) = *(other++);
	}
	
	inline void set(unsigned int itemIndex, TYPE other)
	{
		TYPE *data = get(itemIndex);
		for (int i=0; i<WORKINGSIZE; ++i)
			*(data++) = other;			
	}
	
	inline void resetData(TYPE value)
	{
		unsigned int theSize = size();
		TYPE *tmp = m_data;
		for (int j=0; j<theSize*SIZE; ++j)
		{
			*(tmp++) = value;
		}
	}
	
	inline unsigned int size()
	{
		return m_size;
	}
	
	inline void grow(unsigned int numItems)
	{
		unsigned int newSize = m_size + numItems;

		if (newSize > m_maxSize)
		{
			unsigned int newMaxSize = m_maxSize + (numItems * 2);
			TYPE *tmp = new TYPE[newMaxSize * SIZE * NUMCLONES];
			if (m_size > 0)
			{
				memcpy(tmp, m_data, m_size * SIZE * NUMCLONES * sizeof(TYPE));
				delete [] m_data;
			}
			m_data = tmp;
			m_maxSize = newMaxSize;
		}
		
		m_size = newSize;
	}
	
	void print()
	{
		for (int i=0; i<m_size; ++i)
		{
			printf("%d: (", i);
			for (int j=0; j<(SIZE-1); ++j)
				printf("%f,", m_data[i * SIZE * NUMCLONES +j]);
			printf("%f)\n", m_data[i * SIZE * NUMCLONES + SIZE-1]);
		}
	}
	
	static void add(TYPE *item1, const TYPE *item2)
	{
		for (int i=0; i<WORKINGSIZE; ++i)
			*(item1++) += *(item2++);
	}
	
	static void add(TYPE *item1, TYPE item2)
	{
		for (int i=0; i<WORKINGSIZE; ++i)
			*(item1++) += item2;
	}
	
	static void subtract(TYPE *item1, const TYPE *item2)
	{
		for (int i=0; i<WORKINGSIZE; ++i)
			*(item1++) -= *(item2++);		
	}
	
	static void subtract(TYPE *item1, TYPE item2)
	{
		for (int i=0; i<WORKINGSIZE; ++i)
			*(item1++) -= item2;		
	}
	
	static void multiply(TYPE *item1, const TYPE *item2)
	{
		for (int i=0; i<WORKINGSIZE; ++i)
			*(item1++) *= *(item2++);		
	}
	
	static void multiply(TYPE *item1, TYPE item2)
	{
		for (int i=0; i<WORKINGSIZE; ++i)
			*(item1++) *= item2;		
	}
	
	static void divide(TYPE *item1, const TYPE *item2)
	{
		for (int i=0; i<WORKINGSIZE; ++i)
			*(item1++) /= *(item2++);		
	}	
	
	static void divide(TYPE *item1, TYPE item2)
	{
		for (int i=0; i<WORKINGSIZE; ++i)
			*(item1++) /= item2;		
	}	
	
	static float length2(const TYPE *item1)
	{
		float sum=0.0f;
		for (int i=0; i<WORKINGSIZE; ++i)
		{
			sum+=(*item1) * (*item1);
			item1++;
		}
		return sum;
	}
	
	static float length(const TYPE *item1)
	{
		return sqrtf(length2(item1));
	}
	
	static float distance2(const TYPE *from, const TYPE *to)
	{
		TYPE tmp[WORKINGSIZE];
		for (int i=0; i<WORKINGSIZE; ++i)
		{
			tmp[i] = *(from++) - *(to++);
		}
		return length2(tmp);
	}
	
	static float distance(const TYPE *from, const TYPE *to)
	{
		return sqrtf(distance2(from,to));
	}
	
	static float innerProduct(const TYPE *v1, const TYPE *v2)
	{
		float sum = 0.0;
		for (int i=0; i<WORKINGSIZE; ++i)
			sum += *(v1++) * *(v2++);
		return sum;
	}
	
	enum { VECTSIZE = SIZE, VECTWORKSIZE = WORKINGSIZE, VECTNUMCLONES=NUMCLONES };
protected:
	inline void clone(unsigned int index)
	{
		TYPE *val = get(index);
		for (int clone = 0; clone<NUMCLONES; ++clone)
		{
			memcpy(val + (clone+1) * SIZE, val, sizeof(TYPE) * SIZE);
		}
	}

	TYPE *m_data;
	unsigned int m_size;
	unsigned int m_maxSize;
};


typedef DataVector<float,3,3,1> vec3f;
typedef DataVector<float,1,1,1> vec1f;
typedef DataVector<int,1,1,1> vec1i;

#endif // DATAVECTOR_H
