
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;
bool tank2 = true;
bool bullet = false;
int bulletcolor=0;
int flag=0;
float e;
float teta_pipe=0.0;
int x=-40,y=-40;
int life;
float bulletx,bullety,bulletradius=.5;
const int numofblocks=22;
bool game;
struct block{
  float x;
  float y;
  bool exist=1;

}b[numofblocks],b1[numofblocks],b2[10];
struct planes
{
  float x;
  float y;
  bool exist;
  int time;
}p[5],p1[5];
int score,highscore,planeXadd=1,planeYadd=1,times=1;
float px=1,py=1;
void moveright(void)
{
  if(x<42)
    for (int b = 0; b <= 1; b++) {
        x+=b;
        glutPostRedisplay();
    }
}

void moveleft(void)
{
  if(x>-42)
    for (int a = 0; a >= -1; a--) {
        x+=a;
        glutPostRedisplay();
    }
}

void moveup(void)
{
  if(y<42)
    for (int c = 0; c <= 1; c++) {
        y+=c;
        glutPostRedisplay();
    }
}

void movedown(void)
{
  if(y>-42)
    for (int d = 0; d >= -1; d--) {
        y+=d;
        glutPostRedisplay();
    }
}
void shoot(void)
{
    bullet = true;
}

void update_objects(void)
{
    if (bullet == true) {
        e = e + 0.5;
        if (e > 75) {
            bullet = false;
            e = 0;
        }
    }
    glutPostRedisplay();
}
void exits(int value)
{
    if (value == 1)
        exit(0);
    if (value == 2) {
        tank2 = false;
        bullet = false;
        glutPostRedisplay();
        glClearColor(1.0, 1.0, 1.0, 0.0);
    }
    if (value == 4) {
        tank2 = true;
        glutPostRedisplay();
    }
}

void drawtank()
{

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(-2.0+x-.2, 2.0+y);
    glVertex2f(-2.0+x-.2, -2.0+y);
    glVertex2f(2.0+x-.2, -2.0+y);
    glVertex2f(2.0+x-.2, 2.0+y);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.25, 0.05);
    glVertex2f(2.0+x, 2.5+y);
    glVertex2f(2.0+x, -2.5+y);
    glVertex2f(2.5+x, -2.5+y);
    glVertex2f(2.5+x, 2.5+y);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.25, 0.05);
    glVertex2f(-2.5+x, 2.5+y);
    glVertex2f(-2.5+x, -2.5+y);
    glVertex2f(-2.0+x, -2.5+y);
    glVertex2f(-2.0+x, 2.5+y);
    glEnd();
    float cx = 0, cy = 0, r = 1;
    glColor3f(.5, .5, 0.5);
    int num_segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int ii = 0; ii < num_segments; ii++) {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments); //get the current angle
        float xx = r * cosf(theta)+x; //calculate the x
        float yy = r * sinf(theta)+y; //calculate the y
        glVertex2f(xx + cx, yy + cy); //output vertex
    }
    glEnd();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void key(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        glutPostRedisplay();
        break;
    case 'd':
    case 'D':
        moveright();
        glutPostRedisplay();
        break;
    case 'a':
    case 'A':
        moveleft();
        glutPostRedisplay();
        break;
    case 'w':
    case 'W':
        moveup();
        glutPostRedisplay();
        break;
    case 's':
    case 'S':
        movedown();
        glutPostRedisplay();
        break;
    case 'j':
    case 'J':
          teta_pipe-=.01;
          glutPostRedisplay();
          break;
    case 'k':
    case 'K':
          teta_pipe+=.01;
          glutPostRedisplay();
          break;
    case 13:
          game=1;//enter key
          score=100;
          life=3;
          break;
    case 32:
        shoot();
        glutPostRedisplay();
        break;
        default:
        break;
    }
    //cout << key << static_cast<int>(key) << endl; // Don't need
}

static void key1(int key, int x, int y)
{
    switch (key) {

    case GLUT_KEY_RIGHT:
        moveright();
        glutPostRedisplay(); // Don't need
        break;
    case GLUT_KEY_LEFT:
        moveleft();
        glutPostRedisplay(); // Don't need
        break;
    case GLUT_KEY_UP:
        moveup();
        glutPostRedisplay(); // Don't need
        break;
    case GLUT_KEY_DOWN:
        movedown();
        glutPostRedisplay(); // Don't need
        break;
    default:
        break;
    }
    //cout << key << static_cast<int>(key) << endl;
}
void initializeblocks()
{
  for(int i=0;i<numofblocks;i++)
  {
    b[i].x=-47+i*4.5;
    b[i].y=47;
  }
  for(int i=0;i<numofblocks;i++)
  {
    b1[i].y=-45+i*4.2;
    b1[i].x=-47;
  }
  for(int j=0;j<10;j++)
  {
    b2[j].y=-25+j*4.2;
    b2[j].x=-27;
  }
}
void drawblocks()
{
  initializeblocks();
  for(int i=0;i<numofblocks;i++)
  {
    // top blocks
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0);
    glVertex2f(-2.0+b[i].x, 2.0+b[i].y);
    glVertex2f(-2.0+b[i].x, -2.0+b[i].y);
    glVertex2f(2.0+b[i].x, -2.0+b[i].y);
    glVertex2f(2.0+b[i].x, 2.0+b[i].y);
    glEnd();
    // bottom blocks
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0);
    glVertex2f(-2.0+b[i].x, 2.0+b[i].y-94);
    glVertex2f(-2.0+b[i].x, -2.0+b[i].y-94);
    glVertex2f(2.0+b[i].x, -2.0+b[i].y-94);
    glVertex2f(2.0+b[i].x, 2.0+b[i].y-94);
    glEnd();
    //left
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0);
    glVertex2f(-2.0+b1[i].x, 2.0+b1[i].y);
    glVertex2f(-2.0+b1[i].x, -2.0+b1[i].y);
    glVertex2f(2.0+b1[i].x, -2.0+b1[i].y);
    glVertex2f(2.0+b1[i].x, 2.0+b1[i].y);
    glEnd();
    // right blocks
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0);
    glVertex2f(-2.0+b1[i].x+94.5, 2.0+b1[i].y);
    glVertex2f(-2.0+b1[i].x+94.5, -2.0+b1[i].y);
    glVertex2f(2.0+b1[i].x+94.5, -2.0+b1[i].y);
    glVertex2f(2.0+b1[i].x+94.5, 2.0+b1[i].y);
    glEnd();
  }
  for(int j=0;j<10;j++)
  {
    times++;
    if(times%200==0)
      py=py+px;
    if(py>3)
      px=-1;
    if(py<0)
      px=1;
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 1);
    glVertex2f(-2.0+b2[j].x+py, 2.0+b2[j].y);
    glVertex2f(-2.0+b2[j].x+py, -2.0+b2[j].y);
    glVertex2f(2.0+b2[j].x+py, -2.0+b2[j].y);
    glVertex2f(2.0+b2[j].x+py, 2.0+b2[j].y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 01);
    glVertex2f(-2.0+b2[j].x+54-py, 2.0+b2[j].y);
    glVertex2f(-2.0+b2[j].x+54-py, -2.0+b2[j].y);
    glVertex2f(2.0+b2[j].x+54-py, -2.0+b2[j].y);
    glVertex2f(2.0+b2[j].x+54-py, 2.0+b2[j].y);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 01);
    glVertex2f(-2.0+b2[j].x+20+py, 2.0+b2[j].y-10);
    glVertex2f(-2.0+b2[j].x+20+py, -2.0+b2[j].y-10);
    glVertex2f(2.0+b2[j].x+20+py, -2.0+b2[j].y-10);
    glVertex2f(2.0+b2[j].x+20+py, 2.0+b2[j].y-10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 01);
    glVertex2f(-2.0+b2[j].x+34-py, 2.0+b2[j].y+20);
    glVertex2f(-2.0+b2[j].x+34-py, -2.0+b2[j].y+20);
    glVertex2f(2.0+b2[j].x+34-py, -2.0+b2[j].y+20);
    glVertex2f(2.0+b2[j].x+34-py, 2.0+b2[j].y+20);
    glEnd();

  }
}
bool check_collision(float ballX,float ballY,float BallDiameter,float RectX,float RectY,float RectWidth=6.0, float RectHeight=6.0)
{
  if ( ballY + BallDiameter < RectY ) return false;
  else if ( ballY > RectY + RectHeight ) return false;
  else if ( ballX + BallDiameter < RectX ) return false;
  else if ( ballX > RectX + RectWidth ) return false;
  return true;
}
bool check_collision_brick()
{
  for(int i=0;i<numofblocks;i++)
  {
    if(check_collision(bulletx,bullety,bulletradius,b[i].x,b[i].y))
    {
      return true;
    }
    if(check_collision(bulletx,bullety,bulletradius,b[i].x,b[i].y-94))
    {
      return true;
    }
    if(check_collision(bulletx,bullety,bulletradius,b1[i].x,b1[i].y))
    {
      return true;
    }
    if(check_collision(bulletx,bullety,bulletradius,b1[i].x+94.5,b1[i].y))
    {
      return true;
    }
  }
  for(int i=0;i<10;i++)
  {
    if(check_collision(bulletx,bullety,bulletradius,b2[i].x,b2[i].y))
    {
      return true;
    }
    if(check_collision(bulletx,bullety,bulletradius,b2[i].x+54,b2[i].y))
    {
      return true;
    }
    if(check_collision(bulletx,bullety,bulletradius,b2[i].x+20,b2[i].y-10))
    {
      return true;
    }
    if(check_collision(bulletx,bullety,bulletradius,b2[i].x+34,b2[i].y+20))
    {
      return true;
    }
  }
  for(int i=0;i<5;i++)
  if(check_collision(bulletx,bullety,bulletradius,p[i].x,p[i].y))
  {
    p[i].exist=0;
    score+=100;
    // cout<<score;
    return true;
  }
  for(int i=0;i<5;i++)
  if(check_collision(bulletx,bullety,bulletradius,p1[i].x,p1[i].y,20))
  {
    life--;
    p1[i].exist=0;
    // cout<<score;
    return true;
  }
  return false;
}
void drawbullet()
{
  if (bullet == true) {
      float cx = 0, cy = 0, r = bulletradius;
      glColor3f(bulletcolor, 0, 0);
      int num_segments = 1000;
      glBegin(GL_TRIANGLE_FAN);
      for (int ii = 0; ii < num_segments; ii++) {
          float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments); //get the current angle
          float xx = r * cosf(theta)+x; //calculate the x
          float yy = r * sinf(theta)+y; //calculate the y
          bulletx=xx+cx+e*sinf(teta_pipe);
          bullety=yy+cy+e*cosf(teta_pipe);
          glVertex2f(bulletx,bullety); //output vertex

      }
      glEnd();

  }
  glColor3f(bulletcolor, 0, 0);
  int num_segments = 1000;
  float r=.7;
  glBegin(GL_TRIANGLE_FAN);
  for (int ii = 0; ii < num_segments; ii++) {
      float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments); //get the current angle
      float xx = r * cosf(theta)+x+2*sinf(teta_pipe); //calculate the x
      float yy = r * sinf(theta)+y+2*cosf(teta_pipe); //calculate the y
      glVertex2f(xx,yy); //output vertex

  }
  glEnd();

}
void initializeplanes()
{
  for(int i=0;i<5;i++)
  {
    if(p[i].exist==0||p[i].time==0)
    {
      p[i].x=rand()%80-40;
      p[i].y=rand()%80-40;
      p[i].exist=1;
      p[i].time=500;
    }
  }
}
void drawplanes()
{
  for(int i=0;i<5;i++)
  {
  if(p[i].time==0 || p[i].exist==0){
    initializeplanes();

  }
  glBegin(GL_QUADS);
  glColor3f(0, 1, .5);
  glVertex2f(-2.0+p[i].x, 2.0+p[i].y);
  glVertex2f(-2.0+p[i].x, -2.0+p[i].y);
  glVertex2f(2.0+p[i].x, -2.0+p[i].y);
  glVertex2f(2.0+p[i].x, 2.0+p[i].y);
  p[i].time--;
  glEnd();
}}

void initializetraps()
{
  for(int i=0;i<5;i++)
  {
    if(p[i].exist==0||p[i].time==0)
    {
      p1[i].x=rand()%80-40;
      p1[i].y=rand()%80-40;
      p1[i].exist=1;
      p1[i].time=300;
    }
  }
}
void drawtraps()
{
  for(int i=0;i<5;i++)
  {
  if(p1[i].time==0 || p1[i].exist==0){
    initializetraps();

  }
  glBegin(GL_QUADS);
  glColor3f(1, 0, 0);
  for(int j=-2;j<3;j++)
  {
    glVertex2f(-2.0+p1[i].x+j*4.5, 2.0+p1[i].y);
    glVertex2f(-2.0+p1[i].x+j*4.5, -2.0+p1[i].y);
    glVertex2f(2.0+p1[i].x+j*4.5, -2.0+p1[i].y);
    glVertex2f(2.0+p1[i].x+j*4.5, 2.0+p1[i].y);
  }
  p1[i].time--;
  glEnd();
}}

void writeOnScreen(char *string) {
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}

void writeHeadingOnScreen(char *string) {
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void points()
{
  glColor3f(0, 1, 0);
  glRasterPos2f(35, 40);
  char tmp_str[40];
  sprintf(tmp_str, "Score : %d", score);
  writeOnScreen(tmp_str);
  glColor3f(1, 0, 0);
  glRasterPos2f(35, 35);
  // char tmp_str[40];
  sprintf(tmp_str, "Life : %d", 25+life/10);
  writeOnScreen(tmp_str);
}
char s1[]="SCORE:";
void printscore(int x, int y,int z, char *string)
{
//set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x,y);
//get the length of the string to display
    int len = (int) strlen(string);

//loop to display character by character
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
    char tmp_str[40];
    sprintf(tmp_str, ": %d", score);
    //sprintf(" %d",score);
}
void display(void)
{
  if(game==1)
  {
    if(25+life/10==0)
      game=0;
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST); //disable depth comparisons and update the depth buffer.
    usleep(10000);
    glPushMatrix();
    if (tank2 == true) {
        drawtank();
    }
    drawblocks();
    drawbullet();
    drawplanes();
    drawplanes();
    drawtraps();

    points();
    // cout<<bulletx<<bullety<<endl;

    if(flag==1)
    {
      bullet=false;
      e=0;
      bulletcolor=0;
      bulletradius=.5;
      flag=0;
    }
    if(check_collision_brick())
    {
      bulletcolor=1;
      bulletradius=2;
      flag=1;

    }
  }
  else if(game==0)
   {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clean the screen and the depth buffer
     glLoadIdentity();
     if(score>highscore)
      highscore=score;
     string s2;
     char s3[3];
     glColor3f(1, 1, 0);
     printscore(-10,0,0,s1);
     s2=to_string(score);
     strcpy(s3, s2.c_str());
     printscore(1,0,0,s3);
     char s7[]="HIGH SCORE ";
     strcat(s7,to_string(highscore).c_str());
     printscore(-12,-3,0,s7);
     glColor3f(0, 1, 0);
     char s4[]="IMMORTAL WARS";
     printscore(-13,10,0,s4);
     glColor3f(0.2, .1, 1);
     char s5[]="PRESS ENTER TO START GAME ";
     printscore(-18,-10,0,s5);
     char s6[]="PRESS ESC TO EXIT GAME ";
     printscore(-16,-15,0,s6);

	}
    glPopMatrix();
    glutSwapBuffers();

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Immortal Wars");
    game=0;
    highscore=0;
    glClearColor(0.1, 0.1, 0.1, 0.0);
    glutDisplayFunc(display);
    glutIdleFunc(update_objects);
    glutReshapeFunc(reshape);
    glutSpecialFunc(key1);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
