#include "planetarium.h"
#include "subdividedicosahedron.h"

#include <GL/glu.h>
#include <SDL.h>
#include <stdlib.h>

void Planetarium::initObjects()
{
	m_bodies.generateRandomBodies(1000);
	/*float pos1[4] = {0.0f, 0.0f, 0.0f, 0.0f};
	float pos2[4] = {100.0f, 0.0f, 0.0f, 0.0f};	
	float pos3[4] = {-200.0f, 0.0f, 0.0f, 0.0f};		
	float pos4[4] = {-150.0f, 0.0f, 0.0f, 0.0f};			
	float pos5[4] = {-120.0f, 0.0f, 0.0f, 0.0f};				
	float vel1[4] = {0.0f, 0.0f, 0.0f, 0.0f};
	float vel2[4] = {0.0f, 5.0f, 5.0f, 0.0f};	
	float col1[4] = {1.0f, 1.0f, 0.0f, 1.0f};
	float col2[4] = {0.5f, 1.0f, 0.75f, 1.0f};	
	float col3[4] = {0.75f, 0.2f, 0.1f, 1.0f};		
	float col4[4] = {0.5f, 1.0f, 0.23f, 1.0f};	
	float col5[4] = {0.23f, 0.8f, 0.23f, 1.0f};		
	
	m_bodies.grow(5);
	m_bodies.addBody(pos1, vel1, col1, 100000.0f);
	m_bodies.addBody(pos2, vel2, col2, 10000.0f);	
	m_bodies.addBody(pos3, vel2, col3, 1000.0f);	
	m_bodies.addBody(pos4, vel2, col4, 1000.0f);	
	m_bodies.addBody(pos5, vel2, col5, 1000.0f);		*/
}

void Planetarium::startRunning()
{
	initGL();
	resizeWindow(800, 600);
	
	bool done = false;
	bool active = true;
	
	while (!done)
	{
		SDL_Event event;	
		while (SDL_PollEvent( &event ))
		{
			switch(event.type)
			{
				case SDL_ACTIVEEVENT:
					/* Something's happend with our focus
					 * If we lost focus or we are iconified, we
					 * shouldn't draw the screen
					 */
					active = event.active.gain != 0;
					break;			    
				case SDL_VIDEORESIZE:
					/* handle resize event */
					m_surface = SDL_SetVideoMode( event.resize.w,
								event.resize.h,
								32, m_videoFlags );
					if ( !m_surface )
					{
						fprintf( stderr, "Could not get a surface after resize: %s\n", SDL_GetError( ) );
						exit(1);
					}
					resizeWindow( event.resize.w, event.resize.h );
					break;
				/*case SDL_KEYDOWN:
					handleKeyPress( &event.key.keysym );
					break;*/
				case SDL_QUIT:
					/* handle quit requests */
					done = true;
					break;
				default:
					break;
			}
		}		
		
		m_integrator.advanceSimulation(m_bodies, 1);

		renderNextFrame();
	}
}

/* function to reset our viewport after a window resize */
void Planetarium::resizeWindow( int width, int height )
{
    /* Height / width ration */
    GLfloat ratio;

    /* Protect against a divide by zero */
    if ( height == 0 )
	height = 1;

    ratio = ( GLfloat )width / ( GLfloat )height;

    /* Setup our viewport. */
    glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

    /* change to the projection matrix and set our viewing volume. */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    /* Set our perspective */
    gluPerspective( 45.0f, ratio, 0.1f, 10000.0f );
	gluLookAt(0.0, 0.0, -1000.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    /* Make sure we're chaning the model view and not the projection */
    glMatrixMode( GL_MODELVIEW );

    /* Reset The View */
    glLoadIdentity( );
}

void Planetarium::initGL()
{
    /* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

    /* Depth buffer setup */
    glClearDepth( 1.0f );

    /* Enables Depth Testing */
    glEnable( GL_DEPTH_TEST );

    /* The Type Of Depth Test To Do */
    glDepthFunc( GL_LEQUAL );

    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

void Planetarium::renderNextFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
	glLoadIdentity();
	
	vec3f &pos = m_bodies.getPositions();
	vec3f &col = m_bodies.getColours();
	vec1f &mass = m_bodies.getMasses();
	
	float *ccol;
	float *cpos;

	unsigned int numBodies = m_bodies.size();
	SubdividedIcosahedron hedron(3.0, 0.0, 5);
	
	for (int i=0; i<numBodies; ++i)
	{
		ccol = col.get(i);
		cpos = pos.get(i);
		float cmass = *mass.get(i);
		glPushMatrix();

		glTranslatef(cpos[0], cpos[1], cpos[2]);
		const vector<bvect> &pts = hedron.getPoints();
		const vector<int> &inds = hedron.getTriangleIndices();
		glColor3fv(ccol);		
		glBegin(GL_TRIANGLES);
		for (int i=0; i<inds.size(); i+=3)
		{
			glVertex3f(pts[inds[i]][0], pts[inds[i]][1], pts[inds[i]][2]);
			glVertex3f(pts[inds[i+1]][0], pts[inds[i+1]][1], pts[inds[i+1]][2]);			
			glVertex3f(pts[inds[i+2]][0], pts[inds[i+2]][1], pts[inds[i+2]][2]);			
		}
		glEnd();

		glPopMatrix();
	}
	
	SDL_GL_SwapBuffers();	
}