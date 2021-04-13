/* 
   Author:    Princekumar Diyora
   Date:      6 Dec. 2019
   Purpose:   The main purpose of this assignment is to show the waht I learned
              from this subject. In this lab I created 2D array, constants, char array,
              structs, enum, typedef, for loops, do while loops, while loops, and 
              functions. 
*/

#include <cstdio> //for printf and scanf
#include <cctype> //for toupper
#include <cstdlib> //for srand, and rand
#include <ctime>  //for TIME
#include<iostream> // using cin and cout
using namespace std;

//declaring constant for playing game 
const char YES = 'Y';

//constant for not playing game
const char NO = 'N';

const int NA=0;

//constant for the food
//and we are storing the character x into the
//variable named food
const char FOOD='x';

//declaring constant for the rabbit
//and character r we are storing the
//variable named rabbit
const char RABBIT='R';

//declaring constant for maximum array size
const int MAX_SIZE=256;

//declaring constant for moving left
const char LEFT_MOVE='a';

//declaring constant for moving right
const char RIGHT_MOVE='d';

//declaring constant character for moving up
const char UP_MOVE='w';

//declaring constant character for moving down
const char DOWN_MOVE='s';

//declaring typdef
//character array named Buffer
typedef char Buffer[MAX_SIZE];

//declaring enum for moving rabbit
enum Move{LEFT, RIGHT, UP, DOWN};

/* Declaring a global variable is not good idea but if declare variable
   in the function then it creates confusion for me so this is the reason
   I created my all variables globally. 
*/

//storing that move into moving variable
Move moving;

//decalring variable for so that we can access in whole program
//and later we are calling getIntInRange function
//in this variable
int size=0;

//declairng the variable and storing size in the varaible
//this variable shows the life of rabbit
int rabbitLife;

//here we are decalring constant for minimum value
//and which is 4
const int MIN = 4;

//decalring costant for maximum value
//and which is 16
const int MAX = 16;

//decalring the 2D array for the using in whole program
//and maximum size for 2d array is 16 by 16
//storing them in varaible named MAX before
char input[MAX][MAX];

//this variable is for x axis
//and I am using these variable when I am passing arguments
//to mu function
int a=0;

//this variable is for the y axis
int b=0;

//declaring the function named displayOverview
//this will desplay all the rules and regulation of the game
void displayOverview();

//prompts the user to enter Y for yes, or N for no
//returns true if they enterd yes, if they say no then it will display BYE message
//if user enter any other character insted of y and n then it will ask user
//untill they will not enter true caharacter
//and we are asuming that user only enters single characater
bool wantToPlay();

//decalres the function name getIntInRange
//promots user to enter a number between range 4 and 16
//if wrong displays message and ask untill you will not enter a true value
//we are passing min and max value as an parameter
//this function returns integer value 
int getIntInRange(int min, int max);

//declaring the function named printArray
//this will print the grid as per user value
//we also prints food and rabbit's (0,0) position in
//this function
void  printGrid();

//declaring the function named generateFood
//this function will generate food at random place
//for example user enters 4 then it will generate 4 food
//at random place
//in this function we are using random function
void generateFood();

//declaring the function named moveRabbit
//through this function rabbit can move into the grid by cell
//if there is a food then it will increase rabbit's life by 2
//and if there is no any food then it will decrease the life
//of rabbit by 1.
//and if user will enter any invalid number then 'a','s','d','w'
//these four character then it will print error messsge and ask
//agin to enter a valid number until user will not
//enter a correct number
void moveRabbit(int &xAxis, int &yAxis);

//I am calling all my function in one function
//and decalring as callAllFunction
void callAllFunction();

//main routine
int main()
{
     //this is for random function for getting radom value
     srand(time(NULL));

     //calling the function named callAllFunction
     callAllFunction();

     //returning 0
     return 0;
}

//implementing the function named displayOverview
//this will desplay all the rules and regulation of the game
void displayOverview()
{
     cout << "Hello Dear:\n";
     cout << "Welcome to this amazing game!\n";
     cout << "\n";
     cout << "* First of all, this will display overview of all the game,\n";
     cout << "  means what are the rules and regulation you have to follow.\n";
     cout << "* This will ask you that, do you want to play a game or not?,\n";
     cout << "* If you want to play a game then press (Y or y) and for quit the game,\n ";
     cout << "  please press (N or n) and then it will show you bye message. \n";
     cout << "* Now, It will ask you to enter a number for the size of grid you want,\n";
     cout << "  to play on and you can enter a number between 4 and 16 (inclusive).\n";
     cout << "* After that it wil show you n by n grid with some randomly generated food and,\n";
     cout << "  character x is for the food and character R is for the Rabbit.\n";
     cout << "* Also it will show the current life of rabbit.\n";
     cout << "* Then it will ask you to enter your move and in which direction you want to move,\n";
     cout << "  your rabbit.\n";
     cout << "* For moving the rabbit there are some key you can press.For example,\n";
     cout << "  for going right side press 'd', for going left side press 'a', for going up side\n";
     cout << "  please press 'w', and for down side please press 's'.\n";
     cout << "* If you will enter any other number or character then it will ask you again,and \n";
     cout << "* we are assuming that you only enters a single charcater.\n";
     cout << "* Now if you will move rabbit towards the food and if rabbit successfully,\n";
     cout << "  able to eat food then it will increase your health by 2.\n";
     cout << "* If the cell you move to has no food then it will decrease helth by 1.\n";
     cout << "* If the rabbit's health reaches to zero , then rabbit will go into hiberation and, \n";
     cout << "  you lose the game.\n";
     cout << "* If the rabbits all the food then you will win the game.\n";
     cout << "* In the end, It will ask you to restart the game and if you wish to play again then\n";
     cout << "  please enter 0 and for quit enter any other number.\n";
     cout << "* SO, Are you Rady,\n";
     cout << "\n";
     cout << "Let's play this GAME!\n";   
}

//prompts the user to enter Y for yes, or N for no
//returns true if they enterd yes, if they say no then it will display BYE message
//if user enter any other character insted of y and n then it will ask user
//untill they will not enter true caharacter
//and we are asuming that user only enters single characater
bool wantToPlay()
{
     // declaring the variable
     bool doPlay = true;

     cout << "Do you want to play this interessting GAME: "<<YES<<":yes, "<<NO<<":no :\n";

     // this variable is for user input
     char Input;
     cin >> Input;

     //toupper will help user for typing y and n
     //means you can enter lowercase and uppercase
     Input=toupper(Input);
     
     // here we are using recursion
     if(Input==YES) // if user will enter y then it will return true
     {
          return true;
	  
     }else if(Input==NO) // if user will enter n then it will return false
     {
          return false;
     }
     else
     {
	  // we are trying to clear buffer by reading in a single character
          scanf("%*c");
	  return wantToPlay(); // if user will enter any other character then function will call by it self
     }
    
     return doPlay;
}

// defines the function named getIntnRange
// passing min and max value as parameters
// getting value from the user
int getIntInRange(int min, int max)
{
     // decalring the variable name userNumber
     int userNumber=0;

     //declaring new variable named text
     Buffer text;

     //we are using cin.getline if user enter not valid input
     //or it will take the word before the white space
     cin.getline(text,MAX_SIZE);
     
     // do while loop for entering value again and again if the value is outside of the range
     //or not valid
     do
     {
          //promots user to enter a number
          cout << "Please enter a number for grid between " <<MIN<<" and "<<MAX <<" :" <<  endl;
      
          cin.getline(text,MAX_SIZE);

	  //coverting user input into the integer
          userNumber=atoi(text);
	 	
	  // if outside of the range or not valid then displays the message 
	  if(!(userNumber>=min && userNumber<=max))
	  { 
	       cout << "Please, enter a Valid Number.\n";
	  }
			
     }while(userNumber<min || userNumber>max); // checking condition in do while loop
     //stroing the value in rabbitLife
     rabbitLife=atoi(text);
     return userNumber; // here we are returning the userNumber that number is entered by the user	
}

//defining the function
//this will print the grid as per user value
//we also prints food and rabbit's (0,0) position in
//this function
void printGrid()
{
     //using nested for loop for printing the grid
     for(int i=0; i<size; i++)
     {
          cout << endl;
          cout << " ";
          cout << "|";

          for(int j=0; j<size; j++)
          {
	       //printing rabbit on (0,0) position
               if(i==a && j==b)
               {
	            cout <<RABBIT;
               }
               else
               {
	            cout << " ";
               } 
               cout <<input[i][j]<<" ";
               cout << "|";
          }
          cout << endl;
          cout << " ";
          for(int k=0;k<size;k++)
          {
               cout << "----";
          }
	  cout << "-";
          
      }
      cout << endl;

      //printing rabbit's current life
      cout << "Rabbit's Life Remaining:" << rabbitLife << endl;

}

//through this function rabbit can move into the grid by cell
//if there is a food then it will increase rabbit's life by 2
//and if there is no any food then it will decrease the life
//of rabbit by 1.
//and if user will enter any invalid number then 'a','s','d','w'
//these four character then it will print error messsge and ask
//agin to enter a valid number until user will not
//enter a correct number
void moveRabbit(int &xAxis, int &yAxis)
{
     //declaring chracter variable named userMove
     char userMove;
     //decalring the new variable
     Buffer text;
      
     //asking user untill will not get valid input 
     do{
          cout << endl;
	  //prompting user for entering the move
          cout << "Please Enter your Move:=" << endl;
    
	  cin.getline(text,MAX_SIZE);
	  //we are storing text data into the useMove
	  userMove=text[0];
	  //if the user input is not valid then prints this message and
	  //asking them again
          if(!(userMove==LEFT_MOVE || userMove==RIGHT_MOVE || userMove==UP_MOVE || userMove==DOWN_MOVE))
          {
               cout << "Please Don't Sleep and Enter a valid Number.";
          }
      
     }while(!(userMove==LEFT_MOVE || userMove==RIGHT_MOVE || userMove==UP_MOVE || userMove==DOWN_MOVE));

     //we are using switch case for moving rabbit
     switch(userMove)
     {
          //if user will enter d then it increase y axis by one
          case RIGHT_MOVE:
                         moving=RIGHT;
                         yAxis++;
                         break;

	  //if user will enter a then it decrease y axis by one	
          case LEFT_MOVE:
                        moving=LEFT;
	                yAxis--;
	                break;

	  //if user will enter w then it decrese x axis by one
          case UP_MOVE:
                        moving=UP;
                        xAxis--;
	                break;
			
          //if user will enter s then it increases x axis by one
          case DOWN_MOVE:
                        moving=DOWN;
                        xAxis++;
                        break;
	  //default case
          default:
                        break;  
            
     }
     
 
}

//defines the function named generateFood
//this function will generate food at random place
//for example user enters 4 then it will generate 4 food
//at random place
//in this function we are using random function
void generateFood()
{
     //declaring the variavle named x as bool 
     bool x=false;

     //calling the function named getIntInRange and stroing them into size
     size=getIntInRange(MIN,MAX); // calling the function named getIntInRange
     
     //declaring the array named var
     int var[size];

     //while x is true it will go inside the for loop
     while(!x)
     {
          //setting x is true
          x=true;

	  //making nested for loop
          for(int i=0; i< size; i++)
          {
	       //genearting random value by random function
	       //and we are generating food like it will never
	       //generate on first cell
               var[i]=(rand()%((size*size)-1))+1;
               for(int j=0; j<i; j++)
               {
		    //if the generated values are same then it will reaturn false
		    //and if not same then it will continuev through the loop
	            if(var[i]==var[j])
	            {
	                 x=false;
	            }
               }
          }
     }

     //using for loop for putting space on the places where
     //food is not generated
     for(int i=0; i<size;i++)
     { 
          for(int j=0; j<size; j++)
          {
               input[i][j]=' ';
          }
     }

     //here stroing the the generated value into FOOD
     //for example if generated value is 6 and uservalue is 4 then
     //it will generate food at (1,2) position
     for(int i=0; i<size; i++)
     {
          //stroing the food vallue
          input[var[i]/size][var[i]%size]=FOOD;
   
     }
   
}

//I am calling all my function in one function
//and decalring as callAllFunction
void callAllFunction()
{
  //this while for restarting the game again
     while(true)
       {
          //calling the function named displayOverview
          displayOverview();

          //decalring the bool variable named play
          bool play;
     
          //calling the function name wantToPlay
          play = wantToPlay();

          // if user don't want to play a game then this massege will display
          //and terminate the game safely
          if(!play){
               cout << "Sorry, you don't like my game.\n";
               cout <<"! Good Bye !\n";
               return;
          }
          //calling the function named generateFood
          generateFood();

          //this while loop works when rabbitLife is not equal to 0
          while(!(rabbitLife==0))
          {

     
               //calling the function named printGrid
               printGrid();

	       //calling the function named moveRabbit
	       //and passing the arguments a and b
	       moveRabbit(a,b);

	       //if rabbit will eat food then it increase life by 2
	       if(input[a][b]==FOOD)
	       {
	            rabbitLife+=2;
	            input[a][b]=0;
	       
	       
	       }else
	       {
	            //otherwise decrease life by 1
                    rabbitLife--;
		    //if life will be 0 then you will lose the game
		    if(rabbitLife==0)
		    {
		         cout << "You lost the game!!!!\n";
		         cout << "BYEEEEEE!!!!!\n";

			 //variable is for repeting the game
	                 int number=0;

			 //asking user for playing game again
	                 cout <<"Do you want to try this program again?\n";
	                 cout<<"Please enter any \"INTEGER NUMBER\" for playing Again and for Quit the game please enter \"0\":=\n";
	                 cin >> number;
	                 //if user will enter 0 then this condition will satisfy and 
		         //program will terminate safely
		         if(number==NA)
		         {
		              cout<<"Thank you for your time and BYE BYE!!!\n";
			      return;
		         } 
		    }
	      	 	
	        }     	
           }
       }
 }
