#include <GL/glut.h>
#include <iostream>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, -3.0);
	glutWireCube(1.0);
	glFlush();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, 1.0, 1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Graphics - Perspective");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}