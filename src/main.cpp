#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

using namespace std;

void initialize(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
}
void drawWindow(int w, int h) {

    // Set up inside Window
    glutInitWindowSize(w,h);
    glutInitWindowPosition(100,100);

    // Create Window
    glutCreateWindow("Tugas 1");

    // Set up outside Window
	glViewport(0, 0, 100, 100);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
				   (double)w / (double)h, //The width-to-height ratio
				   1.0,                   //The near z clipping coordinate
				   200.0);                //The far z clipping coordinate
}

float _angle = 0.0f;
float _x = 0.0f;
float _y = 0.0f;
float _z = 0.0f;
void drawScene1() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	glTranslatef(0.0f, 0.0f, -5.0f);

	// Transformasi setelah keypress
	glTranslatef(_x,_y,_z);
	glRotatef(_angle, 0.0f, 0.0f, 2.0f);

    // Segitiga 1
    glBegin(GL_TRIANGLES); //Begin triangle coordinates
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(1.0f,0.0f,0.0f);
        glVertex3f(0.0f,1.0f,0.0f);
        glVertex3f(-1.0f,0.0f,0.0f);
	glEnd(); //End triangle coordinates

    // Segitiga 2
    glPushMatrix();
    glTranslatef(0.0f,-1.0f,0.0f);
    glBegin(GL_TRIANGLES); //Begin triangle coordinates
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(1.0f,0.0f,0.0f);
        glVertex3f(0.0f,1.0f,0.0f);
        glVertex3f(-1.0f,0.0f,0.0f);
	glEnd(); //End triangle coordinates
    glPopMatrix();

    // Segitiga 3
    glPushMatrix();
    glTranslatef(0.0f,1.0f,0.0f);
    glBegin(GL_TRIANGLES); //Begin triangle coordinates
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(1.0f,0.0f,0.0f);
        glVertex3f(0.0f,1.0f,0.0f);
        glVertex3f(-1.0f,0.0f,0.0f);
	glEnd(); //End triangle coordinates
	glPopMatrix();
	glutSwapBuffers();
}
void drawScene2() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	glTranslatef(0.0f, 0.0f, -5.0f);

	// Transformasi setelah keypress
	glTranslatef(_x,_y,_z);
	glRotatef(_angle, 0.0f, 0.0f, 2.0f);

    // Segitiga 1
    glBegin(GL_TRIANGLES); //Begin triangle coordinates
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(1.0f,0.0f,0.0f);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(0.0f,1.0f,0.0f);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(-1.0f,0.0f,0.0f);
	glEnd(); //End triangle coordinates

	glutSwapBuffers();
}
void handleKeypress (unsigned char key, int x, int y) {
    switch (key) {
        case 'a': _x -= 1.0f; glutPostRedisplay(); break;
        case 'd': _x += 1.0f; glutPostRedisplay(); break;
        case 'w': _y += 1.0f; glutPostRedisplay(); break;
        case 's': _y -= 1.0f; glutPostRedisplay(); break;
        case 'q': _angle += 10.0f; glutPostRedisplay(); break;
        case 'e': _angle -= 10.0f; glutPostRedisplay(); break;
        case 'z': drawScene1(); break;
        case 'x': drawScene2(); break;
        case 27: exit(0);
    }
}

int main(int argc, char** argv) {
    // Initialize
    initialize(argc,argv);

    // Create window
    drawWindow(500,500);

    // Enables
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR);

    // Function handlers
    glutDisplayFunc(drawScene1);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();

    return 0;
}
