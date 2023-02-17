#include <gl/glut.h>
#include <cmath>

void arc(float x, float y, int s_angle, int e_angle, float r) {
	int i, z;
	float x1, y1;
	z = s_angle;
	for (i = s_angle; i <= e_angle; i++) {
		x1 = x + (r * cos((z * 3.1415) / 180.0));
		y1 = y + (r * sin((z * 3.1415) / 180.0));
		glBegin(GL_POINTS);
		glVertex2f(x1, y1);
		glEnd();
		z = z + 1;
	}
}

void display() {
	int z;					// angle
	int b;					// Parameter
	int s_angle, e_angle;	// Start angle and End angle
	int i;
	float r = 1.0;			// radius
	float x, y;

	glClear(GL_COLOR_BUFFER_BIT);

	z = 0;
	b = 60;					// 360 / 6 = 60 ==> angle between two section
	s_angle = 120;
	e_angle = 240;

	for (i = 1; i <= 6; i++) {

		x = r * cos((z * 3.1415) / 180.0);
		y = r * sin((z * 3.1415) / 180.0);

		arc(x, y, s_angle, e_angle, r);

		s_angle = s_angle + b;
		e_angle = e_angle + b;

		z = z + b;
	}

	glFlush();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.5, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Graphics - 8 Par");
	glPointSize(3.0);
	glutDisplayFunc(display);
	init();
	glutMainLoop();

}




