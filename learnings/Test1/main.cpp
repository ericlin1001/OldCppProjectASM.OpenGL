// hellowold.cpp : Defines the entry point for the console application.
//
#include<math.h>
#include <time.h>
#include<stdio.h>
//
#include "DrawModule.h"
#include<GL/glut.h>
//


//
void init(){
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1,0.1,0.1,1);
	drawInit();
	
}
	static double day = 200; // day的变化：从0到359
void display(){
	/*glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightf(GL_POSITION);
	glMaterialf();
	glLightModelf(*/
	draw();
/*
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(75, 1, 1, 400000000);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

     // 绘制红色的“太阳”
     glColor3f(1.0f, 0.0f, 0.0f);
     glutSolidSphere(69600000, 20, 20);
     // 绘制蓝色的“地球”
     glColor3f(0.0f, 0.0f, 1.0f);
     glRotatef(day/360.0*360.0, 0.0f, 0.0f, 1.0f);
     glTranslatef(150000000, 0.0f, 0.0f);
     glutSolidSphere(15945000, 20, 20);
     // 绘制黄色的“月亮”
     glColor3f(1.0f, 1.0f, 0.0f);
     glRotatef(day/30.0*360.0 - day/360.0*360.0, 0.0f, 0.0f, -1.0f);
     glTranslatef(38000000, 0.0f, 0.0f);
     glutSolidSphere(4345000, 20, 20);
*/
     glFlush();
	glutSwapBuffers();
}
void reshape(int w,int h){
	
}
void idle(){
	 
	display();
}
int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	//glutInitDisplayMode
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutCreateWindow("This a opengl's Model");
	init();
	glutDisplayFunc(display);
	//glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}

