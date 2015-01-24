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
    //glClearColor(0.0, 0.0, 0.0, 0.0); //设置清楚屏幕所需要的颜色背景相当于填充工具
    glClear(GL_COLOR_BUFFER_BIT);    //调用清楚任务
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); //确定所使用的坐标系
    //开始定义要绘制的物体
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0); //设置笔刷颜色
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    
    glFlush();
}

int main(int argc, char * argv[]) {
    // insert code here...
    
    glutInit(&argc, argv);
    glutCreateWindow("Xcode Glut Demo");
    glutDisplayFunc(display);
    glutMainLoop();
    
    //std::cout << "Hello, World!\n";
    return 0;
}
