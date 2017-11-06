#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <math.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "orbit.h"
#include "imageloader.h"
#include "shader.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include <GL/freeglut.h>

using namespace std;

static int isAnimate = 0;
static int animationPeriod = 100;
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0;
static int z_dir = 20;
bool fullscreen;

GLuint programID;

GLUquadric *quad_space;
GLUquadric *quad_sun;
GLUquadric *quad_earth;
GLUquadric *quad_moon;
GLUquadric *quad_mercury;
GLUquadric *quad_venus;
GLUquadric *quad_mars;
GLUquadric *quad_jupiter;
GLUquadric *quad_saturn;
GLUquadric *quad_uranus;
GLUquadric *quad_neptune;
GLUquadric *quad_pluto;
GLUquadric *quad_saturnRing;
GLUquadric *quad_uranusRing;

GLuint textureId_space;
GLuint textureId_sun;
GLuint textureId_earth;
GLuint textureId_moon;
GLuint textureId_mercury;
GLuint textureId_venus;
GLuint textureId_mars;
GLuint textureId_jupiter;
GLuint textureId_saturn;
GLuint textureId_uranus;
GLuint textureId_neptune;
GLuint textureId_pluto;
GLuint textureId_saturnRing;
GLuint textureId_uranusRing;

COrbitLine *OrbitEarth;
COrbitLine *OrbitMercury;
COrbitLine *OrbitVenus;
COrbitLine *OrbitMars;
COrbitLine *OrbitJupiter;
COrbitLine *OrbitSaturn;
COrbitLine *OrbitUranus;
COrbitLine *OrbitNeptune;
COrbitLine *OrbitPluto;


float extra_rad = 0.1;
//planet Mercury-------------------------------
float MercuryRotation = 0.0;
float MercuryOrbitRotation = 0.0;
float MercuryDistance = 2.00;
float MercuryRadius=.20 + extra_rad;
float MercuryMajorAxis=MercuryDistance+.20;
float MercuryMinorAxis=MercuryDistance-.20;

//planet Venus-------------------------------
float VenusRotation = 0.0;
float VenusOrbitRotation = 0.0;
float VenusDistance = MercuryDistance + .70;
float VenusRadius=.20 + extra_rad;
float VenusMajorAxis=VenusDistance+.15;
float VenusMinorAxis=VenusDistance-.25;

//planet Earth-------------------------------
float EarthRotation = 0.0;
float EarthOrbitRotation = 0.0;
float EarthDistance = VenusDistance + 1.20;
float EarthRadius=.30 + extra_rad;
float EarthMajorAxis=EarthDistance+.50;
float EarthMinorAxis=EarthDistance-.50;


//planet Mars-------------------------------
float MarsRotation = 0.0;
float MarsOrbitRotation = 0.0;
float MarsDistance = EarthDistance + 1.50;
float MarsRadius=.28 + extra_rad;
float MarsMajorAxis=MarsDistance+.50;
float MarsMinorAxis=MarsDistance -.50;

//planet Jupiter-------------------------------
float JupiterRotation = 0.0;
float JupiterOrbitRotation = 0.0;
float JupiterDistance = MarsDistance + 1.40;
float JupiterRadius=.55 + extra_rad;
float JupiterMajorAxis=JupiterDistance+1.00;
float JupiterMinorAxis=JupiterDistance -1.00;

//planet Saturn-------------------------------
float SaturnRotation = 0.0;
float SaturnOrbitRotation = 0.0;
float SaturnDistance = JupiterDistance + 2.70;
float SaturnRadius=.51 + extra_rad;
float SaturnMajorAxis=SaturnDistance + 1.00;
float SaturnMinorAxis=SaturnDistance -1.00;

//planet Uranus-------------------------------
float UranusRotation = 0.0;
float UranusOrbitRotation = 0.0;
float UranusDistance=SaturnDistance + 2.20;
float UranusRadius=.31 + extra_rad;
float UranusMajorAxis=UranusDistance + 2.00;
float UranusMinorAxis=UranusDistance -2.00;

//planet Naptune-------------------------------
float NeptuneRotation = 0.0;
float NeptuneOrbitRotation = 0.0;
float NeptuneDistance=UranusDistance + 3.00;
float NeptuneRadius=.31 + extra_rad;
float NeptuneMajorAxis=NeptuneDistance + 3.00;
float NeptuneMinorAxis=NeptuneDistance -2.50;


//planet Pluto-------------------------------
float PlutoRotation = 0.0;
float PlutoOrbitRotation = 0.0;
float PlutoDistance=NeptuneDistance + 3.00;
float PlutoRadius=.21 + extra_rad;
float PlutoMajorAxis=PlutoDistance + 4.00;
float PlutoMinorAxis=PlutoDistance -4.00;

float plutoOrbitShift=50.0;
float plutoOrbitTilt=2.0;
#endif // MAIN_H
