#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>

int currentView = 4; 

void drawRobot() {
    glColor3f(0.7f, 0.7f, 0.7f);
    glPushMatrix();
    glTranslatef(0.0f, 1.2f, 0.0f);
    glutSolidCube(0.5);
    glPopMatrix();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(-0.1f, 1.25f, 0.25f);
    glutSolidSphere(0.05, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.1f, 1.25f, 0.25f);
    glutSolidSphere(0.05, 10, 10);
    glPopMatrix();
    
    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glScalef(0.8f, 1.0f, 0.5f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glColor3f(0.6f, 0.6f, 0.6f);
    glPushMatrix();
    glTranslatef(-0.5f, 0.5f, 0.0f);
    glRotatef(20.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.2f, 0.7f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5f, 0.5f, 0.0f);
    glRotatef(-20.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.2f, 0.7f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glColor3f(0.4f, 0.4f, 0.4f);
    glPushMatrix();
    glTranslatef(-0.2f, -0.3f, 0.0f);
    glScalef(0.2f, 0.6f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.2f, -0.3f, 0.0f);
    glScalef(0.2f, 0.6f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();
}

void displayViewName() {
    char* viewName;
    int i;
    
    switch (currentView) {
        case 1: viewName = "Plan View (Top)"; break;
        case 2: viewName = "Front View"; break;
        case 3: viewName = "Side View"; break;
        case 4: viewName = "Isometric View"; break;
        case 5: viewName = "Dimetric View"; break;
        case 6: viewName = "Trimetric View"; break;
        case 7: viewName = "1-Point Perspective"; break;
        case 8: viewName = "2-Point Perspective"; break;
        case 9: viewName = "3-Point Perspective"; break;
        default: viewName = "Unknown View";
    }
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(10, 10);
    
    for (i = 0; i < strlen(viewName); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, viewName[i]);
    }
    
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void setupView() {
    float aspect = 1.0;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    switch (currentView) {
        case 1: 
            glOrtho(-3.0, 3.0, -3.0, 3.0, -10.0, 10.0);
            gluLookAt(0.0, 5.0, 0.0,  
                      0.0, 0.0, 0.0,  
                      0.0, 0.0, -1.0); 
            break;
            
        case 2: 
            glOrtho(-3.0, 3.0, -3.0, 3.0, -10.0, 10.0);
            gluLookAt(0.0, 0.0, 5.0,  
                      0.0, 0.0, 0.0,  
                      0.0, 1.0, 0.0); 
            break;
            
        case 3: 
            glOrtho(-3.0, 3.0, -3.0, 3.0, -10.0, 10.0);
            gluLookAt(5.0, 0.0, 0.0,  
                      0.0, 0.0, 0.0,  
                      0.0, 1.0, 0.0); 
            break;
            
        case 4: 
            glOrtho(-3.0, 3.0, -3.0, 3.0, -10.0, 10.0);
            gluLookAt(3.0, 3.0, 3.0,  
                      0.0, 0.0, 0.0,  
                      0.0, 1.0, 0.0); 
            break;
            
        case 5: 
            glOrtho(-3.0, 3.0, -3.0, 3.0, -10.0, 10.0);
            gluLookAt(3.5, 2.0, 3.5,  
                      0.0, 0.0, 0.0,  
                      0.0, 1.0, 0.0); 
            break;
            
        case 6: 
            glOrtho(-3.0, 3.0, -3.0, 3.0, -10.0, 10.0);
            gluLookAt(4.0, 2.5, 2.0,  
                      0.0, 0.0, 0.0,  
                      0.0, 1.0, 0.0); 
            break;
            
        case 7: 
            gluPerspective(45.0, aspect, 0.1, 100.0);
            gluLookAt(0.0, 0.0, 5.0,  
                      0.0, 0.0, 0.0,  
                      0.0, 1.0, 0.0); 
            break;
            
        case 8: 
            gluPerspective(45.0, aspect, 0.1, 100.0);
            gluLookAt(4.0, 0.0, 4.0,  
                      0.0, 0.0, 0.0,  
                      0.0, 1.0, 0.0); 
            break;
            
        case 9: 
            gluPerspective(45.0, aspect, 0.1, 100.0);
            gluLookAt(3.0, 3.0, 3.0,  
                      0.0, 0.0, 0.0,  
                      0.0, 1.0, 0.0); 
            break;
    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    setupView();
    
    drawRobot();
    
    displayViewName();
    
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key >= '1' && key <= '9') {
        currentView = key - '0';  
        glutPostRedisplay();
    } else if (key == 27) { 
        exit(0);
    }
}

void init() {
    GLfloat light_position[] = { 5.0, 5.0, 5.0, 0.0 };
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    
    glClearColor(0.0, 0.0, 0.2, 1.0);
    glEnable(GL_DEPTH_TEST);
    
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robot Model with Multiple Projections");
    
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}
