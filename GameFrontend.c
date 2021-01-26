#include <GL/glut.h>
#include <math.h>

#define SCREEN_HEIGHT 750
#define SCREEN_WIDTH 1400
#define XFactor 190
#define YFactor 85
#define PI 3.1459

#define BACKGROUND 255, 255, 255
#define LINE 0,0,0
#define CIRCLE 180,120,50
#define POTENTIALLINE 0,0,0
#define POTENTIALCIRCLE 255,140,0
#define TEXTCOLOR 66, 66, 66
#define SELECTEDTEXTCOLOR 220, 20, 60
#define TEXTCIRCLE 255,255,255
#define TEXTPOTENTIALCIRCLE 255,255,255
#define LASTCIRCLE 20,200,200
#define LASTCIRCLETEXT 255,255,255

int r = 16, try;

void SetColor4d(double r, double g, double b, double alpha)
{
    glColor4d(r / 255.0d, g / 255.0d, b / 255.0d, alpha);
}

void DrawBitmapString(char *c, double x, double y, double z)
{
    glRasterPos3d(x, y, z);
    int i;

    for (i = 0; c[i] != '\0'; ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
    }

    glFlush();
}

void DrawCircle(int h, int k, int num)
{
    int i;
    char c[3];

    SetColor4d(CIRCLE, 1);

    glBegin(GL_POLYGON);

    for (i = 0; i < 1000; ++i)
    {
        double angle = i * 2 * PI / 100;
        glVertex2d(h + r * cos(angle), k + r * sin(angle));
    }
    glEnd();

    SetColor4d(TEXTCIRCLE, 1);

    sprintf(c, "%d", num);
    DrawBitmapString(c, h - 6, k + 3, 0);

    glFlush();
}

void DrawLastCircle(int h, int k, int num)
{
    int i;
    char c[3];

    SetColor4d(LASTCIRCLE, 1);

    glBegin(GL_POLYGON);

    for (i = 0; i < 1000; ++i)
    {
        double angle = i * 2 * PI / 100;
        glVertex2d(h + r * cos(angle), k + r * sin(angle));
    }
    glEnd();

    SetColor4d(LASTCIRCLETEXT, 1);

    sprintf(c, "%d", num);
    DrawBitmapString(c, h - 6, k + 3, 0);

    glFlush();
}

void DrawPotentialCircle(int h, int k, int num)
{
    int i;
    char c[3];

    SetColor4d(POTENTIALCIRCLE, 1);

    glBegin(GL_POLYGON);    //Circle

    for (i = 0; i < 1000; ++i)
    {
        double angle = i * 2 * PI / 100;
        glVertex2d(h + r * cos(angle), k + r * sin(angle));
    }
    glEnd();

    SetColor4d(TEXTCIRCLE, 1);

    sprintf(c, "%d", num);
    DrawBitmapString(c, h - 6, k + 3, 0);

    glFlush();
}

void DrawLines(x1, y1, x2, y2)
{
    SetColor4d(LINE, 1);
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glEnd();

    glFlush();
}

void DrawPotentialLines(x1, y1, x2, y2)
{
    SetColor4d(POTENTIALLINE, 1);
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glEnd();

    glFlush();
}

void ClearInstructions()
{
    SetColor4d(BACKGROUND, 1.0f);

    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(SCREEN_WIDTH, 0);
    glVertex2d(SCREEN_WIDTH, 65);
    glVertex2d(0, 65);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2d(0, SCREEN_HEIGHT - 30);
    glVertex2d(SCREEN_WIDTH, SCREEN_HEIGHT - 30);
    glVertex2d(SCREEN_WIDTH, SCREEN_HEIGHT);
    glVertex2d(0, SCREEN_HEIGHT);
    glEnd();
}

void ClearTree()
{
    SetColor4d(BACKGROUND, 1.0f);

    glBegin(GL_POLYGON);
    glVertex2d(0, 65);
    glVertex2d(SCREEN_WIDTH, 65);
    glVertex2d(SCREEN_WIDTH, SCREEN_HEIGHT);
    glVertex2d(0, SCREEN_HEIGHT);
    glEnd();
}

void StartTheGame()
{
    glClearColor(255 / 255.0, 219 / 255.0, 162 / 255.0, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // sets each pixel to "clearcolor", above.

    SetColor4d(TEXTCOLOR, 1);
    DrawBitmapString("Enter the value to the first node", 40,
                     30, 0);

    DrawCircle(SCREEN_WIDTH / 2, 90 + r, 0);

    glFlush();
}

void Display()
{

}
