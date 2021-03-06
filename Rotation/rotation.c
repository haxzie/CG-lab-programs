#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float angle = 0.0;
int repeat = 0;

GLubyte patt[] = {
			0x01, 0x80, 0x01, 0x80,
			0x02, 0x40, 0x02, 0x40,
			0x8c, 0x61, 0x8c, 0x61,
			0x98, 0x31, 0x98, 0x31,
			0x31, 0x98, 0x31, 0x98,
			0x21, 0x8c, 0x21, 0x8c,
			0x60, 0x06, 0x60, 0x06,
			0x80, 0x81, 0x80, 0x81,
			0x01, 0x80, 0x01, 0x80,
			0x02, 0x40, 0x02, 0x40,
			0x8c, 0x61, 0x8c, 0x61,
			0x98, 0x31, 0x98, 0x31,
			0x31, 0x98, 0x31, 0x98,
			0x21, 0x8c, 0x21, 0x8c,
			0x60, 0x06, 0x60, 0x06,
			0x80, 0x81, 0x80, 0x81,
			0x01, 0x80, 0x01, 0x80,
			0x02, 0x40, 0x02, 0x40,
			0x8c, 0x61, 0x8c, 0x61,
			0x98, 0x31, 0x98, 0x31,
			0x31, 0x98, 0x31, 0x98,
			0x21, 0x8c, 0x21, 0x8c,
			0x60, 0x06, 0x60, 0x06,
			0x80, 0x81, 0x80, 0x81,
			0x01, 0x80, 0x01, 0x80,
			0x02, 0x40, 0x02, 0x40,
			0x8c, 0x61, 0x8c, 0x61,
			0x98, 0x31, 0x98, 0x31,
			0x31, 0x98, 0x31, 0x98,
			0x21, 0x8c, 0x21, 0x8c,
			0x60, 0x06, 0x60, 0x06,
			0x80, 0x81, 0x80, 0x81
			
		};


float v[3][2] = { {300, 100}, {450, 100}, {375, 200} };

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void triangle()
{
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.5, 0.0);
		glVertex2fv(v[0]);
		glColor3f(0.2, 0.7, 0.4);
		glVertex2fv(v[1]);
		glColor3f(0.0, 0.2, 0.4);
		glVertex2fv(v[2]);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(3);
		glVertex2fv(v[0]);
		glVertex2fv(v[1]);
		glVertex2fv(v[2]);
		glColor3f(0.0, 0.0, 0.0);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	triangle();
	
	glPushMatrix();
	glTranslatef(v[0][0],v[0][1],0.0);
	glRotatef(angle,0.0,0.0,1.0);
	glTranslatef(-v[0][0],-v[0][1],0.0);
	triangle();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0.0);
	glRotatef(angle,0.0,0.0,1.0);
	glTranslatef(0,0,0.0);
	triangle();
	glPopMatrix();


	glFlush();
}

int main(int argc, char **argv)
{

	printf("\nEnter the degree to rotate and repeat count\n");
	scanf("%f%d", &angle, &repeat);

	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Rotation");
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(patt);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
}
