#include<GL/glut.h>

GLfloat transX = 0.0;
GLfloat transY = 0.0;
GLfloat transZ = 0.0;

//Defining a Color matrix for the color for different colored faces
GLfloat Color[6][3] = {
    {1.0,0.0,0.0},
    {0.0,1.0,0.0},
    {0.0,0.0,1.0},
    {1.0,0.25,0.0},
    {1.0,0.0,0.25},
    {1.0,0.5,0.25},
};
// Defining Face function 
void face(GLfloat A[3], GLfloat B[3], GLfloat C[3], GLfloat D[3], GLfloat Cl[3]) {
    glBegin(GL_POLYGON);
    glColor3fv(Cl);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);
    glEnd();
}

// Definition of  cube function 
void cube(GLfloat V[8][3]) {
    face(V[0], V[1], V[2], V[3], Color[0]); // front face 
    face(V[4], V[5], V[6], V[7], Color[1]); // backface  
    face(V[0], V[1], V[5], V[4], Color[2]); // top  
    face(V[2], V[3], V[7], V[6], Color[3]); // bottom  
    face(V[0], V[3], V[7], V[4], Color[4]); // left  
    face(V[1], V[2], V[6], V[5], Color[5]); // right  

}

// Draw function for Displaying objects
void Draw() {

    GLfloat Vertices[8][3] = {
        {-100.0,100.0,100.0},
        {100.0,100.0,100.0},
        {100.0,-100.0,100.0},
        {-100.0,-100.0,100.0},
        {-100,100,-100},
        {100,100,-100},
        {100,-100,-100},
        {-100,-100,-100},

    };
    glClearColor(0.2f, 0.75f, 0.75f, 0.1f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(10, 1.0, 1.0, 1.0);
    glTranslatef(transX, transY, transZ);
    // calling Cube function to create cube 
    cube(Vertices);


    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        transX -= 1;
        break;
    case 'd':
        transX += 1;
        break;
    case 'w':
        transY += 1;
        break;
    case 's':
        transY -= 1;
        break;
    case 'q':
        transZ += 1;
        break;
    case 'e':
        transZ -= 1;
        break;
    }
    glutPostRedisplay();
}

// MyInit Function for basic setup
void MyInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-350, 350, -350, 350, -350, 350);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(720, 720);
    glutCreateWindow("3d object transformation ");
    MyInit();
    glutDisplayFunc(Draw);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}