#include<graphics.h>
#include <conio.h>
#include<iostream>
#include <stdio.h>
#include <conio.h>
//#include <iostream>
#include <math.h>
using namespace std;

int main() {
  	 int gd = DETECT, gm;
	initgraph(&gd,&gm, "C:\\tc\\bgi");
    circle(300,300,50);
    closegraph();
    getch();
}
