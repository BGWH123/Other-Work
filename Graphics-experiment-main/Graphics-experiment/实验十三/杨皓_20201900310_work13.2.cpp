#include<GL/glut.h>

GLsizeei winWidth=500, winHeight=500;//设置长宽

void init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);//设置显示窗口颜色为白色
}
void wireQuad(void){
    glclear(GL_COLOR_BUFFER_BIT);//清除颜色缓冲区
    glColor3f(0.0, 0.0, 1.0);//设置颜色为蓝色
    gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);//设置视点
    glPushMatrix();//保存当前矩阵
    glTranslatef(1.0, 1.0, 0.0);//移动视点
    glutWireSphere(0.75, 8, 6);//绘制球体
    glPopMatrix();//恢复矩阵
    glPushMatrix();//保存当前矩阵
    glTranslatef(-1.0, -0.5, 0.5);//移动视点
    glutWireCone(0.7, 2.0, 7, 6);// 绘制圆柱体
    glPopMatrix();//恢复矩阵
    GLUquadricObj *cylinder;//声明一个圆柱体
    glPushMatrix();//保存当前矩阵
    glTranslatef(0.0, -0.0, 0.8);//移动视点
    cylinder=gluNewQuadric();//创建一个圆柱体
    gluQuadricDrawStyle(cylinder, GLU_LINE);//设置绘制方式为线条
    gluCylinder(cylinder, 0.5, 0.5, 1.0, 8, 1);//绘制圆柱体
    glPopMatrix();//恢复矩阵
    glFlush();//刷新显示
}
void winReshapeFunc(GLsizei w, GLsizei h){
  glViewport(0, 0, newWidth, newHeight);//设置视口
  glMatrixMode(GL_PROJECTION);//设置投影矩阵
  glOrtho(-2.0, 2.0, -2.0, 2.0, 0.0, 5.0);//设置投影矩阵
  glMatrixMode(GL_MODELVIEW);//设置模型视图矩阵
  glClear(GL_COLOR_BUFFER_BIT);//清除颜色缓冲区
}
void main(int argc, char** argv){
  glutInit(&argc, argv);//初始化glut
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//设置显示模式
  glutInitWindowSize(winWidth, winHeight);//设置窗口大小
  glutInitWindowPosition(100, 100);//设置窗口位置
  glutCreateWindow("OpenGL");//创建窗口
  init();//初始化
  glutDisplayFunc(wireQuad);//设置显示函数
  glutReshapeFunc(winReshapeFunc);//设置窗口改变函数
  glutMainLoop();//进入glut主循环
}