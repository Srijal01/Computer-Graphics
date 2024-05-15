#include<GL/glut.h>
GLfloat C1[3] = { 1.0f,0.0f,0.0f };
GLfloat C2[3] = { 0.0f,0.0f,1.0f };
GLfloat C3[3] = { 0.0f,1.0f,0.0f };
GLfloat C4[3] = { 1.0f,1.0f,1.0f };
GLfloat C5[3] = { 0.2f,0.75f,0.75f };
void polygunPlot(GLfloat vertices[3][2], GLfloat pic_color[3])
{
    glBegin(GL_LINE_LOOP);
    glColor3fv(pic_color);
    for (int i = 0;i < 3;i++)
    {
        glVertex2fv(vertices[i]);
    }
    glEnd();
}
void translate(GLfloat v[3][2], GLfloat tx, GLfloat ty)
{
    for (int i = 0;i < 3;i++)
    {
        v[i][0] += tx;
        v[i][1] += ty;
    }
    polygunPlot(v, C5);
}
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // Define the initial triangle at the center
    GLfloat v[3][2] = {
                            {-0.3f, -0.3f}, // Adjusted x and y coordinates
                            {-0.1f, -0.3f}, // Adjusted x coordinate
                            {-0.3f, -0.1f}, // Adjusted y coordinate
    };
    // Draw the coordinate axes
    glBegin(GL_LINES);
    glColor3fv(C4);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();
    // Draw the initial triangle
    polygunPlot(v, C1);
    // Perform translation
    translate(v, 0.5f, 0.5f);
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(150, 150);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(520, 520);
    glutCreateWindow("OpenGL Translation");
    glutDisplayFunc(display);
    glutMainLoop();
    return  0;
}