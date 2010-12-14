#include <stdio.h>

#include "planetarium.h"

int main(int argc, char **argv)
{
       /* initialize SDL */
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
	    fprintf( stderr, "Video initialization failed: %s\n",
		     SDL_GetError( ) );
		return -1;
	}
	

    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	SDL_GL_SetAttribute( SDL_GL_SWAP_CONTROL, 1 );    
	
	/* Flags to pass to SDL_SetVideoMode */
    int videoFlags;	
	videoFlags  = SDL_OPENGL;          /* Enable OpenGL in SDL */
    videoFlags |= SDL_GL_DOUBLEBUFFER; /* Enable double buffering */
    videoFlags |= SDL_HWPALETTE;       /* Store the palette in hardware */
    videoFlags |= SDL_RESIZABLE;       /* Enable window resizing */
	videoFlags |= SDL_HWSURFACE;
	videoFlags |= SDL_HWACCEL;
	
	SDL_Surface *surface = SDL_SetVideoMode( 800, 600, 32, videoFlags);	
	
	Planetarium planetarium(surface, videoFlags);
	planetarium.startRunning();	
	
	return 0;
}
