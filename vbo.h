#ifndef VBO_H
#define VBO_H
#define GL_GLEXT_PROTOTYPES

#include <vector>

#include <GL/gl.h>
#include <GL/glext.h>
#include "datavector.h"

/*
 * This class manages VBOs on the GPU
 */
template <typename TYPE> 
class VBO {

public:
	VBO(GLenum target=GL_ARRAY_BUFFER, GLenum usage=GL_STREAM_DRAW)
		: m_size(0), m_target(target), m_usage(usage), m_initialised(false)
	{}
	~VBO()
	{
		if (m_initialised)
			glDeleteBuffers(1, &m_bufferID);
	}	

	
	template<unsigned int WORKINGSIZE, unsigned int SIZE>
	void copyDataIn(DataVector<TYPE, WORKINGSIZE, SIZE> &data)
	{
		if (!m_initialised)
			bind();
		if (data.size() > m_size)
			m_size = data.size();
		glBufferData(m_target, SIZE * m_size, data.basePtr(), m_usage);
	}
	
	void setUsageHint(GLenum usage)
	{
		m_usage = usage;
	}
	
	void setTarget(GLenum target)
	{
		m_target = target;
	}

private:
	void bind()
	{
		glGenBuffers(1,&m_bufferID);
		glBindBuffer(m_target, m_bufferID);
		m_initialised = true;
	}
	
	GLuint m_bufferID;
	GLenum m_target;
	GLenum m_usage;
	unsigned int m_size;
	bool m_initialised;
};

#endif // VBO_H
