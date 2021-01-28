#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define PI 3.14159265
int RenderMode = 2;
int win_width = 640;
int win_height = 480;

float _angle = 60.0f;
float _cameraAngle = 30.0f;

using namespace std;


void print_text(int x, int y, const char *str)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0f, win_width, win_height, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRasterPos2f(x, y);

    while(*str) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *str++);
    }

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

//Draws the 3D scene
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    print_text(50, 30, "Spacebar to cycle render mode.");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(RenderMode == 0)
        glPolygonMode( GL_FRONT_AND_BACK, GL_POINT );
    if(RenderMode == 1)
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    if(RenderMode == 2)
        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL);
    glTranslatef(0.0f, 0.0f, -8.0f);
    glScalef(2.0, 2.0, 0.0);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
        // float a1 = sqrt(1 - 0.25);
        float a2 = sin(60*(PI/180.0));

        // // glColor3f(0.0f, 0.0f, 1.0f); //blue
        // glVertex3f(-1.25f, 0.0f, 0.0f); //bottom left
        // // glColor3f(0.0f, 1.0f, 0.0f); //green
        // glVertex3f(-0.25f, 0.0f, 0.0f); //bottom right
        // // glColor3f(1.0f, 0.0f, 0.0f); //red
        // glVertex3f(-0.75f, a1, 0.0f); //top

        // glColor3f(0.0f, 0.0f, 1.0f); //blue
        glVertex3f(0.25f, 0.0f, 0.0f); //bottom left
        // glColor3f(0.0f, 1.0f, 0.0f); //green
        glVertex3f(1.25f, 0.0f, 0.0f); //bottom right
        // glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f(0.75f, a2, 0.0f); //top

        // // glColor3f(0.0f, 0.0f, 1.0f); //blue
        // glVertex3f(-0.5f, 0.0f, 0.0f); //bottom left
        // // glColor3f(0.0f, 1.0f, 0.0f); //green
        // glVertex3f(0.5f, 0.0f, 0.0f); //bottom right
        // // glColor3f(1.0f, 0.0f, 0.0f); //red
        // glVertex3f(0.0f, 1.0, 0.0f); //top
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}


void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27: //Escape key
            exit(0);
        case ' ':
            RenderMode++;
            if(RenderMode > 2) {RenderMode = 1;}
            drawScene();
        // default:
            // std::cout << key << std::endl;
    }
}


void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL); 
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void update(int value) {
    _angle += 2.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(win_width, win_height);
    
    //Create the window
    glutCreateWindow("OpenGL Triangle");
    initRendering();
    
    //Set handler functions
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    
    // glutTimerFunc(25, update, 0); //Add a timer
    
    glutMainLoop();
    return 0;
}