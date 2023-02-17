#include <GL/glut.h>
#include <cmath>
void display() {
	int i;
	float x, y, z, w;
	float x1 = 0.0, y1 = 0.0;

	glClear(GL_COLOR_BUFFER_BIT);
	z = 60.0; // Angle - Zavie
	w = 0.0; // Radius - Shoa
	for (i = 0; i < 40; i++) {
		x = w * (cos(z * (3.1415 / 180.0)));
		y = w * (sin(z * (3.1415 / 180.0)));

		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();

		z = z + 120.0;
		w = w + (9.0 / 360.0);

		//Connect points - Vasl kardan point ha be yek digar
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(x1, y1);
		glEnd();

		x1 = x;
		y1 = y;

	}
	glFlush();
}
void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.8, 0.2,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sajad Kolahchi - Spiral Triangle");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}


