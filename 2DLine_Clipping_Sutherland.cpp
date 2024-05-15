#include<GL/glut.h>
GLfloat x_min = -200, x_max = 200, y_min = -200, y_max = 200;
GLfloat x1 = -300, y1 = -100, x2 = -50, y2 = 300;
int left = 1, right = 2, top = 4, bottom = 8;
int C1, C2, clip_flag = 0, flag = 1;

int get_Code(GLfloat x, GLfloat y)
{
    int code = 0;
    if (x < x_min)
        code = code | left;
    if (x > x_max)
        code = code | right;
    if (y < y_min)
        code = code | bottom;
    if (y > y_max)
        code = code | top;
    return code;

}

void clip()
{
    int C;
    GLfloat x, y;
    if (C1)
        C = C1;
    else
        C = C2;
    if (C & left)
    {
        x = x_min;
        y = y1 + ((y2 - y1) * (x_min - x1) / (x2 - x1));
    }
    if (C & right)
    {
        x = x_max;
        y = y1 + ((y2 - y1) * (x_max - x1) / (x2 - x1));
    }
    if (C & bottom)
    {
        y = y_min;
        x = x1 + ((x2 - x1) * (y_min - y1) / (y2 - y1));
    }
    if (C & top)
    {
        y = y_max;
        x = x1 + ((x2 - x1) * (y_max - y1) / (y2 - y1));
    }

    if (C == C1)
    {
        x1 = x;
        y1 = y;
    }
    else
    {
        x2 = x;
        y2 = y;
    }

}

// Draw function for Displaying objects
void Draw()
{
    glClearColor(0.2f, 0.75f, 0.75f, 0.1f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Display the clipping window 
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(x_min, y_min);
    glVertex2f(x_max, y_min);
    glVertex2f(x_max, y_max);
    glVertex2f(x_min, y_max);
    glEnd();
    //displaying the line 
    if (flag == 1)
    {
        glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glEnd();
    }

    while (1 & clip_flag == 1)
    {
        C1 = get_Code(x1, y1);
        C2 = get_Code(x2, y2);
        if ((C1 | C2) == 0)
            break;
        else if ((C1 & C2) != 0)
        {
            flag = 0;
            break;
        }

        else
            clip();
    }


    glFlush();
}

// MyInit Function for basic setup
void MyInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-350, 350, -350, 350);
    glMatrixMode(GL_MODELVIEW);
}
void Key(unsigned char ch, int x, int y)
{
    clip_flag = 1;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(720, 720);
    glutCreateWindow("2D Line Clipping in Opengl");
    MyInit();
    glutDisplayFunc(Draw);
    glutKeyboardFunc(Key);
    glutMainLoop();
    return 0;
}