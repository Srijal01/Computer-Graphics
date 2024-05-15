#include<windows.h>
#include<GL/glut.h>
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);               //Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);                       //Clear the color buffer (background)
    //Draw a point
    glPointSize(5);
    glBegin(GL_POINTS);                                 //Each set of 4 vertices from a quad
    glColor3f(1.0f, 0.0f, 0.0f);                        //Red color
    glVertex2f(-0.5f, -0.5f);                           //x,y
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glEnd();
    glFlush();                                          //Render now
}
//Main function: GLUT runs as a console application starting at main()
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                              //Initialize GLUT
    glutInitWindowPosition(50, 100);                    //Position the window's initial top-left corner
    glutInitWindowSize(520, 520);                       //Set the window's initial width & height 
    glutCreateWindow("OpenGL Points of Rectangle");    //Create a window with the given title
    glutDisplayFunc(display);                           //Register display callback handler for window re-paint
    glutMainLoop();                                     //Enter the event-processing loop
    return 0;
}