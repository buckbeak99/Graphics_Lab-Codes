#include <GL/glut.h>


void displayMe()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_LINE_STRIP);
			glVertex2f(-0.75f, 0.75f);
			glVertex2f(-0.25f, 0.25f);
			glVertex2f(0.25f, 0.25f);
			glVertex2f(0.75f, 0.75f);
		glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(400,300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Line Strip");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}
