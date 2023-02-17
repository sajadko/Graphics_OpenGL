#include <GL/glut.h>
#include <cmath>
void display() {
	int i;
	int c = 1; // 0 = forward | 1 = up | 2 = backward | 3 = bottom
	float tool = 0.0;
	float toolAB;
	float ax = 0, ay = 0; // A init value
	float bx = 1, by = 0; // B init value
	float px, py, px_old, py_old;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	glVertex2f(ax, ay);
	glVertex2f(bx, by);
	toolAB = sqrtf(powf((ax - bx), 2.0) + powf((ay - by), 2.0));
	tool = toolAB;
	px = bx;
	py = by;

	for (i = 0; i < 40; i++) {

		px_old = px;
		py_old = py;

		if (c == 0) {
			// Just add to x
			px = px + (tool + toolAB);
			c = 1;
		}
		else if (c == 1) {
			// just add to y
			py = py + (tool + toolAB);
			c = 2;
		}
		else if (c == 2) {
			// just substract x
			px = px - (tool + toolAB);
			c = 3;
		}
		else if (c == 3) {
			// just subtract y
			py = py - (tool + toolAB);
			c = 0;
		}

		glVertex2f(px, py);
		tool = sqrtf(powf((px - px_old), 2.0) + powf((py - py_old), 2.0));
	}

	glEnd();
	glFlush();
}
void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.5, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-25.0, 25.0, -25.0, 25.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 900);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sajad Kolahchi - Spiral");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}


