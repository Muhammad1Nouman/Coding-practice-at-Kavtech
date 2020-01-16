#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<bios.h>
#include<stdio.h>


//key for detecting keyboard keys
int key=0;

//cordinates for rectangle

int minX=0,minY=0,maxX=639,maxY=475;

//cordinates for intiailzing Player

int dirRight=0,dirLeft=0,dirUp=0,dirDown=0;

//variables for player
int playerPosX1=339,playerPosX2=400,playerPosY1=420,playerPosY2=470;
int lineX1,lineX2,lineY1,lineY2;

//count is for number of fire
int count=0;

int fireIsPressed=0; //variable if fire is pressed

//loop variabel for fire
int loop;

//intial max and min position of player
int playerMaxPos=0;
int playerMinPos=0;
int playerDownMax=0;
int playerUpMax=0;

//counter for checking number of enemy
int count1=0;

//variable of score
int score=1;

//variable for increasing number of enemey
int noOfEnemy=0;
void updatePlayer();

void updateLine();

void update(); //utility program to move array one step backward

struct fireData
{
  int lineX1,lineY1,lineY2;
};

fireData Line[5000];

struct enemyData
{
  int boxX1,boxX2,boxY1,boxY2;
};
enemyData Box[900];


//function for detecing collsion of Box and fire
void collsionBoxAndFire();

//function for update boxes
void updateBoxes();

//function for generate boxes
void generateBoxes();

//function fpr show score
void showscore();

//function for game over
void gameOver();
//variable for game over
int gameOve=0;
main()
{

  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  //drawBorderRectangle
//  setbkcolor(BLUE);
  rectangle(minX,minY,maxX,maxY);
  generateBoxes();

  getch();
  while(1)
  {

  while(bioskey(1)==0)
  {
    if(gameOve!=1)
    {
     updatePlayer();
     updateLine();
     updateBoxes();
     gameOver();
     }
  }

  //Draw border rectangle
//  rectangle(minX,minY,maxX,maxY);
   setcolor(BLACK);
   line(minX,maxY,maxX,maxY);
   line(minX,minY,maxX,minY);
   setcolor(WHITE);
  showscore();

  key=bioskey(0);

    if(key==4209)  //For QUIT
    {
      return 0;
    }
    if(key==19712) //right move
    {
       dirRight=1;   //assure that player move right
       dirLeft=0;
       dirUp=0;
       dirDown=0;
    }
    if(key==19200)   //left move
    {
	dirLeft=1;   //assure that player move left
	dirRight=0;
	dirUp=0;
	dirDown=0;
    }
    if(key==18432)
    {
      dirUp=1;
      dirDown=0;
      dirLeft=0;
      dirRight=0;
    }
    if(key==20480)
    {
      dirDown=1;
      dirUp=0;
      dirLeft=0;
      dirRight=0;
    }
    if(key==14624) //space bar
    {
	//  sound(90);
	 Line[count].lineX1=(playerPosX1+playerPosX2)/2;
	 Line[count].lineY1=playerPosY1-5;
	 Line[count].lineY2=playerPosY1-7;
	 //draw fire
	 line(Line[count].lineX1,Line[count].lineY1,Line[count].lineX1,Line[count].lineY2);
	 fireIsPressed=1;
	 count++;          //store number of fire is pressed
	 if(count==2000)
	 {
	    count=0;
	 }
    }

  }
 // getch();

//  return 0;

}
void updatePlayer()
{


   delay(10);
   setcolor(BLACK);
//   rectangle(playerPosX1,playerPosY1,playerPosX2,playerPosY2);
   line((playerPosX1+playerPosX2)/2,playerPosY2-2,(playerPosX1+playerPosX2)/2-10,playerPosY2-2);
   line((playerPosX1+playerPosX2)/2,playerPosY2-2,(playerPosX1+playerPosX2)/2+10,playerPosY2-2);
   line((playerPosX1+playerPosX2)/2+10,playerPosY2-2,(playerPosX1+playerPosX2)/2+10,playerPosY2-9);
   line((playerPosX1+playerPosX2)/2-10,playerPosY2-2,(playerPosX1+playerPosX2)/2-10,playerPosY2-9);

   line((playerPosX1+playerPosX2)/2+10,playerPosY2-9,(playerPosX1+playerPosX2)/2+4,playerPosY2-12);
   line((playerPosX1+playerPosX2)/2-10,playerPosY2-9,(playerPosX1+playerPosX2)/2-4,playerPosY2-12);
   line((playerPosX1+playerPosX2)/2-4,playerPosY2-12,(playerPosX1+playerPosX2)/2-8,playerPosY2-20);
   line((playerPosX1+playerPosX2)/2+4,playerPosY2-12,(playerPosX1+playerPosX2)/2+8,playerPosY2-20);
   line((playerPosX1+playerPosX2)/2+8,playerPosY2-20,(playerPosX1+playerPosX2)/2+8,playerPosY2-40);
   line((playerPosX1+playerPosX2)/2-8,playerPosY2-20,(playerPosX1+playerPosX2)/2-8,playerPosY2-40);
   line((playerPosX1+playerPosX2)/2-8,playerPosY2-40,(playerPosX1+playerPosX2)/2,playerPosY2-50);
   line((playerPosX1+playerPosX2)/2+8,playerPosY2-40,(playerPosX1+playerPosX2)/2,playerPosY2-50);
   //cockpit
   line((playerPosX1+playerPosX2)/2-8,playerPosY2-35,(playerPosX1+playerPosX2)/2-20,playerPosY2-35);
   line((playerPosX1+playerPosX2)/2+8,playerPosY2-35,(playerPosX1+playerPosX2)/2+20,playerPosY2-35);
  //wing
   line((playerPosX1+playerPosX2)/2+20,playerPosY2-35,(playerPosX1+playerPosX2)/2+20,playerPosY2-30);
   line((playerPosX1+playerPosX2)/2-20,playerPosY2-35,(playerPosX1+playerPosX2)/2-20,playerPosY2-30);
   //wing
   line((playerPosX1+playerPosX2)/2-20,playerPosY2-30,(playerPosX1+playerPosX2)/2-9,playerPosY2-28);
   line((playerPosX1+playerPosX2)/2+20,playerPosY2-30,(playerPosX1+playerPosX2)/2+9,playerPosY2-28);

   line((playerPosX1+playerPosX2)/2,playerPosY1,(playerPosX1+playerPosX2)/2,playerPosY1-5);
     if(dirLeft==1&&playerMinPos==0)
     {
       playerPosX1=playerPosX1-3;
       playerPosX2=playerPosX2-3;
       playerMaxPos=0;
     }
     else if(dirRight==1&&playerMaxPos==0)
     {
       playerPosX1=playerPosX1+3;
       playerPosX2=playerPosX2+3;
       playerMinPos=0;
     }
   else if(dirUp==1&&playerUpMax==0)
     {
       playerPosY1=playerPosY1-3;
       playerPosY2=playerPosY2-3;
       playerDownMax=0;

     }
     else if(dirDown==1&&playerDownMax==0)
     {
       playerPosY1=playerPosY1+3;
       playerPosY2=playerPosY2+3;
       playerUpMax=0;
     }
    setcolor(WHITE);
    if(playerPosX2>633)
    {
      playerMaxPos=1;
    }
    if(playerPosX1<5)
    {
	playerMinPos=1;
    }
    if(playerPosY1<5)
    {
      playerUpMax=1;
    }
    if(playerPosY2>470)
    {
       playerDownMax=1;
    }
//   rectangle(playerPosX1,playerPosY1,playerPosX2,playerPosY2);

    line((playerPosX1+playerPosX2)/2,playerPosY2-2,(playerPosX1+playerPosX2)/2-10,playerPosY2-2);
   line((playerPosX1+playerPosX2)/2,playerPosY2-2,(playerPosX1+playerPosX2)/2+10,playerPosY2-2);
   line((playerPosX1+playerPosX2)/2+10,playerPosY2-2,(playerPosX1+playerPosX2)/2+10,playerPosY2-9);
   line((playerPosX1+playerPosX2)/2-10,playerPosY2-2,(playerPosX1+playerPosX2)/2-10,playerPosY2-9);

   line((playerPosX1+playerPosX2)/2+10,playerPosY2-9,(playerPosX1+playerPosX2)/2+4,playerPosY2-12);
   line((playerPosX1+playerPosX2)/2-10,playerPosY2-9,(playerPosX1+playerPosX2)/2-4,playerPosY2-12);
   line((playerPosX1+playerPosX2)/2-4,playerPosY2-12,(playerPosX1+playerPosX2)/2-8,playerPosY2-20);
   line((playerPosX1+playerPosX2)/2+4,playerPosY2-12,(playerPosX1+playerPosX2)/2+8,playerPosY2-20);
   line((playerPosX1+playerPosX2)/2+8,playerPosY2-20,(playerPosX1+playerPosX2)/2+8,playerPosY2-40);
   line((playerPosX1+playerPosX2)/2-8,playerPosY2-20,(playerPosX1+playerPosX2)/2-8,playerPosY2-40);
   line((playerPosX1+playerPosX2)/2-8,playerPosY2-40,(playerPosX1+playerPosX2)/2,playerPosY2-50);
   line((playerPosX1+playerPosX2)/2+8,playerPosY2-40,(playerPosX1+playerPosX2)/2,playerPosY2-50);
   //cockpit
   line((playerPosX1+playerPosX2)/2-8,playerPosY2-35,(playerPosX1+playerPosX2)/2-20,playerPosY2-35);
   line((playerPosX1+playerPosX2)/2+8,playerPosY2-35,(playerPosX1+playerPosX2)/2+20,playerPosY2-35);
  //wing
   line((playerPosX1+playerPosX2)/2+20,playerPosY2-35,(playerPosX1+playerPosX2)/2+20,playerPosY2-30);
   line((playerPosX1+playerPosX2)/2-20,playerPosY2-35,(playerPosX1+playerPosX2)/2-20,playerPosY2-30);
   //wing
   line((playerPosX1+playerPosX2)/2-20,playerPosY2-30,(playerPosX1+playerPosX2)/2-9,playerPosY2-28);
   line((playerPosX1+playerPosX2)/2+20,playerPosY2-30,(playerPosX1+playerPosX2)/2+9,playerPosY2-28);

   line((playerPosX1+playerPosX2)/2,playerPosY1,(playerPosX1+playerPosX2)/2,playerPosY1-5);
}
void updateLine()
{
  if(fireIsPressed==1)
  {

	delay(1);
	for(loop=0;loop<count;loop++)
	{
		setcolor(BLACK);

		collsionBoxAndFire();    //check collision

		line(Line[loop].lineX1,Line[loop].lineY1,Line[loop].lineX1,Line[loop].lineY2);
		Line[loop].lineY1=Line[loop].lineY1-4;
		Line[loop].lineY2=Line[loop].lineY2-4;

		collsionBoxAndFire();     //check collsion

		setcolor(WHITE);
		line(Line[loop].lineX1,Line[loop].lineY1,Line[loop].lineX1,Line[loop].lineY2);

	}





  }
}
void collsionBoxAndFire()
{
    int Box_no=0;
     for(Box_no=0;Box_no<count1;Box_no++)
     {
	if(Line[loop].lineX1>=Box[Box_no].boxX1&&Line[loop].lineY2<=Box[Box_no].boxY2&&Line[loop].lineX1<=Box[Box_no].boxX2&&Line[loop].lineY1>=Box[Box_no].boxY1)
	{
	  setcolor(BLACK);
	//  rectangle(Box[Box_no].boxX1,Box[Box_no].boxY1,Box[Box_no].boxX2,Box[Box_no].boxY2);
	     line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1-2,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1-2);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1-2,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1-2);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1-1,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+5);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1-1,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+5);

   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+6,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+4,Box[Box_no].boxY1+10);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+6,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-4,Box[Box_no].boxY1+10);

   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-4,Box[Box_no].boxY1+10,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+25);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+4,Box[Box_no].boxY1+10,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+25);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+25,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1+30);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+25,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1+30);



	  Box[Box_no].boxX1=-1;
	  line(Line[loop].lineX1,Line[loop].lineY1,Line[loop].lineX1,Line[loop].lineY2);
	  Line[loop].lineX1=-1;
	  score++;
	  showscore();
	  update();
	  generateBoxes();
	}
    }
}
void updateBoxes()
{
   delay(3);
   int Box_no=0;
   for(Box_no=0;Box_no<count1;Box_no++)
   {

    setcolor(BLACK);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1-2,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1-2);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1-2,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1-2);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1-1,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+5);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1-1,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+5);

   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+6,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+4,Box[Box_no].boxY1+10);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+6,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-4,Box[Box_no].boxY1+10);

   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-4,Box[Box_no].boxY1+10,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+25);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+4,Box[Box_no].boxY1+10,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+25);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+25,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1+30);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+25,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1+30);


 //   rectangle(Box[Box_no].boxX1,Box[Box_no].boxY1,Box[Box_no].boxX2,Box[Box_no].boxY2);
    Box[Box_no].boxY1++;
    Box[Box_no].boxY2++;
    setcolor(WHITE);
   // rectangle(Box[Box_no].boxX1,Box[Box_no].boxY1,Box[Box_no].boxX2,Box[Box_no].boxY2);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1-2,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1-2);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1-2,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1-2);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1-1,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+5);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1-1,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+5);

   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+6,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+4,Box[Box_no].boxY1+10);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+6,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-4,Box[Box_no].boxY1+10);

   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-4,Box[Box_no].boxY1+10,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+25);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+4,Box[Box_no].boxY1+10,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+25);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2-10,Box[Box_no].boxY1+25,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1+30);
   line((Box[Box_no].boxX1+Box[Box_no].boxX2)/2+10,Box[Box_no].boxY1+25,(Box[Box_no].boxX1+Box[Box_no].boxX2)/2,Box[Box_no].boxY1+30);

   }
}
void generateBoxes()
{




	   int c=-60,d=-30;

	   Box[count1].boxX2=rand()%639;
	  //generating random x-axis position of enemey
	   if(Box[count1].boxX2>=100)
	   {
	   Box[count1].boxX1=Box[count1].boxX2-30;
	   }
	   else
	   {

	   Box[count1].boxX2=Box[count1].boxX2+500;
	   Box[count1].boxX1=Box[count1].boxX2-30;
	   }
	  Box[count1].boxY1=-60;  //assigneing intial position to enemey
	  Box[count1].boxY2=-30;
	  setcolor(WHITE);
     //	  rectangle(Box[count1].boxX1,Box[count1].boxY1,Box[count1].boxX2,Box[count1].boxY2);
	 // rectangle(minX,minY,maxX,maxY);
	      line((Box[count1].boxX1+Box[count1].boxX2)/2,Box[count1].boxY1-2,(Box[count1].boxX1+Box[count1].boxX2)/2-10,Box[count1].boxY1-2);
   line((Box[count1].boxX1+Box[count1].boxX2)/2,Box[count1].boxY1-2,(Box[count1].boxX1+Box[count1].boxX2)/2+10,Box[count1].boxY1-2);
   line((Box[count1].boxX1+Box[count1].boxX2)/2+10,Box[count1].boxY1-1,(Box[count1].boxX1+Box[count1].boxX2)/2+10,Box[count1].boxY1+5);
   line((Box[count1].boxX1+Box[count1].boxX2)/2-10,Box[count1].boxY1-1,(Box[count1].boxX1+Box[count1].boxX2)/2-10,Box[count1].boxY1+5);

   line((Box[count1].boxX1+Box[count1].boxX2)/2+10,Box[count1].boxY1+6,(Box[count1].boxX1+Box[count1].boxX2)/2+4,Box[count1].boxY1+10);
   line((Box[count1].boxX1+Box[count1].boxX2)/2-10,Box[count1].boxY1+6,(Box[count1].boxX1+Box[count1].boxX2)/2-4,Box[count1].boxY1+10);

   line((Box[count1].boxX1+Box[count1].boxX2)/2-4,Box[count1].boxY1+10,(Box[count1].boxX1+Box[count1].boxX2)/2-10,Box[count1].boxY1+25);
   line((Box[count1].boxX1+Box[count1].boxX2)/2+4,Box[count1].boxY1+10,(Box[count1].boxX1+Box[count1].boxX2)/2+10,Box[count1].boxY1+25);
   line((Box[count1].boxX1+Box[count1].boxX2)/2-10,Box[count1].boxY1+25,(Box[count1].boxX1+Box[count1].boxX2)/2,Box[count1].boxY1+30);
   line((Box[count1].boxX1+Box[count1].boxX2)/2+10,Box[count1].boxY1+25,(Box[count1].boxX1+Box[count1].boxX2)/2,Box[count1].boxY1+30);

	   count1++;

	  setcolor(BLACK);
	  if(score%10==0)
	  {
	   int enemy=0;
	   if(noOfEnemy<4)
	   noOfEnemy++;
	   if(count1<6){

	   for(enemy=0;enemy<noOfEnemy;enemy++)
	   {
		Box[count1].boxX2=rand()%639;
		 //generating random x-axis position of enemey
		if(Box[count1].boxX2>30)
		{
		Box[count1].boxX1=Box[count1].boxX2-30;
		}
		else
		{
		 Box[count1].boxX2=Box[count1].boxX2+100;
		 Box[count1].boxX1=Box[count1].boxX2-30;
		}
		 Box[count1].boxY1=c;  //assigneing intial position to enemey
		 Box[count1].boxY2=d;
		 setcolor(WHITE);
       //		 rectangle(Box[count1].boxX1,Box[count1].boxY1,Box[count1].boxX2,Box[count1].boxY2);
	 // rectangle(minX,minY,maxX,maxY);
		c=c-60;
		d=d-30;
		count1++;
		if(count1<10)
		break;

	       }
	   }
	  }
}

void update()
{  //enemy
   int q=0;
   for(q=0;q<count1;q++)
   {
      if(Box[q].boxX1==-1)
      break;
   }
   int x=0;
   for(x=q;x<count1;x++)
   {
    if((x+1)<count1){
     Box[x].boxX1=Box[x+1].boxX1;
     Box[x].boxY1=Box[x+1].boxY1;
     Box[x].boxX2=Box[x+1].boxX2;
     Box[x].boxY2=Box[x+1].boxY2;
    }
   }
   count1--;//enemy is less
   for(q=0;q<count;q++)
   {
      if(Line[q].lineX1==-1)
      break;

   }
   for(x=q;x<count;x++)
   {
    if((x+1)<count){
     Line[x].lineX1=Line[x+1].lineX1;
     Line[x].lineY1=Line[x+1].lineY1;
     Line[x].lineY2=Line[x+1].lineY2;
    }
   }
   count--;

}
void showscore()
{
  gotoxy(3,3);
  printf("Score:%d",score);
}
void gameOver()
{
  int q=0;
   for(q=0;q<count1;q++)
   {
       if(Box[q].boxY2>=475)
       {
	 gameOve=1;
	 gotoxy(35,16);
	 printf("Game Over");
	 break;
       }
   }


}