#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
int click,xpos,ypos;
union REGS in,out;
void mouse();
void mou_position();
void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	rectangle(0,0,getmaxx(),getmaxy());
	mouse();
	while(!kbhit())
	{
		mou_position();
		gotoxy(2,2);
		printf("%d  %3dx%3d",click,xpos,ypos);
		if(click==1)
			//there aare two way to drow line
			lineto(xpos,ypos);
			//or
			//putpixel(xpos,ypos,WHITE);
	}
	getch();
}
void mouse()
{
	in.x.ax=1;
	int86(0x33,&in,&out);
}
void mou_position()
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	xpos=out.x.cx;
	ypos=out.x.dx;
	click=out.x.bx;
}
