#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include <ctype.h>
using namespace std;
void display();  //prototype of function for displaying details for the prgram
//This class contain all the possible state of a single state
class PossibleState{
private:
	char currCharater;
	int State;
public:
	//Deafulat Contructor
	PossibleState()
	{
		currCharater = '\0';
		State = 0;
	}
	//Overloaded constructor
	PossibleState(char currChatacter, int state)
	{
		this->currCharater = currChatacter;
		this->State = state;
	}
	//setter for character
	void setChar(char chara)
	{
		currCharater = chara;
	}
	//setter for state
	void setState(int setS)
	{
		State = setS;
	}
	//getter for character
	char getChar()
	{
		return currCharater;
	}
	//getter for state
	int getState()
	{
		return State;
	}

};
//This class store the current stat and the number of state that each state have
class state : public PossibleState{
private:
	int currentState;
	int numberOfPossibleState;
	PossibleState* possibleState;
	int nextState;
public:
	//Default constructor
	state()
	{
		currentState = 0;
		numberOfPossibleState = 0;
		nextState = NULL;
	}

	// constructor overloaded
	state(int currentState, int numberOfPossibleState, PossibleState* possibleState)
	{
		this->numberOfPossibleState = numberOfPossibleState;
		this->currentState =currentState;
		this->possibleState = new PossibleState[numberOfPossibleState];

		for (int i = 0; i < numberOfPossibleState; i++)
		{
			this->possibleState[i].setChar(possibleState[i].getChar());
			this->possibleState[i].setState(possibleState[i].getState());
		}

	}
	//Function for determin next state
	int nextStateFind(int currentState,char a)
	{
		for (int i = 0; i < numberOfPossibleState; i++)
		{
			if (isupper(a))
			{
				a = tolower(a);   //This method is for transforming the uper case letter to lower
			}
			if (this->possibleState[i].getChar() == a)
				return this->possibleState[i].getState();
			

		}
		for (int i = 0; i < numberOfPossibleState; i++)
		{
			if (this->possibleState[i].getChar() == '!')
				return this->possibleState[i].getState();

			if (this->possibleState[i].getChar() == '#')
				return this->possibleState[i].getState();

			if (this->possibleState[i].getChar() == '@')
				return this->possibleState[i].getState();
       }
	}
};
int main()
{

   	display();
	//Variable section
	PossibleState ** allState = new PossibleState*[20];
	int nextState = 0;   //nextState is for after state after reading a character
	char userChoice;    //this var is used for determine user choice to end a program
	
	
	//0
	allState[0] = new PossibleState[3];
	allState[0][0].setState(1);
	allState[0][0].setChar('w');
	allState[0][1].setState(4);
	allState[0][1].setChar('!');  //Any Character except w and .
	allState[0][2].setState(19);
	allState[0][2].setChar('.');
	//1

	allState[1] = new PossibleState[3];
	allState[1][0].setState(4);
	allState[1][0].setChar('!');  //Any Character except w and .
	allState[1][1].setState(5);
	allState[1][1].setChar('.');
	allState[1][2].setState(2);
	allState[1][2].setChar('w');

	//2
	allState[2] = new PossibleState[3];
	allState[2][0].setState(4);
	allState[2][0].setChar('!');  //Any Character except w and .
	allState[2][1].setState(5);
	allState[2][1].setChar('.');
	allState[2][2].setState(3);
	allState[2][2].setChar('w');

	//3
	allState[3] = new PossibleState[2];
	allState[3][0].setState(4);
	allState[3][0].setChar('@');  //Any Character except  .
	allState[3][1].setState(14);
	allState[3][1].setChar('.');

	//4
	allState[4] = new PossibleState[2];
	allState[4][0].setState(4);
	allState[4][0].setChar('@');  //Any Character except  .
	allState[4][1].setState(5);
	allState[4][1].setChar('.');
	//5 
	allState[5] = new PossibleState[4];
	allState[5][0].setState(19);
	allState[5][0].setChar('#');  //All character 
	allState[5][1].setState(11);
	allState[5][1].setChar('p');
	allState[5][2].setState(6);
	allState[5][2].setChar('e');
	allState[5][3].setState(9);
	allState[5][3].setChar('c');

	//6
	allState[6] = new PossibleState[2];
	allState[6][0].setState(19);
	allState[6][0].setChar('#');  //All character 
	allState[6][1].setState(7);
	allState[6][1].setChar('d');

	//7
	allState[7] = new PossibleState[2];
	allState[7][0].setState(19);
	allState[7][0].setChar('#');  //All character 
	allState[7][1].setState(8);
	allState[7][1].setChar('u');

	//8
	allState[8] = new PossibleState[1];
	allState[8][0].setState(19);
	allState[8][0].setChar('#');  //All character

	//9
	allState[9] = new PossibleState[2];
	allState[9][0].setState(10);
	allState[9][0].setChar('o');  //All character 
	allState[9][1].setState(19);
	allState[9][1].setChar('#');  //All character 


	//10
	allState[10] = new PossibleState[2];
	allState[10][0].setState(19);
	allState[10][0].setChar('#');  //All character 
	allState[10][1].setState(8);
	allState[10][1].setChar('m');  //All character 


	 //11
	allState[11] = new PossibleState[2];
	allState[11][0].setState(19);
	allState[11][0].setChar('#');  //All character 
	allState[11][1].setState(8);
	allState[11][1].setChar('k');  //All character 

	//12
	allState[12] = new PossibleState[3];
	allState[12][0].setState(5);
	allState[12][0].setChar('.');  //All character 
	allState[12][1].setState(15);
	allState[12][1].setChar('o');  //All character 
	allState[12][2].setState(4);
	allState[12][2].setChar('@');  //All character 

	//13
	allState[13] = new PossibleState[3];
	allState[13][0].setState(5);
	allState[13][0].setChar('.');  //All character 
	allState[13][1].setState(17);
	allState[13][1].setChar('d');  //All character 
	allState[13][2].setState(4);
	allState[13][2].setChar('@');  //All character 

	//14
	allState[14] = new PossibleState[5];
	allState[14][0].setState(4);
	allState[14][0].setChar('@');  //Any Character except  .
	allState[14][1].setState(12);
	allState[14][1].setChar('c');
	allState[14][2].setState(19);
	allState[14][2].setChar('.');
	allState[14][3].setState(13);
	allState[14][3].setChar('e');
	allState[14][4].setState(16);
	allState[14][4].setChar('p');

	//15
	allState[15] = new PossibleState[3];
	allState[15][0].setState(18);
	allState[15][0].setChar('m'); 
	allState[15][1].setState(4);
	allState[15][1].setChar('@'); //Any Character except  .
	allState[15][2].setState(5);
	allState[15][2].setChar('.');   


	//16
	allState[16] = new PossibleState[3];
	allState[16][0].setState(18);
	allState[16][0].setChar('k');   
	allState[16][1].setState(4);
	allState[16][1].setChar('@'); //Any Character except  .
	allState[16][2].setState(5);
	allState[16][2].setChar('.');  

	//17
	allState[17] = new PossibleState[3];
	allState[17][0].setState(18);
	allState[17][0].setChar('u');  
	allState[17][1].setState(4);
	allState[17][1].setChar('@'); //Any Character except  . 
	allState[17][2].setState(5);
	allState[17][2].setChar('.');

	//18
	allState[18] = new PossibleState[2];
	allState[18][0].setState(4);
	allState[18][0].setChar('@'); //Any Character except  . 
	allState[18][1].setState(5);
	allState[18][1].setChar('.');

	//19
	allState[19] = new PossibleState[1];
	allState[19][0].setState(19);
	allState[19][0].setChar('#');    //Any character



	
	
	//Intialzing all state with possible states
	state* State[] = { new state(0, 3, allState[0]),
		new state(1, 3, allState[1]),
		new state(2, 3, allState[2]),
		new state(3, 2, allState[3]),
		new state(4, 2, allState[4]),
		new state(5, 4, allState[5]),
		new state(6, 2, allState[6]),
		new state(7, 2, allState[7]),
		new state(8, 1, allState[8]),
		new state(9, 2, allState[9]),
		new state(10, 2, allState[10]),
		new state(11, 2, allState[11]),
		new state(12, 2, allState[12]),
		new state(13, 3, allState[13]),
		new state(14, 5, allState[14]),
		new state(15, 3, allState[15]),
		new state(16, 3, allState[16]),
		new state(17, 3, allState[17]),
		new state(18, 2, allState[18]),
		new state(19, 1, allState[19]),
	};
	
	
	cin >> userChoice;    //Getting an input  user choice
	while (userChoice == 'y' || userChoice == 'Y')
	{
		string validUrl = ""; //this is for getting url from the user

		cout << "Enter your URL:";
		cin >> validUrl; /*Note:: It will break on  space character*/
		for (int i = 0; i < validUrl.length(); i++)
		{
			nextState = State[nextState]->nextStateFind(nextState, validUrl[i]);
			cout << "State q:" << nextState << endl;
		}
		// HERE 17 19 13 8 and 10 are final state of this automata
		if (nextState == 18 || nextState == 8)
		{
			cout << "Your URL is accepted by the machine your final state is "<<nextState<<endl;
		}
		else if (nextState == 19)
		{
			cout << "Your URL ended in trap state  " << nextState<<endl;
		}
		else
		{
			cout << "Your URL is inncorrect" << endl;
		}
		nextState = 0;
		
		cout << "Press Y for enter a string or N for terminating program:";
	//	cin >> userChoice;
	}
	return 0;

}
void display()
{
	// This Segment of the code will provide the introduction about the program such its all valid state as well as dead state

	cout << "\n  \t Name: Muhammad Nouman \n\t Section: CS-F \n\t Rollno:16-4309\n\n";
	cout << " What this program actual does? \n Ans: This program is for a machine that take a string as input and print out its state until string is end ";
	cout << "\n \n There are total 20 tates \n \t 19 are valid \n \t 1 is trap state";

	//End of introduction segment

	system("pause");  //System call that pauses program excution until any character is pressed
	system("CLS");   //System call that clear the current screen of program


	cout << "\n\nPress Y for enter a string or N for terminating program:";

}