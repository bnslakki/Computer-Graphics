#include "orbit.h"

using namespace std;

COrbitLine::COrbitLine(float _MajorAxis,float _MinorAxis){

	int noOfElements = 100;
	float angle = 360.0 / noOfElements;
	float increaseAngle = 0;
	float X, Y, Z;
	for (int i = 0; i < noOfElements; i++){
		X = _MajorAxis * cosf(increaseAngle * (PI / 180));;
		Y = 0.0;
		Z = _MinorAxis * sinf(increaseAngle * (PI / 180));
		_OrbitPoints.push_back(Vector3(X , Y , Z ));
		increaseAngle += angle;

		_Index.push_back(i);
		if (i==noOfElements - 1)_Index.push_back(0);
		else _Index.push_back(i+1);
	}

	//Vertex array Creation
	glGenVertexArrays(1, &_OrbitVAO);
	glBindVertexArray(_OrbitVAO);

	glGenBuffers(1, &_OrbitVBO);
	glBindBuffer(GL_ARRAY_BUFFER, _OrbitVBO);
	glBufferData(GL_ARRAY_BUFFER, _OrbitPoints.size() * sizeof(Vector3), _OrbitPoints.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	//Creating the Elementary Buffer Object
	glGenBuffers(1, &_OrbitEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _OrbitEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _Index.size() * sizeof(GLuint), _Index.data(), GL_STATIC_DRAW);

	IndexCount = _Index.size();
	_OrbitPoints.clear();
}


COrbitLine::~COrbitLine(){
	glDisableVertexAttribArray(0);
	glDeleteVertexArrays(1, &_OrbitVAO);
	glDeleteBuffers(1, &_OrbitVBO);
	glDeleteBuffers(1, &_OrbitEBO);
}


void COrbitLine::DrawOrbitLine(){
	glLineWidth(3.0);
	glBindVertexArray(_OrbitVAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _OrbitEBO);
	glDrawElements(GL_LINES, IndexCount, GL_UNSIGNED_INT, NULL);
	glBindVertexArray(0);
}



