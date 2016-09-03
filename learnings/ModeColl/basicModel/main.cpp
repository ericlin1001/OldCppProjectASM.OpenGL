// hellowold.cpp : Defines the entry point for the console application.
//
#include<math.h>
//
#include "DrawModule.h"
#include<GL/glut.h>
//


//
void init(){
	//glEnable(GL_DEPTH_TEST);
	glClearColor(0.1,0.1,0.1,1);
	drawInit();
	
}
void display(){
	draw();
	glutSwapBuffers();
}
void reshape(int w,int h){
	
}
void idle(){
}
int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	//glutInitDisplayMode
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutCreateWindow("This a opengl's Model");
	init();
	glutDisplayFunc(display);
	//glutReshapeFunc(reshape);
	//glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}

