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


	glutWireTeapot(4.2);
	glFlush();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-8.0, 8.0, -8.0, 8.0, -8.0, 8.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Orthographic");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}