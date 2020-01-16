//Game Flapp  y Bird
//Include header file

#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<bios.h>
#include <stdlib.h>
#include <stdio.h>

//varible to increase speed of game
int speed=10;

//variable to draw border

int maxX=620,maxY=460,minX=0  ,minY=9;
//Player
int playerPosX=100,playerPosY=250,playerPosX1=110,playerPosY1=260;
//variable for detection of key
int key;
//Varibale to game over
int gameOver=0;

//vairable for enviroment
//for upper wall

int startWallx1=300,startWally1=10,endWally2=150,endWallx2=350;

//for lower wall

int lowWally1=200,lowWally2=460;

//function to update the direction of player

// variable for second wall
//second upper wall

 int secStartWallx1=450,secStartWally1=10,secEndWally1=250,secStartWallx2=500;

//second lower wall

int secLowWally1=360,secLowWally2=460;

//function to update player position
void updatePlayer();
//function to update player position by key
void updatePlayerByKey();

//function for update eniviroment

void updateEnviroment();

//variable for score

int score=0;

main()
{
   int gd=DETECT, gm;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   //draw rectanlge
   rectangle(minX,minY,maxX,maxY);
    getch();

   while(1)
   {

    while(bioskey(1)==0)
    {
	  //auto update player position
		updatePlayer();
	   //enviroment is update
	   updateEnviroment();

	//check wheather player collide with the wall or not

	if((startWallx1<=(playerPosX1)&&startWally1<=(playerPosY1)&&((playerPosX<=(endWallx2))&&playerPosY<=(endWally2)))||((startWallx1<=(playerPosX1)&&lowWally1<=(playerPosY1)&&((playerPosX<=(endWallx2))&&playerPosY<=(lowWally2))))||playerPosY1>=maxY||(gameOver==1))
	{
	gotoxy(32,15);
	printf("    Game Over    ");
	getch();
	gameOver=0;
	return 0;
	    }
       //condition if player manage to get throuh the wall
       //intillize second wall
	if(playerPosX1>endWallx2+80)
	 {

	   setcolor(BLACK);

	   rectangle(startWallx1,startWally1,endWallx2,endWally2);
	   rectangle(startWallx1,lowWally1,endWallx2,lowWally2);

	   setcolor(WHITE);

	   rectangle(minX,minY,maxX,maxY);
	   rectangle(secStartWallx1,secStartWally1,secStartWallx2,secEndWally1);
	   rectangle(secStartWallx1,secLowWally1,secStartWallx2,secLowWally2);

	   //shifting values of old position to currenyt position

	   startWallx1=secStartWallx1;
	   startWally1=secStartWally1;
	   startWally1=secStartWally1;
	   endWallx2=secStartWallx2;
	   endWally2=secEndWally1;
	   lowWally1=secLowWally1;
	   lowWally2=secLowWally2;


	   //genrate random number for y-axis upper
	   secEndWally1=(rand()%200);
	   if(secEndWally1<100)     //condtion if random number is small
	   {
	     secEndWally1=150;
	   }
	  secLowWally1 =(rand()%400); //random number for lower wall


	   if(secLowWally1<350)     //condtion for lower wall if the lower wall is too small
	   {
	    secLowWally1=250;
	   }
		  if(score%5==0)   //increse speed of game on the basis of score
		  speed=speed-2;

	    secStartWallx1=570,secStartWallx2=610;    //set position of player
	    gotoxy(3,3);
	    printf("Score:%d",score); //print score
	    score++;      //increase score
	 }

       }//end of bioskey while

     key=bioskey(0);

     if(key==4209) //Q(quit)
     {
      return 0;
     }
     if(key==14624)   //Space bar
     {
	updatePlayerByKey();   //if player want to update his/her postion
     }


   }//End of main while

}
//update player positon if not any key is pressed
void updatePlayer()
{
  delay(speed);
  setcolor(BLACK);
  rectangle(playerPosX,playerPosY,playerPosX1,playerPosY1);
  playerPosY++;
  playerPosY1++;
  setcolor(WHITE);
  rectangle(playerPosX,playerPosY,playerPosX1,playerPosY1);
}
//update player position by key
void updatePlayerByKey()
{
	int playerMove=0;
	//Remark here is one more condition if player do'nt cross between the wall

	while(playerMove<20)
	{
	   delay(speed);

	   //condtion for collsion
	   if((startWallx1<=(playerPosX1)&&startWally1<=(playerPosY1)&&((playerPosX<=(endWallx2))&&playerPosY<=(endWally2)))||((startWallx1<=(playerPosX1)&&lowWally1<=(playerPosY1)&&((playerPosX<=(endWallx2))&&playerPosY<=(lowWally2))))||playerPosY1>=maxY)
	   {
	      gotoxy(32,15);
	      printf("    Game Over    ");
	      gameOver=1;
	      break;
	    }
	   updateEnviroment();
	   setcolor(BLACK);
	   rectangle(playerPosX,playerPosY,playerPosX1,playerPosY1);
	   playerPosY--;
	   playerPosY1--;
	   setcolor(WHITE);

	   rectangle(playerPosX,playerPosY,playerPosX1,playerPosY1);
	   playerMove++;
	}
}
//update enviroment on every single step
void updateEnviroment()
{

   setcolor(BLACK);
   rectangle(startWallx1,startWally1,endWallx2,endWally2);
   rectangle(startWallx1,lowWally1,endWallx2,lowWally2);
   rectangle(secStartWallx1,secStartWally1,secStartWallx2,secEndWally1);
   rectangle(secStartWallx1,secLowWally1,secStartWallx2,secLowWally2);
   secStartWallx1--;

   secStartWallx2--;
   startWallx1--;
   endWallx2--;
   setcolor(WHITE);

   rectangle(startWallx1,startWally1,endWallx2,endWally2);
   rectangle(startWallx1,lowWally1,endWallx2,lowWally2);
   rectangle(secStartWallx1,secStartWally1,secStartWallx2,secEndWally1);
   rectangle(secStartWallx1,secLowWally1,secStartWallx2,secLowWally2);
   rectangle(minX,minY,maxX,maxY);
   gotoxy(3,3);
   printf("Score:%d",score);
}