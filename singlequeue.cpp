void insert()
{
    if(rear == qcap)
    {
        printtext("QUEUE IS FULL", -14, 30, 13);
        ins = false;
    }
    else
    {
        draw_poly(-20, 50, 20, 40);
        glColor3f(0,0,1);
        printtext("Enter the Element : ", -18, 43, 20);
        glColor3f(1,1,1);
        draw_poly(23, 50, 32, 40);
        glColor3f(0,0,1);
        printtext("GO", 25, 43, 2);
        printtext(inp, 13, 43, linp);
        glColor3f(0,0,1);
        if(go == true)
        {
            glColor3f(0,0,0);
            draw_poly(-20, 50, 32, 40);
            glColor3f(0,0,1);
            draw_poly(p, q, r, s);
            glColor3f(1,1,1);
            printtext(inp, p+6, q-8, linp);
            glColor3f(0,0,1);
            if(instime == false)
            {
                instime = true;
                timer1(0);
            }
            if(r <= (20+posrear))
            {
                strcpy(qu[rear++],inp);
                len[rear-1] = linp;
                linp = 0;
                strcpy(inp,"");
                instime = false;
                go = false;
                ins = false;
                p = 100;
                r = 120;
                glutPostRedisplay();
            }
        }
    }
    glColor3f(1,1,1);
}

void delet()
{
    if(front == rear)
    {
        printtext("QUEUE IS EMPTY", -14, 30, 14);
        del = false;
    }
    else
    {
        glColor3f(0,0,0);
        draw_poly(posfront,8,posfront+20-0.2,-8+0.2);
        glColor3f(0,0,1);
        draw_poly(p, q, r, s);
        glColor3f(1,1,1);
        printtext(qu[front], p+6, q-8, len[front]);
        glColor3f(0,0,1);
        if(p == 100)
        {
            p = posfront; 
            r = p+20;
        }
        if(deltime == false)
        {
            deltime = true;
            timer2(0);
        }
        if(r <= -100)
        {
            front++;
            deltime = false;
            del = false;
            p = 100;
            r = 120;
            glutPostRedisplay();
        }
    }
    if(front == qcap && rear == qcap)
        front = rear = 0;
    glColor3f(1,1,1);
}