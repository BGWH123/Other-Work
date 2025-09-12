#include <GL/glut.h> //其中包含了gl.h和glu.h头文件

void init(void) {
  glClearColor(0.5, 1.0, 1.0, 0.0); //建立一个背景色为白色
  glMatrixMode(GL_PROJECTION);      //设置项目参数
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}
void linesegment(void) {
  glClear(GL_COLOR_BUFFER_BIT); //清除显示窗口
  glColor3f(1.0, 0.0, 0.5);     //颜色设定
                                /*glColor3f(0.0, 0.0, 0.0);  --> 黑色
                                                      glColor3f(1.0, 0.0, 0.0);  --> 红色
                                                  glColor3f(0.0, 1.0, 0.0);  --> 绿色
                                                                  glColor3f(0.0, 0.0, 1.0);  --> 蓝色
                          glColor3f(1.0, 1.0, 0.0);  --> 黄色
                          glColor3f(1.0, 0.0, 1.0);  --> 品红色
                          glColor3f(0.0, 1.0, 1.0);  --> 青色
                          glColor3f(1.0, 1.0, 1.0);  --> 白色*/
  glBegin(GL_LINES);            //画线 指定线序列几何图形
  glVertex2i(150, 150);         //指定 x y坐标
  glVertex2i(10, 10);
  glEnd();
  glFlush(); //用于强制刷新缓冲，保证绘图命令将被执行
}
void main(int argc, char **argv) {
  glutInit(&argc, argv);                       //初始化
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //函数功能为设置初始显示模式
  glutInitWindowPosition(500, 100);            //设置初始窗口的位置
  glutInitWindowSize(800, 800);                //设置初始窗口的大小
  glutCreateWindow("这是一个opengl 的例子");
  init();
  glutDisplayFunc(linesegment); //画线
  glutMainLoop(); // glutMainLoop进入GLUT事件处理循环，让所有的与“事件”有关的函数调用无限循环
                  // 无线刷新
}