-白璧微瑕  8:49:05
#include <GL/glut.h>
#include <Windows.h>

static GLfloat angle = 0.0f;
void myDisplay(void)
{
    glClearColor(0.3, 0.7, 0.5, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //清理颜色和深度缓存     

    // 创建透视效果视图      
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0f, 1.0f, 1.0f, 20.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 12.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // 定义太阳光源，它是一种白色的光源   
    {
        GLfloat sun_light_position[] = { 0.0f, 0.0f, 0.0f, 1.0f }; //光源的位置在世界坐标系圆心，齐次坐标形式
        GLfloat sun_light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; //RGBA模式的环境光，为0
        GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //RGBA模式的漫反射光，全白光
        GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };  //RGBA模式下的镜面光 ，全白光
        glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

        //开启灯光
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);
    }

    // 定义太阳的材质并绘制太阳    
    {
        GLfloat sun_mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };  //定义材质的环境光颜色，为0
        GLfloat sun_mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };  //定义材质的漫反射光颜色，为0
        GLfloat sun_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //定义材质的镜面反射光颜色，为0
        GLfloat sun_mat_emission[] = { 0.8f, 0.0f, 0.0f, 1.0f };   //定义材质的辐射广颜色，为偏红色
        GLfloat sun_mat_shininess = 0.0f;
        glMaterialfv(GL_FRONT, GL_AMBIENT, sun_mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, sun_mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, sun_mat_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
        glMaterialf(GL_FRONT, GL_SHININESS, sun_mat_shininess);
        glutSolidSphere(3.0, 40, 32);
    }

    // 定义地球的材质并绘制地球    
    {
        GLfloat earth_mat_ambient[] = { 0.0f, 0.0f, 1.0f, 1.0f };  //定义材质的环境光颜色，骗蓝色
        GLfloat earth_mat_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };  //定义材质的漫反射光颜色，偏蓝色
        GLfloat earth_mat_specular[] = { 1.0f, 0.0f, 0.0f, 1.0f };   //定义材质的镜面反射光颜色，红色
        GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //定义材质的辐射光颜色，为0
        GLfloat earth_mat_shininess = 30.0f;
        glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
        glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
        glRotatef(angle, 0.0f, -1.0f, 0.0f);
        glTranslatef(7.0f, 0.0f, 0.0f);
        glutSolidSphere(3.0, 40, 32);
    }
    Sleep(10);
    glutSwapBuffers();
}

void myIdle(void)
{
    angle += 1.0f;
    if (angle >= 360.0f)
        angle = 0.0f;
    myDisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL光照演示");
    glutDisplayFunc(&myDisplay);
    glutIdleFunc(&myIdle);
    glutMainLoop();
    return 0;
}

白璧微瑕  9:20:22
#include <GL/glut.h>//引入glut库
#include <Windows.h>//引入windows库

static GLfloat angle = 0.0f;//静态定义一个角度
void myDisplay(void)
{
    glClearColor(0.8, 0.2, 0.4, 0.3);//设置背景色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //清理颜色和深度缓存     

    // 创建透视效果视图      
    glMatrixMode(GL_PROJECTION);//设置投影矩阵
    glLoadIdentity();//重置投影矩阵
    gluPerspective(80.0f, 1.0f, 1.0f, 20.0f);//设置透视视图

    glMatrixMode(GL_MODELVIEW);//设置模型视图
    glLoadIdentity();//重置模型视图
    gluLookAt(0.0, 12.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//设置观察视图

    // 定义太阳光源，它是一种白色的光源   
    {
        GLfloat sun_light_position[] = { 0.0f, 0.0f, 0.0f, 1.0f }; //光源的位置在世界坐标系圆心，齐次坐标形式
        GLfloat sun_light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; //RGBA模式的环境光，为0
        GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //RGBA模式的漫反射光，全白光
        GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };  //RGBA模式下的镜面光 ，全白光
        glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);//设置光源的位置
        glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);//设置环境光
        glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);//设置漫反射光
        glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);//设置镜面光

        //开启灯光
        glEnable(GL_LIGHT0);//开启灯光
        glEnable(GL_LIGHTING);//开启光照
        glEnable(GL_DEPTH_TEST);//开启深度测试
    }

    // 定义太阳的材质并绘制太阳    
    {
        GLfloat sun_mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };  //定义材质的环境光颜色，为0
        GLfloat sun_mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };  //定义材质的漫反射光颜色，为0
        GLfloat sun_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //定义材质的镜面反射光颜色，为0
        GLfloat sun_mat_emission[] = { 0.0f, 0.3f, 0.7f, 1.0f };   //定义材质的辐射广颜色，为偏红色
        GLfloat sun_mat_shininess = 0.0f;
        glMaterialfv(GL_FRONT, GL_AMBIENT, sun_mat_ambient);//设置材质的环境光颜色
        glMaterialfv(GL_FRONT, GL_DIFFUSE, sun_mat_diffuse);//设置材质的漫反射光颜色
        glMaterialfv(GL_FRONT, GL_SPECULAR, sun_mat_specular);//设置材质的镜面反射光颜色
        glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);//设置材质的辐射广颜色
        glMaterialf(GL_FRONT, GL_SHININESS, sun_mat_shininess);//设置材质的高光系数
      // glutSolidSphere(3.0, 50, 42);//绘制一个球体 第一个参数为半径，第二个参数为细分等级，第三个参数为细分等级
        //glutWireTeapot(3.0f);
       // glutSolidTeapot(2.0f);
       // glutSolidTorus(1.0f, 3.0f, 20, 20);//第一次参数是内圆半径，第二个参数是外圆半径，第三个参数是细分等级，第四个参数是细分等级
      // glutSolidCube(3.0f);
        glutSolidCone(1.0f, 3.0f, 20, 20);
    }

    // 定义地球的材质并绘制地球    
    {
        GLfloat earth_mat_ambient[] = { 0.0f, 1.0f, 1.0f, 1.0f };  //定义材质的环境光颜色，偏蓝色
        GLfloat earth_mat_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };  //定义材质的漫反射光颜色，偏蓝色
        GLfloat earth_mat_specular[] = { 1.0f, 0.0f, 0.0f, 1.0f };   //定义材质的镜面反射光颜色，红色
        GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };   //定义材质的辐射光颜色，为0
        GLfloat earth_mat_shininess = 30.0f;//定义材质的高光系数
        glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);//设置材质的环境光颜色
        glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);//设置材质的漫反射光颜色
        glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);//设置材质的镜面反射光颜色
        glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);//设置材质的辐射光颜色
        glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);//设置材质的高光系数
        glRotatef(angle, 0.0f, -1.0f, 0.0f);//旋转地球
        glTranslatef(7.0f, 0.0f, 0.0f);//平移地球
       // glutSolidSphere(3.0, 30, 22);//绘制一个球体 第一个参数为半径，第二个参数为细分等级，第三个参数为细分等级
        glutSolidTeapot(2.0f);//
    }
    Sleep(15);/眠10毫秒
    glutSwapBuffers();//交换缓冲区
}

void myIdle(void)
{
    angle += 1.0f;//角度加1
    if (angle >= 360.0f)//如果角度大于360
        angle = 0.0f;//角度置0
    myDisplay();//调用myDisplay函数
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);//初始化glut
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);//设置显示模式
    glutInitWindowPosition(200, 200);//设置窗口位置
    glutInitWindowSize(400, 400);//设置窗口大小
    glutCreateWindow("杨皓的光照模型的实验");//创建窗口
    glutDisplayFunc(&myDisplay);//设置显示函数
    glutIdleFunc(&myIdle);//设置空闲函数
    glutMainLoop();//进入glut主循环
    return 0;//返回0
}

