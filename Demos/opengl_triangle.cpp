#include <iostream>
#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27: //Escape key
            exit(0);
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

float _angle = 30.0f;
float _cameraAngle = 0.0f;

//Draws the 3D scene
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    // glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    glTranslatef(0.0f, 0.0f, -8.0f);
    glScalef(3.0, 3.0, 0.0);

    glPushMatrix();
    
    glBegin(GL_TRIANGLES);


        float width = 1.0f;
        float height = sqrt(width*width - (0.5 * width)*(0.5 * width));
        
        glColor3f(0.0f, 0.0f, 1.0f); //blue
        glVertex3f(-2.0f, 0.0f, 0.0f); //bottom left
        glColor3f(0.0f, 1.0f, 0.0f); //green
        glVertex3f(-1.0f, 0.0f, 0.0f); //bottom right
        glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f(-1.5f, height, 0.0f); //top
        
        //Triangle
        glColor3f(0.0f, 0.0f, 1.0f); //blue
        glVertex3f(-0.9f, 0.0f, 0.0f); //bottom left
        glColor3f(0.0f, 1.0f, 0.0f); //green
        glVertex3f(0.1f, 0.0f, 0.0f); //bottom right
        glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f(-0.4f, -cos(60), 0.0f); //top
        // glVertex3f(1.0f, 1.0f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f); //blue
        glVertex3f(0.2f, 0.0f, 0.0f); //bottom left
        glColor3f(0.0f, 1.0f, 0.0f); //green
        glVertex3f(1.2f, 0.0f, 0.0f); //bottom right
        glColor3f(1.0f, 0.0f, 0.0f); //red
        glVertex3f(0.7f, 1.0, 0.0f); //top

    
    glEnd();
    

    glPopMatrix();
    
    glutSwapBuffers();
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
    glutInitWindowSize(800, 600);
    
    //Create the window
    glutCreateWindow("Color Triangle");
    initRendering();
    
    //Set handler functions
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    
    // glutTimerFunc(25, update, 0); //Add a timer
    
    glutMainLoop();
    return 0;
}









