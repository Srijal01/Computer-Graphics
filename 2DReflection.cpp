#include<GL/glut.h>
GLfloat C1[3] = { 1.0f, 0.0f, 0.0f };
GLfloat C2[3] = { 0.0f, 0.0f, 1.0f };
GLfloat C3[3] = { 0.0f, 1.0f, 0.0f };
GLfloat C4[3] = { 1.0f, 1.0f, 1.0f };
GLfloat C5[3] = { 0.2f, 0.75f, 0.75f };
void PolygunPlot(GLfloat Vertices[3][2], GLfloat Pic_color[3])
{
    glBegin(GL_LINE_LOOP);
    glColor3fv(Pic_color);
    for (int i = 0; i < 3; i++)
    {
        glVertex2fv(Vertices[i]);
    }
    glEnd();
}
void ReflectX(GLfloat V[3][2])
{
    glBegin(GL_LINES);
    glColor3fv(C2);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
    for (int i = 0;i < 3;i++)
    {
        V[i][1] = -V[i][1];
    }
    PolygunPlot(V, C5);
}
void ReflectY(GLfloat V[3][2])
{
    glBegin(GL_LINES);
    glColor3fv(C3);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);
    glEnd();
    for (int i = 0;i < 3;i++)
    {
        V[i][0] = -V[i][0];
    }
    PolygunPlot(V, C4);
}
void Reflect_XeqY(GLfloat V[3][2])
{
    glBegin(GL_LINES);
    glColor3fv(C4);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();
    for (int i = 0;i < 3;i++)
    {
        GLfloat K = V[i][0];
        V[i][0] = V[i][1];
        V[i][1] = K;
    }
    PolygunPlot(V, C3);
}
void Reflect_Xeq_mi_Y(GLfloat V[3][2])
{
    glBegin(GL_LINES);
    glColor3fv(C4);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glEnd();
    for (int i = 0;i < 3;i++)
    {
        GLfloat K = -V[i][0];
        V[i][0] = -V[i][1];
        V[i][1] = K;
    }
    PolygunPlot(V, C3);
}
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat V[3][2] = {
                            {0.3f,0.7f},
                            {0.1f,0.4f},
                            {0.3f,0.4f},
    };
    glBegin(GL_LINES);
    glColor3fv(C4);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();
    PolygunPlot(V, C1);
    ReflectX(V);
    ReflectY(V);
    Reflect_XeqY(V);
    Reflect_Xeq_mi_Y(V);
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(150, 150);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(520, 520);
    glutCreateWindow("OpenGL Reflection");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}