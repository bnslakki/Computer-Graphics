#include <GL/freeglut.h>
#include <GL/glut.h>

#include "obj.h"
#include "imageloader.h"

#include <iostream>
using namespace std;

static int isAnimate = 0;
static int animationPeriod = 100;
static float Angle = 0.0;
static float z_dir = 1300;

static float ball_initial_speed = 20;

static int ball_vec_x = ball_initial_speed;
static int ball_vec_z = -ball_initial_speed;

static int ball_x = 0;
static int ball_z = 0;

static int tray1_x = 0;
static int tray2_x = 0;

GLUquadric *quad_space;
GLUquadric *quad_space1;

GLuint textureId;

GLUquadric *quad;

static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0;
cObj *obj;

void restart(){
    ball_vec_x = ball_initial_speed;
    ball_vec_z = -ball_initial_speed;

    ball_x = 0;
    ball_z = 0;

    tray1_x = 0;
    tray2_x = 0;

    isAnimate = 0;
}
void init(){
    glClearColor(1.0,1.0,1.0,1.0);  //background color and alpha
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,840.0/480.0,0.2,2000.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat ambientLight[]  = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseLight[]  = { 0.8f, 0.8f, 0.8, 1.0f };
	GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat position[]      = { 10.0f, 10.0f, 10.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	quad = gluNewQuadric();
	quad_space = gluNewQuadric();
	quad_space1 = gluNewQuadric();

	obj =new cObj("plane.obj");
	textureId = LoadImage("sky_right.jpg");

}

void moveahead(void){


    if( ball_x >= 450){
        ball_vec_x *= -1;
    }
    else if( ball_x <= -450){
        ball_vec_x *= -1;
    }
    else if(ball_z <= -785 and ball_x >= tray1_x and ball_x <= tray1_x + 200){
        ball_vec_z *= -1;
    }
    else if(ball_z > 15 and ball_x >= tray2_x and ball_x <= tray2_x + 200){
        ball_vec_z *= -1;
    }
    else if(ball_z <= -785 and (ball_x < tray1_x - 200 or ball_x > tray1_x)){
        restart();
    }
    else if(ball_z > 15 and (ball_x < tray2_x or ball_x > tray2_x + 200)){
        restart();
    }

    ball_x += ball_vec_x;
    ball_z += ball_vec_z;

}

void animate(int value){
	if(isAnimate){
        moveahead();
        Angle += 5.0;
        if(Angle > 360)Angle -= 360;
		glutPostRedisplay();
		glutTimerFunc(animationPeriod,animate,1);
	}
}

void keyInput(unsigned char key,int x,int y){
	switch(key){
		case 27:
			exit(0);
			break;
		case ' ':
			if(isAnimate)isAnimate=0;
			else{
				isAnimate=1;
				animate(1);
			}
			break;
		case 'q':
			Xangle += 5.0;
			if(Xangle > 360.0)Xangle -= 360.0;
			glutPostRedisplay();
			break;
		case 'w':
			Xangle -= 5.0;
			if(Xangle < 0.0)Xangle += 360.0;
			glutPostRedisplay();
			break;
		case 'a':
			Yangle += 5.0;
			if(Yangle > 360.0)Yangle -= 360.0;
			glutPostRedisplay();
			break;
		case 's':
			Yangle -= 5.0;
			if(Yangle < 0.0)Yangle += 360.0;
			glutPostRedisplay();
			break;
		case 'z':
			Zangle += 5.0;
			if(Zangle > 360.0)Zangle -= 360.0;
			glutPostRedisplay();
			break;
		case 'x':
			Zangle -= 5.0;
			if(Zangle < 0.0)Zangle += 360.0;
			glutPostRedisplay();
			break;
        case 'e':
            if(tray2_x > -460)
			tray2_x -= 20.0;
			glutPostRedisplay();
			break;
		case 'r':
		    if(tray2_x <= 240)
			tray2_x += 20.0;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}


void specialKeyInput(int key,int x,int y){
	if(key==GLUT_KEY_DOWN)animationPeriod+=5;
	if(key==GLUT_KEY_UP && animationPeriod>5)animationPeriod-=5;

	if( key == GLUT_KEY_LEFT  && tray1_x > -460 ){
        tray1_x -= 20;
    }

    else if( key == GLUT_KEY_RIGHT  && tray1_x <= 240 ){
        tray1_x += 20;
    }

	glutPostRedisplay();
}

void drawTray(){
    for(int i = -1; i <= 1; i++){
        if(!i)continue;
        glPushMatrix();
            glRotatef(30, 1.0, 0.0, 0.0);
            glTranslatef(0, 0.0, i * 450.0);
            if(i < 0)glTranslatef(tray1_x, 0.0, 0.0);
            else glTranslatef(tray2_x, 0.0, 0.0);
            glTranslatef(0.0, 50.0, .0);
            glRotatef(90, 0.0, 1.0, 0.0);
            gluCylinder(quad_space1, 30, 30, 200, 100, 100);
            glRotatef(-90, 0.0, 1.0, 0.0);
            gluSphere(quad_space, 30, 20, 20);
            glTranslatef(200.0, 0.0, .0);
            gluSphere(quad_space, 30, 20, 20);
        glPopMatrix();
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-z_dir);

    glRotatef(Xangle , 1.0 , 0.0 , 0.0);
    glRotatef(Yangle , 0.0 , 1.0 , 0.0);
    glRotatef(Zangle , 0.0 , 0.0 , 1.0);


//    glEnable( GL_TEXTURE_2D );
//    glBindTexture( GL_TEXTURE_2D, textureId );
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//    glBegin (GL_QUADS);
//        glTexCoord2f(0.0,0.0); glVertex2f(0.0,0.0);
//        glTexCoord2f(1.0,0.0); glVertex2f(1024.0,0.0);
//        glTexCoord2f(1.0,1.0); glVertex2f(1024.0,512.0);
//        glTexCoord2f(0.0,1.0); glVertex2f(0.0,512.0);
//    glEnd();
//    gluQuadricTexture(quad,1);
//    gluSphere(quad, 1000, 20, 20);
//    glDisable( GL_TEXTURE_2D );



    drawTray();

    // ball
    glPushMatrix();
        glRotatef(30, 1.0, 0.0, 0.0);
        glTranslatef(ball_x, 0.0, ball_z + 400);
        //cout<<ball_x<<" "<<ball_z<<endl;
        glTranslatef(0.0, 50.0, .0);
        glRotatef(70, 0.0, 0.0, 1.0);
        gluSphere(quad_space, 30, 20, 20);
    glPopMatrix();

    // plane
    glPushMatrix();
        glScalef(1.5, 1.5, 1.5);
        glRotatef(210, 1.0, 0.0, 0.0);
        obj->render();
    glPopMatrix();



    glutSwapBuffers();
}

void mousewheel(int button, int dir, int x, int y){
    if(dir > 0){
        z_dir += 5;
    }
    else{
        z_dir -= 5;
    }
    cout<<z_dir<<'\n';
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(840,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Akshay Bansal");
	init();
	glutDisplayFunc(display);
    glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);
	glutMouseWheelFunc(mousewheel);
	glutMainLoop();
	free(obj);
}

