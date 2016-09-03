//whether this is a test.
#define __test__
//
//include file:
#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>
//
#include "DrawModule.h"
#include<GL/glut.h>
//

//macro
#ifdef __test__
#define Trace(m) cout<<#m<<"="<<m<<endl;
#else
#define Trace(m) 
#endif
#ifndef PI 
#define PI 3.14159
#endif
#ifndef pi 
#define pi 3.14159
#endif

//function:
struct Point{
	GLfloat x,y,z;
	void set(GLfloat tx,GLfloat ty,GLfloat tz=0){
		x=tx;y=ty;z=tz;
	}
	void print(){
		printf("(%f,%f,%f)",&x,&y,&z);
	}
	Point(){
		x=0;y=0;z=0;
	}
} ;
//
//global varibles:
Point myPoints[100];
#define point2s(p) ((const GLfloat *)&myPoints[p])
#define point3s(p) ((const GLfloat *)&myPoints[p])
#define v2(index) glVertex2fv(point2s(index));
#define v3(index) glVertex3fv(point3s(index));
int pointsLen=1;
//
void generatePoints(){
	const GLfloat loop=2;
	 GLfloat step=(GLfloat)1.0/loop;
	int i;
	for( i=1;i<=loop;i++){
		GLfloat l=(GLfloat)i*step;
		Trace(l);
		Trace(pointsLen);
		myPoints[pointsLen++].set(-l,l);
		myPoints[pointsLen++].set(0,l);
		myPoints[pointsLen++].set(l,l);
		myPoints[pointsLen++].set(l,0);
		myPoints[pointsLen++].set(l,-l);
		myPoints[pointsLen++].set(0,-l);
		myPoints[pointsLen++].set(-l,-l);
		myPoints[pointsLen++].set(-l,0);
		Trace(i);
	}
}
//
//first entry:
void drawInit(){
	generatePoints();
}
//
/**/
void drawTest(){
	glColor3f(0,1,0);
	glRectf(-0.5,-0.5,0,0);
}
//second entry:
void draw(){
	drawTest();
	return;
}

