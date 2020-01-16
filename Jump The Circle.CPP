//Game cirlce jump

#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
#include<bios.h>
#include<time.h>

//creating sturuct for storing point of line
struct pointsOfLine
{
  int x,y,x1,y1;
};
//create varible to store struct line
int numberOfLine=20;
pointsOfLine linePoint[20];
//intial cordinates for line

//cordinates for border

int maxX=639,maxY=460,minX=0,minY=10;

//variable for ellipse
int   midy = 239,midx=40;
int xradius = 10, yradius =30;
int key;

//auto update ellipse
void upDateEllipse();
//if player update the ellipse
void playerUpdateEllipse();
//to update line
void updateLine();
//variable for line

//variable for move line
int countMove=0;
//detction variable
int detect=0;

//utlilty program to find distance

double distance();
// to detect collsion
void detectCollsion();
//function to generate random number for line
void generatingRand();
//funtction to generate one more line
void generateOneLine();
main()
{
   int gd = DETECT, gm;


   linePoint[0].x=0,linePoint[0].y=239,linePoint[0].x1=320,linePoint[0].y1=239;

   //genrate lines of differet size for enviroment
   generatingRand();

   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

   //draw border
   rectangle(minX,minY,maxX,maxY);

   while(1)
   {
      while(bioskey(1)==0)
      {
	//Ellispse is updated downward
	upDateEllipse();
	//to move line
	updateLine();
	//check if player cross the line
	if(linePoint[0].x1<=midx-40)
	{
	  generateOneLine();
	}
	 //function for collsion detection
	 detectCollsion();
	 if(detect)    //if detect is one then player collide with boundry
	 {
	   getch();
	   detect=0;
	 }


      }//endofBioskey
      key=bioskey(0);
      if(key==4209) //Q(quit)
      {
	 return 0;
      }
     if(key==14624)   //Space bar
     {
       updateLine();           //to update envirment
       playerUpdateEllipse();  //update ellispse if user want

      }

   }//endofWhile


  // closegraph();
//   return 0;


}
void upDateEllipse()
{
	  //detect collsion during update of ellipse
	 detectCollsion();

	 if(detect)
	 {
	   getch();

	   detect=0;
	 }

	delay(20);
	setcolor(BLACK);
	ellipse(midx, midy, 0, 360,xradius, yradius);
	midy=midy+2;  //mid of Ellispe
	setcolor(WHITE);
	//draw Ellispse
	ellipse(midx, midy, 0, 360,xradius, yradius);

}
void playerUpdateEllipse()
{

      //if player want to update his/her postion

       delay(10);
       int pixeltomove=0;
       //move ellipse 20 step up
       while(pixeltomove<20)
       {

	 detectCollsion();

	 if(detect)
	 {
	   getch();
	 //  return 0;
	   detect=0;
	 }

       setcolor(BLACK);
       ellipse(midx , midy, 0, 360,xradius, yradius);
       midy--;
       setcolor(WHITE);
       ellipse(midx, midy, 0, 360,xradius, yradius);
       pixeltomove++;

     }
}
void updateLine()
{
     delay(2);
     //loop for move line
    for(countMove=0;countMove<numberOfLine;countMove++)
    {
	 detectCollsion();

	 if(detect)
	 {
	  // getch();
	  // return 0;
	   detect=0;

	 }


	 setcolor(BLACK);
	 line(linePoint[countMove].x,linePoint[countMove].y,linePoint[countMove].x1,linePoint[countMove].y1);
	 linePoint[countMove].x1--;
	 linePoint[countMove].x--;
	 setcolor(WHITE);
	 rectangle(minX,minY,maxX,maxY);
	 setcolor(GREEN);

	line(linePoint[countMove].x,linePoint[countMove].y,linePoint[countMove].x1,linePoint[countMove].y1);
    }//End of For loop
}
//utility program to find distance
double distance(int a,int b,int a1,int b1)
{
   double q;
   double u1;
   q=a1-a;
   u1=b1-b;
   double t,u,sum,ans;
   t=pow(q,2);
   u=pow(u1,2);
   sum=t+u;
   ans=sqrt(sum);
   return ans;
}

void detectCollsion()
{
    int q=0;
	 for(q=0;q<numberOfLine;q++)
	{
	int actualY=midy-yradius;
	int actualY1=midy+yradius;
	double disLine,disPnt1,disPnt2;
	disLine=distance(linePoint[q].x,linePoint[q].y,linePoint[q].x1,linePoint[q].y1);
	disPnt1= distance(midx,actualY,linePoint[q].x,linePoint[q].y);
	disPnt2=distance(linePoint[q].x1,linePoint[q].y1,midx,actualY);
	disLine=ceil(disLine);
	disPnt2=ceil(disPnt2);
	disPnt1=ceil(disPnt1);
	double disL1,disL2;
	disL1=distance(midx,actualY1,linePoint[q].x,linePoint[q].y);
	disL2=distance(linePoint[q].x1,linePoint[q].y1,midx,actualY1);
	disL1=ceil(disL1);
	disL2=ceil(disL2);       //ceil is function to round off number closer to large number

	if((disPnt1+disPnt2)==disLine || ((disL1+disL2)==disLine))
	{
	     detect=1;
	}
	if(detect)
	break;

      }
}
//function for generating random number for line
void generatingRand()
{
   int count=0;
   int rand1x,rand2y;

linePoint[0].x=0,linePoint[0].y=239,linePoint[0].x1=320,linePoint[0].y1=239;
//     time_t t=5;

   for(count=1;count<numberOfLine;count++)
   {
     rand1x=random(620);
     //if x-axis is less then previous x-aix;
     if(rand1x<=linePoint[count-1].x1)
     {
	 rand1x=linePoint[count-1].x1+70;
     }
     rand2y=random(460);
     //check for y whater it too long
     while(rand2y<=200||rand2y>=320)
     {
       rand2y=rand()%460;
     }

     linePoint[count].x=linePoint[count-1].x1;
     linePoint[count].y=linePoint[count-1].y1;
     linePoint[count].y1=rand2y;
     linePoint[count].x1=rand1x;
     rand2y=0;
     rand1x=0;
    // srand((unsigned) time(&t));

  }//EndofForLoop

}
void generateOneLine()
{
    int q=0;

    for(q=0;q<(numberOfLine-1);q++)
    {

     linePoint[q].x=linePoint[q+1].x;
     linePoint[q].y=linePoint[q+1].y;
     linePoint[q].y1=linePoint[q+1].y1;
     linePoint[q].x1=linePoint[q+1].x1;

    }//end of for loop
    int rand1x,rand2y;

    linePoint[numberOfLine-1].x=linePoint[numberOfLine-2].x1;
    linePoint[numberOfLine-1].y=linePoint[numberOfLine-2].y1;

    rand1x=random(620);
     if(rand1x<=linePoint[numberOfLine-2].x1)
     {
	 rand1x=linePoint[numberOfLine-2].x1+70;
     }
     rand2y=random(460);
     while(rand2y<=200||rand2y>=320)
     {
       rand2y=rand()%460-50;
     }

    linePoint[numberOfLine-1].y1=rand2y;
    linePoint[numberOfLine-1].x1=rand1x;

}