#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<bios.h>
//Varible area

//TOSS Varibale
int random1;
int updateLocation=0;
int updateLocation1=0;
//Key is for keyboard
int key=0;
//Two 2d array for inteligence level
int** inteligenceLeVel;

//Varible to decide game is end or not
int gameOver=0;

// number of game win by user and cpu
int user=0,cpu=0;
//if user win
int gameOver1=0;
//if Cpu win
int gameOver2=0;
//Variable for inteligence level
int inteligenceLevel=0;
//Variable for generate Random box for Tic Tac
int randomBox=0;

//ARRAY Variables

//count varibale is for arrayUser[]
int count=0;

//count1 variable is for arrayCpu[]
int count1=0;

// array for keep check location empty or not
int saveLocation[10]={0};

// array for storing locaiton of player
int arrayUser[5];

// array for storing location of CPU
int arrayCpu[5];

//Function area

//Function for Toss
void toss();

//Function for user turn
void userTurn();

//Function for decide winner if cpu
void functionForDecideWinner1();

//Funtion for decide if user win
void functionForDecideWinner();

//Functio for displaying Result of user
void displayResult();

//Function for displaying Result of CPU
void displayResult1();

//Function for cpu turn

void cpuTurn();
//function for inteligence check
int inteligencCheck();

//function for put circle axis in file
void putCirclAxisInFile();

// function for put data in 2d array
void putdata();

//function for intilaizing everything
void intilaizing();
main()
{


int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

  //decide who is going to play first
	intilaizing();
       toss();
      putdata();
      random1=1;
  while(1)
    {


    //if user turn
     if(random1==1)
     {
      if(updateLocation==0)
      {
       userTurn();
       }
      delay(300);
      if(updateLocation==1)
      {
	     cpuTurn();

	 updateLocation=0;
      }

   }
 if(gameOver1==1 || gameOver2==1)
   {
     //increase inteligence level of TicTac


      putCirclAxisInFile();

      cleardevice();

      setcolor(WHITE);
      intilaizing();
      count1=0;
      count=0;
       toss();
      random1=1;
      gameOver1=0;
      gameOver2=0;
      updateLocation=0;
      int x=0;
      for(x=0;x<inteligenceLevel;x++)
      delete[] inteligenceLeVel[x];
      delete inteligenceLeVel;
      putdata();

 }

   if(key==4209)
   {
     return 0;
   }


 }

 // getch();
 // return 0;
}
void toss()
{


  gotoxy(37,13);
  printf("TICTAC GAME");
  getch();
  cleardevice();

  gotoxy(35,13);
  printf("TOSS IF ONE THEN YOUR TURN");
  getch();

  srand(time(NULL));

  cleardevice();
  gotoxy(37,13);
  random1=rand()%2+1;

  if(random1==1)
  {
  printf("YOUR TURN %d",random1);
  }
  else
  {
   printf("CPU TURN %d",random1);
  }
  getch();
  cleardevice();

   //vertical lines

   line(234,142,234,342);
   line(290,142,290,342);

   //Botttom lines

   line(118,216,418,216);
   line(118,270,418,270);
   gotoxy(30,5);
   printf("User:%d - Cpu:%d",user,cpu);
   gotoxy(50,5);
   printf("Inteligence LeveL: %d",inteligenceLevel);
  // getch();


}

void userTurn()
{
   key=bioskey(0);

  if(key==561&&!saveLocation[0])    //1
    {
	setcolor(5);
	circle(177,178,20);
	saveLocation[0]=1;
	updateLocation1=0;
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
	updateLocation1=0;
	arrayUser[count]=2;
	count++;

    }
    if(key==1075&&!saveLocation[2])     //3
    {
	setcolor(5);
	circle(332,180,20);
	saveLocation[2]=3;
	updateLocation=1;
	updateLocation1=0;
	arrayUser[count]=3;
	count++;

    }
    if(key==1332&&!saveLocation[3])        //4
    {
	setcolor(5);
	circle(175,240,20);
	saveLocation[3]=4;
	updateLocation=1;
	updateLocation1=0;
	arrayUser[count]=4;
	count++;
    }
    if(key==1589&&!saveLocation[4])           //5
    {
	setcolor(5);
	circle(257,239,20);
	saveLocation[4]=5;
	updateLocation=1;
	updateLocation1=0;
	arrayUser[count]=5;
	count++;
    }
    if(key==1846&&!saveLocation[5])              //6
    {
	setcolor(5);
	circle(327,239,20);
	saveLocation[5]=6;
	updateLocation=1;
	updateLocation1=0;
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
	updateLocation1=0;
	count++;
    }

    if(key==2360&&!saveLocation[7])                //8
    {
	setcolor(5);
	circle(258,299,20);
	saveLocation[7]=8;
	updateLocation=1;
	arrayUser[count]=8;
	updateLocation1=0;
	count++;
    }
    if(key==2617&&!saveLocation[8])    //9
    {
	setcolor(5);
	circle(332,297,20);
	saveLocation[8]=9;
	updateLocation=1;
	updateLocation1=0;
	arrayUser[count]=9;
	count++;
    }
    functionForDecideWinner();

}
void cpuTurn()
{
   int varil=0;

    while(saveLocation[randomBox]!=0)
    {
     srand(time(NULL));
     randomBox=rand()%8;
    }
 varil=inteligencCheck();
 if(!varil){
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
  }
  functionForDecideWinner1();
}
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
   c=0;
}
void displayResult()
{
     gotoxy(7,7);
     printf("WINNER IS USER");
     gameOver1=1;
     gameOver=1;
     inteligenceLevel++;
     user++;

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
   c=0;

}
void displayResult1()
{
     gotoxy(7,7);
     printf("WINNER IS CPU");
     gameOver=1;
     gameOver2=1;
     cpu++;
}
int inteligencCheck()
{
  int loop=0,loop1=0,loop3=0,checkMeet=0,q=0,z,d;
  for(loop=0;loop<inteligenceLevel;loop++)
  {
     z=inteligenceLeVel[loop][0];

     while(inteligenceLeVel[loop][q]!=0)
     {
     d=inteligenceLeVel[loop][q];
     q++;
     }

    if(z==4)
	d=d-1;


     q=0;
     for(loop1=1,loop3=0;loop1<=inteligenceLeVel[loop][0]&&loop3<=count;loop1++,loop3++)
     {
       if(inteligenceLeVel[loop][loop1]==arrayUser[loop3])
       {
	   checkMeet++;
	   if(checkMeet==(inteligenceLeVel[loop][0]-1)&&saveLocation[d-1]==0)
	   {
	       checkMeet=0;
	       setcolor(6);
	       circle(inteligenceLeVel[loop][6],inteligenceLeVel[loop][7],20);
	       arrayCpu[count1]=d;

	       saveLocation[d-1]=d;
		count1++;
	       return 1;

	   }

       }
     }
     checkMeet=0;
  }
  return 0;
}

void putCirclAxisInFile()
{
   int loop1,loop2;
   ofstream fout;
   fout.open("Example.txt");
   fout<<inteligenceLevel<<endl;

   if(inteligenceLevel>1){

    for(loop1=0;loop1<inteligenceLevel-1;loop1++)
    {
       for(loop2=0;loop2<8;loop2++)
       {
	 fout<<inteligenceLeVel[loop1][loop2]<<" ";
       }
       fout<<endl;
    }
   }
    fout<<count<<" ";
   for(loop1=0;loop1<count;loop1++)
   {
      fout<<arrayUser[loop1]<<" ";
   }
   int c=5-count;
   for(loop1=0;loop1<c;loop1++)
   {
     fout<<0<<" ";
   }

   if(arrayUser[count]==1)
   {
      fout<<177<<" "<<178;
   }
   if(arrayUser[count-1]==2)
   {
     fout<<261<<" "<<178;
   }
   if(arrayUser[count-1]==3)
   {
     fout<<332<<" "<<180;
   }
   if(arrayUser[count-1]==4)
   {
     fout<<175<<" "<<240;
   }
   if(arrayUser[count-1]==5)
   {
     fout<<257<<" "<<239;
   }
   if(arrayUser[count-1]==6)
   {
     fout<<327<<" "<<239;
   }
   if(arrayUser[count-1]==7)
   {
     fout<<173<<" "<<296;
   }
   if(arrayUser[count-1]==8)
   {
     fout<<258<<" "<<299;
   }
   if(arrayUser[count-1]==9)
   {
     fout<<332<<" "<<297;
   }
   fout.close();
  // filecolse=0;
}
void putdata()
{

     ifstream fin;
     fin.open("Example.txt");
     fin>>inteligenceLevel;
       inteligenceLeVel=new int*[inteligenceLevel];
       //loop variable
       int loop,loop1;
       for(loop=0;loop<inteligenceLevel;loop++)
       {
	  inteligenceLeVel[loop]=new int[8];
       }
     if(inteligenceLevel>0)
     {
       //variable for reading data from file

       for(loop=0;loop<inteligenceLevel;loop++)
       {
	 for(loop1=0;loop1<8;loop1++)
	 {

		 fin>>inteligenceLeVel[loop][loop1];


	  }


       }

	 fin.close();
    }


}
void intilaizing()
{
	   int q=0;
     for(q=0;q<5;q++)
     {
       arrayUser[q]=0;
       arrayCpu[q]=0;

      }
    for(q=0;q<10;q++)
    saveLocation[q]=0;

}




