#include<windows.h>
#include</home/student/Desktop/project cg/req.cpp>
#include</home/student/Desktop/project cg/singlequeue.cpp>
#include</home/student/Desktop/project cg/doublequeue.cpp>
int main(int argc, char**argv)
{
    cout<<"Enter the maximum capacity of queue : ";
    cin>>qcap;
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowPosition(10,10);
    glutInitWindowSize(1000,700);
    glutCreateWindow("QUEUE Implementation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
}

void queueinit()
{
    init();
    glBegin(GL_LINES);
    glVertex2f(0-20*qcap/2, 8);
    glVertex2f(0+20*qcap/2, 8);
    glVertex2f(0-20*qcap/2, -8);
    glVertex2f(0+20*qcap/2, -8);
    for(int i=0-20*qcap/2;i<=0+20*qcap/2;i+=20)
    {
        glVertex2f(i, 8);
        glVertex2f(i, -8);
    }
    /*if(front!=rear)
    {
        draw_poly(posfront,8,posfront+20,-8);
        glColor3f(1,1,1);
        printtext(qu[j], posfront+6, 0, len[j]);
        j++;
    }
    //int
    for(int i=posfront;i<posrear;i+=20,j++)
    {
        glColor3f(0,0,1);
        draw_poly(i,8,i+20-0.2,-8+0.2);
        glColor3f(1,1,1);
        printtext(qu[j], i+6, 0, len[j]);
    }*/
    posfront = -20*qcap/2+(front*20); posrear = -20*qcap/2+(rear*20);
    j = front;float i = posfront;
    while(i<(posrear))
    {
        glColor3f(0,0,1);
        draw_poly(posfront,8,posfront+20-0.2,-8+0.2);
        glColor3f(1,1,1);
        printtext(qu[front], posfront+7, 0, len[front]);
        glColor3f(0,0,1);
        draw_poly(i,8,i+20-0.2,-8+0.2);
        glColor3f(1,1,1);
        printtext(qu[j], i+7, 0, len[j]);
        j++;
        i+=20;
    }
    glBegin(GL_LINES);
    glVertex2f(-20*qcap/2,8);
    glVertex2f(-20*qcap/2,-8);
    j = front;
    glEnd();
    margine(-94, 94, 94, -94);
    glColor3f(0,0,1);
    print_front(posfront);
    print_rear(posrear);
    glColor3f(1,1,1);
}

void display()
{
    disp = true;
    margine(-94, 94, 94, -94);
    draw_poly(-40, 20, 40, 5);
    draw_poly(-40, 0, 40, -15);
    glColor3f(0,0,1);
    printtext("NORMAL QUEUE IMPLEMENTATION", -32, 10, 27);
    printtext("DEQUEUE IMPLEMENTATION", -26.5, -10, 22);
    glColor3f(1,1,1);
    glutSwapBuffers();
}

void queue()
{
    queueinit();
    draw_poly(-50, -60, -10, -75);
    draw_poly(10, -60, 50, -75);
    glColor3f(0,0,1);
    printtext("INSERT ELEMENT", -45, -70, 14);
    printtext("DELETE ELEMENT", 15, -70, 14);
    glColor3f(1,1,1);
    if(ins == true)
    {
        insert();
    }
    else if(del == true)
    {
        delet();
    }
    glutSwapBuffers();
}

void dequeue()
{
    queueinit();
    draw_poly(-75, -60, -45, -75);
    draw_poly(-35, -60, -5, -75);
    draw_poly(5, -60, 35, -75);
    draw_poly(45, -60, 75, -75);
    glColor3f(0,0,1);
    printtext("INSERT FRONT", -73, -70, 12);
    printtext("DELETE FRONT", -33, -70, 12);
    printtext("INSERT REAR", 8, -70, 12);
    printtext("DELETE REAR", 48, -70, 12);
    glColor3f(1,1,1);
    if(inr == true)
    {
        insertrear();
    }
    else if(dr == true)
    {
        deleterear();
    }
    else if(inf == true)
    {
        insertfront();
    }
    else if(df == true)
    {
        deletefront();
    }
    glutSwapBuffers();
}


