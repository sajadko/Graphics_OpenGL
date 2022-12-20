#include <GL/glut.h>
#include <iostream>

int i, n;
float x_1, x_2, x_3, x_4, y_1, y_2, y_3, y_4, ax, ay, bx, by, cx, cy, dx, dy, a, b, m;

void drawsquares(int x, int y) {

	n = 25; // Number of squares
	m = 0.9; // Line Parameter

	a = x;
	b = 500.0 - y;

	ax = a;				ay = b;
	bx = 250.0 + a;		by = b;
	cx = 250.0 + a;		cy = 250.0 + b;
	dx = a;				dy = 250.0 + b;

	glClear(GL_COLOR_BUFFER_BIT);

	for (i = 1; i <= n; i++) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(ax, ay);
		glVertex2f(bx, by);
		glVertex2f(cx, cy);
		glVertex2f(dx, dy);
		glEnd();

		x_1 = ax + m * (bx - ax);
		y_1 = ay + m * (by - ay);
		/*====================*/
		x_2 = bx + m * (cx - bx);
		y_2 = by + m * (cy - by);
		/*====================*/
		x_3 = cx + m * (dx - cx);
		y_3 = cy + m * (dy - cy);
		/*====================*/
		x_4 = dx + m * (ax - dx);
		y_4 = dy + m * (ay - dy);

		ax = x_1;	 ay = y_1;
		bx = x_2;	 by = y_2;
		cx = x_3;	 cy = y_3;
		dx = x_4;	 dy = y_4;
	}

	glFlush();

}

void display() {

}

void myMoveMouse(int x, int y) {
	drawsquares(x, y);
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) drawsquares(x, y);
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) exit(-1);
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.9, 0.9);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Line Parameter Equation Example 2");

	// Monfasel
	//glutMouseFunc(mouse);

	// Peyvaste - bedoone button
	//glutPassiveMotionFunc(myMoveMouse);

	//Peyvaste - ba zadan har button
	glutMotionFunc(myMoveMouse);

	glutDisplayFunc(display);
	init();
	glutMainLoop();
}