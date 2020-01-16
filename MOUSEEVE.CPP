#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<bios.h>
int inimouse();
void showmouse();

void getmousepos(int*,int*,int*);
union REGS i,o;
int key;
main()
{

   int status=0,gd=DETECT,gm,x,y,button,tempx,tempy;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   status=inimouse();


   getch();
   if(status==0)
   {
     gotoxy(3,3);
     printf("MOUSE NOT SHOW");
   }
   else
   {
   while(bioskey(1)==0){
    getmousepos(&button,&x,&y);
 //   if(x==tempx&&y==tempy)
  //  {}
  //  else
   // {
    int playerPosX1=339,playerPosX2=400,playerPosY1=410,playerPosY2=440;
//   rectangle(playerPosX1,playerPosY1,playerPosX2,playerPosY2);
   int minX=0,minY=0,maxX=639,maxY=475;
   rectangle(minX,minY,maxX,maxY);
   //Rudder
   line((playerPosX1+playerPosX2)/2,playerPosY1-2,(playerPosX1+playerPosX2)/2-10,playerPosY1-2);
   line((playerPosX1+playerPosX2)/2,playerPosY1-2,(playerPosX1+playerPosX2)/2+10,playerPosY1-2);
   line((playerPosX1+playerPosX2)/2+10,playerPosY1-1,(playerPosX1+playerPosX2)/2+10,playerPosY1+5);
   line((playerPosX1+playerPosX2)/2-10,playerPosY1-1,(playerPosX1+playerPosX2)/2-10,playerPosY1+5);

   line((playerPosX1+playerPosX2)/2+10,playerPosY1+6,(playerPosX1+playerPosX2)/2+4,playerPosY1+10);
   line((playerPosX1+playerPosX2)/2-10,playerPosY1+6,(playerPosX1+playerPosX2)/2-4,playerPosY1+10);

   line((playerPosX1+playerPosX2)/2-4,playerPosY1+10,(playerPosX1+playerPosX2)/2-10,playerPosY1+25);
   line((playerPosX1+playerPosX2)/2+4,playerPosY1+10,(playerPosX1+playerPosX2)/2+10,playerPosY1+25);
   line((playerPosX1+playerPosX2)/2-10,playerPosY1+25,(playerPosX1+playerPosX2)/2,playerPosY1+30);
   line((playerPosX1+playerPosX2)/2+10,playerPosY1+25,(playerPosX1+playerPosX2)/2,playerPosY1+30);


     cleardevice();
     gotoxy(3,3);
    printf("%d %d",x,y);
    showmouse();
     //  }
		}
    }
    key=bioskey(0);
    getch();
    return 0;
}
int inimouse()
{
   i.x.ax=0;
   int86(0X33,&i,&o);
   return (o.x.ax);

}
void showmouse()
{
  i.x.ax=1;
  int86(0X33,&i,&o);
}
void getmousepos(int* button,int* x,int* y)
{
   i.x.ax=3;
   int86(0X33,&i,&o);
   *button=o.x.bx;
   *x=o.x.cx;
   *y=o.x.dx;

}