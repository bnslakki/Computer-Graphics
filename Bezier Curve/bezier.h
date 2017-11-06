#ifndef BEZIER_H
#define BEZIER_H

#include <GL/freeglut.h>
#include <GL/glut.h>

#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

static int isAnimate = 0;
static int animationPeriod = 100;
static float Angle = 0.0;
static float z_dir = 1300;


static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0;

using namespace std;

typedef long long ll;


class color{
    public:
        GLfloat R;
        GLfloat G;
        GLfloat B;
        color(){};
        color(float a, float b , float c){
            R = a; G = b; B = c;
        }
};

class vec3{
    public:
        GLfloat xpos;
        GLfloat ypos;
        GLfloat zpos;
		vec3(){};
        vec3(float a, float b , float c){
            xpos=a;ypos=b;zpos=c;
        }
};

typedef void (*fp)( vec3 , color );

enum alphabet{A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

class Bezier{
    private:
        const ll fact[21] ={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};
        float J_fun(int, int, float);
        pair<float, float>pt_util(float, vector<pair<float, float>>);
        void drawVerLine(color c){
            glColor3f(c.R, c.G, c.B);
            glBegin(GL_LINES);
                glVertex3f(0, 0, 0.0);
                glVertex3f(0, 5, 0.0);
            glEnd();
        }
        void drawVerLine(float l, color c){
            glColor3f(c.R, c.G, c.B);
            glBegin(GL_LINES);
                glVertex3f(0, 0, 0.0);
                glVertex3f(0, l, 0.0);
            glEnd();
        }
        void drawHorLine(float l, color c){
            glColor3f(c.R, c.G, c.B);
            glBegin(GL_LINES);
                glVertex3f(0, 0, 0.0);
                glVertex3f(l, 0, 0.0);
            glEnd();
        }
    public:
        Bezier();
        void draw(vector<pair<float, float>>, color);

        void draw_A(vec3, color);
        void draw_B(vec3, color);
        void draw_C(vec3, color);
        void draw_D(vec3, color);
        void draw_E(vec3, color);
        void draw_F(vec3, color);
        void draw_G(vec3, color);
        void draw_H(vec3, color);
        void draw_I(vec3, color);
        void draw_J(vec3, color);
        void draw_K(vec3, color);
        void draw_L(vec3, color);
        void draw_M(vec3, color);
        void draw_N(vec3, color);
        void draw_O(vec3, color);
        void draw_P(vec3, color);
        void draw_Q(vec3, color);
        void draw_R(vec3, color);
        void draw_S(vec3, color);
        void draw_T(vec3, color);
        void draw_U(vec3, color);
        void draw_V(vec3, color);
        void draw_W(vec3, color);
        void draw_X(vec3, color);
        void draw_Y(vec3, color);
        void draw_Z(vec3, color);

        fp a[26];

};

#endif // BEZIER_H
