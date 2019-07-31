void insertrear()
{
    if(rear == qcap)
    {
        printtext("QUEUE IS FULL", -14, 30, 13);
        inr = false;
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
                inr = false;
                p = 100;
                r = 120;
                glutPostRedisplay();
            }
        }
    }
    glColor3f(1,1,1);
}

void deleterear()
{
    if(front == rear)
    {
        printtext("QUEUE IS EMPTY", -14, 30, 14);
        dr = false;
    }
    else
    {
        glColor3f(0,0,0);
        draw_poly(posrear-20,8,posrear-0.2,-8+0.2);
        glColor3f(0,0,1);
        draw_poly(p, q, r, s);
        glColor3f(1,1,1);
        printtext(qu[rear-1], p+6, q-8, len[rear-1]);
        glColor3f(0,0,1);
        if(p == 100)
        {
            p = posrear-20; 
            r = p+20;
        }
        if(deltime == false)
        {
            deltime = true;
            timer3(0);
        }
        if(r >= 119)
        {
            rear--;
            deltime = false;
            dr = false;
            p = 100;
            r = 120;
            glutPostRedisplay();
        }
    }
    glColor3f(1,1,1);
}

void insertfront()
{
    if(front == 0)
    {
        printtext("QUEUE IS FULL", -14, 30, 13);
        inf = false;
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
            if(p == 100)
            {
                p = -120;
                r = p+20;
            }
            draw_poly(p, q, r, s);
            glColor3f(1,1,1);
            printtext(inp, p+6, q-8, linp);
            glColor3f(0,0,1);
            if(instime == false)
            {
                instime = true;
                timer4(0);
            }
            if(r >= (posfront))
            {
                strcpy(qu[front-1],inp);
                len[front-1] = linp;
                front--;
                linp = 0;
                strcpy(inp,"");
                instime = false;
                go = false;
                inf = false;
                p = 100;
                r = 120;
                glutPostRedisplay();
            }
        }
        glColor3f(1,1,1);
    }
}

void deletefront()
{
    if(front == rear)
    {
        printtext("QUEUE IS EMPTY", -14, 30, 14);
        df = false;
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
            df = false;
            p = 100;
            r = 120;
            glutPostRedisplay();
        }
    }
    if(front == qcap && rear == qcap)
        front = rear = 0;
    glColor3f(1,1,1);
}