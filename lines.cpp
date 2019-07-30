#include <GL/glut.h>

void displayMe()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_LINES);
			glVertex2f(0.5f, 0.5f);
			glVertex2f(-0.5f, 0.5f);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.5f, -0.5f);
		glEnd();
	glutSwapBuffers();

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(400,300);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Hello World");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}