#include <GL/freeglut.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;


void init(){
    glClearColor(1.0,1.0,1.0,1.0);  //background color and alpha
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,840.0/480.0,.2,1000.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

}

void plot(float x, float y){
    glPointSize(5);
    glBegin(GL_POINTS);
        glColor3f(1,0,0);
        glVertex3f(x,y,0);
        glVertex3f(-x,y,0);
        glVertex3f(x,-y,0);
        glVertex3f(-x,-y,0);
        glVertex3f(y,x,0);
        glVertex3f(-y,x,0);
        glVertex3f(y,-x,0);
        glVertex3f(-y,-x,0);
    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0, -100);
    float x,y,R,delta,s1,s2;
    R = 20;
    x = 0, y = R, delta = 2*(1-R);

    while( y >= x ){

        plot(x,y);

        if(delta < 0){
            s1 = 2*(delta-y)+1;
            if( s1 < 0 ){
                x += 1;
                y = sqrt(R*R - x*x);
                delta += 2*x - 1 ;
            }else{
                x += 1; y -= 1; delta += 2*(x-y+1);
            }
        }
        else if(delta > 0){
            s2 = 2*(delta-x)-1;
            if( s2 < 0 ){
                y -= 1;
                x = sqrt(R*R-y*y);
                delta -= (2*y+1);
            }
            else{
                x += 1; y -= 1; delta += 2*(x-y+1);
            }
        }
        else{
            x += 1; y -= 1; delta += 2*(x-y+1);
        }
    }

    glutSwapBuffers();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(840,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Circle");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

