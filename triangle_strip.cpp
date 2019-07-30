#include <GL/glut.h>


void displayMe()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f,0.0f,1.0f);//blue color
		glBegin(GL_TRIANGLE_STRIP);
			glVertex2f(0.0f, 0.75f);
			glVertex2f(-0.5f, 0.25f);
			glVertex2f(0.5f, 0.25f);
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
	glutCreateWindow("Triangle Strip");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}
