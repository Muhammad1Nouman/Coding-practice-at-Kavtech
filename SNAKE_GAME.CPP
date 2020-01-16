#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<bios.h>
#include<stdio.h>

//function
void updateSnake();
void drawfood();
//check for direction
void snakeBiteitself();
//Global variables for check direction function
//if size is greater then 3
int snakeBite=0; //detect snakebiteitself
//function for move increase parts of snake
int oldKey=0;
void copysnake();

//function to printincrease part of snake

void printIncreaseSnake();

//BORDER

int maxX=620,maxY=460,minX=0,minY=10;

//PLAYER

//Variable to store old position of snake

int up,left,down,right,prePosX,prePosY;

int foodWidth=5; //width of food

int foodX,foodY,foodeat=0;

//GLOBAL

//key
int key;

//score

int score=0;

//struct to store the position of Snake

struct Snake
{
  int playerPosX,playerPosY;
  int dirX,dirY,dirX1,dirY1;
};

// for size,and current size of snake;

int size=2;
int size1=400;
int count=0;

// to store the values of snake size

Snake snakeSize[400];

main()
{
    //snake intial position

    snakeSize[0].playerPosX=100,snakeSize[0].playerPosY=100,snakeSize[0].dirX=1,snakeSize[0].dirY=-1,snakeSize[0].dirY1=-1,snakeSize[0].dirX1=-1;

    //draw graph
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");


    //draw border rectecangle

    rectangle(minX,minY,maxX,maxY);
    setcolor(9);

    //draw food

    rectangle(snakeSize[0].playerPosX,snakeSize[0].playerPosY,snakeSize[0].playerPosX+foodWidth,snakeSize[0].playerPosY+foodWidth);

  while(1){

    while(bioskey(1)==0)
    {
	if(snakeBite!=4)
	updateSnake();

	if(foodeat==0)
	  {

	       //generate random number for food

		foodX=(rand()%590)+10;
		foodY=(rand()%410)-10;
		setcolor(RED);
		rectangle(foodX,foodY,foodX+foodWidth,foodY+foodWidth);
		foodeat++;
	}

	//collsion detection

	if((foodX<=(snakeSize[0].playerPosX+foodWidth)&&foodY<=(snakeSize[0].playerPosY+foodWidth)&&((snakeSize[0].playerPosX<=(foodX+foodWidth))&&snakeSize[0].playerPosY<=(foodY+foodWidth))))
	{
	  drawfood();
	  setcolor(WHITE);
	  printIncreaseSnake();

	}
    }//End of While(key)

    // dirX =right dirX1=left dirY=down dirY1=up
     key=bioskey(0);

     if(key==4209)    //Q(quit)
     {
       return 0;
     }
     if(key==6512) //pause game
     {
       getch();
     }
     if(key==19712&&oldKey!=19200)    //Right move
     {
	snakeSize[0].dirX=1;
	snakeSize[0].dirX1=-1;
	snakeSize[0].dirY=-1;
	snakeSize[0].dirY1=-1;
	oldKey=key;
     }
     if(key==20480&&oldKey!=18432)        //down move
     {
	 snakeSize[0].dirX=-1;
	 snakeSize[0].dirX1=-1;
	 snakeSize[0].dirY=1;
	 snakeSize[0].dirY1=-1;
	 oldKey=key;
     }
     if(key==18432&&oldKey!=20480)   //up  move
     {
	 snakeSize[0].dirX=-1;
	 snakeSize[0].dirX1=-1;
	 snakeSize[0].dirY=-1;
	 snakeSize[0].dirY1=1;
	 oldKey=key;
     }
     if(key==19200&&oldKey!=19712)       //left move
     {
	 snakeSize[0].dirX=-1;
	 snakeSize[0].dirX1=1;
	 snakeSize[0].dirY=-1;
	 snakeSize[0].dirY1=-1;
	 oldKey=key;
     }

}

}
void updateSnake()
{

  //store values of previous position of snake
 right=snakeSize[count].dirX,down=snakeSize[count].dirY,left=snakeSize[count].dirX1,up=snakeSize[count].dirY1,prePosX=snakeSize[count].playerPosX,prePosY=snakeSize[count].playerPosY;

  //border check

  if(snakeSize[count].playerPosX>=maxX || snakeSize[count].playerPosX<=minX ||snakeSize[count].playerPosY>=maxY || snakeSize[count].playerPosY<=minY)
  {
     //start from intial position of specified direction
       setcolor(BLACK);
      rectangle(snakeSize[count].playerPosX,snakeSize[count].playerPosY,snakeSize[count].playerPosX+foodWidth,snakeSize[count].playerPosY+foodWidth);
     if(snakeSize[count].playerPosX>=maxX)
     {
      snakeSize[count].playerPosX=minX+2;
     }
     if(snakeSize[count].playerPosX<=minX)
     {
      snakeSize[count].playerPosX=maxX-2;
     }
    if(snakeSize[count].playerPosY>=maxY)
     {
      snakeSize[count].playerPosY=minY+2;
     }
    if(snakeSize[count].playerPosY<=minY)
     {
      snakeSize[count].playerPosY=maxY-2;
     }
     setcolor(WHITE);
     rectangle(minX,minY,maxX,maxY);
   }
 else
 {


     delay(60+(50-size));


   setcolor(BLACK);

   for(count=0;count<=size-1;count++)
    {
      rectangle(snakeSize[count].playerPosX,snakeSize[count].playerPosY,snakeSize[count].playerPosX+foodWidth,snakeSize[count].playerPosY+foodWidth);
    }
     count=0;

   if(snakeSize[count].dirX==1)//right direction
   {
      snakeSize[count].playerPosX=snakeSize[count].playerPosX+8;
   }

   if(snakeSize[count].dirY==1)   //downDirection
   {
    snakeSize[count].playerPosY=snakeSize[count].playerPosY+8;
   }

   if(snakeSize[count].dirX1==1)             //leftDirection
   {
     snakeSize[count].playerPosX=snakeSize[count].playerPosX-8;
   }

   if(snakeSize[count].dirY1==1)        //upDirection
   {
     snakeSize[count].playerPosY=snakeSize[count].playerPosY-8;
   }

    setcolor(WHITE);

    copysnake();
    snakeBiteitself();
   if(snakeBite)
   {
     gotoxy(32,15);

     printf("    Game Over    ");
     snakeSize[0].dirX=-1;
     snakeSize[0].dirY=-1;
     snakeSize[0].dirX1=-1;
     snakeSize[0].dirY1=-1;
     snakeBite=4;

   }

    //draw all snake with white

    for(count=0;count<=size-1;count++)
    {
      rectangle(snakeSize[count].playerPosX,snakeSize[count].playerPosY,snakeSize[count].playerPosX+foodWidth,snakeSize[count].playerPosY+foodWidth);
    }

    count=0;


  }
}
//method to increas size of snake
void copysnake()
{
  int allSnakeMove;

 //loop for one move back
  for(allSnakeMove=size-1;allSnakeMove>=1;allSnakeMove--)
   {
     snakeSize[allSnakeMove].playerPosX=snakeSize[allSnakeMove-1].playerPosX;
     snakeSize[allSnakeMove].playerPosY=snakeSize[allSnakeMove-1].playerPosY;
     snakeSize[allSnakeMove].dirX=snakeSize[allSnakeMove-1].dirX;
     snakeSize[allSnakeMove].dirY=snakeSize[allSnakeMove-1].dirY;
     snakeSize[allSnakeMove].dirY1=snakeSize[allSnakeMove-1].dirY1;
     snakeSize[allSnakeMove].dirX1=snakeSize[allSnakeMove-1].dirX1;
   }
}

//method to remove food and update score
void drawfood()
{
	setcolor(BLACK);
	rectangle(foodX,foodY,foodX+foodWidth,foodY+foodWidth);
	gotoxy(3,3);
	score++;
	printf("Score:%d",score);
	foodeat=0;
}
//method to check the direction if snake size is greater than 2
//then snake is move on same direction if opposite key is pressed
void snakeBiteitself()
{
   int j=0,t=0;

   if(size>=3)
   {
	 for(t=3;t<size;t++)
	 {
	   if(snakeSize[0].playerPosX==snakeSize[t].playerPosX&&(snakeSize[0].playerPosY==snakeSize[t].playerPosY))
	   {
	     snakeBite=1;
	   }
	   if(snakeBite)
	   {

	    break;

	   }
	}

}
}

//print increased snake value
void printIncreaseSnake()
{

   if(size<=size1-1)
	  {
	    snakeSize[size].playerPosX=prePosX,snakeSize[size].playerPosY=prePosY,
	    snakeSize[size].dirX=right,snakeSize[size].dirY=down,snakeSize[size].dirX1=left,snakeSize[size].dirY1=up;
	    rectangle(snakeSize[size].playerPosX,snakeSize[size].playerPosY,snakeSize[size].playerPosX+foodWidth,snakeSize[size].playerPosY+foodWidth);
	    size++;
	  }
}
