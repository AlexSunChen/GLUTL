//
//  main.cpp
//  GLUTLSpinSharp
//
//  Created by 孫辰 on 15/1/25.
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
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 3.0);
    glVertex2f(4.0, 3.0);
    glVertex2f(6.0, 1.5);
    glVertex2f(4.0, 0.0);
    glEnd();
    
    glPopMatrix();
    glutSwapBuffers();
}
void spinDisplay(void)
{
    spin = spin + 2.0;
    if(spin >360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void  mouse(int button, int state, int x, int y)
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
                //std::cout << "鼠标左键按下了！！";
                glutIdleFunc(spinDisplay);
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}
int main(int argc,  char * argv[]) {
    // insert code here...
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("spin rect");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    std::cout << "Hello, World!\n";
    
    return 0;
}
