#include <GL/glut.h>
#include <cmath>
#include<stdio.h>
#include<stdlib.h>
#include "Bresenham.h"
using namespace std;

void init() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display() {
  int x1 = 10, y1 = 10, x2 = 150, y2 = 100;
    printf_s("请输入起点坐标（用空格作为分隔符）：");
  scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
  int dx = abs(x2 - x1);//取整
  int dy = abs(y2 - y1);//取整
  int x, y;
  int temp1 = 2 * dy;
  int temp2 = 2 * (dy - dx);
  int p = temp1 - dx;
  if (x1 > x2) {
    x = x2;
    y = y2;
    x2 = x1;
  } else {
    x = x1;
    y = y1;
  }

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.5, 0.5);
  glBegin(GL_LINES);
  glVertex2i(x, y);
  while (x < x2) {
    x++;
    if (p < 0)
      p += temp1;
    else {
      y++;
      p += temp2;
    }
    glVertex2i(x, y);
  }
  glEnd();
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(500, 500);
  glutInitWindowSize(400, 300);
  glutCreateWindow("Bresenham 画直线！");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;


改进版本
GLfloat pointsize = 1.0f;
void drawOneLine(GLint x, GLint y, GLint x1, GLint y1) {
  GLint a = x;
  GLfloat m = (y1 - y) * 1.0 / (x1 - x); //斜率
  GLfloat b = y - m * x;
  GLfloat thethay = m * a + b - y; // thetha y
  GLfloat d0 = 2 * thethay - 1;    //初始化d0
  glPointSize(pointsize);
  GLint  cy = y;
  glVertex2i(x, y);            //画第一个点
  while (a <= x1) {
    a++;
    thethay = m * a + b - cy; //更新thetha y
    if (d0 <= 0) {           
      d0 += 2 * thethay;       //更新d0
      cy = cy;
    } else {
      d0 += 2 * thethay - 2;
      cy = cy + 1;
    }
    glVertex2i(a, cy);
  }
}

void display(void) { 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0f, 0.0f);
  glBegin(GL_POINTS);
  int x1 = 10, y1 = 10, x2 = 150, y2 = 100;
  printf_s("请输入起点坐标（用空格作为分隔符）：");
    scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);

  drawOneLine(x1, y1, x2, y2);

  glEnd();
  glFlush();
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Bresenhamplus++");
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-500.0, 800.0, -500.0, 800.0);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
