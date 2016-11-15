#include <stdio.h>
#include <GLUT/GLUT.h>
#include<time.h>
void delay(float secs)
{
    float end = clock()/CLOCKS_PER_SEC + secs;
    while((clock()/CLOCKS_PER_SEC) < end);
}
void display(void)
{
    float y=-4;;
    while(y<3)
    {
    glPushMatrix();
    
    glTranslatef(-1,y,0.0); // 3. Translate to the object's position.
    
   //glRotatef(45,0.0,y,0.0); // 2. Rotate the object.
    
    glClear( GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(2.0, 4.0, 0.0);
    glVertex3f(3.5, 4.0, 0.0);
    glVertex3f(3.5, 6.0, 0.0);
    glVertex3f(2.0, 6.0, 0.0);
    glEnd();
    glLineWidth(2.5);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(3.5, 5.0, 0.0);
    glVertex3f(3.56, 5.0, 0.0);
    glEnd();
    glLineWidth(2.5);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(4.0, 5.0, 0.0);
    glVertex3f(4.06, 5.0, 0.0);
    glEnd();
    glLineWidth(2.5);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(4.60, 5.0, 0.0);
    glVertex3f(4.66, 5.0, 0.0);
    glEnd();
    glLineWidth(2.5);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(5.04, 5.0, 0.0);
    glVertex3f(5.10, 5.0, 0.0);
    glEnd();
    glLineWidth(2.5);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(5.48, 5.0, 0.0);
    glVertex3f(5.54, 5.0, 0.0);
    glEnd();
    glLineWidth(2.5);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(5.92, 5.0, 0.0);
    glVertex3f(5.98, 5.0, 0.0);
    glEnd();
    glPopMatrix();
    glFlush();
      //  x=x+0.4;
        y=y+0.4;
        delay(0.0002);
    }
}

int main(int argc, char **argv)
{
    printf("hello world\n");
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,500);
    glutCreateWindow ("square");
    
    glClearColor(0.0, 0.0, 0.0, 0.0);         // black background
    glMatrixMode(GL_PROJECTION);              // setup viewing projection
    glLoadIdentity();                           // start with identity matrix
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world
    
    glutDisplayFunc(display); 
    glutMainLoop();
    
    return 0; 
}