#include<gl\glut.h>
#include<math.h>
#include<iostream>
using namespace std;
float r;
void BresenhamCircle(void)
{
    float d, x, y;

    glClear(GL_COLOR_BUFFER_BIT);
    x = 0;
    y = r;
    d = 1 - r;

    while (x <= y)
    {
        glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);//线的颜色为红色
        glVertex3f(x, y, 0);
        glVertex3f(-x, -y, 0);
        glVertex3f(-x, y, 0);
        glVertex3f(x, -y, 0);
        glVertex3f(y, -x, 0);
        glVertex3f(-y, -x, 0);
        glVertex3f(-y, x, 0);
        glVertex3f(y, x, 0);//八个兑成部分
        glEnd();

        if (d < 0)
        {

            d += 2 * x + 3;

        }
        else
        {

            d += 2 * (x - y) + 5;
            y--;

        }
        x++;
        glFlush();
    }

}

void main(int argc, char** argv) {
    glutInit(&argc, argv); //初始化glut
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    //设置窗口的模式－深度缓存，单缓存，颜色模型
    glutInitWindowPosition(200, 200); //设置窗口的位置
    glutInitWindowSize(500, 500); //设置窗口的大小
    glutCreateWindow("画圆"); //创建窗口并赋予title
    cout << "输入R" << endl;
    cin >> r;



    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(BresenhamCircle);//调用renderScene把绘制传送到窗口
    glutMainLoop(); //进入循环等待
}
