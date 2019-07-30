#include <GL/glut.h>

void displayMe(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
		glVertex2f(-0.25f,0.25f);
		glVertex2f(-0.25f,-0.25f);
		glVertex2f(-0.75f,-0.25f);
		glVertex2f(-0.75f,0.25f);
		glVertex2f(0.25f,0.25f);
		glVertex2f(0.75f,0.25f);
		glVertex2f(0.75f,-0.25f);
		glVertex2f(0.25f,-0.25f);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(400,300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Quads");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}