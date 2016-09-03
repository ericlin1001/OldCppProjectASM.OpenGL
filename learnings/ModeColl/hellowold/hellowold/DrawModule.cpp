//whether this is a test.
#define __test__
#define _CRT_SECURE_NO_WARNINGS
//
//include file.
#include<iostream>
using namespace std;
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include "DrawModule.h"

//macro
#ifdef __test__
#define Trace(m) cout<<#m<<"="<<m<<endl;
#else
#define Trace(m) 
#endif
//function:
struct Point{
	GLfloat x,y;
	void set(GLfloat tx,GLfloat ty){
		x=tx;y=ty;
	}
	void print(){
		printf("(%f,%f)",&x,&y);
	}
	Point(){
		x=0;y=0;
	}
} ;
//
//global varibles:
Point myPoints[100];
#define points(p) ((const GLfloat *)&myPoints[p])
int pointsLen=1;
static GLubyte Mask[128];
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
bool getBit(GLubyte *mask,int p){
	return (mask[p/8] & (1<<(7-(p%8))))==1;
}
void test(){
	for(int i=0;i<32;i++){
		for(int j=0;j<32;j++){
			int row=i;
			int col=j;
			//change;
			//col+=7;col%=32;
			row=31-row;
			//end change
			int index=row*32+col;
			if(getBit(Mask,index)){
				cout<<'*';
			}else{
				cout<<' ';
			}
		}
		cout<<endl;
	}
}
void drawInit(){
	FILE *fp;
	fp = fopen("maskTest.bmp", "rb");
	if( !fp )exit(0);
	if(fseek(fp, -(int)sizeof(Mask), SEEK_END))exit(0);
	// 读取sizeof(Mask)个字节到Mask
	if( !fread(Mask, sizeof(Mask), 1, fp))exit(0);
	fclose(fp);
	test();
	generatePoints();
}
//
/**/
GLushort binaryToNum(char *str){
	GLushort n=0;
	while(*str){
		n*=2;
		n+=*str-'0';
		str++;
	}
	return n;
}
#define B(binaryNum) binaryToNum(#binaryNum)
void drawsin(){
	const GLfloat factor = 0.1f;
	GLfloat x;
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_LINES);
         glVertex2f(-1.0f, 0.0f);
         glVertex2f(1.0f, 0.0f);         // 以上两个点可以画x轴
         glVertex2f(0.0f, -1.0f);
         glVertex2f(0.0f, 1.0f);         // 以上两个点可以画y轴
     glEnd();
     glBegin(GL_LINE_STRIP);
     for(x=-1.0f/factor; x<1.0f/factor; x+=0.01f)
     {
         glVertex2f(x*factor, sin(x)*factor);
     }
     glEnd();

}
void drawPonits(){
	//glPointSize(100);
	glBegin(GL_POINTS);
	//glVertex2f(0,0);
	glVertex2fv(points(1));
	glEnd();
	
}
void drawLineStrip(){
	glPointSize(3);
	glLineWidth(8);
glEnable(GL_LINE_STIPPLE);
glLineStipple(1,B(1100001000100101));
glBegin(GL_LINES);
glVertex2fv(points(0));
glVertex2f(1-0.001,1);

glEnd();
}


void drawPolygon(){
	glLineWidth(1);
glEnable(GL_LINE_STIPPLE);
glLineStipple(1,B(1100001000100101));
//
glPolygonMode(GL_FRONT,GL_LINE);
glPolygonMode(GL_BACK,GL_POINT);
glFrontFace(GL_CCW);
//
glBegin(GL_POLYGON);
glVertex2fv(points(1));
glVertex2fv(points(7));
glVertex2fv(points(4));
glVertex2fv(points(2));

glEnd();
}
void drawPolygonTest(){
	glLineWidth(7);
glEnable(GL_LINE_STIPPLE);
glLineStipple(1,B(1100001000100101));
	//
glPolygonMode(GL_FRONT,GL_FILL|GL_LINE);
glPolygonMode(GL_BACK,GL_POINT);
glFrontFace(GL_CCW);
//
glBegin(GL_POLYGON);
glVertex2fv(points(1));
glVertex2fv(points(7));
glVertex2fv(points(4));
glVertex2fv(points(2));
glEnd();
}
void drawPolygon2(){

glEnable(GL_POLYGON_STIPPLE);
glPolygonStipple(Mask);
//
glBegin(GL_POLYGON);
glVertex2fv(points(1));
glVertex2fv(points(7));
glVertex2fv(points(4));
glVertex2fv(points(2));
glEnd();
}
void draw(){
	drawsin();
	return ;
	
	drawPolygon();
	drawPolygon2();
	//
	return;
	
	
	drawPonits();
	drawLineStrip();

}

