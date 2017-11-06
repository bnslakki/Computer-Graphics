#include "bezier.h"

Bezier* obj;

void DrawA(vec3 a,color b){
    obj->draw_A(a, b);
}

void DrawB(vec3 a,color b){
    obj->draw_B(a, b);
}

void DrawC(vec3 a,color b){
    obj->draw_C(a, b);
}

void DrawD(vec3 a,color b){
    obj->draw_D(a, b);
}

void DrawE(vec3 a,color b){
    obj->draw_E(a, b);
}

void DrawF(vec3 a,color b){
    obj->draw_F(a, b);
}

void DrawG(vec3 a,color b){
    obj->draw_G(a, b);
}

void DrawH(vec3 a,color b){
    obj->draw_H(a, b);
}

void DrawI(vec3 a,color b){
    obj->draw_I(a, b);
}

void DrawJ(vec3 a,color b){
    obj->draw_J(a, b);
}

void DrawK(vec3 a,color b){
    obj->draw_K(a, b);
}

void DrawL(vec3 a,color b){
    obj->draw_L(a, b);
}

void DrawM(vec3 a,color b){
    obj->draw_M(a, b);
}

void DrawN(vec3 a,color b){
    obj->draw_N(a, b);
}

void DrawO(vec3 a,color b){
    obj->draw_O(a, b);
}

void DrawP(vec3 a,color b){
    obj->draw_P(a, b);
}

void DrawQ(vec3 a,color b){
    obj->draw_Q(a, b);
}

void DrawR(vec3 a,color b){
    obj->draw_R(a, b);
}

void DrawS(vec3 a,color b){
    obj->draw_S(a, b);
}

void DrawT(vec3 a,color b){
    obj->draw_T(a, b);
}

void DrawU(vec3 a,color b){
    obj->draw_U(a, b);
}

void DrawV(vec3 a,color b){
    obj->draw_V(a, b);
}

void DrawW(vec3 a,color b){
    obj->draw_W(a, b);
}

void DrawX(vec3 a,color b){
    obj->draw_X(a, b);
}

void DrawY(vec3 a,color b){
    obj->draw_Y(a, b);
}

void DrawZ(vec3 a,color b){
    obj->draw_Z(a, b);
}
Bezier::Bezier(){
    obj = this;
     a[0] =  DrawA;
     a[1] =  DrawB;
     a[2] =  DrawC;
     a[3] =  DrawD;
     a[4] =  DrawE;
     a[5] =  DrawF;
     a[6] =  DrawG;
     a[7] =  DrawH;
     a[8] =  DrawI;
     a[9] =  DrawJ;
     a[10] =  DrawK;
     a[11] =  DrawL;
     a[12] =  DrawM;
     a[13] =  DrawN;
     a[14] =  DrawO;
     a[15] =  DrawP;
     a[16] =  DrawQ;
     a[17] =  DrawR;
     a[18] =  DrawS;
     a[19] =  DrawT;
     a[20] =  DrawU;
     a[21] =  DrawV;
     a[22] =  DrawW;
     a[23] =  DrawX;
     a[24] =  DrawY;
     a[25] =  DrawZ;
}

float Bezier::J_fun(int i, int j, float t){
    ll ncr = fact[i - 1] / (fact[j] * fact[i - 1 - j]);
    return (float)ncr * powf(t, j) * powf(1 - t, i - j - 1);
}

pair<float, float>Bezier::pt_util(float t, vector<pair<float, float>> pts){
    pair<float, float> ret;
    ret.first = ret.second = 0.0;
    for(int i = 0; i < pts.size(); i++){
        float tm = J_fun(pts.size(), i, t);
        ret.first += tm * (pts[i].first);
        ret.second += tm * (pts[i].second);
    }
    return ret;
}

void Bezier::draw(vector<pair<float, float>> arr, color cl){
    pair<float, float>p;
	glBegin(GL_POINTS);
		glColor3f(cl.R, cl.G, cl.B);
		for(float t = 0.0; t <= 1.0; t += 0.001){
			p = pt_util(t, arr);
			glVertex2f(p.first, p.second);
		}
	glEnd();
}

void Bezier::draw_A(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 3, pos.ypos - 1.0, pos.zpos);
    pos = {0, 0, 0};
    vector<pair<float, float>> tm;
    tm = {{0, 1}, {2, 10}, {3.5, 1}};
    draw(tm, cl);
    glBegin(GL_LINES);
        glVertex3f(0.5, 3, 0.0);
        glVertex3f(3.1, 3, 0.0);
    glEnd();
    glPopMatrix();
}

void Bezier::draw_B(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos, pos.ypos, pos.zpos);
    pos = {3, 0.5, 0};
    glScalef(0.7, 0.5, .5);
    glRotatef(180, 0.0, 1.0, 0.0);
    draw_C(pos, cl);
    glTranslatef(0.0, 5.0, 0.0);
    draw_C(pos, cl);
    glPushMatrix();
    glBegin(GL_LINES);
        glVertex3f(3, 5, 0.0);
        glVertex3f(3, -5, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void Bezier::draw_C(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos -3, pos.ypos - .5, pos.zpos);
    pos = {0, 0, 0};
    vector<pair<float, float>> tm;
    tm = { {3, 0}, {0, 1}, {0, 4}, {3, 5} };
    draw(tm, cl);
    glPopMatrix();
}

void Bezier::draw_D(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos + 1, pos.ypos - .5, pos.zpos);
    pos = {3, 0.5, 0};
    glRotatef(180, 0.0, 1.0, 0.0);
    draw_C(pos, cl);
    glBegin(GL_LINES);
        glVertex3f(3, 0, 0.0);
        glVertex3f(3, 5, 0.0);
    glEnd();
    glPopMatrix();
}

void Bezier::draw_E(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 2, pos.ypos - 0.6, pos.zpos);
    pos = {0, 0, 0};
    drawVerLine(cl);
    drawHorLine(3.5, cl);
    glTranslatef(0.0, 2.5, 0.0);
    drawHorLine(3, cl);
    glTranslatef(0.0, -2.5, 0.0);
    glTranslatef(0.0, 5.0, 0.0);
    drawHorLine(3.5, cl);
    glPopMatrix();
}

void Bezier::draw_F(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 2, pos.ypos - 0.6, pos.zpos);
    pos = {0, 0, 0};
    drawVerLine(cl);
    glTranslatef(0.0, 2.5, 0.0);
    drawHorLine(3, cl);
    glTranslatef(0.0, -2.5, 0.0);
    glTranslatef(0.0, 5.0, 0.0);
    drawHorLine(3.5, cl);
    glPopMatrix();
}

void Bezier::draw_G(vec3 pos, color cl){
    glPushMatrix();
    glScalef(2.0, 2.0, 2.0);
    glTranslatef(pos.xpos + 1.5, pos.ypos - 1.8, pos.zpos);
    pos = {0, 0, 0};
    vector<pair<float, float>> tm;
    tm = { {3, 4}, {0, 4}, {0, 0}, {4, 0}, {4, 2.5}, {3, 2.5}, {2, 2.5} };
    draw(tm, cl);
    glPopMatrix();
}

void Bezier::draw_H(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 2.5, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    drawVerLine(cl);
    glTranslatef(0, 2.5, 0);
    drawHorLine(3, cl);
    glTranslatef(0, -2.5, 0);
    glTranslatef(3, 0, 0);
    drawVerLine(cl);
    glPopMatrix();
}

void Bezier::draw_I(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 1, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    drawVerLine(cl);
    glTranslatef(-.5, 0, 0);
    drawHorLine(1, cl);
    glTranslatef(0.0, 5.0, 0.0);
    drawHorLine(1, cl);
    glPopMatrix();
}

void Bezier::draw_J(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 1, pos.ypos + 1, pos.zpos);
    pos = {3, 0.5, 0};
    glTranslatef(-0.5, 3.0, 0.0);
    drawHorLine(1, cl);
    glTranslatef(0.5, -3.0, 0.0);
    drawVerLine(3, cl);
    glTranslatef(0.0, -1.2, 0.0);
    glScalef(0.4, 0.4, 0.4);
    glRotatef(90.0,0.0, 0.0, 1.0);
    draw_C(pos, cl);
    glPopMatrix();
}

void Bezier::draw_K(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 2, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    drawVerLine(cl);
    glTranslatef(0.0, 2.5, 0.0);
    glRotatef(45, 0.0, 0.0, 1.0);
        drawHorLine(3.5, cl);
    glRotatef(-45, 0.0, 0.0, 1.0);

    glRotatef(-45, 0.0, 0.0, 1.0);
    drawHorLine(3.5, cl);
    glPopMatrix();
}

void Bezier::draw_L(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 2, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    drawVerLine(cl);
    drawHorLine(3.0, cl);
    glPopMatrix();
}

void Bezier::draw_M(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 3, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    drawVerLine(cl);
    glTranslatef(0.0, 5.0, 0.0);
        glRotatef(-45, 0.0, 0.0, 1.0);
        drawHorLine(3, cl);
        glRotatef(45, 0.0, 0.0, 1.0);

        glTranslatef(2.1, -2.1, 0.0);
            glRotatef(45, 0.0, 0.0, 1.0);
            drawHorLine(3, cl);
            glRotatef(-45, 0.0, 0.0, 1.0);
        glTranslatef(-2.1, 2.1, 0.0);

    glTranslatef(0.2, -5.0, 0.0);

    glTranslatef(4.0, 0.0, 0.0);
    drawVerLine(cl);
    glPopMatrix();
}

void Bezier::draw_N(vec3 pos, color cl){

    glPushMatrix();
    glTranslatef(pos.xpos - 3, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    drawVerLine(cl);

    glTranslatef(2.8, 0.0, 0.0);
    glRotatef(30, 0, 0, 1);
        drawVerLine(5.7, cl);
    glRotatef(-30, 0, 0, 1);
    glTranslatef(-2.8, 0.0, 0.0);

    glTranslatef(2.8, 0.0, 0.0);
    drawVerLine(cl);
    glPopMatrix();


}

void Bezier::draw_O(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 1.6, pos.ypos + 2.4, pos.zpos);
    pos = {0, 0, 0};
    vector<pair<float, float>> tm;
    tm = { {2,-6}, {-2,-6}, {-4,-4}, {-6,-2}, {-6,2}, {-4,4}, {-2,6} ,{2,6}, {4,4}, {6,2}, {6,-2}, {4,-4}, {2,-6} };
    glScalef(0.5, 0.5, 0.5);
    draw(tm, cl);
    glPopMatrix();

}

void Bezier::draw_P(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 3, pos.ypos - 1, pos.zpos);
    pos = {0, 0, 0};
    vector<pair<float, float>> tm;
    tm = {{1, 1}, {1, 8}, {4, 6}, {4, 4}, {1, 3} };
    draw(tm, cl);
    glPopMatrix();
}

void Bezier::draw_Q(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 1.6, pos.ypos + 2.4, pos.zpos);

    pos = {0, 0, 0};
    glTranslatef(2.0, -4.0, 0.0);
        glRotatef(45, 0, 0, 1);
        glLineWidth(2.0);
        drawVerLine(2.5, cl);
        glRotatef(-45, 0, 0, 1);
    glTranslatef(-2.0, 4.0, 0.0);

    vector<pair<float, float>> tm;
    tm = { {2,-6}, {-2,-6}, {-4,-4}, {-6,-2}, {-6,2}, {-4,4}, {-2,6} ,{2,6}, {4,4}, {6,2}, {6,-2}, {4,-4}, {2,-6} };
    glScalef(0.5, 0.5, 0.5);
    draw(tm, cl);
    glPopMatrix();

}

void Bezier::draw_R(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 2, pos.ypos, pos.zpos);
    pos = {3, 0.5, 0};
    drawVerLine(cl);
    glTranslatef(0, 2, 0);
    glRotatef(-45, 0, 0, 1);
    drawHorLine(3, cl);
    glRotatef(45, 0, 0, 1);
    glTranslatef(0, -2, 0);

    glTranslatef(1.75, 5, 0);
    glScalef(0.6, 0.6, .6);
    glRotatef(180, 0, 0, 1);
    draw_C(pos, cl);
    glPopMatrix();

}

void Bezier::draw_S(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 3, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    vector<pair<float, float>> tm;
    tm = { {3, 4}, {0, 4}, {0, 2}, {2, 2}, {4, 2}, {4, 0}, {1, 0} };
    draw(tm, cl);
    glPopMatrix();
}

void Bezier::draw_T(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 1, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    drawVerLine(cl);
    glTranslatef(-1.25, 0, 0);
    glTranslatef(0.0, 5.0, 0.0);
    drawHorLine(2.5, cl);
    glPopMatrix();

}

void Bezier::draw_U(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 3, pos.ypos - 1.5, pos.zpos);
    pos = {0, 0, 0};
    vector<pair<float, float>> tm;
    tm = {{1, 5}, {1, 2}, {1, 1}, {3, 1}, {3, 2}, {3, 5} };
    draw(tm, cl);
    glPopMatrix();
}

void Bezier::draw_V(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 1, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    glRotatef(-20, 0, 0, 1);
    drawVerLine(cl);
    glRotatef(20, 0, 0, 1);
    glRotatef(20, 0, 0, 1);
    drawVerLine(cl);
    glRotatef(-20, 0, 0, 1);
    glPopMatrix();

}

void Bezier::draw_W(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 2, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    glRotatef(20, 0, 0, 1);
    drawVerLine(cl);
    glRotatef(-20, 0, 0, 1);

    glRotatef(-20, 0, 0, 1);
    drawVerLine(2.5, cl);
    glRotatef(20, 0, 0, 1);

    glTranslatef(1.7, 0.0, 0.0);
    glRotatef(20, 0, 0, 1);
    drawVerLine(2.5, cl);
    glRotatef(-20, 0, 0, 1);

    glRotatef(-20, 0, 0, 1);
    drawVerLine(cl);
    glRotatef(20, 0, 0, 1);

    glPopMatrix();

}

void Bezier::draw_X(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 3, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    glRotatef(45, 0, 0, 1);
    drawHorLine(5, cl);
    glRotatef(-45, 0, 0, 1);

    glTranslatef(0.0, 3.5, 0.0);
    glRotatef(-45, 0, 0, 1);
    drawHorLine(5, cl);
    glRotatef(45, 0, 0, 1);
    glPopMatrix();

}

void Bezier::draw_Y(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 1.2, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    glTranslatef(0.0, 2.5, 0.0);
    glRotatef(-20, 0, 0, 1);
    drawVerLine(2.5, cl);
    glRotatef(20, 0, 0, 1);
    glRotatef(20, 0, 0, 1);
    drawVerLine(2.5, cl);
    glRotatef(-20, 0, 0, 1);
    glTranslatef(0.0, -2.5, 0.0);

    drawVerLine(2.5, cl);
    glPopMatrix();

}

void Bezier::draw_Z(vec3 pos, color cl){
    glPushMatrix();
    glTranslatef(pos.xpos - 2.5, pos.ypos, pos.zpos);
    pos = {0, 0, 0};
    drawHorLine(4, cl);

    glRotatef(45, 0, 0, 1);
    drawHorLine(5.6, cl);
    glRotatef(-45, 0, 0, 1);

    glTranslatef(0.0, 4.0, 0.0);
    drawHorLine(4, cl);
    glPopMatrix();

}
