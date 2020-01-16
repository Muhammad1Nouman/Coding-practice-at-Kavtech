#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<bios.h>
#include<stdio.h>
#include<stdlib.h>
int maxX=639,maxY=460,minX=0,minY=10;
//utitlity program to display reslut of user
void displayResult();
void displayResult1();
//update tictac by computer
void updateTicTac();
//vairable for computer update;
int updateLocation=0;
//union REGS i,o;
int key;
//array for storing location
int saveLocation[9]={0,0,0,0,0,0,0,0,0};
//using array one for cpu and one for user
int arrayCpu[5]={0};
int arrayUser[5]={0};
//counter for detect currently of user input and cpu;
int count=0,count1=0;
//function to decide who is win player or cpu
void functionForDecideWinner();
void functionForDecideWinner1();
//if user one step away from winning
int oneStepAwayFromWinning();
//if cpu one step away from winnig
int oneStepAwayFromWinning1();
//variable for game over;
int gameOver=0;
main()

{

   int gd=DETECT,gm,x,y,button,tempx,tempy;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");



   //vertical lines

   line(234,142,234,342);
   line(290,142,290,342);

   //Botttom lines

   line(118,216,418,216);
   line(118,270,418,270);

   while(1)
   {

 //  while(bioskey(1)==0)
 //  {

  // }//EndOfBiosWhile

    key=bioskey(0);



    if(key==4209 || gameOver==1)    //Q (quit)
    {
     // getch();
      return 0;
    }
  else
  {

   if(key==561&&!saveLocation[0])    //1
    {
	setcolor(5);
	circle(177,178,20);
	saveLocation[0]=1;
	updateLocation=1;
	arrayUser[count]=1;
	count++;
    }
    if(key==818&&!saveLocation[1])   //2
    {
	setcolor(5);
	circle(261,178,20);
	saveLocation[1]=2;
	updateLocation=1;
	arrayUser[count]=2;
	count++;

    }
    if(key==1075&&!saveLocation[2])     //3
    {
	setcolor(5);
	circle(332,180,20);
	saveLocation[2]=3;
	updateLocation=1;
	arrayUser[count]=3;
	count++;

    }
    if(key==1332&&!saveLocation[3])        //4
    {
	setcolor(5);
	circle(175,240,20);
	saveLocation[3]=4;
	updateLocation=1;
	arrayUser[count]=4;
	count++;
    }
    if(key==1589&&!saveLocation[4])           //5
    {
	setcolor(5);
	circle(257,239,20);
	saveLocation[4]=5;
	updateLocation=1;
	arrayUser[count]=5;
	count++;
    }
    if(key==1846&&!saveLocation[5])              //6
    {
	setcolor(5);
	circle(327,239,20);
	saveLocation[5]=6;
	updateLocation=1;
	arrayUser[count]=6;
	count++;
    }
    if(key==2103&&!saveLocation[6])                 //7
    {
	setcolor(5);
	circle(173,296,20);
	saveLocation[6]=7;
	updateLocation=1;
	arrayUser[count]=7;
	count++;
    }

    if(key==2360&&!saveLocation[7])                //8
    {
	setcolor(5);
	circle(258,299,20);
	saveLocation[7]=8;
	updateLocation=1;
	arrayUser[count]=8;
	count++;
    }
    if(key==2617&&!saveLocation[8])    //9
    {
	setcolor(5);
	circle(332,297,20);
	saveLocation[8]=9;
	updateLocation=1;
	arrayUser[count]=9;
	count++;
    }

      functionForDecideWinner();



      if(gameOver)
      {
	 getch();
	 return 0;

      }
    delay(500);
    if(updateLocation)
    {

	updateTicTac();
      updateLocation=0;

    }

  //  gotoxy(5,5);
 //   printf("%d",key);
    }
   }
   // getch();
  //  return 0;
}

void updateTicTac()
{
  int randomBox=-1;
  int checkfill;
  int check=0,check1=0;
    if(!check)
   check1=oneStepAwayFromWinning1();  //For winnig of CPU
    if(!check1)
    check=oneStepAwayFromWinning();

  for(checkfill=0;checkfill<9;checkfill++)
  {
	if(saveLocation[checkfill]==0)
	{
	  break;
	}

  }
    if(checkfill!=9)
   {

    while(saveLocation[randomBox]!=0)
    {         srand(time(NULL));
//   random1=rand()%12;

     randomBox=rand()%8;

    }
  }

 // int check1=0;
  // if(!check1){
  if(randomBox!=-1)
  {
 if(!check&&!check1)
 {


  if(randomBox==0&&!saveLocation[0])
  {
     setcolor(6);
     circle(177,178,20);
     saveLocation[0]=1;
     arrayCpu[count1]=1;
     count1++;
  }

  if(randomBox==1&&!saveLocation[1])
  {
    setcolor(6);
     circle(261,178,20);
     saveLocation[1]=2;
     arrayCpu[count1]=2;
     count1++;
   }
  if(randomBox==2&&!saveLocation[2])
  {
     setcolor(6);
     circle(332,180,20);
     saveLocation[2]=3;
     arrayCpu[count1]=3;
     count1++;
  }
  if(randomBox==3&&!saveLocation[3])
  {
     setcolor(6);
     circle(175,240,20);
     saveLocation[3]=4;
     arrayCpu[count1]=4;
     count1++;
  }
  if(randomBox==4&&!saveLocation[4])
  {
     setcolor(6);
     circle(257,239,20);
     saveLocation[4]=5;
     arrayCpu[count1]=5;
     count1++;
  }
  if(randomBox==5&&!saveLocation[5])
  {
     setcolor(6);
     circle(327,239,20);
     saveLocation[5]=6;
     arrayCpu[count1]=6;
     count1++;
  }
  if(randomBox==6&&!saveLocation[6])
  {
     setcolor(6);
     circle(173,296,20);
     saveLocation[6]=7;
     arrayCpu[count1]=7;
     count1++;
  }
  if(randomBox==7&&!saveLocation[7])
  {
     setcolor(6);
     circle(258,299,20);
     saveLocation[7]=8;
     arrayCpu[count1]=8;
     count1++;
  }
  if(randomBox==8&&!saveLocation[8])
  {
     setcolor(6);
     circle(332,297,20);
     saveLocation[8]=9;
     arrayCpu[count1]=9;
     count1++;
  }

   } //Endoffuntion if
   functionForDecideWinner1();
  //   if(!oneStepAwayFromWinning())
//  }//for cpu
 }//endofif

}//end of function
void functionForDecideWinner()
{
   int k=0;  //it is for loop
   int c=0;  //check user win
   for(k=0;k<count;k++)
   {
     if(arrayUser[k]==1||arrayUser[k]==2||arrayUser[k]==3)
     {
	  c++;
     }

   }

   if(c==3)
   {
      displayResult();
//      setcolor(RED);
      line(140,178,370,178);
   }
    c=0;
   for(k=0;k<count;k++)
   {
     if(arrayUser[k]==4||arrayUser[k]==5||arrayUser[k]==6)
     {
	  c++;
     }

   }

   if(c==3)
   {  displayResult();
      line(140,240,370,240);
      c=0;
    }
    c=0;
    for(k=0;k<count;k++)
   {
     if(arrayUser[k]==7||arrayUser[k]==8||arrayUser[k]==9)
     {
	  c++;
     }
   }

   if(c==3)
   {
      displayResult();
      line(140,296,370,296);
      c=0;
    }
    c=0;
    for(k=0;k<count;k++)
   {
     if(arrayUser[k]==1||arrayUser[k]==4||arrayUser[k]==7)
     {
	  c++;
     }

   }


   if(c==3)
   {  displayResult();
      line(177,140,177,350);

      c=0;
    }
    c=0;
    for(k=0;k<count;k++)
   {
     if(arrayUser[k]==2||arrayUser[k]==5||arrayUser[k]==8)
     {
	  c++;
     }

   }

   if(c==3)
   {
    displayResult();
    line(261,140,261,350);
      c=0;
    }
     c=0;
    for(k=0;k<count;k++)
   {
     if(arrayUser[k]==3||arrayUser[k]==6||arrayUser[k]==9)
     {
	  c++;
     }

   }

   if(c==3)
   {  displayResult();
      line(332,140,332,350);
      c=0;
    }
    c=0;
    for(k=0;k<count;k++)
   {
     if(arrayUser[k]==1||arrayUser[k]==5||arrayUser[k]==9)
     {
	  c++;
     }

   }

   if(c==3)
   {
      displayResult();
      c=0;
    }
    c=0;
    for(k=0;k<count;k++)
   {
     if(arrayUser[k]==3||arrayUser[k]==5||arrayUser[k]==7)
     {
	  c++;
     }

   }
    if(c==3)
   {
      displayResult();
      c=0;
    }

}
void displayResult()
{
     gotoxy(7,7);
     printf("THE WINNER IS USER");
    // getch();
    gameOver=1;

}
void functionForDecideWinner1()
{
   int k=0;   //it is for loop
   int c=0;  //to check cpu win or not
   for(k=0;k<count1;k++)
   {
     if(arrayCpu[k]==1||arrayCpu[k]==2||arrayCpu[k]==3)
     {
	  c++;
     }

   }

   if(c==3)
   {
      displayResult1();

      line(140,178,370,178);
   }
    c=0;
   for(k=0;k<count1;k++)
   {
     if(arrayCpu[k]==4||arrayCpu[k]==5||arrayCpu[k]==6)
     {
	  c++;
     }

   }

   if(c==3)
   {  displayResult1();
      line(140,240,370,240);
      c=0;
    }
    c=0;
    for(k=0;k<count1;k++)
   {
     if(arrayCpu[k]==7||arrayCpu[k]==8||arrayCpu[k]==9)
     {
	  c++;
     }
   }

   if(c==3)
   {  displayResult1();
      line(140,296,370,296);
      c=0;
    }
    c=0;
    for(k=0;k<count1;k++)
   {
     if(arrayCpu[k]==1||arrayCpu[k]==4||arrayCpu[k]==7)
     {
	  c++;
     }

   }


   if(c==3)
   {  displayResult1();
      line(177,140,177,350);

      c=0;
    }
    c=0;
    for(k=0;k<count1;k++)
   {
     if(arrayCpu[k]==2||arrayCpu[k]==5||arrayCpu[k]==8)
     {
	  c++;
     }

   }

   if(c==3)
   {
    displayResult1();
    line(261,140,261,350);
      c=0;
    }
     c=0;
    for(k=0;k<count1;k++)
   {
     if(arrayCpu[k]==3||arrayCpu[k]==6||arrayCpu[k]==9)
     {
	  c++;
     }

   }

   if(c==3)
   {  displayResult1();
      line(332,140,332,350);
      c=0;
    }
    c=0;
    for(k=0;k<count1;k++)
   {
     if(arrayCpu[k]==1||arrayCpu[k]==5||arrayCpu[k]==9)
     {
	  c++;
     }

   }

   if(c==3)
   {
      displayResult1();
      c=0;
    }
    c=0;
     for(k=0;k<count1;k++)
   {
     if(arrayCpu[k]==3||arrayCpu[k]==5||arrayCpu[k]==7)
     {
	  c++;
     }

   }
    if(c==3)
   {
      displayResult1();
      c=0;
    }


}
void displayResult1()
{
     gotoxy(7,7);
     printf("WINNER IS CPU");
     gameOver=1;
}
int oneStepAwayFromWinning()
{
    int k=0;
    int c=0;
    for(k=0;k<count;k++) //1
    {
	if(arrayUser[k]==2 || arrayUser[k]==3)
	c++;
	if(c==2&&!saveLocation[0])
	{
	   setcolor(6);
	   circle(177,178,20);
	   saveLocation[0]=1;
	   arrayCpu[count1]=1;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count;k++)  //1
      {
	if(arrayUser[k]==4 || arrayUser[k]==7)
	c++;
	if(c==2&&!saveLocation[0])
	{
	   setcolor(6);
	   circle(177,178,20);
	   saveLocation[0]=1;
	   arrayCpu[count1]=1;
	   count1++;
	   return 1;

	}

      }
      c=0;
       for(k=0;k<count;k++)    //1
      {
	if(arrayUser[k]==5 || arrayUser[k]==9)
	c++;
	if(c==2&&!saveLocation[0])
	{
	   setcolor(6);
	   circle(177,178,20);
	   saveLocation[0]=1;
	   arrayCpu[count1]=1;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count;k++)        //2
      {
	if(arrayUser[k]==5 || arrayUser[k]==8)
	c++;
	if(c==2&&!saveLocation[1])
	{
	   setcolor(6);
	   circle(261,178,20);
	   saveLocation[1]=2;
	   arrayCpu[count1]=2;
	   count1++;
	   return 1;

	}

      }
     c=0;
	  for(k=0;k<count;k++)        //2
	 {
	if(arrayUser[k]==1 || arrayUser[k]==3)
	c++;
	if(c==2&&!saveLocation[1])
	{
	   setcolor(6);
	   circle(261,178,20);
	   saveLocation[1]=2;
	   arrayCpu[count1]=2;
	   count1++;
	   return 1;

	}

      }

      c=0;
      for(k=0;k<count;k++)           //3
      {
	if(arrayUser[k]==1 || arrayUser[k]==2)
	c++;
	if(c==2&&!saveLocation[2])
	{
	   setcolor(6);
	   circle(332,178,20);
	   saveLocation[2]=3;
	   arrayCpu[count1]=3;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count;k++)              //3
      {


      if(arrayUser[k]==5 || arrayUser[k]==7)
	c++;
	if(c==2&&!saveLocation[2])
	{
	   setcolor(6);
	   circle(332,178,20);
	   saveLocation[2]=3;
	   arrayCpu[count1]=3;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count;k++)   //3
      {
	if(arrayUser[k]==6 || arrayUser[k]==9)
	c++;
	if(c==2&&!saveLocation[2])
	{
	   setcolor(6);
	   circle(332,178,20);
	   saveLocation[2]=3;
	   arrayCpu[count1]=3;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count;k++)      //4
      {
	if(arrayUser[k]==5 || arrayUser[k]==6)
	c++;
	if(c==2&&!saveLocation[3])
	{
	   setcolor(6);
	   circle(175,240,20);
	   saveLocation[3]=4;
	   arrayCpu[count1]=4;
	   count1++;
	   return 1;

	}

      }
	c=0;
      for(k=0;k<count;k++)      //4
      {
	if(arrayUser[k]==1 || arrayUser[k]==7)
	c++;
	if(c==2&&!saveLocation[3])
	{
	   setcolor(6);
	   circle(175,240,20);
	   saveLocation[3]=4;
	   arrayCpu[count1]=4;
	   count1++;
	   return 1;

	}

      }
	c=0;
      for(k=0;k<count;k++)      //5
      {
	if(arrayUser[k]==1 || arrayUser[k]==9)
	c++;
	if(c==2&&!saveLocation[4])
	{
	   setcolor(6);
	   circle(257,239,20);
	   saveLocation[4]=5;
	   arrayCpu[count1]=5;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count;k++)      //5
      {
	if(arrayUser[k]==3 || arrayUser[k]==7)
	c++;
	if(c==2&&!saveLocation[4])
	{
	   setcolor(6);
	   circle(257,239,20);
	   saveLocation[4]=5;
	   arrayCpu[count1]=5;
	   count1++;
	   return 1;

	}

      }
       c=0;
      for(k=0;k<count;k++)      //5
      {
	if(arrayUser[k]==2 || arrayUser[k]==8)
	c++;
	if(c==2&&!saveLocation[4])
	{
	   setcolor(6);
	   circle(257,239,20);
	   saveLocation[4]=5;
	   arrayCpu[count1]=5;
	   count1++;
	   return 1;

	}

      }
	    c=0;
      for(k=0;k<count;k++)      //5
      {
	if(arrayUser[k]==4 || arrayUser[k]==6)
	c++;
	if(c==2&&!saveLocation[4])
	{
	   setcolor(6);
	   circle(257,239,20);
	   saveLocation[4]=5;
	   arrayCpu[count1]=5;
	   count1++;
	   return 1;

	}

      }


       c=0;
       for(k=0;k<count;k++)        //6
      {
	if(arrayUser[k]==4 || arrayUser[k]==5)
	c++;
	if(c==2&&!saveLocation[5])
	{
	   setcolor(6);
	   circle(327,239,20);
	   saveLocation[5]=6;
	   arrayCpu[count1]=6;
	   count1++;
	   return 1;

	}

      }
	  c=0;
       for(k=0;k<count;k++)        //6
      {
	if(arrayUser[k]==3 || arrayUser[k]==9)
	c++;
	if(c==2&&!saveLocation[5])
	{
	   setcolor(6);
	   circle(327,239,20);
	   saveLocation[5]=6;
	   arrayCpu[count1]=6;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count;k++)      //7
      {
	if(arrayUser[k]==1 || arrayUser[k]==4)
	c++;
	if(c==2&&!saveLocation[6])
	{
	   setcolor(6);
	   circle(173,296,20);
	   saveLocation[6]=7;
	   arrayCpu[count1]=7;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count;k++)         //7
      {
	if(arrayUser[k]==3 || arrayUser[k]==5)
	c++;
	if(c==2&&!saveLocation[6])
	{
	   setcolor(6);
	   circle(173,296,20);
	   saveLocation[6]=7;
	   arrayCpu[count1]=7;
	   count1++;
	   return 1;

	}
	c=0;
	for(k=0;k<count;k++)          //7
	{
	if(arrayUser[k]==8 || arrayUser[k]==9)
	c++;
	if(c==2&&!saveLocation[6])
	{
	   setcolor(6);
	   circle(173,296,20);
	   saveLocation[6]=7;
	   arrayCpu[count1]=7;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count;k++)               //8
      {
	if(arrayUser[k]==2 || arrayUser[k]==5)
	c++;
	if(c==2&&!saveLocation[7])
	{
	   setcolor(6);
	   circle(258,299,20);
	   saveLocation[7]=8;
	   arrayCpu[count1]=8;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count;k++)               //8
      {
	if(arrayUser[k]==7 || arrayUser[k]==9)
	c++;
	if(c==2&&!saveLocation[7])
	{
	   setcolor(6);
	   circle(258,299,20);
	   saveLocation[7]=8;
	   arrayCpu[count1]=8;
	   count1++;
	   return 1;

	}

      }

       c=0;
       for(k=0;k<count;k++)           //9
       {
	if(arrayUser[k]==1 || arrayUser[k]==5)
	c++;
	if(c==2&&!saveLocation[8])
	{
	   setcolor(6);
	   circle(332,297,20);
	   saveLocation[8]=9;
	   arrayCpu[count1]=9;
	   count1++;
	   return 1;

	}

      }
	 c=0;
	 for(k=0;k<count;k++)            //9
	 {
	if(arrayUser[k]==3 || arrayUser[k]==6)
	c++;
	if(c==2&&!saveLocation[8])
	{
	   setcolor(6);
	   circle(332,297,20);
	   saveLocation[8]=9;
	   arrayCpu[count1]=9;
	   count1++;
	   return 1;

	}

      }
      c=0;
	for(k=0;k<count;k++)      //9
       {
	if(arrayUser[k]==7 || arrayUser[k]==8)
	c++;
	if(c==2&&!saveLocation[8])
	{
	   setcolor(6);
	   circle(332,297,20);
	   saveLocation[8]=9;
	   arrayCpu[count1]=9;
	   count1++;
	   return 1;

	}

      }





      }






       return 0;




}
int oneStepAwayFromWinning1()
{
       int k=0;
    int c=0;
    for(k=0;k<count1;k++) //1
    {
	if(arrayCpu[k]==2 || arrayCpu[k]==3)
	c++;
	if(c==2&&!saveLocation[0])
	{
	   setcolor(6);
	   circle(177,178,20);
	   saveLocation[0]=1;
	   arrayCpu[count1]=1;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count1;k++)  //1
      {
	if(arrayCpu[k]==4 || arrayCpu[k]==7)
	c++;
	if(c==2&&!saveLocation[0])
	{
	   setcolor(6);
	   circle(177,178,20);
	   saveLocation[0]=1;
	   arrayCpu[count1]=1;
	   count1++;
	   return 1;

	}

      }
      c=0;
       for(k=0;k<count1;k++)    //1
      {
	if(arrayCpu[k]==5 || arrayCpu[k]==9)
	c++;
	if(c==2&&!saveLocation[0])
	{
	   setcolor(6);
	   circle(177,178,20);
	   saveLocation[0]=1;
	   arrayCpu[count1]=1;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count1;k++)        //2
      {
	if(arrayCpu[k]==5 || arrayCpu[k]==8)
	c++;
	if(c==2&&!saveLocation[1])
	{
	   setcolor(6);
	   circle(261,178,20);
	   saveLocation[1]=2;
	   arrayCpu[count1]=2;
	   count1++;
	   return 1;

	}

      }
     c=0;
	  for(k=0;k<count1;k++)        //2
	 {
	if(arrayCpu[k]==1 || arrayCpu[k]==3)
	c++;
	if(c==2&&!saveLocation[1])
	{
	   setcolor(6);
	   circle(261,178,20);
	   saveLocation[1]=2;
	   arrayCpu[count1]=2;
	   count1++;
	   return 1;

	}

      }

      c=0;
      for(k=0;k<count1;k++)           //3
      {
	if(arrayCpu[k]==1 || arrayCpu[k]==2)
	c++;
	if(c==2&&!saveLocation[2])
	{
	   setcolor(6);
	   circle(332,178,20);
	   saveLocation[2]=3;
	   arrayCpu[count1]=3;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count1;k++)              //3
      {


      if(arrayCpu[k]==5 || arrayCpu[k]==7)
	c++;
	if(c==2&&!saveLocation[2])
	{
	   setcolor(6);
	   circle(332,178,20);
	   saveLocation[2]=3;
	   arrayCpu[count1]=3;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count1;k++)   //3
      {
	if(arrayCpu[k]==6 || arrayCpu[k]==9)
	c++;
	if(c==2&&!saveLocation[2])
	{
	   setcolor(6);
	   circle(332,178,20);
	   saveLocation[2]=3;
	   arrayCpu[count1]=3;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count1;k++)      //4
      {
	if(arrayCpu[k]==5 || arrayCpu[k]==6)
	c++;
	if(c==2&&!saveLocation[3])
	{
	   setcolor(6);
	   circle(175,240,20);
	   saveLocation[3]=4;
	   arrayCpu[count1]=4;
	   count1++;
	   return 1;

	}

      }
	c=0;
      for(k=0;k<count1;k++)      //4
      {
	if(arrayCpu[k]==1 || arrayCpu[k]==7)
	c++;
	if(c==2&&!saveLocation[3])
	{
	   setcolor(6);
	   circle(175,240,20);
	   saveLocation[3]=4;
	   arrayCpu[count1]=4;
	   count1++;
	   return 1;

	}

      }
	c=0;
      for(k=0;k<count1;k++)      //5
      {
	if(arrayCpu[k]==1 || arrayCpu[k]==9)
	c++;
	if(c==2&&!saveLocation[4])
	{
	   setcolor(6);
	   circle(257,239,20);
	   saveLocation[4]=5;
	   arrayCpu[count1]=5;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count1;k++)      //5
      {
	if(arrayCpu[k]==3 || arrayCpu[k]==7)
	c++;
	if(c==2&&!saveLocation[4])
	{
	   setcolor(6);
	   circle(257,239,20);
	   saveLocation[4]=5;
	   arrayCpu[count1]=5;
	   count1++;
	   return 1;

	}

      }
       c=0;
      for(k=0;k<count1;k++)      //5
      {
	if(arrayCpu[k]==2 || arrayCpu[k]==8)
	c++;
	if(c==2&&!saveLocation[4])
	{
	   setcolor(6);
	   circle(257,239,20);
	   saveLocation[4]=5;
	   arrayCpu[count1]=5;
	   count1++;
	   return 1;

	}

      }
	    c=0;
      for(k=0;k<count1;k++)      //5
      {
	if(arrayCpu[k]==4 || arrayCpu[k]==6)
	c++;
	if(c==2&&!saveLocation[4])
	{
	   setcolor(6);
	   circle(257,239,20);
	   saveLocation[4]=5;
	   arrayCpu[count1]=5;
	   count1++;
	   return 1;

	}

      }


       c=0;
       for(k=0;k<count1;k++)        //6
      {
	if(arrayCpu[k]==4 || arrayCpu[k]==5)
	c++;
	if(c==2&&!saveLocation[5])
	{
	   setcolor(6);
	   circle(327,239,20);
	   saveLocation[5]=6;
	   arrayCpu[count1]=6;
	   count1++;
	   return 1;

	}

      }
	  c=0;
       for(k=0;k<count1;k++)        //6
      {
	if(arrayCpu[k]==3 || arrayCpu[k]==9)
	c++;
	if(c==2&&!saveLocation[5])
	{
	   setcolor(6);
	   circle(327,239,20);
	   saveLocation[5]=6;
	   arrayCpu[count1]=6;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count1;k++)      //7
      {
	if(arrayCpu[k]==1 || arrayCpu[k]==4)
	c++;
	if(c==2&&!saveLocation[6])
	{
	   setcolor(6);
	   circle(173,296,20);
	   saveLocation[6]=7;
	   arrayCpu[count1]=7;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count1;k++)         //7
      {
	if(arrayCpu[k]==3 || arrayCpu[k]==5)
	c++;
	if(c==2&&!saveLocation[6])
	{
	   setcolor(6);
	   circle(173,296,20);
	   saveLocation[6]=7;
	   arrayCpu[count1]=7;
	   count1++;
	   return 1;

	}
	c=0;
	for(k=0;k<count1;k++)          //7
	{
	if(arrayCpu[k]==8 || arrayCpu[k]==9)
	c++;
	if(c==2&&!saveLocation[6])
	{
	   setcolor(6);
	   circle(173,296,20);
	   saveLocation[6]=7;
	   arrayCpu[count1]=7;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count1;k++)               //8
      {
	if(arrayCpu[k]==2 || arrayCpu[k]==5)
	c++;
	if(c==2&&!saveLocation[7])
	{
	   setcolor(6);
	   circle(258,299,20);
	   saveLocation[7]=8;
	   arrayCpu[count1]=8;
	   count1++;
	   return 1;

	}

      }
      c=0;
      for(k=0;k<count1;k++)               //8
      {
	if(arrayCpu[k]==7 || arrayCpu[k]==9)
	c++;
	if(c==2&&!saveLocation[7])
	{
	   setcolor(6);
	   circle(258,299,20);
	   saveLocation[7]=8;
	   arrayCpu[count1]=8;
	   count1++;
	   return 1;

	}

      }

       c=0;
       for(k=0;k<count1;k++)           //9
       {
	if(arrayCpu[k]==1 || arrayCpu[k]==5)
	c++;
	if(c==2&&!saveLocation[8])
	{
	   setcolor(6);
	   circle(332,297,20);
	   saveLocation[8]=9;
	   arrayCpu[count1]=9;
	   count1++;
	   return 1;

	}

      }
	 c=0;
	 for(k=0;k<count1;k++)            //9
	 {
	if(arrayCpu[k]==3 || arrayCpu[k]==6)
	c++;
	if(c==2&&!saveLocation[8])
	{
	   setcolor(6);
	   circle(332,297,20);
	   saveLocation[8]=9;
	   arrayCpu[count1]=9;
	   count1++;
	   return 1;

	}

      }
      c=0;
	for(k=0;k<count1;k++)      //9
       {
	if(arrayCpu[k]==7 || arrayCpu[k]==8)
	c++;
	if(c==2&&!saveLocation[8])
	{
	   setcolor(6);
	   circle(332,297,20);
	   saveLocation[8]=9;
	   arrayCpu[count1]=9;
	   count1++;
	   return 1;

	}

      }





      }






       return 0;



}