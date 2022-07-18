#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include<cmath>
using namespace std;


float base_x = 0.0,base_y = 0.0;

void initRendering() {

	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluPerspective(45.0,
				   (double)w / (double)h,
				   1.0,
				   200.0);
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex3f(x + cx, y + cy,-5.0f);

    }
    glEnd();
}


void drawScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_QUADS);
	glVertex3f(-0.5f + base_x, 0.0f + base_y, -5.0f);
	glVertex3f(0.5f + base_x, 0.0f + base_y, -5.0f);
	glVertex3f(0.5f + base_x, 1.0f + base_y, -5.0f);
	glVertex3f(-0.5f + base_x, 1.0f + base_y, -5.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.5f + base_x, 0.0f + base_y, -5.0f);
	glVertex3f(0.5f + base_x, 0.0f + base_y, -5.0f);
	glVertex3f(0.8f + base_x, -0.6f + base_y, -5.0f);
	glVertex3f(-0.2f + base_x, -0.6f + base_y, -5.0f);
	glEnd();

	///1st leg
	glBegin(GL_QUADS);
	glVertex3f(-0.5f + base_x, 0.0f + base_y, -5.0f);
	glVertex3f(-0.4f + base_x, 0.0f + base_y, -5.0f);
	glVertex3f(-0.4f + base_x, -1.0f + base_y, -5.0f);
	glVertex3f(-0.5f + base_x, -1.0f + base_y, -5.0f);
	glEnd();

    ///2nd leg
	glBegin(GL_QUADS);
	glVertex3f(-0.2f + base_x, -0.6f + base_y, -5.0f);
	glVertex3f(-0.1f + base_x, -0.6f + base_y, -5.0f);
	glVertex3f(-0.1f + base_x, -1.5f + base_y, -5.0f);
	glVertex3f(-0.2f + base_x, -1.5f + base_y, -5.0f);
	glEnd();

	///3rd leg
	glBegin(GL_QUADS);
	glVertex3f(0.4f + base_x, -0.6f + base_y, -5.0f);
	glVertex3f(0.5f + base_x, -0.6f + base_y, -5.0f);
	glVertex3f(0.5f + base_x, -1.0f + base_y, -5.0f);
	glVertex3f(0.4f + base_x, -1.0f + base_y, -5.0f);
	glEnd();

    ///4th leg
	glBegin(GL_QUADS);
	glVertex3f(0.7f + base_x, -0.6f + base_y, -5.0f);
	glVertex3f(0.8f + base_x, -0.6f + base_y, -5.0f);
	glVertex3f(0.8f + base_x, -1.5f + base_y, -5.0f);
	glVertex3f(0.7f + base_x, -1.5f + base_y, -5.0f);
	glEnd();


	glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case 'w':
            base_y += 0.1f;
            break;

        case 's':
            base_y -= 0.1f;
            break;
        case 'a':
            base_x -= 0.1f;
            break;
        case 'd':
            base_x += 0.1f;
            break;
    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

void init(void)
{
        glClearColor(0,0,0,0);
        glColor3f(0.0,1.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 400);

	glutCreateWindow("Rectangle,triangle and circle");
	initRendering();

	init();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(key);
	glutReshapeFunc(handleResize);
	glutMainLoop();
	return 0;
}
