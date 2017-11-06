#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<stdio.h>
#include<math.h>
 
using namespace std;
 
void plot(float x, float y){
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
    glVertex2i(round(x), round(y));
    glEnd();
}
void DDA(float x1, float y1, float x2, float y2){
	float dx = (x2 - x1);
	float dy = (y2- y1);
	float sign1 = 1.0, sign2 = 1.0;
	float step;
	if(dx < 0){
		sign1 *= -1;	
	}
	if(dy < 0){
		sign2 *= -1;	
	}
	if(!dx){
		step = abs(dy);
		for(float k = 0; k < step; k++){
			y1 = y1 + 1.0;
			plot(x1, y1);
		}
		return ;
	}
    float m = dy / dx;	
	if(dy <= dx){
		step = abs(dx);
		for(float k = 0; k < step; k++){
			x1 = x1 + 1.0 * sign1;
			y1 = y1 + m * sign2;
			//printf("%lf %lf\n",x, y);
			plot(x1, y1);
		}
 
 
	}
	else{
		step = abs(dy);
		for(float k = 0; k < step; k++){
			x1 = x1 + (1 / m) * sign1 ;
			y1 = y1 + 1.0 * sign2;
			plot(x1, y1);
		}
		//printf("%lf %lf\n",x, y);
	}		
}
 
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	float a, b;
 
	DDA(-800.f, 0.0f, 800.f, 0.f);
	DDA(0.f, -800.0f, 0.f, 800.f);
 
	DDA(-200, -300, 100.f, 100.f);
	//scanf("%f %f", &a, &b);
	//DDA(0.0f, 0.0f, a, b);
	glFlush();
}
 
void init(){
    glClearColor(0.1f, 0.1f, 1.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1000, 1000, -1000, 1000);
}
 
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1024, 1024);
	glutCreateWindow("line prog");	
	init();
 
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
