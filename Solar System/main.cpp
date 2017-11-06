#include "main.h"


void drawSun(){
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        //glRotatef(latAngle , 0.0 , 1.0 , 0.0);
        glBindTexture(GL_TEXTURE_2D, textureId_sun);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        gluQuadricTexture(quad_sun,1);
        gluSphere(quad_sun, 1.5, 20, 20);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void drawMoon(){
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glRotatef(23.0, 1.0, 0.0, 0.0);
        glRotatef(275 - 6.8, 1.0, 0.0, 0.0);
        glRotatef(EarthOrbitRotation, 0.0, 0.0, 1.0);
        float x_ = EarthMajorAxis * cosf(EarthOrbitRotation * (PI / 180));
        float y_ = EarthMinorAxis * sinf(EarthOrbitRotation * (PI / 180));
        glTranslatef(sqrt(x_ * x_  + y_ * y_), 0.0, 0.0);
        glRotatef(-EarthOrbitRotation, 0.0, 0.0, 1.0);
        glRotatef(EarthRotation, 0.0, 1.0, 0.0);
        glTranslatef(.7, 0.0, 0.0);
        glBindTexture(GL_TEXTURE_2D, textureId_moon);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        gluQuadricTexture(quad_moon,1);
        gluSphere(quad_moon, .15, 20, 20);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void drawPlanet(float inclination, float radious, float planetMajorAxis, float planetMinorAxis, GLUquadric *quad, GLuint textureId_planet, float angle, float rot_axis, float error){
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glRotatef(23.0, 1.0, 0.0, 0.0);
        glRotatef(inclination, .0 , 0.0 , 1.0);
        glRotatef(275 - error, 1.0, 0.0, 0.0);
        glRotatef(angle, 0.0, 0.0, 1.0);
        float x_ = planetMajorAxis * cosf(angle * (PI / 180));
        float y_ = planetMinorAxis * sinf(angle * (PI / 180));
        glTranslatef(sqrt(x_ * x_  + y_ * y_), 0.0, 0.0);
        glRotatef(-angle, 0.0, 0.0, 1.0);
        glRotatef(rot_axis, 0.0, 0.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, textureId_planet);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        gluQuadricTexture(quad, 1);
        gluSphere(quad, radious, 20, 20);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void draworbit(COrbitLine *Orbit, color in, float inclination){
    glUseProgram(programID);
    glPushMatrix();
        glRotatef(23, 1.0 , 0.0 , 0.0);
        glRotatef(inclination, .0 , 0.0 , 1.0);
        glUniform3f(glGetUniformLocation(programID, "color"), in.R, in.G, in.B);
        Orbit->DrawOrbitLine();
    glPopMatrix();
    glUseProgram(0);
}

void drawPlanetRing(float planet_rot, float planetRadius, float planetMajorAxis, float planetMinorAxis, GLUquadric *quad, GLuint textureId_planet ){

    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glRotatef(23.0, 1.0, 0.0, 0.0);
        glRotatef(275 - 6.8 , 1.0, 0.0, 0.0);
        glRotatef(planet_rot, 0.0, 0.0, 1.0);
        float x_ = planetMajorAxis * cosf(planet_rot * (PI / 180));
        float y_ = planetMinorAxis * sinf(planet_rot * (PI / 180));
        glTranslatef(sqrt(x_ * x_  + y_ * y_), 0.0, 0.0);
        glRotatef(-planet_rot, 0.0, 0.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, textureId_planet);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glRotatef(30.0, 1.0, 0.0, 0.0);
        //glRotatef(SaturnRotation, 0.0, 0.0, 1.0);
        gluQuadricTexture(quad,1);
        gluDisk(quad, planetRadius, planetRadius + .25, 20, 20);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
void drawScene(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    glTranslatef(0.0 , 1.0 , -z_dir);

    glRotatef(Xangle , 1.0 , 0.0 , 0.0);
    glRotatef(Yangle , 0.0 , 1.0 , 0.0);
    glRotatef(Zangle , 0.0 , 0.0 , 1.0);

    // draw space
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureId_space);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        gluQuadricTexture(quad_space,1);
        gluSphere(quad_space, 100, 20, 20);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    // draw sun
    drawSun();

    // draw moon
    drawMoon();

    // draw Planets
    drawPlanet(0, MercuryRadius, MercuryMajorAxis, MercuryMinorAxis, quad_mercury, textureId_mercury, MercuryOrbitRotation, MercuryRotation, 6.8);
    drawPlanet(0, VenusRadius, VenusMajorAxis, VenusMinorAxis, quad_venus, textureId_venus, VenusOrbitRotation, VenusRotation,6.8);
    drawPlanet(0, EarthRadius, EarthMajorAxis, EarthMinorAxis, quad_earth, textureId_earth, EarthOrbitRotation, EarthRotation, 6.8);
    drawPlanet(0, MarsRadius, MarsMajorAxis, MarsMinorAxis, quad_mars, textureId_mars, MarsOrbitRotation, MarsRotation,6.8);
    drawPlanet(0, JupiterRadius, JupiterMajorAxis, JupiterMinorAxis, quad_jupiter, textureId_jupiter, JupiterOrbitRotation, JupiterRotation,6.8);
    drawPlanet(0, SaturnRadius, SaturnMajorAxis, SaturnMinorAxis, quad_saturn, textureId_saturn, SaturnOrbitRotation, SaturnRotation,6.8);
    drawPlanet(0, UranusRadius, UranusMajorAxis, UranusMinorAxis, quad_uranus, textureId_uranus, UranusOrbitRotation, UranusRotation,6.8);
    drawPlanet(0, NeptuneRadius, NeptuneMajorAxis, NeptuneMinorAxis, quad_neptune, textureId_neptune, NeptuneOrbitRotation, NeptuneRotation,6.8);
    drawPlanet(4, PlutoRadius, PlutoMajorAxis, PlutoMinorAxis, quad_pluto, textureId_pluto, PlutoOrbitRotation, PlutoRotation, 6.8);

    // draw orbit
    draworbit(OrbitMercury, color(0.5, 0.5, 0.5), 0);
    draworbit(OrbitVenus, color(0.5, 0.0, 0.0), 0);
    draworbit(OrbitEarth, color(1.0, 1.0, 0.0), 0);
    draworbit(OrbitMars, color(0.0, 1.0, 1.0), 0);
    draworbit(OrbitJupiter, color(0.0, 1.0, 0.0), 0);
    draworbit(OrbitSaturn, color(0.0, 0.0, 1.0), 0);
    draworbit(OrbitUranus, color(0.0, 0.5, 1.0), 0);
    draworbit(OrbitNeptune, color(0.5, 0.5, 1.0), 0);
    draworbit(OrbitPluto, color(0.5, 0.0, 0.5), 4);

    // draw ring
    drawPlanetRing(SaturnOrbitRotation, SaturnRadius + 0.1 ,SaturnMajorAxis, SaturnMinorAxis, quad_saturnRing, textureId_saturnRing);
    drawPlanetRing(UranusOrbitRotation, UranusRadius + 0.1 ,UranusMajorAxis, UranusMinorAxis, quad_uranusRing, textureId_uranusRing);

	glutSwapBuffers();
}

void setup(void){
	glClearColor(.0 , .0 , .0 , 0.0);
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glewInit();

    quad_space   = gluNewQuadric();
    quad_sun     = gluNewQuadric();
    quad_mercury = gluNewQuadric();
    quad_venus   = gluNewQuadric();
    quad_earth   = gluNewQuadric();
    quad_mars    = gluNewQuadric();
    quad_moon    = gluNewQuadric();
    quad_jupiter = gluNewQuadric();
    quad_saturn  = gluNewQuadric();
    quad_uranus  = gluNewQuadric();
    quad_neptune = gluNewQuadric();
    quad_pluto   = gluNewQuadric();

    quad_saturnRing = gluNewQuadric();
    quad_uranusRing = gluNewQuadric();

    programID = LoadShaders( "orbitShader_V.vert", "orbitShader_F.frag" );

    textureId_space      = LoadImage("ImageData/JPGImages/texture_space.jpg");
    textureId_sun        = LoadImage("ImageData/JPGImages/texture_sun.jpg");
    textureId_mercury    = LoadImage("ImageData/JPGImages/texture_mercury.jpg");
    textureId_venus      = LoadImage("ImageData/JPGImages/texture_venus.jpg");
    textureId_earth      = LoadImage("ImageData/JPGImages/texture_earth.jpg");
	textureId_moon       = LoadImage("ImageData/JPGImages/texture_moon.jpg");
	textureId_mars       = LoadImage("ImageData/JPGImages/texture_mars.jpg");
	textureId_jupiter    = LoadImage("ImageData/JPGImages/texture_jupiter.jpg");
	textureId_saturn     = LoadImage("ImageData/JPGImages/texture_saturn.jpg");
	textureId_uranus     = LoadImage("ImageData/JPGImages/texture_uranus.jpg");
	textureId_neptune    = LoadImage("ImageData/JPGImages/texture_naptune.jpg");
	textureId_pluto      = LoadImage("ImageData/JPGImages/texture_pluto.jpg");
	textureId_saturnRing = LoadImage("ImageData/JPGImages/saturnringcolor.jpg");
    textureId_uranusRing = LoadImage("ImageData/JPGImages/uranusringcolour.jpg");

	OrbitMercury = new COrbitLine(MercuryMajorAxis, MercuryMinorAxis);
	OrbitVenus   = new COrbitLine(VenusMajorAxis, VenusMinorAxis);
	OrbitEarth   = new COrbitLine(EarthMajorAxis, EarthMinorAxis);
	OrbitMars    = new COrbitLine(MarsMajorAxis, MarsMinorAxis);
	OrbitJupiter = new COrbitLine(JupiterMajorAxis, JupiterMinorAxis);
	OrbitSaturn  = new COrbitLine(SaturnMajorAxis, SaturnMinorAxis);
	OrbitUranus  = new COrbitLine(UranusMajorAxis, UranusMinorAxis);
	OrbitNeptune = new COrbitLine(NeptuneMajorAxis, NeptuneMinorAxis);
	OrbitPluto   = new COrbitLine(PlutoMajorAxis, PlutoMinorAxis);

}

void resize(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, .2, 1000.0);
}


void animate(int value){
	if(isAnimate){
        MercuryOrbitRotation += 3.0;
        MercuryRotation += 8.2;

        VenusOrbitRotation += 2.0;
        VenusRotation -= 4.2;

        EarthOrbitRotation += 1.5;
        EarthRotation += 6.5;

        MarsOrbitRotation += 1.0;
        MarsRotation += 5.1;

        JupiterOrbitRotation += 0.2;
        JupiterRotation += 2.2;

        SaturnOrbitRotation += 0.17;
        SaturnRotation += 2.0;

        UranusOrbitRotation += 0.15;
        UranusRotation += 1.6;

        NeptuneOrbitRotation += 0.12;
        NeptuneRotation += 1.1;

        PlutoOrbitRotation += .1;
        PlutoRotation += 1.1;

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
		case 'f':
		    fullscreen = !fullscreen;
		    if(fullscreen){
                glutFullScreen();
		    }
		    else{
                glutReshapeWindow(1450, 800);
		    }
			glutPostRedisplay();
			break;
		default:
			break;
	}
}


void specialKeyInput(int key,int x,int y){
	if(key==GLUT_KEY_DOWN)animationPeriod+=5;
	if(key==GLUT_KEY_UP && animationPeriod>5)animationPeriod-=5;
	glutPostRedisplay();
}

void mousewheel(int button, int dir, int x, int y){
    if(dir > 0){
        z_dir += 1;
    }
    else{
        z_dir -= 1;
    }
}


int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(1450,800);
	glutInitWindowPosition(60,10);

	glutCreateWindow("Solar System");

	setup();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);
	glutMouseWheelFunc(mousewheel);
	glutMainLoop();
}

