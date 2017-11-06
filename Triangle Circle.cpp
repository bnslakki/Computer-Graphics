#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<stdio.h>
#include<math.h>
 
void init(){
	glClearColor(0.1f,0.1f,1.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,1000,0.0,1000);
}
 
const float DEG2RAD = 3.14159/180;
 
void drawCircle(float radius)
{
   glBegin(GL_LINE_LOOP);
  	glColor3f(0.0f,0.0f,0.0f);
   for (int i=0; i< 360; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(cos(degInRad)*radius+170,sin(degInRad)*radius+450);
   }
 
   glEnd();
}
 
void drawCircle1(float radius)
{
   glBegin(GL_LINE_LOOP);
 	glColor3f(0.0f,0.0f,0.0f);
   for (int i=0; i< 360; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(cos(degInRad)*radius+240,sin(degInRad)*radius+450);
   }
 
   glEnd();
}
 
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	glBegin(GL_TRIANGLES);
		glColor3f(0.9f,0.9f,0.f);	glVertex2i(0,400);glVertex2i(100,400);glVertex2i(100,350);
		glColor3f(0.9f,0.9f,0.f);	glVertex2i(300,400);glVertex2i(400,400);glVertex2i(300,350);
 
		glColor3f(0.9f,0.9f,0.f);	glVertex2i(100,100);glVertex2i(140,100);glVertex2i(120,0);
		glColor3f(0.9f,0.9f,0.f);	glVertex2i(260,100);glVertex2i(300,100);glVertex2i(280,0);
 
 
		glColor3f(1.0f,1.0f,0.0f);	glVertex2i(100,400);glVertex2i(200,600);glVertex2i(300,400);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0f,0.0f,0.0f);	glVertex2i(100,100);glVertex2i(100,400);glVertex2i(300,400);glVertex2i(300,100);
 
	glEnd();
	drawCircle(20);
	drawCircle1(20);
	glFlush();
}
 
int main(int argc ,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1024,640);
	glutCreateWindow("first prog");		
	init();
	glutDisplayFunc(display);
 
	glutMainLoop();
	return 0;
}
