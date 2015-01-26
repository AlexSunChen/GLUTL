//
//  main.cpp
//  GLUTXcodeDemo1
//
//  Created by 孫辰 on 1/24/15.
//  Copyright (c) 2015 孫辰. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);    //调用清楚任务
    
    //开始定义要绘制的物体
    glColor3f(1.0, 1.0, 1.0); //设置笔刷颜色
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    
    glFlush(); //保证绘图命令实际执行
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);//设置清楚屏幕所需要的颜色背景相当于填充工具
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 0.0, 0.0, 0.0, -1.0, 1.0);//确定所使用的坐标系
    
}
/*
glutReshapeFunc(void(*func)(int w, int h) ); //窗口改变大小时回调函数
glutKeyboardFunc(void(*func)(unsigned char key, int x,int y));//键盘回调函数
glutkeyMouseFunc(void(*func)(int button, int state, int x, int y));//鼠标回调函数
glutMotionFunc(void(*func)(int x, int y));//注册一个函数，当按下一个鼠标按钮移动鼠标时回调函数
 */
int main(int argc, char * argv[]) {
    // insert code here...
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Xcode Glut Demo");
    init();
    glutDisplayFunc(display);
    //glutPostRedisplay();
    glutMainLoop();
    
    //std::cout << "Hello, World!\n";
    return 0;
}
