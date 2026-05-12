#include <iostream>
using namespace std;
#include <GL/glut.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

bool musicOn = true;
float spongebobtx=0.0f;
float spongebobty=0.0f;
float submarinetx =0.0f;
 float submarinety=0.0f;
 float bubbletx =0.0f;
 float bubblety=0.0f;
 float cartx=0.0f;
 float carty=0.0f;
  float loontx=0.0f;
 float loonty=0.0f;
 float loonsx = 1.0f;
 float loonsy = 1.0f;
  float cloudtx=0.0f;
 float cloudty=0.0f;
 float jumptx=0.0f;
 float jumpty=0.0f;
 bool jumpflag=false;
 float jump=0.0f;
int playScene1 =1;
 int       playScene2 = 0;
   int      playScene3 = 0;
     int     playScene4 = 0;
     int runSubmarine=0;


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
void brick3D()
{
    glBegin(GL_QUADS);

    //front
    glColor3ub(205,129,98);
    glVertex3f(-20, -50, 0);
    glVertex3f(-30, -50, 0);
    glVertex3f(-30, -45, 0);
    glVertex3f(-20, -45, 0);

    //back
 glColor3ub(139,87,66);
    glVertex3f(-20, -50, -5);
    glVertex3f(-30, -50, -5);
    glVertex3f(-30, -45, -5);
    glVertex3f(-20, -45, -5);

    //left

    glVertex3f(-30, -50, 0);
    glVertex3f(-30, -50, -5);
    glVertex3f(-30, -45, -5);
    glVertex3f(-30, -45, 0);

    //right

    glVertex3f(-20, -50, 0);
    glVertex3f(-20, -50, -5);
    glVertex3f(-20, -45, -5);
    glVertex3f(-20, -45, 0);

    //up
 glColor3ub(238,149,114);
    glVertex3f(-20, -45, 0);
    glVertex3f(-30, -45, 0);
    glVertex3f(-30, -45, -5);
    glVertex3f(-20, -45, -5);

    //down
 glColor3ub(139,87,66);
    glVertex3f(-20, -50, 0);
    glVertex3f(-30, -50, 0);
    glVertex3f(-30, -50, -5);
    glVertex3f(-20, -50, -5);

    glEnd();
}


void scene1(){


    //sky

    glColor3ub(204,255,255);
    polygon(-100,100,100,100,100,0,-100,0);

    glPushMatrix();
    glTranslatef(cloudtx,cloudty,0);

//cloud
  glColor3ub(255,255,255);
    circle(-60,87.5,4);
    circle(-64,87.5,3);
    circle(-56,87.5,3);

     glColor3ub(255,255,255);
    circle(-20,75,8);
    circle(-28,75,5);
    circle(-12,75,5);

    glColor3ub(255,255,255);
    circle(40,80,6);
    circle(46,80,4);
    circle(34,80,4);
glPopMatrix();


glPushMatrix();
glTranslatef(loontx,loonty,0);
glScalef(loonsx,loonsy,0);

    //airloon
    glColor3ub(255,0,0);
    circle(10,87.5,10);
    polygon(0,87.5,20,87.5,15,70,5,70);
    glColor3ub(0,0,0);
     glColor3ub(255,102,0);
    circle(7,87.5,5);
 glColor3ub(255,204,0);
    circle(13,87.5,5);
    glColor3ub(255,153,0);
    circle(10,82.5,5);
        glColor3ub(0,0,0);
         polygon(15,70,5,70,5,67.5,15,67.5);
    polygon(13,62.5,7,62.5,7,60,13,60);
    line(13,62.5,13,67.5);
     line(7,62.5,7,67.5);
glPopMatrix();
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


glPushMatrix();
glTranslatef(jumptx,jumpty,0.0f);
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
glPopMatrix();
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

    glPushMatrix();
glTranslatef(cartx,carty,0);
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
glPopMatrix();
//3D
glMatrixMode(GL_PROJECTION);
glPushMatrix();
glLoadIdentity();
glOrtho(-100, 100, -100, 100, -100, 100);

glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glLoadIdentity();

glTranslatef(5, -4, 0);
glRotatef(50, .5, .5, 0);

brick3D();

glPopMatrix();
glMatrixMode(GL_PROJECTION);
glPopMatrix();
glMatrixMode(GL_MODELVIEW);

glColor3ub(0,0,0);
dda(-100,100,-50,-50);
}

scene2()
{
    //sky

  glColor3ub(0,0,128);
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
   glColor3ub(46,139,87);
    polygon(-100,0,100,0,100,-50,-100,-50);



    //footpath
 glColor3ub(0,0,0);
    polygon(-100,-95,100,-95,100,-100,-100,-100);

//far city
glColor3ub(0,0,0);
polygon(30, 20,30, 37.5,40, 37.5,40,20);
polygon(40,20,40,50,50,50,50,20);
polygon(50,20,50,30,60,30,60,20);
polygon(60,20,60,62.5,70,62.5,70,20);
polygon(70,20,70,37.5,80,37.5,80,20);
polygon(80,20,80,50,90,50,90,20);
polygon(90,20,90,62.5,100,62.5,100,20);

//back trees
glColor3ub(46,139,87);

circle(-90,12.5,12.5);
circle(-70,12.5,12.5);
circle(10,12.5,12.5);
circle(30,12.5,12.5);
circle(50,12.5,12.5);
circle(70,12.5,12.5);
circle(90,12.5,12.5);

glColor3ub(67,205,128);

circle(-80,16,10);
circle(20,16,10);
circle(40,16,10);
circle(60,16,10);
circle(80,16,10);

glColor3ub(78,238,148);

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
//ferb

//head
glColor3ub(255,204,153);
polygon(-78,-30,-70,-30,-70,-5,-78,-5);
triangle(-80,-25,-78,-22.5,-78,-25);
polygon(-78,-20,-82,-20,-82,-15,-78,-15);
circle(-69,-13.75,1);
glColor3ub(205,179,139);
line(-82,-20,-76,-20);
line(-76,-20,-75,-18.75);

//eye
glColor3ub(255,255,255);
circle(-76,-12.5,2);
glColor3ub(0,0,0);
circle(-76,-12.5,.75);

//hair
glColor3ub(50,205,50);
polygon(-68,-5,-82,-5,-78,-2.5,-70,-2.5);
polygon(-70,-2.5,-68,0,-70,0,-74,-2.5);
polygon(-74,-2.5,-78,0,-82,0,-78,-2.5);
triangle(-78, -5, -80, -7.5,-76,-5);
triangle(-76, -5,-74, -7.5,-72,-5);
triangle(-72, -5,-72, -7.5,-70,-5);

//shirt
glColor3ub(228,232,170);
polygon(-82,-35,-80,-30,-70,-30,-68,-35);
triangle(-76, -35,-75, -37.5,-74,-35);
glColor3ub(255,255,255);
polygon(-80,-30,-78,-32.5,-75,-31.25,-75,-30);
polygon(-75,-31.25,-75,-30,-70,-30,-72,-32.5);
glColor3ub(228,232,170);
triangle(-82,-35,-80,-30,-80,-35);
triangle(-70,-35,-68,-35, -70,-30);

//pants
glColor3ub(125,38,205);
polygon(-75, -37.5 ,-76, -35,-80,-35,-80,-37.5);
polygon(-74,-35,-70,-35,-70,-37.5,-75,-37.5);
polygon(-80,-37.5,-70,-37.5,-70,-45,-80,-45);
polygon(-78,-45,-76,-45,-76,-50,-78,-50);
polygon(-72,-45,-70,-45,-70,-50,-72,-50);

//shoe
glColor3ub(0,0,0);
polygon(-80,-47.5,-76,-47.5,-76,-50,-80,-50);
polygon(-74,-47.5,-70,-47.5,-70,-50,-74,-50);

//hand
glColor3ub(255,204,153);
triangle(-82,-35,-80,-35,-80,-40);
triangle(-70,-35,-68,-35, -70,-40);

glPushMatrix();
glTranslatef(submarinetx,submarinety-2.5, 0.0f);
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
glPopMatrix();

//patrick house
glColor3ub(139,0,0);
semiCircle(0,-50,20);
glColor3ub(255,215,0);
polygon(8,-25,-6,-25,-6,-22.5,8,-22.5);
triangle(-10,-25,-6,-25,-6,-22.5);
triangle(-10,-25,-4,-20,-6,-22.5);
triangle(-10,-25,-4,-27.5,-6,-25);
line(0,-30,0,-25);

//simpson
//head
glColor3ub(255,204,0);
polygon(-60,-22.5,-60,-5,-50,-5,-50,-22.5);
polygon(-60,-17.5,-62,-17.5,-62,-15,-60,-15);
triangle(-60,-20,-62,-20,-60,-17.5);
triangle(-60,-5,-60,-2.5,-59,-5);
triangle(-59,-5,-58,-2.5,-57,-5);
triangle(-57,-5,-56,-2.5,-55,-5);
triangle(-55,-5,-54,-2.5,-53,-5);
triangle(-53,-5,-52,-2.5,-51,-5);
triangle(-51,-5,-50,-2.5,-50,-5);
circle(-49,-18.75,1);
polygon(-58,-25,-58,-22.5,-50,-22.5,-50,-25);
glColor3ub(255,255,255);
circle(-60,-12.5,2);
circle(-56,-12.5,2);
glColor3ub(0,0,0);
circle(-60,-12.5,.5);
circle(-56,-12.5,.5);
glColor3ub(255,153,0);
line(-62,-20,-56,-20);


//body
glColor3ub(255,69,0);
polygon(-58,-30,-60,-37.5,-48,-37.5,-49,-30);
polygon(-58,-25,-58,-30,-50,-30,-50,-25);
triangle(-58,-25,-60,-30,-58,-30);
triangle(-49,-30,-50,-27.5,-50,-30);
glColor3ub(0,0,0);
line(-53, -30,-52, -27.5);
line(-49, -30,-53, -30);
line(-49, -30,-50, -27.5);
glColor3ub(255,204,0);
triangle(-60, -37.5,-60, -30,-58,-30);
polygon(-52, -30,-52, -37.5,-50,-37.5,-50,-30);
//pant
glColor3ub(0,154,205);
polygon(-60,-37.5,-48,-37.5,-50,-45,-60,-45);
glColor3ub(16,78,139);
line(-60,-37.5,-54,-42.5);
line(-54,-42.5,-54,-45);
glColor3ub(255,204,0);
polygon(-58, -45,-58, -50,-56, -50,-56, -45);
polygon(-52, -45,-52, -50,-50, -50,-50, -45);
glColor3ub(0,154,205);
polygon(-60, -47.5,-60, -50,-56, -50,-56,-47.5);
polygon(-54,-47.5,-54,-50,-50,-50,-50,-47.5);


glPushMatrix();
glTranslatef(spongebobtx, spongebobty, 0.0f);
//spongebob

//head
glColor3ub(255,204,0);
polygon(10,87.5,50,87.5,50,50,10,50);

//eye
glColor3ub(255,225,255);
circle(24,75,5);
glColor3ub(135,206,250);
circle(24,75,3);
glColor3ub(0,0,0);
circle(24,75,1);

glColor3ub(255,225,255);
circle(36,75,5);
glColor3ub(135,206,250);
circle(36,75,3);
glColor3ub(0,0,0);
circle(36,75,1);

//blush
glColor3ub(255,69,0);
semiCircle(20,67.5,2);
semiCircle(40,67.5,2);

glColor3ub(0,0,0);
//smile
line(40, 67.5,36, 62.5);
line(20, 67.5, 24, 62.5);

//nose
line(28, 66.25, 28, 70);
line(32, 70, 28, 70);
line(32, 66.25, 32, 70);

//teeth
glColor3ub(255,255,255);
polygon(24,62.5,28,62.5,28,57.5,24,57.5);
polygon(32,62.5,36,62.5,36,57.5,32,57.5);
glColor3b(0,0,0);
line(24,62.5,36,62.5);

//Body
glColor3ub(255,255,255);
polygon(10,50,50,50,50,42.5,10,42.5);
glColor3ub(0,0,0);
midLine(10,50,42.5,42.5);
midLine(10,50,50,50);
//pant
glColor3ub(139,69,19);
polygon(10,42.5,50,42.5,50,37.5,10,37.5);

//tie
glColor3ub(255,255,255);
triangle(20,50,24,46.125 ,28,50);
triangle(32,50,36,46.125,40,50);
glColor3ub(255,0,0);
polygon(28,50,32,50,32,47.5,28,47.5);
polygon(28,47.5,32,47.5,33,42.5,27,42.5);
triangle(27,42.5,33,42.5,30,37.5);
glColor3ub(0,0,0);
line(20, 50,24, 46.125);
line(24, 46.125,28, 50);
line(32, 50,36, 46.125);
line(36, 46.125,40, 50);
line(28,47.5,32,47.5);

glPopMatrix();

//bubbles
glPushMatrix();
glTranslatef(bubbletx,bubblety,0.0f);
glColor3ub(191,239,255);

circle(-90,-130,2);
circle(-70,-150,2);
circle(-70,50,2);
circle(100,-120,2);
circle(50,-10,2);
circle(30,60,2);
circle(-10,-10,2);
circle(-30,30,2);
circle(0,50,2);
circle(-30,-160,2);
circle(-90,0,2);
circle(-60,10,2);
circle(20,-50,2);
circle(70,0,2);
circle(80,75,2);
circle(-50,60,2);
circle(80,-70,2);
circle(0,-90,2);
circle(-90,-50,2);
circle(-70,-70,2);
circle(-90,90,2);
circle(-30,90,2);
circle(70,-130,2);
circle(50,-150,2);
glPopMatrix();
}

scene3()
{

//sky
    glColor3ub(0, 191, 255);
    polygon(-100, 0, 100, 0, 100, 100, -100, 100);


     //cloud
    glColor3ub(255,255,255);
    circle(-60,87.5,4);
    circle(-64,87.5,3);
    circle(-56,87.5,3);

     glColor3ub(255,255,255);
    circle(-20,75,8);
    circle(-28,75,5);
    circle(-12,75,5);

    glColor3ub(255,255,255);
    circle(40,80,6);
    circle(46,80,4);
    circle(34,80,4);

    glColor3ub(255,255,255);
    circle(-120,75,8);
    circle(-128,75,5);
    circle(-112,75,5);


    //road
    glColor3ub(150,150,150);
    polygon(-100, -100, 100, -100, 100, -50, -100, -50);

    //road divider
     glColor3ub(255,255,255);
    polygon(-100,-75,-80,-75,-80,-70,-100,-70);
    polygon(-60,-75,-40,-75,-40,-70,-60,-70);
    polygon(-20,-75,0,-75,0,-70,-20,-70);
    polygon(20,-75,40,-75,40,-70,20,-70);
    polygon(60,-75,80,-75,80,-70,60,-70);


    //forest
    //forest 1st layer (left to right)
    glColor3ub(0, 100, 0);
    circle(-85, 16.5, 8); //1
    circle(-65, 16.5, 8); //2
    circle(-45, 16.5, 8); //3
    circle(-25, 16.5, 8); //4
    circle(-5, 16.5, 8); //5
    circle(20, 16.5, 8); //6
    circle(40, 16.5, 8); //7
    circle(60, 16.5, 8); //8
    circle(80, 16.5, 8); //9

    //forest 2nd layer (left to right)
    glColor3ub(0, 139, 0);
    circle(-95, 10, 8); //1
    circle(-80, 10, 8); //2
    circle(-65, 10, 8); //3
    circle(-50, 10, 8); //4
    circle(-35, 10, 8); //5
    circle(-20, 10, 8); //6
    circle(-5, 10, 8); //7
    circle(10, 10, 8); //8
    circle(25, 10, 8); //9
    circle(40, 10, 8); //10
    circle(55, 10, 8); //11
    circle(70, 10, 8); //12
    circle(85, 10, 8); //13
    circle(100, 10, 8); //14

    //forest 3rd layer (left to right)
    glColor3ub(50, 205, 50);
    circle(-100, 5, 6.5); //1
    circle(-90, 5, 6.5); //2
    circle(-80, 5, 6.5); //3
    circle(-70, 5, 6.5); //4
    circle(-60, 5, 6.5); //5
    circle(-50, 5, 6.5); //6
    circle(-40, 5, 6.5); //7
    circle(-30, 5, 6.5); //8
    circle(-20, 5, 6.5); //9
    circle(-10, 5, 6.5); //10
    circle(0, 5, 6.5); //11
    circle(10, 5, 6.5); //12
    circle(20, 5, 6.5); //13
    circle(30, 5, 6.5); //14
    circle(40, 5, 6.5); //15
    circle(50, 5, 6.5); //16
    circle(60, 5, 6.5); //17
    circle(70, 5, 6.5); //18
    circle(80, 5, 6.5); //19
    circle(90, 5, 6.5); //20
    circle(100, 5, 6.5); //21

    //river
    glColor3ub(0, 191, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-100, -50);
    glVertex2f(100, -50);
    glColor3ub(16, 78, 139);
    glVertex2f(100, 0);
    glVertex2f(-100, 0);
    glEnd();

    //sky line
    glColor3ub(0, 0, 0);
    line(-100, 0, 100, 0);
    //river line
    glColor3ub(0, 0, 0);
    line(-100, -50, 100, -50);



    //ponyo boat
    //body
    glColor3ub(255, 255, 255);
    polygon(-30, -25, 10, -25, 10, -27.5, -30, -27.5);
    polygon(-30, -27.5, 10, -27.5, 10, -30, -29, -30);
    glColor3ub(205, 38, 38);
    polygon(-29, -30, 10, -30,10, -32.5, -28, -32.5);
    //pipe
    glColor3ub(205, 38, 38);
    polygon(10, -30, 14, -30, 14, -27.5, 10, -27.5);
    //upper pipe
    glColor3ub(135, 135, 135);
    polygon(0, -17.5, 2, -17.5, 2, -20, 0, -20);
    polygon(0, -20, 0, -22, 8, -22, 8, -20);
    polygon(8, -20, 8, -25, 10, -25, 10, -22.5);
    //upper part
    glColor3ub(255, 193, 37);
    triangle(-30, -25, -24, -25, -24, -22.5);
    //outline
    glColor3ub(16, 78, 139);
    polygon(-24, -25, -24, -22.5, -21, -22.5, -22, -25);
    polygon(-24, -22.5, -21, -22.5, -19, -17.5, -20, -15);
    polygon(-20, -15, -4, -15, -4, -17.5, -19, -17.5);
    polygon(-8, -17.5, -6, -17.5, -4, -25, -6, -25);
    //inner part
    glColor3ub(102, 102, 102);
    polygon(-20, -25, -18, -20, -16, -20, -18, -25);
    line(-18, -20, -10, -20);
    //fire
    glColor3ub(238, 64, 0);
    semiCircle(-13, -25, 3);
    glColor3ub(255, 153, 0);
    circle(-14, -22.5, 1.75);
    glColor3ub(255, 204, 0);
    circle(-12, -22.5, 1.75);


    //up house
    //left house
    //window wall
    glColor3ub(255, 140, 0);
    polygon(26, -40, 40, -40, 40, 0, 26, 0);
    //window wall side
    glColor3ub(255, 215, 0);
    polygon(24, -40, 26, -40, 26, 0, 24, 0);
    //door wall
    glColor3ub(255, 140, 0);
    polygon(40, -40, 62, -40, 62, 0, 40, 0);
    //left side upper wall
    glColor3ub(191, 239, 255);
    polygon(26, -7.5, 62, -7.5, 62, 0, 26, 0);
    //upper wall lines
    glColor3ub(0, 0, 0);
    line(26, -2.5, 62, -2.5);
    line(26, -5, 62, -5);

    //upper railing back side
    glColor3ub(205, 102, 0);
    polygon(26, -7.5, 62, -7.5, 62, -12.5, 26, -12.5);
    //upper railing (left to right)
    glColor3ub(255, 215, 0);
    polygon(28, -12.5, 30, -12.5, 30, -7.5, 28, -7.5);
    polygon(32, -12.5, 34, -12.5, 34, -7.5, 32, -7.5);
    polygon(36, -12.5, 38, -12.5, 38, -7.5, 36, -7.5);
    polygon(42, -12.5, 44, -12.5, 44, -7.5, 42, -7.5);
    polygon(46, -12.5, 48, -12.5, 48, -7.5, 46, -7.5);
    polygon(50, -12.5, 52, -12.5, 52, -7.5, 50, -7.5);
    polygon(54, -12.5, 56, -12.5, 56, -7.5, 54, -7.5);
    //upper railing up-line
    glColor3ub(255, 245, 10);
    line(26, -7.5, 62, -7.5);
    //upper railing lower-line
    line(26, -12.5, 62, -12.5);
    //lower railing
    glColor3ub(255, 215, 0);
    polygon(28, -40, 30, -40, 30, -35, 28, -35);
    polygon(32, -40, 34, -40, 34, -35, 32, -35);
    polygon(36, -40, 38, -40, 38, -35, 36, -35);
    //lower railing line
    glColor3ub(255, 245, 10);
    line(26, -35, 40, -35);

    //window
    //outer window
    glColor3ub(255, 215, 0);
    polygon(28, -32.5, 38, -32.5, 38, -15, 28, -15);
    //inner window
    glColor3ub(255, 246, 143);
    polygon(30, -30, 36, -30, 36, -17.5, 30, -17.5);
    //inner window bar
    glColor3ub(205, 140, 149);
    polygon(30, -25, 36, -25, 36, -22.5, 30, -22.5);
    //window bar
    glColor3ub(70, 170, 190);
    polygon(26, -35, 40, -35, 40, -32.5, 26, -32.5);

    //door
    //outer door
    glColor3ub(170, 170, 190);
    polygon(44, -40, 56, -40, 56, -17.5, 44, -17.5);
    //inner door
    glColor3ub(120, 20, 190);
    polygon(46, -40, 54, -40, 54, -20, 46, -20);

    //stairs bar
    glColor3ub(110, 190, 90);
    polygon(20, -42.5, 60, -42.5, 60, -40, 20, -40);
    //outer stairs
    glColor3ub(210, 190, 90);
    polygon(24, -50, 60, -50, 60, -42.5, 24, -42.5);
    //inner stairs
    glColor3ub(255, 245, 10);
    polygon(26, -47.5, 60, -47.5, 60, -45, 26, -45);
    //middle stairs bar
    glColor3ub(255, 255, 0);
    polygon(38, -50, 40, -50, 40, 0, 38, 0);



    //right house
    //wall
    glColor3ub(188, 238, 0);
    polygon(60, -50, 90, -50, 90, -12.5, 60, -12.5);
    //wall lines
    glColor3ub(50, 50, 50);
    line(70, -50, 70, -12.5);
    line(80, -50, 80, -12.5);

    //left window
    //outer
    glColor3ub(30, 80, 10);
    polygon(61, -35, 69, -35, 69, -20, 61, -20);
    //inner
    glColor3ub(30, 180, 10);
    polygon(62, -32.5, 68, -32.5, 68, -22.5, 62, -22.5);
    //inner bar
    glColor3ub(130, 180, 210);
    polygon(62, -28.5, 68, -28.5, 68, -26.5, 62, -26.5);
    //outer left bar
    glColor3ub(130, 180, 210);
    polygon(61, -37.5, 62, -37.5, 62, -35, 61, -35);
    //outer right bar
    glColor3ub(130, 180, 210);
    polygon(68, -37.5, 69, -37.5, 69, -35, 68, -35);

    //middle window
    //outer
    glColor3ub(30, 80, 10);
    polygon(71, -35, 79, -35, 79, -20, 71, -20);
    //inner
    glColor3ub(30, 180, 10);
    polygon(72, -32.5, 78, -32.5, 78, -22.5, 72, -22.5);
    //inner bar
    glColor3ub(130, 180, 210);
    polygon(72, -28.5, 78, -28.5, 78, -26.5, 72, -26.5);
    //outer left bar
    glColor3ub(130, 180, 210);
    polygon(71, -37.5, 72, -37.5, 72, -35, 71, -35);
    //outer right bar
    glColor3ub(130, 180, 210);
    polygon(78, -37.5, 79, -37.5, 79, -35, 78, -35);

    //left roof
    glColor3ub(139, 69, 19);
    polygon(30, 0, 68, 0, 68, 25, 30, 25);
    //left roof triangle
    triangle(20, 0, 30, 0, 30, 25);


    //right window
    //outer
    glColor3ub(30, 80, 10);
    polygon(81, -35, 89, -35, 89, -20, 81, -20);
    //inner
    glColor3ub(30, 180, 10);
    polygon(82, -32.5, 88, -32.5, 88, -22.5, 82, -22.5);
    //inner bar
    glColor3ub(130, 180, 210);
    polygon(82, -28.5, 88, -28.5, 88, -26.5, 82, -26.5);
    //outer left bar
    glColor3ub(130, 180, 210);
    polygon(81, -37.5, 82, -37.5, 82, -35, 81, -35);
    //outer right bar
    glColor3ub(130, 180, 210);
    polygon(88, -37.5, 89, -37.5, 89, -35, 88, -35);

    //window line
    glColor3ub(50, 50, 50);
    line(60, -15, 90, -15);
    line(60, -17.5, 90, -17.5);
    line(60, -40, 90, -40);
    line(60, -42.5, 90, -42.5);

    //window bar
    glColor3ub(238, 180, 34);
    polygon(60, -12.5, 90, -12.5, 90, -7.5, 60, -7.5);
    triangle(60, -12.5, 60, -7.5, 59, -7.5);//left
    triangle(90, -12.5, 90, -7.5, 91, -7.5);//right

    //2nd floor
    //lower part
    glColor3ub(255, 245, 10);
    polygon(62, -7.5, 88, -7.5, 88, -2.5, 62, -2.5);
    triangle(58, -7.5, 62, -7.5, 62, -2.5);//left
    triangle(88, -7.5, 88, -2.5, 92, -7.5);//left
    //wall
    glColor3ub(255, 245, 10);
    polygon(62, -2.5, 88, -2.5, 88, 12.5, 62, 12.5);
    triangle(62, 12.5, 88, 12.5, 75, 37.5);
    //window
    //outer window
    glColor3ub(50, 50, 50);
    polygon(68, 0, 82, 0, 82, 17.5, 68, 17.5);
    //inner window
    glColor3ub(250, 250, 250);
    polygon(70, 2.5, 80, 2.5, 80, 15, 70, 15);
    //inner window bar
    glColor3ub(50, 50, 50);
    polygon(70, 7.5, 80, 7.5, 80, 10, 70, 10);
    //window bar
    glColor3ub(150, 150, 150);
    polygon(66, -2.5, 84, -2.5, 84, 0, 66, 0);
    //outer bar
    glColor3ub(250, 50, 150);
    polygon(68, -5, 70, -5, 70, -2.5, 68, -2.5);//left
    polygon(80, -5, 82, -5, 82, -2.5, 80, -2.5);//right
    //roof left
    glColor3ub(250, 50, 150);
    polygon(56, 7.5, 60, 7.5, 75, 32.5, 75, 37.5);
    //roof right
    polygon(94, 7.5, 90, 7.5, 75, 32.5, 75, 37.5);
    //roof house
    //wall
    glColor3ub(250, 50, 150);
    polygon(34, 10, 46, 10, 46, 20, 34, 20);
    triangle(34, 20, 46, 20, 40, 34);
    //window
    //outer window
    glColor3ub(50, 50, 150);
    polygon(36, 13.75, 44, 13.75, 44, 22.5, 36, 22.5);
    //inner window
    glColor3ub(50, 50, 50);
    polygon(37, 15.25, 43, 15.25, 43, 21, 37, 21);
    glColor3ub(250, 250, 250);
    line(37, 18.125, 43, 18.125);
    //window bar
    glColor3ub(250, 250, 250);
    polygon(36, 12.5, 38, 12.5, 38, 13.75, 36, 13.75);
    polygon(42, 12.5, 44, 12.5, 44, 13.75, 42, 13.75);
    //left roof
    glColor3ub(50, 150, 250);
    polygon(32, 20, 34, 20, 40, 32.5, 40, 35);
    //right roof
    polygon(46, 20, 48, 20, 40, 35, 40, 32.5);



    //chimney
    glColor3ub(50, 50, 150);
    polygon(54, 25, 60, 25, 60, 32.5, 54, 32.5);
    glColor3ub(150, 150, 150);
    polygon(53, 32.5, 61, 32.5, 61, 33.75, 53, 33.75);




    //street lamp
    //lower part
    glColor3ub(128,0,0);
    polygon(-98,-50,-98,-45,-92,-45,-92,-50);
    polygon(-98,-45,-96,-42.5,-94,-42.5,-92,-45);
    polygon(-96,-42.5,-96,0,-94,0,-94,-42.5);
    polygon(-96,0,-98,2.5,-92,2.5,-94,0);
    //light
    glColor3ub(255,255,153);
    polygon(-96,2.5,-98,7.5,-92,7.5,-94,2.5);
    //upper part
    glColor3ub(128,0,0);
    polygon(-97,7.5,-97,10,-93,10,-93,7.5);
    triangle(-96,10,-95,12.5,-94,10);




    //vector house
    //boundary
    glColor3ub(240, 255, 240);
    polygon(-72, 0, -8, 0, -8, 5, -72, 5);
    //triangle
    glColor3ub(24, 116, 205);
    triangle(-68, 5, -12, 5, -40, 50);
    //house circle
    glColor3ub(255, 255, 255);
    semiCircle(-45, 22.5, 13);
    polygon(-58, 22.5, -58, 12.5, -32, 12.5, -32, 22.5);
    //house wall
    glColor3ub(205, 201, 201);
    polygon(-54, 5, -36, 5, -36, 12.5, -54, 12.5);
    //gate
    glColor3ub(240, 255, 240);
    semiCircle(-45, 5, 5);
    glColor3ub(255, 127, 36);
    polygon(-52, 0, -50, 0, -50, 10, -52, 10);
     polygon(-38, 0, -40, 0, -40, 10, -38, 10);
     //lower v
     polygon(-42, 7.5, -44, 7.5, -45, 2.5, -44, 0);
     polygon(-46, 7.5, -48, 7.5, -46, 0, -45, 2.5);
     triangle(-44, 0, -46, 0, -45, 2.5);
     //upper v
     polygon(-40, 40, -42, 40, -45, 32.5, -44, 30);
     polygon(-48, 40, -50, 40, -46, 30, -45, 32.5);
     triangle(-44, 30, -46, 30, -45, 32.5);



     //simpsons car
     //body
     glColor3ub(255, 110, 180);
     polygon(32, -87.5, 96, -87.5, 96, -75, 32, -75);
     //side part
     glColor3ub(191, 239, 255);
     polygon(30, -87.5, 32, -87.5, 32, -75, 30, -75);
     polygon(96, -87.5, 98, -87.5, 98, -75, 96, -75);
     //upper body
     glColor3ub(255, 110, 180);
     polygon(44, -75, 86, -75, 80, -62.5, 54, -62.5);
     //left window
     glColor3ub(224, 255, 255);
     polygon(46, -75, 64, -75, 64, -65, 54, -65);
     //right window
     polygon(68, -75, 84, -75, 78, -65, 68, -65);
     //left door
     glColor3ub(238, 106, 167);
     polygon(46, -85, 84, -85, 84, -75, 46, -75);
     glColor3ub(255, 110, 180);
     semiCircle(43, -87.5, 8);//left
     semiCircle(87, -87.5, 8);//right
     //door divider
     glColor3ub(50, 10, 50);
     line(66, -62.5, 66, -85);
     //door handle
     glColor3ub(130, 130, 130);
     polygon(60, -78.75, 64, -78.75, 64, -76.25, 60, -76.25);
     polygon(78, -78.75, 82, -78.75, 82, -76.25, 78, -76.25);
     //headlight
     glColor3ub(173, 216, 230);
     polygon(28, -87.5, 34, -87.5, 34, -82.5, 28, -82.5);
     //left tire
     //shade
     glColor3ub(64, 64, 64);
     semiCircle(43, -87.5, 7);
     glColor3ub(99, 99, 99);
     circle(43, -87.5, 5);
     glColor3ub(191, 239, 255);
     circle(43, -87.5, 2.5);
     //right tire
     //shade
     glColor3ub(64, 64, 64);
     semiCircle(87, -87.5, 7);
     glColor3ub(99, 99, 99);
     circle(87, -87.5, 5);
     glColor3ub(191, 239, 255);
     circle(87, -87.5, 2.5);
     //door line
     glColor3ub(250, 220, 250);
     line(34, -77.5, 42, -77.5);




     //angry bird
     //tail
     glColor3ub(0, 0, 0);
     triangle(-6, 55, 4.5, 62.5, 2, 55);
     triangle(-3, 57.5, 0, 58, -4, 62.5);
     //body
     glColor3ub(255, 225, 0);
     polygon(2, 52.5, 34, 52.5, 34, 55, 2, 55);
     triangle(2, 55, 34, 55, 20, 77.5);
     //stomach
     glColor3ub(255, 225, 255);
     semiCircle(23, 52.5, 4);
     //eye
     glColor3ub(0, 0, 0);
     circle(15, 58.75, 2.5);//left
     circle(29, 58.75, 2.5);//right
     //eye ball
     glColor3ub(250, 250, 250);
     circle(15, 58.75, 1);//left
     circle(29, 58.75, 1);//right
     //brows
     glColor3ub(238, 44, 44);
     polygon(12, 62.5, 20, 57.5, 20, 60, 14, 64);//left
     polygon(26, 57.5, 32, 65, 30, 66.25, 24, 60);//right
     //mouth
     glColor3ub(255, 127, 36);
     triangle(21, 55, 23, 53.75, 25, 55);
     //lips
     glColor3ub(255, 127, 36);
     triangle(20, 53.75, 24.5, 57.5, 22, 57.5);//left
     triangle(21, 55, 30, 55, 24, 57.5);//right
     //hair
     glColor3ub(0, 0, 0);
     polygon(20, 77.5, 21, 87.5, 23, 77.5, 22, 75);
     triangle(18, 75, 14, 77.5, 20, 77.5);
     polygon(17, 77.5, 16, 82.5, 21, 80, 20, 77.5);
     triangle(22, 80, 24, 82.5, 22, 75);



     //imposter
     //body
     glColor3ub(0, 135, 0);
     polygon(-60, -45, -46, -45, -46, -25, -60, -25);
     semiCircle(-53, -25, 7);
     //leg
     polygon(-60, -50, -56, -50, -56, -45, -60, -45);//left
     polygon(-50, -50, -46, -50, -46, -45, -50, -45);//right
     //bag
     glColor3ub(0, 100, 0);
     polygon(-64, -42.5, -60, -42.5, -60, -27.5, -64, -27.5);
     //glass
     glColor3ub(220, 220, 220);
     polygon(-51, -35, -46, -35, -46, -27.5, -51, -27.5);
     circle(-50, -31.25, 3.75);
     //hand
     glColor3ub(0, 100, 0);
     circle(-43, -40, 2);


     //minion
     //head
     glColor3ub(255, 255, 0);
     semiCircle(-75, -30, 5);
     polygon(-80, -30, -80, -45, -70, -45, -70, -30);
     //hand
     triangle(-80, -37.5, -82, -41.25, -80, -45);
     triangle(-70, -37.5, -68, -41.25, -70, -45);
     //eye frame
     glColor3ub(0, 0, 0);
     polygon(-80, -31, -78, -31, -78, -33.5, -80, -33.5);
     polygon(-72, -31, -70, -31, -70, -33.5, -72, -33.5);
      glColor3ub(133, 133, 133);
     circle(-75, -32.5, 3.5);
     glColor3ub(255, 255, 255);
     circle(-75, -32.5, 3);
     //eye
     glColor3ub(0, 0, 0);
     circle(-74, -32.5, 1.5);
     glColor3ub(255, 255, 0);
     semiCircle(-75, -32.5, 3);
     //body
     glColor3ub(54, 100, 139);
     polygon(-80, -35, -80, -37.5, -78, -40, -78, -37.5);
     polygon(-70, -35, -70, -37.5, -72, -40, -72, -37.5);
     polygon(-78, -37.5, -78, -42.5, -72, -42.5, -72, -37.5);
     polygon(-80, -42.5, -80, -45, -70, -45, -70, -42.5);
     glColor3ub(255, 204, 0);
     line(-80, -37.5, -80, -42.5);
     line(-70, -37.5, -70, -42.5);
     //leg
     glColor3ub(54, 100, 139);
     polygon(-78, -45, -78, -47.5, -76, -47.5, -76, -45);
     polygon(-74, -45, -74, -47.5, -72, -47.5, -72, -45);
     //shoe
     glColor3ub(10, 280, 0);
     polygon(-78, -47.5, -78, -50, -75, -50, -75, -47.5);
     polygon(-74, -47.5, -74, -50, -71, -50, -71, -47.5);





     //pokemon ball
     glColor3ub(255, 255, 255);
     circle(13, -44.25, 5.5);//outer part
     glColor3ub(255, 0, 0);
     semiCircle(13, -44.25, 5.5);//outer part
     glColor3ub(0, 0, 0);
     polygon(7.5, -45.5, 18.5, -45.5, 18.5, -43.5, 7.5, -43.5);//bar
glColor3ub(0, 0, 0);
     circle(13, -44.25, 3);//outer part boundary
     glColor3ub(255, 255, 255);
     circle(13, -44.25, 2.5);//outer part
     glColor3ub(0, 0, 0);
     circle(13, -44.25, 1);//outer part
}
scene4()
{

}
void display() {

     glClearColor(0.4f,0.8f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

if(playScene1==1)
{
    scene1();
}
else if(playScene2==1)
{
    scene2();
}
else if(playScene3==1)
{
    scene3();
}
    glFlush();
}
void update(int value) {

if(playScene1==1)
{
    cartx +=1.0f;
     cloudtx +=.1f;
     loontx+=.1f;
     loonsx -= 0.001f;
     loonsy -= 0.001f;

        if(cartx>200.0f){
            cartx= -130.0f;

        }
        if(cloudtx>50.0f){
            cloudtx= 0.0f;

        }
        if(loontx>60)
        {

            loontx=0.0f;
             loonsx = 1.0f;
     loonsy = 1.0f;
        }
         if (jumpflag) {
        jump -= 0.1f;
        jumpty += jump;


        if (jumpty <= 0.0f) {
            jumpty= 0.0f;
            jump = 0.0f;
            jumpflag = false;
        }
    }
}
    if(playScene2== 1 && runSubmarine==1){
        submarinetx -=1.0f;
    bubblety +=.1f;

        if(submarinetx<-180.0f){
            submarinetx = 80.0f;

        }

        if(bubblety>100.0f){
            bubblety = -50.0f;

        }
    }
if(playScene3==1)
{


}

if(playScene4==1)
{


}
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}
void playMusic()
{
   PlaySound(TEXT("C:\\Users\\mahim\\Desktop\\Files\\CSE\\Computer Graphics\\CODES\\Toonverse\\bgmusic.wav"),
          NULL,
          SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void stopMusic()
{
    PlaySound(NULL, 0, 0);
}
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
    case '1':
        playScene1 = 1;
        playScene2 = 0;
         playScene3 = 0;
          playScene4 = 0;
        break;
    case '2':
         playScene1 = 0;
        playScene2 = 1;
         playScene3 = 0;
          playScene4 = 0;
          runSubmarine=1;
        break;

    case '3':
         playScene1 = 0;
        playScene2 = 0;
         playScene3 = 1;
          playScene4 = 0;
        break;

    case '4':
        playScene1 = 0;
        playScene2 = 0;
         playScene3 = 0;
          playScene4 = 1;
        break;
        case 'w': if(playScene2==1) {
            if(spongebobty<15) {spongebobty += 7.5f;}
            }
            break;
        case 's': if(playScene2==1){
              if(spongebobty>-135) {spongebobty -= 7.5f;}
            }
            break;
        case 'a': if(playScene2==1){
        if(spongebobtx>-112.5) {spongebobtx -= 7.5f;}
            }
            break;
        case 'd': if(playScene2==1){
            if(spongebobtx<52.5) {spongebobtx += 7.5f;}
            }
            break;
            case ' ':
                if (!jumpflag) {
            jumpflag = true;
            jump= 1 ;
        };
         break;
         case 'o':
              if(musicOn==false)
    {
        playMusic();
        musicOn = true;

    }
         break;
         case 'f':
    if(musicOn)
    {
        stopMusic();
        musicOn = false;

    }
    break;
         case 'x':  exit(0);
         break;

    }
    glutPostRedisplay();
}
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

}


int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);

    glutInitWindowSize(1000, 768);
    glutInitWindowPosition(250,0);

    glutCreateWindow("Toonverse");


    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);
    cout<<"Press '1' for scene 1."<<endl;
    cout<<"Press SPACE to Jump!!."<<endl;
    cout<<endl;
      cout<<"Press '2' for scene 2."<<endl;
       cout<<"To move SpongeBob:"<<endl;
      cout<<"-Press 'w' for UP."<<endl;
      cout<<"-Press 'a' for LEFT."<<endl;
      cout<<"-Press 'd' for RIGHT."<<endl;
      cout<<"-Press 's' for DOWN."<<endl;
         cout<<endl;
        cout<<"Press '3' for scene 3."<<endl;
           cout<<endl;
           cout<<"Press '4' for scene 4.";
         playMusic();
    glutMainLoop();

    return 0;
}
