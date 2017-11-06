#include<iostream>
#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<stdio.h>


#define PI 3.14159265

using namespace std;

static int isAnimate = 0;
static int animationPeriod = 50;
static float angle = 0.0;

void drawScene(void){

     float R = 20.0;
     float t;
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0.0, 0.0, 0.0);
     glPushMatrix();
     glTranslatef(0.0, 0.0, -60.0);
     glRotatef(angle,0.0, 1.0, 0.0);
     glTranslatef(0.0, 0.0, 60.0);

     glBegin(GL_LINE_STRIP);
     for(t = -10 * PI; t <= 10 + PI;  t += PI / 20.0)
        glVertex3f(R * cos(t), t, R * sin(t)- 60.0);
     glEnd();
     glPopMatrix();
     glutSwapBuffers();
}

void setup(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void resize(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void increasingAngle(void){
	angle += 5.0;
	if(angle > 360.0) angle -= 360.0;
}

void animate(int value){
	if(isAnimate){
		increasingAngle();
		glutPostRedisplay();
		glutTimerFunc(animationPeriod, animate, 1);
	}
}

void keyInput(unsigned char key, int x, int y){
	switch(key){
		case 27:
        	exit(0);
			break;
        case ' ':
			if(isAnimate)isAnimate = 0;
			else{
				isAnimate = 1;
				animate(1);
			}
			break;
		default:
			break;
	}
}

void specialKeyInput(int key, int x, int y){
	if(key == GLUT_KEY_DOWN)animationPeriod += 5;
	if(key == GLUT_KEY_UP){
		if(animationPeriod > 5)animationPeriod -= 5;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("akshay");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);
	setup();
	glutMainLoop();
}
