#include<stdio.h>
#include<GL/glut.h>

GLfloat vertex[8][3] = { 	{-30.0, 30.0, 30.0},
				{30.0, 30.0, 30.0 },
				{30.0, -30.0, 30.0},
				{-30.0, -30.0, 30.0},
				{-30.0, 30.0, -30.0},
				{30.0, 30.0, -30.0},
				{30.0, -30.0, -30.0},
				{-30.0, -30.0, -30.0}};

GLfloat colors[6][3] = { 
				{0.6, 0.2, 0.2},
				{0.7, 0.4, 0.1},
				{0.5, 0.7, 0.4},
				{0.2, 0.5, 0.7},
				{0.6, 0.4, 0.4},
				{1.0, 0.4, 0.3}
			};

			
GLfloat angle[3] = {45.0, 45.0, 45.0};
GLfloat rX = 0, rY = 0, rZ = 0;
int axis = 0;

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1.3, 0, 90);
	glMatrixMode(GL_MODELVIEW);
	gluPerspective (90, 1, 10, 1000);
	glClearColor(1.0, 1.0, 1.0, 1.0);
		
}

void drawFace(GLfloat* A, GLfloat* B, GLfloat* C, GLfloat* D, GLfloat* color)
{
	glColor3fv(color);	
	glBegin(GL_POLYGON);
		glVertex3fv(A);
		glVertex3fv(B);
		glVertex3fv(C);
		glVertex3fv(D);
	glEnd();	
}

void drawCube()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle[0], 1, 0, 0);
	glRotatef(angle[1], 0, 1, 0);
	glRotatef(angle[2], 0, 0, 1);
	
	//raw all the faces
	drawFace(vertex[0], vertex[1], vertex[2], vertex[3], colors[0]);
	drawFace(vertex[1], vertex[5], vertex[6], vertex[2], colors[1]);
	drawFace(vertex[0], vertex[4], vertex[7], vertex[3], colors[2]);
	drawFace(vertex[3], vertex[7], vertex[6], vertex[2], colors[3]);
	drawFace(vertex[0], vertex[4], vertex[5], vertex[1], colors[4]);
	drawFace(vertex[4], vertex[5], vertex[6], vertex[7], colors[5]);
	glFlush();
	glutSwapBuffers();
}

void spinCube()
{
	angle[axis] += 0.7;
	if ( angle[axis] >= 360.0)
		angle[axis] = 0;
	
	glutPostRedisplay();
}

void mouseControl(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
		switch(button)
		{
			case GLUT_LEFT_BUTTON:
				axis = 0;
				break;
			case GLUT_RIGHT_BUTTON:
				axis = 1;
				break;
			case GLUT_MIDDLE_BUTTON:
				axis = 2;
				break;
				
		}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(20, 30);
	glutCreateWindow("3D CUBE");
	glEnable(GL_DEPTH_TEST);
	//glPolygonStipple(patt);
	
	glutIdleFunc(spinCube);
	glutMouseFunc(mouseControl);
	
	init();
	glutDisplayFunc(drawCube);
	
	glutMainLoop();
	return 0;
}























