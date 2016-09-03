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
static double angle=0;
void drawTest(){
	/*angle+=(double)1/10;
	if(angle>=360)angle=0;
	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,1,1,500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,1,-100,0,0,0,0,1,0);
	//
	//glEnable(GL_LIGHTING);
	//
	{
		glColor3f(1,0,0);
		glutSolidSphere(20,20,20);
	}
	{
		glColor3f(0,1,0);
		glRotatef(angle,0,0,-1);
		glTranslatef(40,0,0);
		glutSolidSphere(20,20,20);
	}
*/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     // 创建透视效果视图
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(90, 1, 1, 20);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(0, 5, -10, 0, 0.0, 0, 0.0, 1.0, 0.0);
	 glColor3f(1,1,0);
	 glutSolidSphere(2, 40, 32);
	 glColor3f(0,1,0);
		glRotatef(angle,0,0,-1);
		glTranslatef(5,0,0);
		glutSolidSphere(3,20,20);

}
//second entry:
void draw(){
	drawTest();
	return;
}

