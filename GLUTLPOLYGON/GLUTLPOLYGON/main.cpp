//
//  main.cpp
//  GLUTLPOLYGON
//
//  Created by 孫辰 on 15/1/26.
//  Copyright (c) 2015年 孫辰. All rights reserved.
//


#include <iostream>
#include <GLUT/GLUT.h>
static GLfloat spin = 0.0;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    //glRectf(-25.0, -25.0, 25.0, 25.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
    
    glCullFace(GL_BACK);  //剔除背面物体
    //glCullFace(GL_FRONT_AND_BACK);  //剔除全部物体
    //glCullFace(GL_FRONT); //剔除正面物体
    
    //形状1
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 3.0);
    glVertex2f(4.0, 3.0);
    glVertex2f(6.0, 1.5);
    glVertex2f(4.0, 0.0);
    glEnd();
    //形状2
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(10.0, 0.0);
    glVertex2f(0.0, 20.0);
    glVertex2f(100.0, 30.0);
    glVertex2f(90.0, 40.5);
    glVertex2f(20.0, 10.0);
    glEnd();
    
    //形状3
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(10.0, 10.0);
    glVertex2f(0.0, 20.0);
    glVertex2f(10.0, 30.0);
    glVertex2f(90.0, 40.5);
    glVertex2f(20.0, 10.0);
    glEnd();
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc,  char * argv[]) {
    // insert code here...
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("POLYGON");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
