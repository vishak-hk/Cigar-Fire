#include<stdio.h>
#include<GL/glut.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>

float house[11][2] = {{0,0},{-20,137},{0,150},{75,200},{150,150},{170,130},{150,0},
        {300,180},{350,150},{330,150},{330,70}};
float door[4][2] = {{55,0},{95,0},{95,75},{55,75}};

float h=100,k=100,theta,a,b;
const float DEG2RAD = 3.14159/180;
int man=1;
int fire=0;
int rain=0;
float n=0.0;
float o=0.0;
float s=0.0;
float r=0.0;

int m=0;
int firecount=0;
int raincount=601;
int mancount=0;
int manposition=850;

#define GroundY 100
int ldisp = 0;

typedef struct
{
        float x;
        float y;
}point;
point p0,p1,p2;



void draw_pixel(GLint cx, GLint cy)
{

        glBegin(GL_POINTS);
        glVertex2i(cx,cy);
        glEnd();
}
//circle
void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
        draw_pixel(x+h,y+k);
        draw_pixel(-x+h,y+k);
        draw_pixel(x+h,-y+k);
        draw_pixel(-x+h,-y+k);
        draw_pixel(y+h,x+k);
        draw_pixel(-y+h,x+k);
        draw_pixel(y+h,-x+k);
        draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
        GLint d=1-r, x=0, y=r;
        while(y>x)
        {
                plotpixels(h,k,x,y);
                if(d<0) d+=2*x+3;
                else
                {
                        d+=2*(x-y)+5;
                        --y;
                }
                ++x;
        }
        plotpixels(h,k,x,y);
}




//function to draw circle------
void drawCircle(float radius,float xc,float yc)
{
        int i;
        glBegin(GL_POLYGON);

        for (i=0; i < 360; i++)
        {
                float degInRad = i*DEG2RAD;
                glVertex2f(cos(degInRad)*radius+xc,sin(degInRad)*radius+yc);
        }

        glEnd();
}

//function to draw a line-------------------------
void line(int x1, int y1, int x2, int y2)
{
        glBegin(GL_LINES);
        glVertex2f(x2, y2);
        glVertex2f(x1, y1);
        glEnd();
}

//function to draw tree---
void drawTree(int xc,int yc) {
        //tree1
        glColor3f(0.52,0.37,0.26);
        glBegin(GL_POLYGON);
        glVertex2f(-80+xc,0+yc);
        glVertex2f(-45+xc,0+yc);
        glVertex2f(-48+xc,75+yc);
        glVertex2f(-77+xc,75+yc);
        glEnd();

        glColor3f(0.1,0.9,0.3);
        glBegin(GL_POLYGON);
        glVertex2f(-120+xc,65+yc);
        glVertex2f(-63+xc,92+yc);
        glVertex2f(-15+xc,62+yc);
        glVertex2f(-63+xc,72+yc);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-115+xc,82+yc);
        glVertex2f(-63+xc,112+yc);
        glVertex2f(-20+xc,80+yc);
        glVertex2f(-63+xc,92+yc);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(-115+xc,96+yc);
        glVertex2f(-63+xc,125+yc);
        glVertex2f(-20+xc,96+yc);
        glVertex2f(-63+xc,105+yc);
        glEnd();

        glColor3f(0.1,0.9,0.3);
        glBegin(GL_POLYGON);
        glVertex2f(-110+xc,109+yc);
        glVertex2f(-63+xc,131+yc);
        glVertex2f(-25+xc,109+yc);
        glVertex2f(-63+xc,111+yc);
        glEnd();

        glColor3f(0.1,0.9,0.3);
        glBegin(GL_POLYGON);
        glVertex2f(-120+xc,65+yc);
        glVertex2f(-63+xc,92+yc);
        glVertex2f(-15+xc,62+yc);
        glVertex2f(-63+xc,72+yc);
        glEnd();
}

//second type of tree funtion
void treeTwo(int xc,int yc)
{
        glColor3f(0.5f, 0.35f, 0.05);
        glBegin(GL_POLYGON);
        glVertex2f(0+ xc,0+ yc);
        glVertex2f(0+ xc,80+ yc);
        glVertex2f(30+ xc,80+ yc);
        glVertex2f(30+ xc,0+ yc);
        glEnd();

        glColor3f(0.0,1.0,0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(-40+ xc,70+ yc);
        glVertex2f(15+ xc,80+ yc);
        glVertex2f(15+ xc,150+ yc);
        glEnd();

        glColor3f(0.0,1.0,0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(15+ xc,80+ yc);
        glVertex2f(75+ xc,70+ yc);
        glVertex2f(15+ xc,150+ yc);
        glEnd();

        glColor3f(0.0,1.0,0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(15+ xc,130+ yc);
        glVertex2f(-40+ xc,110+ yc);
        glVertex2f(15+ xc,210+ yc);
        glEnd();

        glColor3f(0.0,1.0,0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(15+ xc,130+ yc);
        glVertex2f(75+ xc,110+ yc);
        glVertex2f(15+ xc,210+ yc);
        glEnd();

        glColor3f(0.0,1.0,0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(15+ xc,190+ yc);
        glVertex2f(75+ xc,140+ yc);
        glVertex2f(15+ xc,240+ yc);
        glEnd();

        glColor3f(0.0,1.0,0.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(15+ xc,190+ yc);
        glVertex2f(-40+ xc,140+ yc);
        glVertex2f(15+ xc,240+ yc);
        glEnd();
}

void treeThree(int xc,int yc)
{
        glColor3f(0.4f, 0.35f, 0.05);
        glBegin(GL_POLYGON);
        glVertex2f(0+ xc,0+ yc);
        glVertex2f(0+ xc,80+ yc);
        glVertex2f(30+ xc,80+ yc);
        glVertex2f(30+ xc,0+ yc);
        glEnd();

        glColor3f(0.2,0.502,0);
        drawCircle(50,-15+xc,100+yc);
        drawCircle(50,40+xc,100+yc);
        drawCircle(50,12.5+xc,160+yc);
}



//draw the land---------------------------------------------------------------------------------------
void land() {


        //river blue
        glBegin(GL_POLYGON);
        glColor3f(0,0,1);
        glVertex2f(-700.0,-200.0);
        glVertex2f(1000.0,-200.0);
        glVertex2f(1000.0,-600.0);
        glVertex2f(-700.0,-600.0);
        glEnd();
        glFlush();
        //river blue ends here

        glBegin(GL_POLYGON);
        glColor3f(0,0.847058824,0.396078431);
        glVertex2f(-700,100);
        glVertex2f(1000,100);
        glColor3f(0.666666,0.486274,0);
        glVertex2f(1000.0,-200.0);
        glVertex2f(-700.0,-200.0);
        glEnd();
        glFlush();

        glBegin(GL_POLYGON);
        glColor3f(0.666666,0.486274,0);
        glVertex2f(-700.0,-200.0);
        glVertex2f(1000.0,-200.0);

        glColor3f(0.490196078,0.247058824,0.141176471);
        glVertex2f(600.0,-400.0);
        glColor3f(0.490196078,0.8,0.141176471);
        glVertex2f(500.0,-400.0);
        glVertex2f(100.0,-360.0);
        glVertex2f(-300.0,-250.0);
        glVertex2f(-700.0,-400.0);

        glEnd();
        glFlush();

        glBegin(GL_POLYGON);
        glColor3f(0.333333,0.4,0);
        glVertex2f(550.0,-450.0);
        glVertex2f(150.0,-400.0);
        glVertex2f(-350.0,-300.0);
        //glVertex2f(-700.0,-700.0);
        glVertex2f(-750.0,-450.0);

        glEnd();
        glFlush();
}

void drawMan(int x, int y, int cigar)
{
        glColor3f(0,0,0);
        drawCircle(20, x, y);
        glLineWidth(5);

        //Neck
        line(x, y-18, x, y-40);

        //Arm 1
        if (cigar == 1)
        {
                line(x, y-40, x-40, y-15);
                line(x-40, y-15, x-10, y-10);
                //Cigar
                glColor3f(1,0,0);
                line(x-10, y-4, x-30, y-1);
        }
        else
        {
                line(x, y-40, x-20, y-70);
        }

        glColor3f(0,0,0);
        //Arm 2
        line(x, y-40, x+20, y-70);

        //Body
        line(x, y-40, x, y-90);

        //Legs
        line(x, y-90, x-20, y-150);
        line(x, y-90, x+20, y-150);

}

//function to draw Forest------------------------------------------------------------
void drawForest()
{
        int l;

        //drawhouse();
        //tree type 1
        if((firecount<1100)&&(raincount>600))
        {
                drawTree(0,0);
                treeTwo(0,0);

                drawTree(50,-20);
                treeTwo(70,40);
                treeThree(160,0);
                drawTree(200,-50);
                treeTwo(200,40);
                drawTree(-200,-20);
                treeTwo(-200,100);
                drawTree(-300,50);
                treeTwo(750,50);
                drawTree(-400,100);
                treeTwo(-2250,100);
                drawTree(500,-20);
                treeTwo(-340,50);
                drawTree(400,80);
                treeTwo(-440,-50);

                drawTree(520,-40);
                treeTwo(-360,70);
                drawTree(420,100);
                treeTwo(-460,-70);

                //treeThree(290,130);
                drawTree(650,-150);
                //treeTwo(-490,200);
                treeThree(60,-100);
                treeThree(-80,-200);
                treeThree(-200,-260);
                treeThree(-200,-40);
                treeThree(200,-260);
                treeThree(400,-260);
                treeThree(-450,-170);
                treeThree(-550,70);
                treeThree(750,70);
                treeThree(750,-170);

                drawTree(700,-260);
                drawTree(700,-120);
                drawTree(700,-100);

                treeTwo(550,50);
               // treeTwo(250,-70);
                treeTwo(-350,-170);
                treeTwo(-550,-170);
                treeTwo(50,-300);
        }

        if (man == 1)
        {
                if (mancount < 300)
                {
                        manposition -= (1.8);
                        drawMan(manposition, 150, 1);
                }
                else if ((mancount >= 300) && (mancount < 580))
                {
                        drawMan(manposition, 150, 1);
                }
                else
                {
                        manposition += (2);
                        drawMan(manposition, 150, 0);
                }
        }

        if(fire==1)
        {
                for(l=0;l<=20;l++)
                {
                        glColor3f(1.0,1.0,0.0);
                        draw_circle(200+n,100+o,l);
                        draw_circle(200-40+n,100+15+o,l);
                        glColor3f(1,1,0.0);
                        draw_circle(200-40+n,100-15+o,l);
                        glColor3f(1.0,1,0.0);
                        draw_circle(200-20+n,100-25+o,l);
                        glColor3f(1,7.0,0.0);
                        draw_circle(200-20+n,100+25+o,l);
                        glColor3f(1,1,0.0);
                        draw_circle(200-10+n,100+o,l);
                        glColor3f(1.0,0.6,0.0);
                        draw_circle(200-10+n,100+o,l);
                        glColor3f(1.0,1,0.0);
                        draw_circle(200+n,100+25+o,l);
                        glColor3f(1.0,0.7,0);
                        draw_circle(200+n,100+25+o,l);
                        glColor3f(1,1.0,0.0);
                        draw_circle(200+n,100-35+o,l);
                        glColor3f(1,0.5,0.0);
                        draw_circle(200+n,100-35+o,l);
                        glColor3f(1.0,0.6,0.0);
                        draw_circle(200-60+n,100+o,l);
                        glColor3f(1,1.0,0.0);
                        draw_circle(200-10+n,100+o,l);


                        //smoke 1
                        glColor3f(0.7,0.7,0.7);
                        draw_circle(200-40+n+80,200+15+s+o-100,l);
                        draw_circle(200-40+n+80,200-15-s+o-100,l);
                        draw_circle(200-50+n+80,200+18+s+o-100,l);
                        draw_circle(200-50+n+80,200-18-s+o-100,l);
                        draw_circle(200+n-20+80,200-25-s+o-100,l);
                        draw_circle(200+n-20+80,200+25+s+o-100,l);
                        draw_circle(200+n+80,200-35-s+o-100,l);
                        draw_circle(200+n+80,200+35+s+o-100,l);
                        draw_circle(200-40+n+80,200-s+o-100,l);
                        draw_circle(200+n-20+80,200+s+o-100,l);
                        draw_circle(200+n+80,200-s+o-100,l);
                }
                if(firecount > 500)
                {
                        for(l=0;l<=20;l++)
                        {
                                glColor3f(1.0,1.0,0.0);
                                draw_circle(50+n,100+o,l);
                                draw_circle(50-40+n,100+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(50-40+n,100-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(50-20+n,100-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(50-20+n,100+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(50-10+n,100+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(50-10+n,100+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(50+n,100+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(50+n,100+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(50+n,100-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(50+n,100-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(50-60+n,100+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(50-10+n,100+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(50-40+n+80,200+15+s+o-100,l);
                                draw_circle(50-40+n+80,200-15-s+o-100,l);
                                draw_circle(50-50+n+80,200+18+s+o-100,l);
                                draw_circle(50-50+n+80,200-18-s+o-100,l);
                                draw_circle(50+n-20+80,200-25-s+o-100,l);
                                draw_circle(50+n-20+80,200+25+s+o-100,l);
                                draw_circle(50+n+80,200-35-s+o-100,l);
                                draw_circle(50+n+80,200+35+s+o-100,l);
                                draw_circle(50-40+n+80,200-s+o-100,l);
                                draw_circle(50+n-20+80,200+s+o-100,l);
                                draw_circle(50+n+80,200-s+o-100,l);
                        }
                }

                if(firecount > 700)
                {
                        for(l=0;l<=20;l++)
                        {

                                ////////////////////11111111///////////////////////////////////////////////////
                                glColor3f(1.0,1.0,0.0);
                                draw_circle(-50+n,100+o,l);
                                draw_circle(-50-40+n,100+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(-50-40+n,100-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(-50-20+n,100-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(-50-20+n,100+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(-50-10+n,100+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(-50-10+n,100+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(-50+n,100+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(-50+n,100+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(-50+n,100-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(-50+n,100-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(-50-60+n,100+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(-50-10+n,100+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(-50-40+n+80,200+15+s+o-100,l);
                                draw_circle(-50-40+n+80,200-15-s+o-100,l);
                                draw_circle(-50-50+n+80,200+18+s+o-100,l);
                                draw_circle(-50-50+n+80,200-18-s+o-100,l);
                                draw_circle(-50+n-20+80,200-25-s+o-100,l);
                                draw_circle(-50+n-20+80,200+25+s+o-100,l);
                                draw_circle(-50+n+80,200-35-s+o-100,l);
                                draw_circle(-50+n+80,200+35+s+o-100,l);
                                draw_circle(-50-40+n+80,200-s+o-100,l);
                                draw_circle(-50+n-20+80,200+s+o-100,l);
                                draw_circle(-50+n+80,200-s+o-100,l);



                                ////////////////22222222222222/////////////////////////////////////////////
                                glColor3f(1.0,1.0,0.0);
                                draw_circle(-100+n,100+o,l);
                                draw_circle(-100-40+n,00+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(-100-40+n,00-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(-100-20+n,00-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(-100-20+n,00+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(-100-10+n,00+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(-100-10+n,00+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(-100+n,00+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(-100+n,00+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(-100+n,00-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(-100+n,00-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(-100-60+n,00+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(-100-10+n,00+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(-100-40+n+80,100+15+s+o-100,l);
                                draw_circle(-100-40+n+80,100-15-s+o-100,l);
                                draw_circle(-100-50+n+80,100+18+s+o-100,l);
                                draw_circle(-100-50+n+80,100-18-s+o-100,l);
                                draw_circle(-100+n-20+80,100-25-s+o-100,l);
                                draw_circle(-100+n-20+80,100+25+s+o-100,l);
                                draw_circle(-100+n+80,100-35-s+o-100,l);
                                draw_circle(-100+n+80,100+35+s+o-100,l);
                                draw_circle(-100-40+n+80,100-s+o-100,l);
                                draw_circle(-100+n-20+80,100+s+o-100,l);
                                draw_circle(-100+n+80,100-s+o-100,l);


                                ///////////////33333333333333///////////////////////////////////////////////////////////

                                glColor3f(1.0,1.0,0.0);
                                draw_circle(150+n,200+o,l);
                                draw_circle(150-40+n,200+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(150-40+n,200-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(150-20+n,200-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(150-20+n,200+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(150-10+n,200+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(150-10+n,200+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(150+n,200+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(150+n,200+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(150+n,200-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(150+n,200-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(150-60+n,200+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(150-10+n,200+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(150-40+n+80,300+15+s+o-100,l);
                                draw_circle(150-40+n+80,300-15-s+o-100,l);
                                draw_circle(150-50+n+80,300+18+s+o-100,l);
                                draw_circle(150-50+n+80,300-18-s+o-100,l);
                                draw_circle(150+n-20+80,300-25-s+o-100,l);
                                draw_circle(150+n-20+80,300+25+s+o-100,l);
                                draw_circle(150+n+80,300-35-s+o-100,l);
                                draw_circle(150+n+80,300+35+s+o-100,l);
                                draw_circle(150-40+n+80,300-s+o-100,l);
                                draw_circle(150+n-20+80,300+s+o-100,l);
                                draw_circle(150+n+80,300-s+o-100,l);

                                /////////////////////44444444444444////////////////////////////////////////////////////////////////

                                glColor3f(1.0,1.0,0.0);
                                draw_circle(350+n,-150+o,l);
                                draw_circle(350-40+n,-150+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(350-40+n,-150-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(350-20+n,-150-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(350-20+n,-150+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(350-10+n,-150+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(350-10+n,-150+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(350+n,-150+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(350+n,-150+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(350+n,-150-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(350+n,-150-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(350-60+n,-150+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(350-10+n,-150+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(350-40+n+80,-50+15+s+o-100,l);
                                draw_circle(350-40+n+80,-50-15-s+o-100,l);
                                draw_circle(350-50+n+80,-50+18+s+o-100,l);
                                draw_circle(350-50+n+80,-50-18-s+o-100,l);
                                draw_circle(350+n-20+80,-50-25-s+o-100,l);
                                draw_circle(350+n-20+80,-50+25+s+o-100,l);
                                draw_circle(350+n+80,-50-35-s+o-100,l);
                                draw_circle(350+n+80,-50+35+s+o-100,l);
                                draw_circle(350-40+n+80,-50-s+o-100,l);
                                draw_circle(350+n-20+80,-50+s+o-100,l);
                                draw_circle(350+n+80,-50-s+o-100,l);

                                /////////////////////55555555555555555//////////////////////////////////////////////////////////////

                                glColor3f(1.0,1.0,0.0);
                                draw_circle(0+n,-150+o,l);
                                draw_circle(0-40+n,-150+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(0-40+n,-150-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(0-20+n,-150-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(0-20+n,-150+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(0-10+n,-150+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(0-10+n,-150+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(0+n,-150+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(0+n,-150+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(0+n,-150-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(0+n,-150-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(0-60+n,-150+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(0-10+n,-150+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(0-40+n+80,-50+15+s+o-100,l);
                                draw_circle(0-40+n+80,-50-15-s+o-100,l);
                                draw_circle(0-50+n+80,-50+18+s+o-100,l);
                                draw_circle(0-50+n+80,-50-18-s+o-100,l);
                                draw_circle(0+n-20+80,-50-25-s+o-100,l);
                                draw_circle(0+n-20+80,-50+25+s+o-100,l);
                                draw_circle(0+n+80,-50-35-s+o-100,l);
                                draw_circle(0+n+80,-50+35+s+o-100,l);
                                draw_circle(0-40+n+80,-50-s+o-100,l);
                                draw_circle(0+n-20+80,-50+s+o-100,l);
                                draw_circle(0+n+80,-50-s+o-100,l);
                        }
                }

                if(firecount > 900)
                {
                        for(l=0;l<=20;l++)
                        {
                                glColor3f(1.0,1.0,0.0);
                                draw_circle(-200+n,-150+o,l);
                                draw_circle(-200-40+n,-150+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(-200-40+n,-150-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(-200-20+n,-150-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(-200-20+n,-150+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(-200-10+n,-150+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(-200-10+n,-150+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(-200+n,-150+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(-200+n,-150+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(-200+n,-150-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(-200+n,-150-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(-200-60+n,-150+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(-200-10+n,-150+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(-200-40+n+80,-50+15+s+o-100,l);
                                draw_circle(-200-40+n+80,-50-15-s+o-100,l);
                                draw_circle(-200-50+n+80,-50+18+s+o-100,l);
                                draw_circle(-200-50+n+80,-50-18-s+o-100,l);
                                draw_circle(-200+n-20+80,-50-25-s+o-100,l);
                                draw_circle(-200+n-20+80,-50+25+s+o-100,l);
                                draw_circle(-200+n+80,-50-35-s+o-100,l);
                                draw_circle(-200+n+80,-50+35+s+o-100,l);
                                draw_circle(-200-40+n+80,-50-s+o-100,l);
                                draw_circle(-200+n-20+80,-50+s+o-100,l);
                                draw_circle(-200+n+80,-50-s+o-100,l);

                                /////////////////////////2222222/////////////////////////////
                                glColor3f(1.0,1.0,0.0);
                                draw_circle(-300+n,-100+o,l);
                                draw_circle(-300-40+n,-100+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(-300-40+n,-100-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(-300-20+n,-100-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(-300-20+n,-100+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(-300-10+n,-100+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(-300-10+n,-100+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(-300+n,-100+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(-300+n,-100+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(-300+n,-100-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(-300+n,-100-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(-300-60+n,-100+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(-300-10+n,-100+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(-300-40+n+80,0+15+s+o-100,l);
                                draw_circle(-300-40+n+80,0-15-s+o-100,l);
                                draw_circle(-300-50+n+80,0+18+s+o-100,l);
                                draw_circle(-300-50+n+80,0-18-s+o-100,l);
                                draw_circle(-300+n-20+80,0-25-s+o-100,l);
                                draw_circle(-300+n-20+80,0+25+s+o-100,l);
                                draw_circle(-300+n+80,0-35-s+o-100,l);
                                draw_circle(-300+n+80,0+35+s+o-100,l);
                                draw_circle(-300-40+n+80,0-s+o-100,l);
                                draw_circle(-300+n-20+80,0+s+o-100,l);
                                draw_circle(-300+n+80,0-s+o-100,l);

                                ////////////////////////////3333333333/////////////////////////////////

                                glColor3f(1.0,1.0,0.0);
                                draw_circle(470+n,-150+o,l);
                                draw_circle(470-40+n,-250+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(470-40+n,-250-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(470-20+n,-250-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(470-20+n,-250+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(470-10+n,-250+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(470-10+n,-250+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(470+n,-250+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(470+n,-250+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(470+n,-250-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(470+n,-250-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(470-60+n,-250+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(470-10+n,-250+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(470-40+n+80,-150+15+s+o-100,l);
                                draw_circle(470-40+n+80,-150-15-s+o-100,l);
                                draw_circle(470-50+n+80,-150+18+s+o-100,l);
                                draw_circle(470-50+n+80,-150-18-s+o-100,l);
                                draw_circle(470+n-20+80,-150-25-s+o-100,l);
                                draw_circle(470+n-20+80,-150+25+s+o-100,l);
                                draw_circle(470+n+80,-150-35-s+o-100,l);
                                draw_circle(470+n+80,-150+35+s+o-100,l);
                                draw_circle(470-40+n+80,-150-s+o-100,l);
                                draw_circle(470+n-20+80,-150+s+o-100,l);
                                draw_circle(470+n+80,-150-s+o-100,l);

                                //////////////////////////////////44444444444444444444/////////////////////////

                                glColor3f(1.0,1.0,0.0);
                                draw_circle(-500+n, 50+o,l);
                                draw_circle(-500-40+n,50+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(-500-40+n,50-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(-500-20+n, 50-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(-500-20+n, 50+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(-500-10+n, 50+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(-500-10+n, 50+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(-500+n, 50+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(-500+n, 50+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(-500+n, 50-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(-500+n, 50-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(-500-60+n, 50+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(-500-10+n, 50+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(-500-40+n+80,150+15+s+o-100,l);
                                draw_circle(-500-40+n+80,150-15-s+o-100,l);
                                draw_circle(-500-50+n+80,150+18+s+o-100,l);
                                draw_circle(-500-50+n+80,150-18-s+o-100,l);
                                draw_circle(-500+n-20+80,150-25-s+o-100,l);
                                draw_circle(-500+n-20+80,150+25+s+o-100,l);
                                draw_circle(-500+n+80,150-35-s+o-100,l);
                                draw_circle(-500+n+80,150+35+s+o-100,l);
                                draw_circle(-500-40+n+80,150-s+o-100,l);
                                draw_circle(-500+n-20+80,150+s+o-100,l);
                                draw_circle(-500+n+80,150-s+o-100,l);

                                ///////////////////////////////////////5555555555555555////////////////////////

                                glColor3f(1.0,1.0,0.0);
                                draw_circle(270+n,-150+o,l);
                                draw_circle(350-40+n,-150+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(270-40+n,-150-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(270-20+n,-150-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(270-20+n,-150+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(270-10+n,-150+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(270-10+n,-150+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(270+n,-150+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(270+n,-150+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(270+n,-150-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(270+n,-150-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(270-60+n,-150+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(270-10+n,-150+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(270-40+n+80,-50+15+s+o-100,l);
                                draw_circle(270-40+n+80,-50-15-s+o-100,l);
                                draw_circle(270-50+n+80,-50+18+s+o-100,l);
                                draw_circle(270-50+n+80,-50-18-s+o-100,l);
                                draw_circle(270+n-20+80,-50-25-s+o-100,l);
                                draw_circle(270+n-20+80,-50+25+s+o-100,l);
                                draw_circle(270+n+80,-50-35-s+o-100,l);
                                draw_circle(270+n+80,-50+35+s+o-100,l);
                                draw_circle(270-40+n+80,-50-s+o-100,l);
                                draw_circle(270+n-20+80,-50+s+o-100,l);
                                draw_circle(270+n+80,-50-s+o-100,l);

                                ////////////

                                ///////////////////////////////////////6666666666666666666////////////////////////

                                glColor3f(1.0,1.0,0.0);
                                draw_circle(370+n,-150+o,l);
                                draw_circle(350-40+n,-150+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(370-40+n,-150-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(370-20+n,-150-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(370-20+n,-150+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(370-10+n,-150+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(370-10+n,-150+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(370+n,-150+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(370+n,-150+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(370+n,-150-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(370+n,-150-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(370-60+n,-150+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(370-10+n,-150+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(370-40+n+80,-50+15+s+o-100,l);
                                draw_circle(370-40+n+80,-50-15-s+o-100,l);
                                draw_circle(370-50+n+80,-50+18+s+o-100,l);
                                draw_circle(370-50+n+80,-50-18-s+o-100,l);
                                draw_circle(370+n-20+80,-50-25-s+o-100,l);
                                draw_circle(370+n-20+80,-50+25+s+o-100,l);
                                draw_circle(370+n+80,-50-35-s+o-100,l);
                                draw_circle(370+n+80,-50+35+s+o-100,l);
                                draw_circle(370-40+n+80,-50-s+o-100,l);
                                draw_circle(370+n-20+80,-50+s+o-100,l);
                                draw_circle(370+n+80,-50-s+o-100,l);

                                /////////////////////////////////////6666666666666666666666666/////////////////////

                                ///////////////////////////////////////6666666666666666666////////////////////////

                                glColor3f(1.0,1.0,0.0);
                                draw_circle(370+n,-50+o,l);
                                draw_circle(350-40+n,-50+15+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(370-40+n,-50-15+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(370-20+n,-50-25+o,l);
                                glColor3f(1,7.0,0.0);
                                draw_circle(370-20+n,-50+25+o,l);
                                glColor3f(1,1,0.0);
                                draw_circle(370-10+n,-50+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(370-10+n,-50+o,l);
                                glColor3f(1.0,1,0.0);
                                draw_circle(370+n,-50+25+o,l);
                                glColor3f(1.0,0.7,0);
                                draw_circle(370+n,-50+25+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(370+n,-50-35+o,l);
                                glColor3f(1,0.5,0.0);
                                draw_circle(370+n,-50-35+o,l);
                                glColor3f(1.0,0.6,0.0);
                                draw_circle(370-60+n,-50+o,l);
                                glColor3f(1,1.0,0.0);
                                draw_circle(370-10+n,-50+o,l);


                                //smoke
                                glColor3f(0.7,0.7,0.7);
                                draw_circle(370-40+n+80,50+15+s+o-100,l);
                                draw_circle(370-40+n+80,50-15-s+o-100,l);
                                draw_circle(370-50+n+80,50+18+s+o-100,l);
                                draw_circle(370-50+n+80,50-18-s+o-100,l);
                                draw_circle(370+n-20+80,50-25-s+o-100,l);
                                draw_circle(370+n-20+80,50+25+s+o-100,l);
                                draw_circle(370+n+80,50-35-s+o-100,l);
                                draw_circle(370+n+80,50+35+s+o-100,l);
                                draw_circle(370-40+n+80,50-s+o-100,l);
                                draw_circle(370+n-20+80,50+s+o-100,l);
                                draw_circle(370+n+80,50-s+o-100,l);
                        }
                }
        }




        if(o<-800 && fire==0 && man==0)
        {
                //rain
                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(100,650+r);
                glVertex2i(110,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(200,650+r);
                glVertex2i(210,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(300,700+r);
                glVertex2i(310,730-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(400,650+r);
                glVertex2i(410,680-10+r);
                glEnd();
                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(500,650+r);
                glVertex2i(510,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(600,650+r);
                glVertex2i(610,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(700,730+r);
                glVertex2i(710,760-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(800,650+r);
                glVertex2i(810,680-10+r);
                glEnd();

                //rain2

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(600+30,650-20+r);
                glVertex2i(610+30,680-10-20+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(700+40,730+r+30);
                glVertex2i(710+40,760-10+r+30);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(800-30,650+r+30);
                glVertex2i(810-30,680-10+r+30);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(100+30,650+r+30);
                glVertex2i(110+30,680-10+r+30);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(200-40,650+r-40);
                glVertex2i(210-40,680-10-40+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(300+30,700+40+r);
                glVertex2i(310+30,730-10+40+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(600-100,650+100+r);
                glVertex2i(610-100,680-10+100+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(700-150,730+r+100);
                glVertex2i(710-150,760-10+100+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(800-200,650+r+100);
                glVertex2i(810-200,680+100-10+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100,650+150+r);
                glVertex2i(110,680-10+150+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200,650+r+150);
                glVertex2i(210,680-10+r+150);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300,700+r+150);
                glVertex2i(310,730-10+r+150);
                glEnd();

                //rain3

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100-50,650+30+r);
                glVertex2i(110-50,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200-50,650+30+r);
                glVertex2i(210-50,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300-50,700+30+r);
                glVertex2i(310-50,730-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(400-50,650+r);
                glVertex2i(410-50,680-10+r);
                glEnd();
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(500-50,650+r);
                glVertex2i(510-50,680-10+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(600-50,650+r);
                glVertex2i(610-50,680-10+r);
                glEnd();

                glColor3f(0,0-50,0.7);
                glBegin(GL_LINES);
                glVertex2i(700-50,730+r);
                glVertex2i(710-50,760-10+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(800-50,650+r);
                glVertex2i(810-50,680-10+r);
                glEnd();

                //rain4
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100-80,650+30+r);
                glVertex2i(110-80,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200-80,650+30+r);
                glVertex2i(210-80,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300-80,700+30+r);
                glVertex2i(310-80,730-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(400-80,650+30+r);
                glVertex2i(410-80,680-10+30+r);
                glEnd();
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(500-80,650+30+r);
                glVertex2i(510-80,680-10+30+r);
                glEnd();

                //rain5
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100-120,650+30+r);
                glVertex2i(110-120,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200-120,650+30+r);
                glVertex2i(210-120,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300-120,700+30+r);
                glVertex2i(310-120,730-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(400-120,650+20+r);
                glVertex2i(410-120,680-10+20+r);
                glEnd();
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(500-120,650+40+r);
                glVertex2i(510-120,680-10+40+r);
                glEnd();


                //rain7
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100-160,650+30+r);
                glVertex2i(110-160,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200-160,650+30+r);
                glVertex2i(210-160,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300-160,700+30+r);
                glVertex2i(310-160,730-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(400-160,650+20+r);
                glVertex2i(410-160,680-10+20+r);
                glEnd();
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(500-160,650+40+r);
                glVertex2i(510-160,680-10+40+r);
                glEnd();



                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(600-120,650+45+r);
                glVertex2i(610-120,680-10+45+r);
                glEnd();

                glColor3f(0,0-50,0.7);
                glBegin(GL_LINES);
                glVertex2i(700-120,730+45+r);
                glVertex2i(710-120,760-10+45+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(800-120,650+r);
                glVertex2i(810-120,680-10+r);
                glEnd();

                //rain6
                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(100-160,650+r);
                glVertex2i(110-160,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(200-160,650+r);
                glVertex2i(210-160,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(300-160,700+r);
                glVertex2i(310-160,730-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(400-160,650+r);
                glVertex2i(410-160,680-10+r);
                glEnd();
                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(500-160,650+r);
                glVertex2i(510-160,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(600-160,650+r);
                glVertex2i(610-160,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(700-160,730+r);
                glVertex2i(710-160,760-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(800-160,650+r);
                glVertex2i(810-160,680-10+r);
                glEnd();

                //rain8
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100-200,650+30+r);
                glVertex2i(110-200,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200-200,650+30+r);
                glVertex2i(210-200,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300-200,700+30+r);
                glVertex2i(310-200,730-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(400-200,650+20+r);
                glVertex2i(410-200,680-10+20+r);
                glEnd();
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(500-200,650+40+r);
                glVertex2i(510-200,680-10+40+r);
                glEnd();

                //rain9
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100-400,650+30+r);
                glVertex2i(110-400,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200-400,650+30+r);
                glVertex2i(210-400,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300-400,700+30+r);
                glVertex2i(310-400,730-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(400-400,650+20+r);
                glVertex2i(410-400,680-10+20+r);
                glEnd();
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(500-400,650+40+r);
                glVertex2i(510-400,680-10+40+r);
                glEnd();

                //rain10
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100-300,650+30+r);
                glVertex2i(110-300,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200-300,650+30+r);
                glVertex2i(210-300,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300-300,700+30+r);
                glVertex2i(310-300,730-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(400-300,650+20+r);
                glVertex2i(410-300,680-10+20+r);
                glEnd();
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(500-300,650+40+r);
                glVertex2i(510-300,680-10+40+r);
                glEnd();

                //rain11
                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(100,650+r);
                glVertex2i(110,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(200,650+r);
                glVertex2i(210,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(300,700+r);
                glVertex2i(310,730-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(400,650+r);
                glVertex2i(410,680-10+r);
                glEnd();
                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(500,650+r);
                glVertex2i(510,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(600,650+r);
                glVertex2i(610,680-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(700,730+r);
                glVertex2i(710,760-10+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(800,650+r);
                glVertex2i(810,680-10+r);
                glEnd();

                //rain12

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(600-600,650-20+r);
                glVertex2i(610-600,680-10-20+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(700-590,730+r+30);
                glVertex2i(710-590,760-10+r+30);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(800-600,650+r+30);
                glVertex2i(810-600,680-10+r+30);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(100-600,650+r+30);
                glVertex2i(110-600,680-10+r+30);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(200-640,650+r-40);
                glVertex2i(210-640,680-10-40+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(300-600,700+40+r);
                glVertex2i(310-600,730-10+40+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(600-700,650+100+r);
                glVertex2i(610-700,680-10+100+r);
                glEnd();

                glColor3f(0,0,0.9);
                glBegin(GL_LINES);
                glVertex2i(700-750,730+r+100);
                glVertex2i(710-750,760-10+100+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(800-800,650+r+100);
                glVertex2i(810-800,680+100-10+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100-600,650+150+r);
                glVertex2i(110-600,680-10+150+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200-600,650+r+150);
                glVertex2i(210-600,680-10+r+150);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300-600,700+r+150);
                glVertex2i(310-600,730-10+r+150);
                glEnd();

                //rain13

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100-650,650+30+r);
                glVertex2i(110-650,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200-650,650+30+r);
                glVertex2i(210-650,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300-650,700+30+r);
                glVertex2i(310-650,730-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(400-650,650+r);
                glVertex2i(410-650,680-10+r);
                glEnd();
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(500-650,650+r);
                glVertex2i(510-650,680-10+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(600-650,650+r);
                glVertex2i(610-650,680-10+r);
                glEnd();

                glColor3f(0,0-50,0.7);
                glBegin(GL_LINES);
                glVertex2i(700-650,730+r);
                glVertex2i(710-650,760-10+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(800-650,650+r);
                glVertex2i(810-650,680-10+r);
                glEnd();

                //rain14
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(100-680,650+30+r);
                glVertex2i(110-680,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(200-680,650+30+r);
                glVertex2i(210-680,680-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(300-680,700+30+r);
                glVertex2i(310-680,730-10+30+r);
                glEnd();

                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(400-680,650+30+r);
                glVertex2i(410-680,680-10+30+r);
                glEnd();
                glColor3f(0,0,0.7);
                glBegin(GL_LINES);
                glVertex2i(500-680,650+30+r);
                glVertex2i(510-680,680-10+30+r);
                glEnd();

        }

}




void main_menu(int id)
{
        switch(id)
        {

                case 0:
                        fire = 0;
                        firecount=0;
                        raincount=601;
                        mancount=0;
                        raincount = 601;
                        man=1;
                        manposition = 850;
                        break;
                case 1:
                        man=0;
                        fire=1;
                        o=n=0.0;
                        mancount = 0;
                        firecount = 0;
                        raincount = 601;
                        break;

                case 2:
                        man = 0;
                        fire=0;
                        o=-801;
                        raincount=0;
                        firecount=0;
                        mancount = 0;
                        break;
                case 3:
                        exit(0);

        }
}





void idle()
{
        glClearColor(1.0,1.0,1.0,1.0);
        r-=2;
        //n-=1;
        if(man == 1)
                mancount++;
        else if(fire>0)
                firecount+=1;
        else
                raincount++;

        o+=0;
        s=s-0.5;
        if(n==-800)
        {
                fire=0.0;
        }

        if (raincount>1025)
        {
                main_menu(0);
        }

        if (mancount > 1025)
        {
                main_menu(1);
        }

        if(firecount>1250)
        {
                main_menu(2);
        }

        if (firecount > 1250)
                exit(0);

        if( o==-700)
        {
                fire=700;

        }
        if(s==-30)
        {
                s=0.0;
        }

        if(r==-600)
        {
                r=0.0;

        }

        glutPostRedisplay();

}








//initialization-----------------------------------------------------------------------------------------
void init()
{
        glClearColor(0.74902,0.847059,0.847059,1);
        gluOrtho2D(-600,800,-600,800);
}


//display funtion---------------------------------------------------------------------------------------
void display()
{
        glClear(GL_COLOR_BUFFER_BIT);
        //drawhouse();
        //drawHills();
        land();
        glFlush();
        glColor3f(1.0,0.19,0.0);
        drawCircle(20,300,500);
        glFlush();
        //drawTree(0,0);
        drawForest();
        glFlush();
        //treeTwo();
        glFlush();
        glutSwapBuffers();


}



//main--------------------------------------=----------------------------------------------------------
void main(int argc,char *argv[])
{

        int x=0,c_menu;
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
        glutInitWindowSize(1500,1500);
        glutCreateWindow("Forestfire");
        glutDisplayFunc(display);
        glutIdleFunc(idle);
        init();
        c_menu=glutCreateMenu(main_menu);
        glutAddMenuEntry("Cigar man",0);
        glutAddMenuEntry("Forestfire",1);
        glutAddMenuEntry("Rain",2);
        glutAddMenuEntry("Exit",3);
        glutAttachMenu(GLUT_LEFT_BUTTON);
        glutMainLoop();

}
