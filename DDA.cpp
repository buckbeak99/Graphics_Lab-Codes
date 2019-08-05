#include <GL/glut.h>
#include <stdio.h>
#define GL_SILENCE_DEPRECATION


float X1,X2,Y1,Y2;

void display(void)
{
    float dy,dx,step,x,y,k,Xin,Yin;
    dx=X2-X1;
    dy=Y2-Y1;
    
    if(abs(dx)> abs(dy))
    {
        step = abs(dx);
    }
    else
        step = abs(dy);
    
    Xin = dx/step;
    Yin = dy/step;
    
    x= X1;
    y=Y1;
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    
    for (k=1 ; k<=step; k++)
    {
        x= x + Xin;
        y= y + Yin;
        
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }
    glFlush();
}

void init(void)
{
    //glClearColor(0.7,0.7,0.7,0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv)
{
    printf( "Enter (X1, Y1, X2, Y2)\n");
    scanf("%f %f %f %f", &X1, &Y1, &X2, &Y2);
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1500, 1500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("DDA Line Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
