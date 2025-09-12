#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
inline int round(const float a) { return int(a + 0.5); }
void setPixel(int x, int y) {
  glPointSize(5.0f);
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  glFlush();
}
void lineDDA(int x0, int y0, int xEnd, int yEnd) {
  int dx = xEnd - x0, dy = yEnd - y0, steps, k;
  float xIncrement, yIncrement, x = x0, y = y0;
  if (fabs(dx) > fabs(dy))
    steps = fabs(dx);
  else
    steps = fabs(dy);
  xIncrement = float(dx) / float(steps);
  yIncrement = float(dy) / float(steps);
  setPixel(round(x), round(y)); //由于每次都加了小于1的增量，所以需要取整
  for (k = 0; k < steps; k++) {
    
    glBegin(GL_POINTS);
    glVertex2i((int)x,(int)y);
    glEnd();
    glFlush();
    x += xIncrement;
    y += yIncrement;
    setPixel(round(x), round(y));
  }
  return;
}

void init(void) {
  glClearColor(0.5, 0.3, 0.5, 0.3); //设置显示窗口颜色
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0f, 200.0f, 0.0f, 150.0f); //设置规划参数
}

void myDisplay() {
  int x0, y0, xEnd, yEnd;

    printf_s("请输入起点坐标（用空格作为分隔符）：");
    scanf_s("%d %d %d %d", &x0, &y0, &xEnd, &yEnd);
  

  lineDDA(x0, y0, xEnd, yEnd);
}

void main(int argc, char **argv) {
  glutInit(&argc, argv);                       //初始化
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //设置显示模式
  glutInitWindowPosition(50, 100);
  glutInitWindowSize(400, 300);                  //设置窗口长宽
  glutCreateWindow("DDA 生成直线 "); //设置标题
  init();
  do {
    glutDisplayFunc(&myDisplay);
    
  } while (0);
  glutMainLoop();
 
}