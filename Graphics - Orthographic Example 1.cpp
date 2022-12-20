#include <GL/glut.h>
#include <iostream>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	/* Dimetric */
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
	
	/* Isometric */
	//gluLookAt(0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0);
	
	/* Terimetric */
	//gluLookAt(0.0, 0.0, 0.0, 0.3, 0.9, 0.7, 0.0, 1.0, 0.0);


	glutWireCube(2.0);
	glFlush();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Orthographic");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}