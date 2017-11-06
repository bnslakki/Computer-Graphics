#ifndef ORBIT_H
#define ORBIT_H

#include <gl/glew.h>

#include <math.h>
#include <vector>

#define PI  3.1415926535897932384626433832795f

using namespace  std;

class Vector3{
    public:
        GLfloat xpos;
        GLfloat ypos;
        GLfloat zpos;
		Vector3(){};
        Vector3(float a, float b , float c){
            xpos=a;ypos=b;zpos=c;
        }
};

class color{
    public:
        GLfloat R;
        GLfloat G;
        GLfloat B;
		color(){};
        color(float a, float b , float c){
            R=a;G=b;B=c;
        }
};
class COrbitLine
{
	private:
		vector<Vector3> _OrbitPoints;
		vector<GLuint> _Index;
		GLuint IndexCount;

		GLuint _OrbitVAO;
		GLuint _OrbitVBO;
		GLuint _OrbitEBO;

	public:
		COrbitLine(float pMajorAxis=0.0,float pMinorAxis=0.0);
		~COrbitLine();
		void DrawOrbitLine();

};

#endif

