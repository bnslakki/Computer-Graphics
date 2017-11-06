#include<iostream>
#include<cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>

#define PI 3.14159265

using namespace std;

static int isAnimate = 0;
static int animationPeriod = 50;
static float angle = 0.0;

void drawScene(void){
	float R = 20.0;
	float t;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	glPushMatrix();
	glTranslatef(0,10,-20);
		//glScalef(3,3,3);
		glColor3f(1,0.4, 0.5);
		glRotatef(angle, 1.0,1.0,0.0);
		glRectf(5,5,4,3);
		//glutWireTeapot(5);

	glTranslatef(0.0,0.0,60);



	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,-60);

		glScalef(3,3,3);
		glColor3f(0,.6,.8);
		glRotatef(angle, 1.0,1.0,0.0);

		glutWireTeapot(5);

	glTranslatef(0.0,0.0,60);



	glPopMatrix();
	glutSwapBuffers();

}

void setup(void){
	glClearColor(1.0,1.0,1.0,0.0);


}

void resize(int w , int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0,5.0,-5.0,5.0,5.0,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void increaseAngle(void){

	angle+=5.0;
	if(angle>360) angle-=360.0;

}

void animate(int value)
{
	if(isAnimate){
		increaseAngle();
		glutPostRedisplay();
		glutTimerFunc(animationPeriod, animate, 1);
	}

}

void keyInput(unsigned char key, int x, int y){
	switch (key){
		case 27:
			exit(0);
			break;
		case ' ':
			if(isAnimate) isAnimate = 0;
			else{
				isAnimate = 1;
				animate(1);
			}
			break;
		default:
			break;
	}
}

void specialKeyInput(int key, int x,int y){
	if(key == GLUT_KEY_DOWN)	animationPeriod +=5;
	if(key == GLUT_KEY_UP)
		if(animationPeriod > 5) animationPeriod -=5;
	glutPostRedisplay();
}


void printInteraction(void){
	cout<<"Interaciton:"<<endl;
	cout<<"Press space to toggle bw animation on and off"<<endl;
	cout<<"Press up/down arrow key to speed up/ slow down animation"<<endl;

}

int main(int argc, char **argv){
	printInteraction();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA );
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("rotateHelix.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);
	setup();
	glutMainLoop();
}
