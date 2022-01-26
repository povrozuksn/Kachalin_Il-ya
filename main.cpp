#include "TXLib.h"

void drawsky(COLORREF color)
{
txSetColor(TX_NULL);
txSetFillColor(color);
txRectangle(0,0,1920,1080);
}

void drawsun(int x,int y)
{
txSetColor(TX_NULL);
txSetFillColor(RGB (255, 172, 98));
txCircle(x,y,107);

txSetColor(TX_NULL);
txSetFillColor(TX_YELLOW);
txCircle(x,y,100);
}

void drawmoon(int x, int y)
{
txSetColor(TX_NULL);
txSetFillColor(TX_GRAY);
txCircle(x,y,80);

txSetColor(TX_NULL);
txSetFillColor(TX_WHITE);
txCircle(x,y,73);
}

void drawplane(int x, int y)
{
txSetColor(TX_BLACK,3);
txSetFillColor(TX_WHITE);
POINT planebase[4] = {{x, y}, {x+11, y-12}, {x+93, y-12}, {x+105, y}};
POINT planetail[3] = {{x, y}, {x, y-34}, {x+11, y-12}};
POINT planeupwing[3] = {{x+32, y-12}, {x+56, y-27}, {x+56, y-12}};
POINT planedownwing[3] = {{x+32, y}, {x+56, y+17}, {x+56, y}};
txPolygon (planebase, 4);
txPolygon (planetail, 3);
txPolygon (planeupwing,3);
txPolygon (planedownwing,3);
}

void drawbuilding(int x, int y, int xx, int yy, int rand[], COLORREF color, COLORREF colorw)
{
txSetColor(color,5);
txSetFillColor(RGB (50, 50, 50));
txRectangle(x,y,xx,yy);
int i=0;

txSetColor(RGB (50,50,50));
txSetFillColor(colorw);
for(int yWin=y+5; yWin<yy-5; yWin+=15)
{
for(int xWin=x+5; xWin<xx-5; xWin+=15)
{
if(rand[i]%3==0)
txSetFillColor(colorw);
else
txSetFillColor(RGB (50,50,50));
txRectangle(xWin,yWin,xWin+10,yWin+10);
i++;
}
}
}

void drawferriswheel(int x,int y)
{
txSetColor(RGB (255, 172, 98),5);
txSetFillColor(RGB (50, 50, 50));
txCircle(x,y,75);
txSetFillColor(TX_ORANGE);
txCircle(x,y,65);
}

void drawferrislines()
{
txSetColor(RGB (50, 50, 50),10);
txSetFillColor(RGB (50, 50, 50));
txLine(1410,750,1410,680);
txLine(1410,750,1370,700);
txLine(1410,750,1450,700);
txLine(1410,750,1470,750);
txLine(1410,750,1345,750);
txLine(1410,750,1410,800);
txLine(1410,750,1370,795);
txLine(1410,750,1450,795);
}

void drawballoon(int x, int y, int x2, int y2)
{
txSetColor(RGB (105,54,35), 4);
txSetFillColor(RGB (105,54,35));
txLine(x,y,x2,y2); // 809 398 792 448
txLine(x-54,y,x2-22,y2);
txSetFillColor(RGB (144,77,48));
txRectangle(x-17,y+50,x2-20,y2+20);
txSetFillColor(RGB (157,129,186));
txCircle(x-27,y,30);
}

void drawclouds(int x,int y, COLORREF color)
{
txSetColor(TX_NULL);
txSetFillColor(color);
txCircle(x-200,y+245,40);
txCircle(x-260,y+232,55);
txCircle(x-300,y+278,45);
txCircle(x-350,y+221,50);
txCircle(x,y,40); // 112 354
txCircle(x+40,y+29,55);
txCircle(x+100,y+20,45);
txCircle(x+150,y-13,50);
txCircle(x+446,y-159,40);
txCircle(x+480,y-200,55);
txCircle(x+530,y-150,45);
txCircle(x+579,y-124,50);
txCircle(x+1270,y-124,40);
txCircle(x+1337,y-150,55);
txCircle(x+1387,y-130,45);
txCircle(x+1426,y-159,50);
txCircle(x+911,y+128,40);
txCircle(x+971,y+128,55);
txCircle(x+1020,y+74,45);
txCircle(x+1030,y+102,45);
txCircle(x+1080,y+111,50);
txCircle(x+1411,y+311,40);
txCircle(x+1471,y+274,55);
txCircle(x+1511,y+304,55);
txCircle(x+1520,y+328,45);
txCircle(x+1580,y+299,50);

}

void drawstars(COLORREF color)
{
txSetColor(TX_NULL);
txSetFillColor(color);
txCircle(529,173,3);
txCircle(678,95,3);
txCircle(558,93,3);
txCircle(1753,159,3);
txCircle(1456,68,3);
txCircle(1654,157,3);
txCircle(239,46,3);
txCircle(391,119,3);
txCircle(92,139,3);
txCircle(1872,200,3);
txCircle(528,75,3);
txCircle(321,70,3);
txCircle(192,148,3);
txCircle(960,92,3);
txCircle(1020,123,3);
txCircle(1230,189,3);
txCircle(1120,122,3);
txCircle(725,96,3);
txCircle(800,145,3);
txCircle(1050,172,3);
txCircle(1572,132,3);
txCircle(1368,147,3);
}

void drawgrass()
{
txSetColor(TX_NULL);
txSetFillColor(RGB (24, 129, 55));
POINT peizazh[6] = {{1,824}, {335,725}, {784,764}, {1277,852}, {1772,744}, {1920,811}};
txPolygon (peizazh, 6);

txSetColor(TX_NULL);
txSetFillColor(RGB (24, 129, 55));
txRectangle(0,800,1920,1080);
}

int main()
{
txCreateWindow(1920,1080);
int balloonone = 450;
int balloontwo = 500;
int v = 2;
int vm = 3;
int sun = 680;
int moon = 910;
int cloud = 0;
int plane = 0;
int x0=1410;
int y0=750;
int x1;
int y1;
int x2;
int y2;
int x3;
int y3;
int x4;
int y4;
int x5;
int y5;
int x6;
int y6;
int x7;
int y7;
int x8;
int y8;
int x9;
int y9;
int r=72;
double a = 0;
double b1;
double b2;
double b3;
double b4;
double b5;
double b6;
double b7;
double b8;
double b9;
double size=60;
int ytext=1090;
int yytext=1980;
int rand1[100];
int rand2[100];
int rand3[100];
int rand4[100];
int rand5[100];
int rand6[100];
int rand7[100];
int rand8[100];
int rand9[100];
int rand10[100];
int rand11[100];
COLORREF colorskyd = TX_ORANGE;
COLORREF colorskyn = RGB (31, 64, 163);
COLORREF colorcd = TX_WHITE;
COLORREF colorcn = RGB (70,69,68);
COLORREF colorbd = RGB (255,172,98);
COLORREF colorbn = TX_WHITE;
COLORREF colorsd = TX_ORANGE;
COLORREF colorsn = TX_WHITE;
COLORREF colorwd = RGB (50,50,50);
COLORREF colorwn = TX_WHITE;

int time = 0;

for(int i=0; i<100; i++)
{
rand1[i]=random(0,50);
rand2[i]=random(0,50);
rand3[i]=random(0,50);
rand4[i]=random(0,50);
rand5[i]=random(0,50);
rand6[i]=random(0,50);
rand7[i]=random(0,50);
rand8[i]=random(0,50);
rand9[i]=random(0,50);
rand10[i]=random(0,50);
rand11[i]=random(0,50);
}


while(sun<=1000)
{
txBegin();
drawsky(colorskyd);
drawstars(colorsd);
drawballoon(809,balloonone,792,balloontwo);
balloonone=balloonone+v;
balloontwo=balloontwo+v;
drawbuilding(113,720,194,836,rand1,colorbd,colorwd);
drawbuilding(194,683,275,836,rand2,colorbd,colorwd);
drawbuilding(275,632,356,836,rand3,colorbd,colorwd);
drawbuilding(356,645,423,836,rand4,colorbd,colorwd);
drawbuilding(423,532,501,836,rand5,colorbd,colorwd);
drawbuilding(501,683,581,836,rand6,colorbd,colorwd);
drawbuilding(581,658,661,836,rand7,colorbd,colorwd);
drawbuilding(661,603,741,836,rand8,colorbd,colorwd);
drawbuilding(741,702,821,836,rand9,colorbd,colorwd);
drawbuilding(1158,612,1238,836,rand10,colorbd,colorwd);
drawbuilding(1238,693,1318,836,rand11,colorbd,colorwd);
drawferriswheel(1410,750);

if (sun>=910)
{
drawsky(colorskyn);
drawstars(colorsn);
drawballoon(809,balloonone,792,balloontwo);
balloonone=balloonone+v;
balloontwo=balloontwo+v;
drawbuilding(113,720,194,836,rand1,colorbn,colorwn);
drawbuilding(194,683,275,836,rand2,colorbn,colorwn);
drawbuilding(275,632,356,836,rand3,colorbn,colorwn);
drawbuilding(356,645,423,836,rand4,colorbn,colorwn);
drawbuilding(423,532,501,836,rand5,colorbn,colorwn);
drawbuilding(501,683,581,836,rand6,colorbn,colorwn);
drawbuilding(581,658,661,836,rand7,colorbn,colorwn);
drawbuilding(661,603,741,836,rand8,colorbn,colorwn);
drawbuilding(741,702,821,836,rand9,colorbn,colorwn);
drawbuilding(1158,612,1238,836,rand10,colorbn,colorwn);
drawbuilding(1238,693,1318,836,rand11,colorbn,colorwn);

txSetColor(TX_WHITE,3);
txSetFillColor(RGB (50, 50, 50));
txCircle(1410,750,75);

txSetColor(TX_WHITE,3);
txSetFillColor(RGB (31, 64, 163));
txCircle(1410,750,65);

moon=moon-vm;

sun=sun-1;
}
if (sun>=810)
{
plane=plane+55;
}
if (sun>=682)
{
txBegin();
txSetColor(RGB (50, 50, 50),10);
txSetFillColor(RGB (50, 50, 50));

b1=(a)*3.14/180;
b2=(a-40)*3.14/180;
b3=(a-80)*3.14/180;
b4=(a-120)*3.14/180;
b5=(a-160)*3.14/180;
b6=(a-200)*3.14/180;
b7=(a-240)*3.14/180;
b8=(a-280)*3.14/180;
b9=(a-320)*3.14/180;

x1=x0+r*cos(b1);
y1=y0+r*sin(b1);
x2=x0+r*cos(b2);
y2=y0+r*sin(b2);
x3=x0+r*cos(b3);
y3=y0+r*sin(b3);
x4=x0+r*cos(b4);
y4=y0+r*sin(b4);
x5=x0+r*cos(b5);
y5=y0+r*sin(b5);
x6=x0+r*cos(b6);
y6=y0+r*sin(b6);
x7=x0+r*cos(b7);
y7=y0+r*sin(b7);
x8=x0+r*cos(b8);
y8=y0+r*sin(b8);
x9=x0+r*cos(b9);
y9=y0+r*sin(b9);


txLine(x0,y0,x1,y1);
txLine(x0,y0,x2,y2);
txLine(x0,y0,x3,y3);
txLine(x0,y0,x4,y4);
txLine(x0,y0,x5,y5);
txLine(x0,y0,x6,y6);
txLine(x0,y0,x7,y7);
txLine(x0,y0,x8,y8);
txLine(x0,y0,x9,y9);

a=a+1.5;
if (sun>=910)
{
a=a-1.5;
}

txEnd();
}

drawplane(plane+-150,100);
drawclouds(cloud+112,354,colorcd);
cloud=cloud+1;

// Дополнительный ИФ для работы облаков
if (sun>=909)
{
drawclouds(cloud+112,354,colorcn);
}

drawmoon(960,moon);
drawsun(960,sun);
sun=sun+2;
drawgrass();
txSelectFont("Times",50);
txTextOut(20,30,"Когда Солнце и Луна меняются местами");

txSleep(50);
txEnd();
}

while(time<=150)
{
txBegin();
time=time+1;
size=size-1;
ytext=ytext-20;
yytext=yytext-20;
txSetColor(TX_BLACK, 100);
txSetFillColor(TX_BLACK);
txRectangle(0,0,1920,1080);
txSetColor(TX_WHITE,50);
txSetFillColor(TX_WHITE);
txSelectFont("Times", size);
txDrawText(500,ytext, 1400,yytext,"Работа выполнена одним крутым челом:\n"
"илюхой,\n"
"ильёй,\n"
"илюхинсом,\n"
"йёьли,\n"
"приколдес,\n"
"крутой чел.");
txSleep(50);
txEnd();
}

return 0;
}
