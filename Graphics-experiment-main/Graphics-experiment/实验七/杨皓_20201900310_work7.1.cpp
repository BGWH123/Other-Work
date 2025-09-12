#include<GL/glut.h>
GLsizei winWidth = 500, winHeight = 500;
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200, 0.0, 150);
}
void displayFcn(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);
}
void winReshapeFcn(GLsizei newWidth, GLsizei newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, GLdouble (newWidth), 0.0, GLdouble (newHeight));
    winWidth = newWidth;
    winHeight = newHeight;
}
void plotPoint(GLdouble x, GLdouble y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void mouseptplot(GLint button,GLint action, GLint xMouse, GLint yMouse)
{
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
    {
        plotPoint(xMouse, winHeight - yMouse);
    }
    glFlush();
}
void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Mouse Point Plot");
    init();
    glutDisplayFunc(displayFcn);
    glutReshapeFunc(winReshapeFcn);
    glutMouseFunc(mouseptplot);
    glutMainLoop();
}