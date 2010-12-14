#ifndef PLANETARIUM_H
#define PLANETARIUM_H
#define GL_GLEXT_PROTOTYPES

#include <SDL.h>
#include <SDL_opengl.h>

#include "bodycontainer.h"
#include "velocity_verlet_integrator.h"
#include "vbo.h"

class Planetarium {

public:
	Planetarium(SDL_Surface *surface, int videoFlags)
		: m_surface(surface), m_videoFlags(videoFlags), m_integrator(0.1)
	{
		initObjects();
	}
	~Planetarium()
	{
	}
	
	void startRunning();
protected:
	void renderNextFrame();
	void initObjects();
	void initGL();
	void resizeWindow( int width, int height );
	
	SDL_Surface *m_surface;
	int m_videoFlags;
	
	BodyContainer m_bodies;
	
	VBO<float> m_positions;
	VBO<float> m_colours;
	VelocityVerletIntegrator m_integrator;
};

#endif // PLANETARIUM_H
