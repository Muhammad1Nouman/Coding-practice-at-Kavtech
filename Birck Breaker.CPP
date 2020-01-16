#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<bios.h>
#include<stdio.h>

void updateXY();
void updateXY1();
void uppos();
int x=100,y=100;
int ballSize = 5;
int x1=100,y1=100;
int dirX1=1,dirY1=1;
int dirX=1, dirY=1;
int minX=10, minY=10, maxX=639, maxY=465;
int key;
int turn2=0;
int second=0;

int RecX1=50;
int RecSize=150;
int score=0;
int turn=0;
int turn1=0;
int dirRi=1;

void drawPlayer(int c)
{
  setcolor(c);
  rectangle(RecX1+1,450,RecX1-1+RecSize,460);
}


main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

  //Draw Border
  rectangle(minX, minY, maxX, maxY);
  setcolor(BLACK);
  line(minX,maxY,maxX,maxY);

  //Draw Player
  drawPlayer(WHITE);

while(1)
{
  while(bioskey(1)==0)
  {
    uppos();
    updateXY();
    //updateXY1();
  }

  key=bioskey(0);

  if(key==4209)//Key q (Quit)
  {
    return 0;
  }

  if(key==19712&&(RecX1+150)!=maxX)  //coded for right move
  {
	dirRi=1;
  }

  if(key==19200&&(RecX1-10!=0)) //start of left move of bar
  {
	dirRi=-1;
  }

}//END MAIN WHILE

	closegraph();
}//main end


void updateXY()
{
 turn++;
 int oldX=x, oldY=y;

 if(turn%50==0)
 {
    turn=0;

    //Detect Collisions
    if( x + ballSize >= maxX)
    {  	dirX=-1;
    }

    if( x-ballSize <= minX)
    {
	dirX=1;
    }

    //if hit by player
    if( (y+ballSize) >= 445 && y <= 460 && ( x + ballSize) >= RecX1 && (x - ballSize) <= (RecX1+RecSize))
    {
	 dirY=-1;
    }

   //if player miss
   if(y+ballSize >= (maxY))
   {
     gotoxy(35,16);      //condition if cirlce touch the bottom of bar
     printf("Game Over");
     dirY=0;
     dirX=0;
    }

    if( y-ballSize <= (minY))
    {
	dirY=1;
    }


	//Update Position
    if(dirX==1)
    {
	x++;
    }

    else if(dirX==-1)
    {
	x--;
    }

    if(dirY==1)
    {
	y++;
    }

    else if(dirY==-1)
    {
	y--;
    }



}//end if turn

    //Remove Ball from current position
    setcolor(BLACK);
    circle(oldX,oldY,ballSize-1);


    //Draw Ball in New position
    setcolor(WHITE);
    circle(x,y,ballSize-1);

  }


void uppos()
{

   turn1++;

   if(turn1%50==0)
      {
	turn1=0;

      //if colides with right border
      if((RecX1+RecSize) >= maxX)
      {
	dirRi=-1;
      }

      if((RecX1) <= minX)
      {
	dirRi=1;
      }


	drawPlayer(BLACK);

       if(dirRi==1)
       {
	  RecX1++;      //update position
       }
       else
       {
	  RecX1--;
       }

      drawPlayer(WHITE);
  }

}