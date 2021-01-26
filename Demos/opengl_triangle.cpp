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
int RenderMode = 0;

using namespace std;

//Draws the 3D scene
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
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

        // std::clock_t start;
        // double duration;

        // start = std::clock();

        /* Your algorithm here */
        float a1 = sqrt(1 - 0.25);

        // duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

        // std::cout<<"time for sqrt "<< duration <<'\n';

        
        // start = std::clock();

        /* Your algorithm here */
        float a2 = sin(60*(PI/180.0));

        // duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

        // std::cout<<"time for sin "<< duration <<'\n';


        glColor3f(0.0f, 0.0f, 1.0f); //blue
        glVertex3f(-1.25f, 0.0f, 0.0f); //bottom left
        glColor3f(0.0f, 1.0f, 0.0f); //green
        glVertex3f(-0.25f, 0.0f, 0.0f); //bottom right
        glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f(-0.75f, a1, 0.0f); //top
        
        //Triangle
        glColor3f(0.0f, 0.0f, 1.0f); //blue
        glVertex3f(0.25f, 0.0f, 0.0f); //bottom left
        glColor3f(0.0f, 1.0f, 0.0f); //green
        glVertex3f(1.25f, 0.0f, 0.0f); //bottom right
        glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f(0.75f, a2, 0.0f); //top
        // glVertex3f(1.0f, 1.0f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f); //blue
        glVertex3f(-0.5f, 0.0f, 0.0f); //bottom left
        glColor3f(0.0f, 1.0f, 0.0f); //green
        glVertex3f(0.5f, 0.0f, 0.0f); //bottom right
        glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f(0.0f, 1.0, 0.0f); //top

        // bool t =  (a1 == a2);
        // std::cout << a1 << " - " << a2 << " = " << t << std::endl;
    
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
            if(RenderMode > 2) {RenderMode = 0;}
            // std::cout << RenderMode << std::endl;
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

float _angle = 60.0f;
float _cameraAngle = 30.0f;

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
    glutInitWindowSize(640, 480);
    
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









