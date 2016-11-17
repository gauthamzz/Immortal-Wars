#include <math.h>      // For math routines (such as sqrt & trig).
#include <stdio.h>
#include <stdlib.h>      // For the "exit" function
#include <GLUT/GLUT.h>   // OpenGL Graphics Utility Library
#include "SimpleAnim.h"
float AnimateStepY = 0.0f,AnimateStepX=0.0f;
int RunMode=1;
void mySpecialKeyFunc( int key, int x, int y )
{
    switch ( key ) {
        case GLUT_KEY_UP:
            if ( AnimateStepY <4) {         // Avoid overflow problems
                AnimateStepY+=0.05f;      // Increase the angle increment
            }
            break;
        case GLUT_KEY_DOWN:
            if (AnimateStepY>-4) {      // Avoid underflow problems.
                AnimateStepY-=0.05;   // Decrease the angle increment
            }
            break;
        case GLUT_KEY_LEFT:
            if ( AnimateStepX <4) {         // Avoid overflow problems
                AnimateStepX-=0.05f;      // Increase the angle increment
                }
                break;
            case GLUT_KEY_RIGHT:
                if (AnimateStepX>-4) {      // Avoid underflow problems.
                    AnimateStepX+=0.05;   // Decrease the angle increment
                }
                break;
    }
}
void drawScene(void)
{
    // Clear the rendering window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Rotate the image
    glMatrixMode( GL_MODELVIEW );         // Current matrix affects objects positions
    glLoadIdentity();                  // Initialize to the identity
    glTranslatef( AnimateStepX, AnimateStepY, 0.0 );               // Translate rotation center from origin
    
    // Draw three overlapping triangles of different colors
    glBegin( GL_POLYGON );
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(-.1, -.1, 0.0 );
    glVertex3f( 0.05, -.1, 0.0 );
    glVertex3f( 0.05, 0.05, 0.0 );
    glVertex3f( -.1, 0.05, 0.0 );
    glEnd();
    glBegin(GL_LINE);
    glColor3f( 1.0, 0.5, 0.5 );
    glVertex3f( -1.0, 1.0, 0.0 );
    glVertex3f(1.0, 1.0, 0.0 );
    glEnd();
    
    glutSwapBuffers();
    
    if ( RunMode==1 ) {
        glutPostRedisplay();   // Trigger an automatic redraw for animation
    }
    
}
void initRendering()
{
    glShadeModel( GL_FLAT );   // The default value of GL_SMOOTH is usually better
    glEnable( GL_DEPTH_TEST );   // Depth testing must be turned on
}

int main( int argc, char** argv )
{
    glutInit(&argc,argv);
    
    // We're going to animate it, so double buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    
    // Window position (from top corner), and size (width% and hieght)
    glutInitWindowPosition( 10, 60 );
    glutInitWindowSize( 800, 600 );
    glutCreateWindow( "Gleba" );
    
    // Initialize OpenGL as we like it..
    initRendering();
    glutSpecialFunc( mySpecialKeyFunc );      // Handles "special" keyboard keys
    glutDisplayFunc( drawScene );
    
    fprintf(stdout, "Arrow keys control speed.  Press \"r\" to run,  \"s\" to single step.\n");
    
    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop(  );
    return 0;
}
    
    