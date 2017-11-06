#include "bezier.h"

Bezier* ptr;
void animate(int value){
	if(isAnimate){
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
		default:
			break;
	}
}

void mousewheel(int button, int dir, int x, int y){
    if(dir > 0){
        z_dir += 5;
    }
    else{
        z_dir -= 5;
    }
}

void specialKeyInput(int key,int x,int y){
	if(key==GLUT_KEY_DOWN)animationPeriod+=5;
	if(key==GLUT_KEY_UP && animationPeriod>5)animationPeriod-=5;
	glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-z_dir);

    glRotatef(Xangle , 1.0 , 0.0 , 0.0);
    glRotatef(Yangle , 0.0 , 1.0 , 0.0);
    glRotatef(Zangle , 0.0 , 0.0 , 1.0);

    string s = "Akshay Bansal";
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    for(int i = 0; i < s.length(); i++){
        if(s[i] ==' '){
            continue;
        }
        ptr->a[s[i]-'A'](vec3(-16 + 4 * i, 0, 0), color((rand()%256)/255.0, (rand()%256)/255.0, (rand()%256)/255.0));
    }
    glutSwapBuffers();
}

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(1, 840.0/480.0, .1, 10000.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    ptr = new Bezier;
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
}

