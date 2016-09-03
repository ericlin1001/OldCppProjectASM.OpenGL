// hellowold.cpp : Defines the entry point for the console application.
//
#include<math.h>
#include<GL/glut.h>
#include "DrawModule.h"
//


//
void init(){
	drawInit();
	//glClearColor(1,0,0,1);
}
void display(){
	draw();
	glutSwapBuffers();
}
void reshape(int w,int h){
	
}
int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	//glutInitDisplayMode
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutCreateWindow("my test");
	init();
	glutDisplayFunc(display);
	//glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

