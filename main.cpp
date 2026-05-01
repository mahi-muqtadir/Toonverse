//mahi
#include <GL/glut.h>
#include <math.h>

void dda(float x1,float x2,float y1 ,float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy / dx;
    float x = x1;
    float y = y1;

    glPointSize(5);
    glBegin(GL_POINTS);
    if (fabs(m) < 1)
    {
        while (x <= x2 && y <= y2)
            {
            glVertex2f(x, y);
            x = x + 1;
            y = y + m;
        }
    }
    else
    {
        while (y <= y2)
            {
            glVertex2f(x, y);
            y = y + 1;
            x = x + (1/m);
        }
    }
    glEnd();
    glFlush();
}
void midLine(float x1,float x2,float y1 ,float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float x = x1;
    float y = y1;

float dOLD = 2*dy-dx; // dstart

    glPointSize(5);
    glBegin(GL_POINTS);
    while (x <= x2)
    {
        if (dOLD< 0)//e
            {
            glVertex2f(x, y);
            x = x +  1;
        dOLD= 2*dy + dOLD;
    }
         else //ne
            {
            glVertex2f(x, y);
            y = y + 1;
            x = x + 1;
        dOLD= 2*(dy-dx) + dOLD;
    }
    }
    glEnd();
    glFlush();
}
void circle( float centerX, float centerY,float radius)
{
     glBegin(GL_POLYGON);
        for(int i = 0;i<360;i++)
        {
            float angle = i * 3.1416 /180;
            float x = centerX + radius * cos(angle);
             float y = centerY + radius * sin(angle);
              glVertex2f(x,y);
        }
        glEnd();

}

void semiCircle(float centerX, float centerY,float radius)
{
     glBegin(GL_POLYGON);
        for(int i = 0;i<=180;i++)
        {
            float angle = i * 3.1416 /180;
            float x = centerX + radius * cos(angle);
             float y = centerY + radius * sin(angle);
              glVertex2f(x,y);
        }
        glEnd();

}

void mickeyLeg(float centerX, float centerY,float radius)
{
     glBegin(GL_POLYGON);
        for(int i = 90;i<=270;i++)
        {
            float angle = i * 3.1416 /180;
            float x = centerX + radius * cos(angle);
             float y = centerY + radius * sin(angle);
              glVertex2f(x,y);
        }
        glEnd();

}

void triangle(float x1,float y1,float x2,float y2,float x3,float y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
 glEnd();
}

void line(float x1,float y1,float x2,float y2)
{
     glBegin(GL_LINES);
     glVertex2f(x1,y1);
     glVertex2f(x2,y2);
     glEnd();
}

void polygon (float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{

glBegin(GL_POLYGON);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
 glEnd();

}
void midpointCircle(int xc,int yc,int r)
{
    int x = 0;
    int y = r;
    int d = 1 - r;

    glBegin(GL_POINTS);
    while(x <= y)
    {
        // 8-symmetry
        glVertex2f(xc + x, yc + y);
        glVertex2f(xc - x, yc + y);
        glVertex2f(xc + x, yc - y);
        glVertex2f(xc - x, yc - y);

        glVertex2f(xc + y, yc + x);
        glVertex2f(xc - y, yc + x);
        glVertex2f(xc + y, yc - x);
        glVertex2f(xc - y, yc - x);

        if(d >= 0) //se
        {
            d = d + 2*x - 2*y + 5;
            x++;
            y--;
        }
        else //e
        {
            d = d + 2*x + 3;
            x++;
        }
    }
    glEnd();
}
void background()
{
    //sky

    glColor3ub(204,255,255);
    polygon(-100,100,100,100,100,0,-100,0);

    //mickey clubhouse

    glColor3f(0,0,0);
    circle(-50,50,9);
    circle(-30,50,9);
    circle(-40,32.5,13);

    //joint
    glColor3ub(0,0,0);
    polygon(-24,2.5,-24,7.5,-12,7.5,-12,2.5);
     //leg
    glColor3ub(255,204,0);
    mickeyLeg(-10,6.25,6.25);
     mickeyLeg(-10,18.75,6.25);
     //body
       glColor3f(1,0,0);
    semiCircle(-40,0,20);
    //window
      glColor3ub(51,204,204);
    circle(-46,7.5,4);
    circle(-34,7.5,4);

    //doofenshmirtz

    glColor3ub(102,0,102);
    polygon(-90,62.5,-80,62.5,-80,60,-88,60);
    polygon(-70,50,-60,50,-62,47.5,-70,47.5);

    glColor3ub(102,102,153);
    polygon( -90,20,-90,50,-70,50,-70,20);
    polygon(-90,62.5,-90,75,-66,75,-70,62.5);
    polygon(-80,62.5,-58,62.5,-60,50,-80,50);

    glColor3ub(153,153,255);
    semiCircle(-78,75,12);
    glColor3ub(128,0,128);
    semiCircle(-78,75,4);

    //background grass
    glColor3ub(153,204,0);
    polygon(-100,0,100,0,100,-50,-100,-50);



    //footpath
 glColor3ub(0,0,0);
    polygon(-100,-95,100,-95,100,-100,-100,-100);

//far city
glColor3ub(153,204,255);
polygon(30, 20,30, 37.5,40, 37.5,40,20);
polygon(40,20,40,50,50,50,50,20);
polygon(50,20,50,30,60,30,60,20);
polygon(60,20,60,62.5,70,62.5,70,20);
polygon(70,20,70,37.5,80,37.5,80,20);
polygon(80,20,80,50,90,50,90,20);
polygon(90,20,90,62.5,100,62.5,100,20);

//back trees
glColor3ub(0,128,0);
circle(-90,12.5,12.5);
circle(-70,12.5,12.5);
circle(10,12.5,12.5);
circle(30,12.5,12.5);
circle(50,12.5,12.5);
circle(70,12.5,12.5);
circle(90,12.5,12.5);

glColor3ub(153,204,0);

circle(-80,16,10);
circle(20,16,10);
circle(40,16,10);
circle(60,16,10);
circle(80,16,10);

glColor3ub(0,150,0);

circle(-100,9,10);
circle(-90,9,10);
circle(-80,9,10);
circle(-70,9,10);
circle(20,9,10);
circle(30,9,10);
circle(40,9,10);
circle(50,9,10);
circle(60,9,10);
circle(70,9,10);
circle(80,9,10);
circle(90,9,10);

//lines
glColor3f(0,0,0);
dda(-100,100,0,0);
glColor3ub(0,0,0);
polygon(-100,-52.5,-100,-50,100,-50,100,-52.5);

//street lamp
glColor3ub(128,0,0);
polygon(-98,-50,-98,-45,-92,-45,-92,-50);
polygon(-98,-45,-96,-42.5,-94,-42.5,-92,-45);
polygon(-96,-42.5,-96,0,-94,0,-94,-42.5);
polygon(-96,0,-98,2.5,-92,2.5,-94,0);
glColor3ub(255,255,153);
polygon(-96,2.5,-98,7.5,-92,7.5,-94,2.5);
glColor3ub(128,0,0);
polygon(-97,7.5,-97,10,-93,10,-93,7.5);
triangle(-96,10,-95,12.5,-94,10);
}

void scene1(){
//powerpuff house
glColor3ub(192,192,192);
polygon(-10,-50,-10,-25,0,-12.5,0,-50);
polygon(20,-12.5,20,0,30,12.5,30,-12.5);

glColor3ub(255,255,255);
polygon(0,-50,0,-12.5,30,-12.5,30,-50);
polygon(30,-50,30,12.5,70,12.5,70,-50);
polygon(70,-50,70,-12.5,100,-12.5,100,-50);


//door
glColor3ub(255,51,102);
polygon(32,-50,32,-30,40,-30,40,-50);

//window
glColor3ub(128,128,128);
polygon(2,-37.5,2,-25,14,-25,14,-37.5);
polygon(16,-37.5,16,-25,28,-25,28,-37.5);

glColor3ub(0,0,0);
circle(64,0,6);
circle(50,0,6);
circle(36,0,6);

//inner window
glColor3ub(255,255,255);
circle(64,0,5.5);
circle(50,0,5.5);
circle(36,0,5.5);
glColor3ub(128,128,128);
circle(64,0,4.5);
circle(50,0,4.5);
circle(36,0,4.5);


polygon(50,-20,70,-20,70,-37.5,50,-37.5);

glColor3ub(192,192,192);
polygon(70,-50,70,-20,98,-20,98,-50);

glColor3ub(128,128,128);
line(30,-50,30,12.5);
line(70,-50,70,-12.5);
line(74,-30,94,-30);
line(74,-40,94,-40);



//phineas

//body
glColor3ub(255,204,0);
polygon(-76,-30,-72,-25,-68,-25,-64,-30);
glColor3ub(255,153,0);
polygon(-66,-35,-66,-30,-72,-30,-74,-35);
glColor3ub(255,204,0);
polygon(-74,-35,-76,-37.5,-66,-37.5,-66,-35);
//neck
glColor3ub(255,153,0);
circle(-70,-25,2);
//head
glColor3ub(255,204,153);
triangle(-80,-20,-70,-12.5,-70,-25);
//hair
glColor3ub(255,102,0);
glBegin(GL_POLYGON);
glVertex2f(-70,-12.5);
glVertex2f(-72,-10);
glVertex2f(-70,-10);
glVertex2f(-70,-7.5);
glVertex2f(-68,-10);
glVertex2f(-66,-10);
glVertex2f(-68,-12.5);
glEnd();
triangle(-68,-12.5,-70,-12.5,-68,-15);
//eyes
glColor3ub(255,255,255);
circle(-74,-15,2);
glColor3ub(0,0,0);
circle(-74,-15,1);
//hand
glColor3ub(255,204,153);
triangle(-66,-30,-64,-30,-66,-35);
polygon(-76,-30,-76,-37.5,-74,-35,-74,-30);
//pants
glColor3ub(51,51,153);
polygon(-76,-42.5,-76,-37.5,-66,-37.5,-66,-42.5);
glColor3ub(0,0,0);
line(-70,-40,-70,-42.5);
//legs
glColor3ub(255,204,153);
polygon(-74,-42.5,-74,-50,-72,-50,-72,-42.5);
polygon(-68,-42.5,-68,-50,-66,-50,-66,-42.5);
//shoes
glColor3ub(0,102,204);
polygon(-72,-50,-72,-47.5,-76,-47.5,-76,-50);
polygon(-66,-50,-66,-47.5,-70,-47.5,-70,-50);

//professor

//shoe
glColor3ub(0,0,0);
polygon(-50,-50,-47,-47.5,-46,-47.5,-48,-50);
polygon(-46,-50,-46,-47.5,-44,-47.5,-44,-50);
polygon(-42,-50,-44,-47.5,-43,-47.5,-40,-50);
//leg
polygon(-48,-40,-48,-47.5,-42,-47.5,-42,-40);
//apron
glColor3ub(255,255,255);
polygon(-50,-40,-50,-20,-40,-20,-40,-40);
polygon(-50,-20,-52,-20,-54,-27.5,-50,-27.5);
polygon(-54,-27.5,-50,-27.5,-50,-32.5,-54,-27.5);
polygon(-40,-20,-38,-20,-34,-27.5,-40,-25);
triangle(-40,-25,-38,-27.5,-34,-27.5);
polygon(-40,-30,-38,-27.5,-34,-27.5,-38,-32.5);
glColor3ub(0,0,0);
line(-50, -40,-50, -22.5);
//hand
glColor3ub(255,204,153);
triangle(-38, -32.5,-40, -32.5,-40, -30);
//shirt
glColor3ub(255,255,255);
triangle(-48,-17.5,-46,-20,-48,-20);
triangle(-42,-17.5,-46,-20,-42,-20);
glColor3ub(0,0,0);
polygon(-47,-22.5,-46,-20,-45,-22.5,-46,-25);
line(-48,-20,-46,-25);
line(-42,-20,-46,-25);
//head
glColor3ub(255,204,153);
polygon(-50,-17.5,-42,-17.5,-42,-5,-50,-5);
polygon(-42,-12.5,-40,-12.5,-40,-5,-42,-5);
triangle(-48,-17.5,-46,-20,-42,-17.5);

//hair
glColor3ub(0,0,0);
polygon(-50,-5,-40,-5,-46,-8.75,-50,-7.5);
triangle(-52,-5,-50,-7.5,-50,-5);
triangle(-42,-8.75,-40,-5,-40,-10);
//face
glColor3ub(0,0,0);
line(-47,-17.5,-44,-15);
line(-47,-17.5,-47,-15);
line(-48, -15,-47, -15);
line(-48, -15,-48, -10);
line(-50, -12.5,-48, -10);
line(-46, -10,-44, -12.5);
line(-49.5, -12.5,-48.5, -12.5);
line(-46, -12.5,-45, -12.5);

//tongue
glColor3ub(255,0,0);
triangle(-44,-17.5,-46,-17.5,-44,-15);
  //road
    glColor3ub(150,150,150);
    polygon(-100,-50,100,-50,100,-95,-100,-95);

    //road divider
     glColor3ub(255,255,255);
    polygon(-100,-75,-80,-75,-80,-70,-100,-70);
    polygon(-60,-75,-40,-75,-40,-70,-60,-70);
    polygon(-20,-75,0,-75,0,-70,-20,-70);
    polygon(20,-75,40,-75,40,-70,20,-70);
    polygon(60,-75,80,-75,80,-70,60,-70);
//hotwheels
//body
glColor3ub(51,51,51);
polygon(-80,-80,-70,-80,-70,-92.5,-80,-92.5);
polygon(-42,-90,-42,-77.5,-32,-77.5,-32,-90);
glColor3ub(0,0,0);
polygon(-50, -70,-46, -70,-46, -75,-50, -75);
polygon(-44, -70,-40, -70,-40, -77.5,-44, -77.5);
polygon(-38, -70,-34, -70, -34, -77.5, -38, -77.5);

glColor3ub(0,204,255);
glBegin(GL_POLYGON);
glVertex2f(-70,-95);
glVertex2f(-46,-95);
glVertex2f(-46,-92.5);
glVertex2f(-44,-92.5);
glVertex2f(-44,-90);
glVertex2f(-42,-90);
glVertex2f(-42,-87.5);
glVertex2f(-40,-87.5);
glVertex2f(-40,-77.5);
glVertex2f(-46,-77.5);
glVertex2f(-46,-75);
glVertex2f(-52,-75);
glVertex2f(-52,-70);
glVertex2f(-58,-70);
glVertex2f(-58,-67.5);
glVertex2f(-62,-67.5);
glVertex2f(-62,-65);
glVertex2f(-66,-65);
glVertex2f(-66,-62.5);
glVertex2f(-70,-62.5);
glEnd();
glColor3ub(0,102,204);
polygon(-84,-80,-70,-80,-70,-70,-84,-70);
glColor3ub(51,102,255);
polygon(-74,-62.5,-74,-80,-70,-80,-70,-62.5);
polygon(-68,-75,-68, -70,-66,-70,-66,-75);
polygon(-62,-77.5,-66,-77.5,-66,-72.5,-62, -72.5);
polygon(-58,-80,-62,-80,-62,-75,-58,-75);


glColor3ub(0,204,255);
glBegin(GL_POLYGON);
glVertex2f(-84,-72.5);
glVertex2f(-76,-72.5);
glVertex2f(-76,-67.5);
glVertex2f(-78,-67.5);
glVertex2f(-78,-65);
glVertex2f(-80,-65);
glVertex2f(-80,-62.5);
glVertex2f(-84,-62.5);
glEnd();
polygon(-76,-75,-80,-75,-80,-72.5,-76,-72.5);
polygon(-86,-70,-86,-65,-84,-65,-84,-70);
//wheels
//right
glColor3ub(0,0,0);
circle(-32,-87.5,7.5);
glColor3ub(255,255,255);
circle(-32,-87.5,6);
glColor3ub(0,0,0);
circle(-32,-87.5,5);
glColor3ub(255,255,255);
circle(-32,-87.5,4);
glColor3ub(0,0,0);
circle(-32,-87.5,2);
//left
glColor3ub(0,0,0);
circle(-80,-87.5,7.7);
glColor3ub(255,255,255);
circle(-80,-87.5,6);
glColor3ub(0,0,0);
circle(-80,-87.5,5);
glColor3ub(255,255,255);
circle(-80,-87.5,4);
glColor3ub(0,0,0);
circle(-80,-87.5,2);

glColor3ub(255,0,0);
polygon(-64,-95,-64,-92.5,-62,-92.5,-62,-95);
polygon(-58,-95,-58,-92.5,-56,-92.5,-56,-95);
polygon(-52,-95,-52,-92.5,-50,-92.5,-50,-95);

glColor3ub(255,255,0);
polygon(-62,-92.5,-62,-90,-60,-90,-60,-92.5);
polygon(-56,-92.5,-56,-90,-54,-90,-54,-92.5);
polygon(-50,-92.5,-50,-90,-48,-90,-48,-92.5);

glColor3ub(255,255,255);
polygon(-60,-90,-60,-87.5,-58,-87.5,-58,-90);
polygon(-54,-90,-54,-87.5,-52,-87.5,-52,-90);
polygon(-48,-90,-48,-87.5,-46,-87.5,-46,-90);
}
scene2()
{
    //squidward house
    glColor3ub(150,150,150);
    polygon(30,-50,30,-5,68,-5,68,-50);
    polygon(32,-5,32,17.5,68,17.5,68,-5);
    glColor3ub(128,128,128);
    polygon(50,-5,52,-22.5,42,-22.5,44,-5);
      polygon(24,-12.5,30,-12.5,30,-25,24,-25);
    polygon(66,-25,70,-25,70,-12.5,66, -12.5);
    polygon(28,2.5,58,2.5,58,-5,28,-5);
    glColor3ub(102,102,153);
    polygon(42,-22.5,46,-25,54,-25,52,-22.5);
    polygon(54,-25,52,-22.5,50,-5,52,-5);
    polygon(30, -25, 24, -25, 26, -30, 30, -30);
    polygon(66, -25, 70, -25, 72, -27.5, 68, -30);
    polygon(70, -25, 72, -27.5, 72, -12.5, 70, -12.5);
    polygon(62,1.25,58,2.5,58,-5,62,-5);
    glColor3ub(153,153,255);
    circle(36,-12.5,6);
     circle(58,-12.5,6);
      glColor3ub(204,204,255);
    circle(36,-12.5,4);
     circle(58,-12.5,4);
     glColor3ub(139,115,85);
     polygon(44,-50,44,-37.5,56,-37.5,56,-50);
     semiCircle(50,-37.5,6);

      //road

    glBegin(GL_POLYGON);
      glColor3ub(51,51,153);
    glVertex2f(-100,-52.5);
    glVertex2f(100,-52.5);

     glColor3ub(0,0,128);
      glVertex2f(100,-95);
    glVertex2f(-100,-95);

glEnd();
    //submarine
     glColor3ub(255,153,0);
polygon(60,-65,70,-65,70,-70,60,-75);
polygon(70,-75,72,-75,72,-80,70,-80);
polygon(60,-85,30,-85,30,-87.5,60,-87.5);
polygon(30,-67.5,30,-87.5,25,-87.5,22,-67.5);

    glColor3ub(255,204,0);
polygon(46,-52.5,46,-60,44,-60,44,-52.5);
polygon(40,-55,40,-52.5,44,-52.5,44,-55);
polygon(40,-67.5,40,-60,50,-60,54,-67.5);
polygon(60,-85,30,-85,30,-67.5,60,-67.5);
polygon(74, -73.75,75,-70,76,-73.75,75,-77.5);
polygon(74,-83.75,75,-80,76,-83.75,75,-87.5);

glColor3ub(255,204,0);
polygon(70,-75,60,-67.5,60,-80,70,-80);
    glColor3ub(0,128,128);
polygon(40,-62.5,46,-62.5,46,-67.5,40,-67.5);
 glColor3ub(255,102,0);
polygon(72,-80,76,-80,76,-77.5,72,-77.5);
midpointCircle(36,-75,4);
midpointCircle(46,-75,4);
midpointCircle(56,-75,4);
triangle(62,-80,64,-87.5,64,-80);
polygon(70,-82.5,64,-82.5,64,-87.5,70,-87.5);
glColor3ub(0,128,128);
circle(36,-75,3.5);
circle(46,-75,3.5);
circle(56,-75,3.5);
glColor3ub(255,153,0);
circle(32,-82.5,1);
circle(36,-82.5,1);
circle(40,-82.5,1);
circle(44,-82.5,1);
circle(48,-82.5,1);
circle(52,-82.5,1);
circle(56,-82.5,1);
}
void display() {


    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    background();
    //scene1();
scene2();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(250,0);

    glutCreateWindow("Mahi Muqtadir");


    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
