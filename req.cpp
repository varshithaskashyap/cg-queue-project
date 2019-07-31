#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<cmath>
#include<iostream>
#include<string.h>

using namespace std;
int qcap, kkey = 32, front = 0, rear = 0, linp = 0, len[50], j = 0;
bool disp = false, que = false, dque = false, ins = false, del = false, go = false, instime = false, deltime = false, inr = false, inf = false, dr = false, df = false;
float x, y, p = 100, q = 8, r = 120, s = -8, a = -20, b = 1000, c = 19.65, d, posfront, posrear;
char inp[100], qu[100][100];

void queue();
void dequeue();
void display();
void insertrear();
void insertfront();
void deletefront();
void deleterear();
void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void margine(float p, float q, float r, float s)
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(p, q);
    glVertex2f(p, s);
    glVertex2f(r, s);
    glVertex2f(r, q);
    glEnd();
}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
}

void draw_poly(float a, float b, float c, float d)
{
    glBegin(GL_POLYGON);
    glVertex2f(a,b);
    glVertex2f(a,d);
    glVertex2f(c,d);
    glVertex2f(c,b);
    glEnd();
}

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        x = (float(mousex) - 500)/5;
        y = (700 - float(mousey) - 350)/3.5;
    }
    if(disp == true)
    {
        if(x >= -40 && x <= 40 && y >= 5 && y <= 20)
        {
            disp = false;
            que = true;
            glutDisplayFunc(queue);
        }
        else if(x >= -40 && x <= 40 && y >= -15 && y <= 0)
        {
            disp = false;
            dque = true;
            glutDisplayFunc(dequeue);
        }
    }
    if(que == true)
    {
        if(x >= -50 && x <= -10 && y >= -75 && y <= -60)
        {
            ins = true;
        }
        else if(x >= 10 && x <= 50 && y >= -75 && y <= -60)
        {
            del = true;
        }
        else if(ins == true)
        {
            if(x >=23 && x <= 32 && y >= 40 && y <= 50)
            {
                go = true;
            }
        }
    }
    if(dque == true)
    {
        draw_poly(-75, -60, -45, -75);//if
        draw_poly(-35, -60, -5, -75);//df
        draw_poly(5, -60, 35, -75);//ir
        draw_poly(45, -60, 75, -75);//dr
        if(x >= -75 && x <= -45 && y >= -75 && y <= -60)
        {
            inf = true;
        }
        else if(x >= -35 && x <= -5 && y >= -75 && y <= -60)
        {
            df = true;
        }
        else if(x >= 5 && x <= 35 && y >= -75 && y <= -60)
        {
            inr = true;
        }
        else if(x >= 45 && x <= 75 && y >= -75 && y <= -60)
        {
            dr = true;
        }
        else if(inr == true || inf == true)
        {
            if(x >=23 && x <= 32 && y >= 40 && y <= 50)
            {
                go = true;
            }
        }
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    kkey = (int)key;
    if(que == true || dque == true)
    {
        if(ins == true || inr == true || inf == true)
        {
            if(isdigit(key) || key == '-')
            {
                inp[linp] = char(kkey);
                linp++;
            }
            else if(kkey == 8)
            {
                inp[--linp] = '\0';
            }
        }
    }
    glutPostRedisplay();
}

void printtext(char s[], float x, float y, int l)
{
    glRasterPos2i(x,y);
    for(int i = 0;i<l;i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }
}

void print_front(int x)
{
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(x+10, -10);
    glVertex2f(x+10, -16);
    glVertex2f(x+10, -10);
    glVertex2f(x+8,-12);
    glVertex2f(x+10, -10);
    glVertex2f(x+12,-12);
    glEnd();
    glLineWidth(1);
    printtext("FRONT", x+4, -21, 5);
    printtext("FRONT = ", 50, 60, 8);
    if(front == -1)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 45);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 49);
    }
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, front + 48);
    }
}

void print_rear(int x)
{
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(x+10, 10);
    glVertex2f(x+10, 16);
    glVertex2f(x+10, 10);
    glVertex2f(x+8,12);
    glVertex2f(x+10, 10);
    glVertex2f(x+12,12);
    glEnd();
    glLineWidth(1);
    printtext("REAR", x+5, 17, 4);
    printtext("REAR = ", 50, 50, 7);
    if(rear == -1)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 45);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 49);
    }
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, rear + 48);
    }
}

void timer1(int)
{
    if(instime == true)
    {
        glutPostRedisplay();
        glutTimerFunc(1000/60,timer1,0);
        if(r > (20+posrear))
        {
            r-=1;
            p = r-20;
        }
        else
        {
            instime = false;
            return;
        }
    }
}

void timer2(int)
{
    if(deltime == true)
    {
        glutPostRedisplay();
        glutTimerFunc(1000/60,timer2,0);
        if(r > -100)
        {
            r-=1;
            p = r-20;
        }
        else
        {
            deltime = false;
            return;
        }
    }
}

void timer3(int)
{
    if(deltime == true)
    {
        glutPostRedisplay();
        glutTimerFunc(1000/60,timer3,0);
        if(r < 119)
        {
            r+=1;
            p = r-20;
        }
        else
        {
            deltime = false;
            return;
        }
    }
}

void timer4(int)
{
    if(instime == true)
    {
        glutPostRedisplay();
        glutTimerFunc(1000/60,timer4,0);
        if(r < (posfront))
        {
            r+=1;
            p = r-20;
        }
        else
        {
            instime = false;
            return;
        }
    }
}




