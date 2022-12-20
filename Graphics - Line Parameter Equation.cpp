#include <GL/glut.h>
#include <iostream>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	float n = 0.0; // main parameter
	int m = 30; // number of squares
	float a, b, c, d;

	float A[2] = { -0.8,-0.8 };
	float B[2] = { 0.8,-0.8 };
	float C[2] = { 0.8,0.8};
	float D[2] = { -0.8,0.8 };

	float x1, y1, x2, y2, x3, y3, x4, y4;

	for (int i = 1; i <= m; i++) {

		a = b = c = d = (n / 30.0);

		x1 = A[0] + a * (B[0] - A[0]);
		y1 = A[1] + a * (B[1] - A[1]);
		/*==========================*/
		x2 = B[0] + b * (C[0] - B[0]);
		y2 = B[1] + b * (C[1] - B[1]);
		/*==========================*/
		x3 = C[0] + c * (D[0] - C[0]);
		y3 = C[1] + c * (D[1] - C[1]);
		/*==========================*/
		x4 = D[0] + d * (A[0] - D[0]);
		y4 = D[1] + d * (A[1] - D[1]);

		glBegin(GL_LINE_LOOP);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glVertex2f(x4, y4);
		glEnd();
		std::cout << i << " : " << a << std::endl;
		n = n + 1.0;

	}
	glFlush();

}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 800);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Line Parametric Equation Example");
	glutDisplayFunc(display);
	glColor3f(0.0, 0.0, 1.0);
	//init();
	glutMainLoop();
}