﻿#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>


#define PI 3.1459

GLfloat R = 640.0 / 480; //Форматное соотношение
GLfloat w = 40;  //Ширина мирового окна
GLfloat h; //Высота мирового окна
GLfloat l, r, b, t; //Параметры мирового окна
GLfloat f = 45.0;
GLfloat tr_x = 2.5;
GLfloat sc_x = -1.0;
GLfloat rt_a = -45;

void init(void)
{
	h = w / R; l = -w / 2; r = w / 2; b = -h / 2; t = h / 2; //Расчет параметров мирового окна
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(l, r, b, t);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void reshape(GLsizei W, GLsizei H)
{
	if (R > W / H) glViewport(0, 0, W, W / R);
	else glViewport(0, 0, H * R, H);
}

void showAxis(void)
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, t);
	glVertex2f(0, 0);
	glVertex2f(r, 0);
	glEnd();
}


void fig0(void)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2d(5.0, -5.0);
	glVertex2d(5.0, 5.0);
	glVertex2d(0.0, 10.0);
	glVertex2d(-5.0, 5.0);
	glVertex2d(-5.0, -5.0);
	glEnd();
}

void fig1(void)
{
	glColor3f(1.0, 0.0, 1.0);
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glVertex2d(-1.0, 0.0);
	glVertex2d(1.0, 0.0);
	glVertex2d(1.0, 3.0);
	glVertex2d(-1.0, 3.0);
	glEnd();
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, t);
	glVertex2f(0, 0);
	glVertex2f(r, 0);
	glEnd();
}



void scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	showAxis();
	fig0();
	glPushMatrix();
	glTranslatef(tr_x, 7.5, 0.0);
	glRotatef(rt_a, 0.0, 0.0, 1.0);
	glScalef(sc_x, 3.0, 1.0);
	fig1();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	tr_x = -tr_x;
	sc_x = -sc_x;
	rt_a = -rt_a;
	Sleep(500);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Lab 2 task 2 Gawish");
	glutReshapeFunc(reshape);
	glutDisplayFunc(scene);
	glutIdleFunc(scene);
	init();
	glutMainLoop();
}
