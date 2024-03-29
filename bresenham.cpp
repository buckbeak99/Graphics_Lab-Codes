#include <GL/glut.h>
#include <stdio.h>
#define GL_SILENCE_DEPRECATION


int X1, Y1, X2, Y2;

void Init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void raw_line(int X1, int X2, int Y1, int Y2)
{
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x,y;
    
    dx = X2-X1;
    dy = Y2-Y1;
    
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (X2 < X1)
        incx = -1;
    incy = 1;
    if (Y2 < Y1)
        incy = -1;
    x = X1;
    y = Y1;
    if (dx > dy)
    {
        draw_pixel(x, y);
        e = 2 * dy-dx;
        inc1 = 2*(dy-dx);
        inc2 = 2*dy;
        for (i=0; i<dx; i++)
        {
            if (e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            draw_pixel(x, y);
        }
        
    }
    else
    {
        draw_pixel(x, y);
        e = 2*dx-dy;
        inc1 = 2*(dx-dy);
        inc2 = 2*dx;
        for (i=0; i<dy; i++)
        {
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            draw_pixel(x, y);
        }
    }
}

void DisplayMe()
{
    raw_line(X1, X2, Y1, Y2);
    glFlush();
}

int main(int argc, char **argv)
{
    printf( "Enter (X1, Y1, X2, Y2)\n");
    scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    Init();
    glutDisplayFunc(DisplayMe);
    glutMainLoop();
}
