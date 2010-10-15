 /* 
  *Connect4.c
  *@author: Philip Kealley 31247952
  *ICT106 Fundamentals of Computer Systems
  *Last revised 15/10/10
  *
  *Description: Simple Connect 4 game that is played in the terminal window.
  *Inputs taken from the Keyboard and output to the terminal.
 */	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//global variables, having these here save me passing or calculating the array size.
	int column_size = 7;
	int row_size = 6;
	

	//global prototypes
    void printGrid(int grid[column_size][row_size]), spacer(), clearScreen(), flush();

int main()
{
	//prototypes for main
    void printTitle(), setGridSize(), clearGrid(int grid[column_size][row_size]), playerTurn(int player, int grid[column_size][row_size]);
    int checkWinner(int grid[column_size][row_size]), continueGame();
	
	//variable initilisation.
	int player, winner;

    printTitle();
		
		do
    	{
			//construction of new game
            player = 1; //resets player
			winner = 0; // resets winner
    		setGridSize();
    		int grid[column_size][row_size]; // constructs grid
            clearGrid(grid); // sets all grid values to 0
    		clearScreen();

			//game plays out inside until winner or draw.
    		while(winner == 0)
    		{

    			playerTurn(player, grid);
    			winner = checkWinner(grid);
    			if(winner == 0) 
				{
					//switches player
    				if(player == 1)
					{
    					player = 2;
					}
    				else
					{
    					player = 1;
					}
				}
    			else
    			{
						//clears screen and prints grid between turns.
    		        	clearScreen();
                        printGrid(grid);
                        spacer(); //spacer called repeatedly to move print to center of console
    					printf("\n\n");
    					spacer();
						
    				if(winner != 3) //checks if winner was a player or a draw. A winner of '3' is a draw
					{
                        printf("Winner is Player %d!!!", winner);
					}
                    else
					{
                        printf("Draw!!!");
					}
                }
    		}
		//starts a new game if true
    	}while(continueGame());

		return(0);
}

	/*
	 *printTitle
	 *Description: Prints out the game title and my information. Waits for enter key before exiting
	 */
   void printTitle()
   {
       char temp;
       clearScreen();
       printf("\n\n\n\n");
       spacer();
       printf(" Welcome to Connect four!\n");
       spacer();
       printf("Created by Philip Kealley\n");
       spacer();
       printf("   ICT106 Assignment 1\n");
       printf("\n\n");
       spacer();
       printf("  Press Enter to play\n");
       spacer();
       getchar(); //waits for enter key
	}

	/* 
	 *setGridSize
	 *Desctiption: Displays current grid size, asks if they want to change. Gives options for changing the grid and takes user input on which option. Changes the global variables for column_size and row_size.
	 */
	void setGridSize()
	{
		//variable declaration
		char input, selection;
		int test;
		char inputerror[25] = "Please Enter a Y or N: "; //initialize of errors
		char selectionerror[35] = "Please Enter a Valid Selection!";
		
		clearScreen();
		printf("\n");
		spacer();
		printf("Grid size is currently %d x %d\n", column_size, row_size); //prints the current values for grid size.
		spacer();
		printf("Change Grid Size? y/n  ");
		
		do
		{
			test = 1; //test is initialised here for the loop. 0 is true and 1 is false
			scanf("%c", &input);
			if(input == '\n') //checks if user just hit enter with no input
            {
                printf("\n");
                spacer();
                printf("%s", inputerror); //print error
                test = 0; //set to false
            }
            else
            {
                flush(); //clear input buffer
                input = tolower(input); // change uppercase input to lowercase
				if(input != 'n' && input != 'y') 
				{
					test = 0; //set to false
					printf("\n");
					spacer();
					printf("%s", inputerror); //print error
				}
            }

		}while(test == 0); //repeats while true  (test == 0)
			
           if(input == 'y') //checks input
           {
				//prints grid size menu.
    			printf("\n");
    			spacer();
                printf("a) 7 x 6\n");
                spacer();
    			printf("b) 8 x 7\n");
    			spacer();
    			printf("c) 9 x 7\n");
    			spacer();
    			printf("d) 10 x 7\n");
				
				do
				{
				 
					test = 1; //set to false
					spacer();
					scanf("%c", &selection);
					if(selection == '\n') //checks if user just hit enter with no input
					{
						 
						spacer();
						printf("%s\n", selectionerror); //print error
						test = 0;
					}
					else
					{
						flush();
						selection = tolower(selection); //change uppercase to lower 
						if(selection != 'a' && selection != 'b' && selection != 'c' && selection != 'd') //check input is valid
						{
								 
							spacer();
							printf("%s\n", selectionerror); //print error
							test = 0;
						}
					}
				}while(test == 0);
				//changes the grid size based on menu selection.
				switch(selection)
				{
					case 'a':
						column_size = 7;
						row_size = 6;
						break;
					case 'b':
						column_size = 8;
						row_size = 7;
						break;
					case 'c':
						column_size = 9;
						row_size = 7;
						break;
					case 'd':
						column_size = 10;
						row_size = 7;
						break;
						//no need for default because input is validated to only correct entry. 
				}
          }

	}

	/*
	 *clearGrid
	 *Description: sets every value in the grid to 0.
	 */
	void clearGrid(int grid[column_size][row_size])
	{
		//variable declaration.
		int col, row;
		
		//nested loop to set all values in array to 0. 
		for(row = 0; row < row_size; row++)
		{
			for(col = 0; col < column_size; col++)
			{
				grid[col][row] = 0;
            }
        }
	}

	/*
	 *playerTurn
	 *Description: Takes in user inputs for column and changes the resulting empty place in that column to the player number
	 */
	void playerTurn(int player, int grid[column_size][row_size])
	{
		//varaible initialisation
        int inputColumn();
		int col,test, row, placement;
		char placementerror[45] = "Can not place in that column! Try Again"; //error msg
        
	    //print out the grid and ask for input
        clearScreen();
        printGrid(grid);
        printf("\n\n");
        spacer();
        printf("Player %d ", player);
			if(player == 1)
			{
				printf("'O'\n");
			}
			else
			{
				printf("'X'\n");
			}
        spacer();
    	printf("Enter column: ");
		 
		do
		{
			placement = 0;
		   //will repeat until player makes a successful move (checks if column selected is full)
            do
			//will repeat until player selects a valid input (checks if column is inside grid)
            {
				test = 1;  //initialised here for repeating loop
				col = inputColumn();
				//validates input is within grid.
				if(col < 0 || col > (column_size - 1))
				{
			        test = 0;
			        
			        spacer();
			        printf("%s\n", placementerror );
			        spacer();
				}
            }while(test == 0);
			
			row = 0; //row is intialised here for repeating loops.
			 
			while(placement == 0 && row < row_size)
			//checks column selected from the bottom row and working upwards until it finds an empty position '0' and changes the value to the player.
			{
				if(grid[col][row] == 0)
				{
					grid[col][row] = player;
					placement = 1; //sets to 0 when a successfull move is made
                }
				else
					row++;
			}
			if(placement == 0) //if the above loop does not make a successful move within the column selected then placement will be 0 here.
			{
                spacer();
				printf("%s\n", placementerror); //print error 
				spacer();
			}
		}while(placement == 0);
	}
	
	/*
	 *printGrid
	 *Description: Prints out the game grid on the screen
	 */
	void printGrid(int grid[column_size][row_size])
	{
		//variable declaration
		//intialised as top row
		int r, c, i;
	
		printf("\n");
		
		for(r = (row_size - 1); r >= 0; r--)
		//outer loop works through each row from the top down
		{
			spacer();
			for(c = 0; c < column_size; c++)
			//inner loop works through each column from left to right
			{
				if(grid[c][r] == 1)
					printf("|O");
				else
					if(grid[c][r] == 2)
						printf("|X"); 
					else
						printf("| ");
			}
			printf("|\n"); //needed to tidy the grid output
		 }
		 spacer();
		 
		for(i = 0; i < column_size; i++)
		 //prints a ---- line depending on grid size
		{
			printf("--");
		}
			printf("-\n"); //needed to tidy the grid output
			spacer();
			   
		for(i = 0; i < column_size; i++)
		//prints the column references depending on grid size
		{
			printf("|%d", i);
		}
		
		printf("|"); //tidying of grid output
	}

	/*
	 *inputColumn
	 *Description: takes input for column and validates the input. Returns the  column number
	 */
	int inputColumn()
	{
		//variable declaration
        char input;
        int check, test;
        char inputerror[25] = "Please Enter a Number: ";  //sets error msg

        do
        {
            test = 1;  //intialised here for repeating loop
            scanf("%c",&input);
            if(input == '\n')
            {
                spacer();
                printf("%s", inputerror); //error mesg
                test = 0;
            }
            else
            {
                flush();
                check = (int)input; // casts char input into and integer
			    //input validation to check input is a number.
                if(check < 48 || check > 57) //asci values for numbers
                {
                    test = 0; //flags loop to repeat
                    spacer();
                    printf("%s", inputerror); //error message
                }
            }
        }while(test == 0);
		
        return(check - 48); //returns number by removing 48 from the ascii value of int
    }

	/*checkWinner
	 *Description: Works through each scanning function to find a winner
	 */
	int checkWinner(int grid[column_size][row_size])
	{
		//prorotypes for checkWinner
        int checkHorizontal(int grid[column_size][row_size]), checkVertical(int grid[column_size][row_size]), forwardDiagonal(int grid[column_size][row_size]), backwardDiagonal(int grid[column_size][row_size]), checkDraw(int grid[column_size][row_size]);
      
		int winner; //intialised as default value.
	  
		//works through each test until winner is not 0
		//this saves doing the deeper tests if one of the higher tests is successful at finding a winner.
		winner = checkHorizontal(grid);
			if(winner == 0)
				winner = checkVertical(grid);
				if(winner == 0)
					winner = forwardDiagonal(grid);
					if(winner == 0)
						winner = backwardDiagonal(grid);
						if(winner == 0)
							winner = checkDraw(grid); //will return a 3 if a draw is found.

		return(winner);
    }

	/*
	 *checkHorizontal
	 *Description: Checks each row for four equal values which means there is a "winner"
	 */
	int checkHorizontal(int grid[column_size][row_size])
    {
		//variable declaration
		int r = 0;
		int c, winner;
		int count = 1; //needed to be initialised to allow the loop to start

		while(count < 4 && r < row_size)
		//loop works through each row from the bottom up or until a count of 4.
		{
           count = 1; //count starts at 1 because we are checking forward. 
           c = 0; //intialised here for repeated loops
			while(count < 4 && c < column_size - 1)  //-1 here is because we are checking forward. it prevents checking values outside the grid.
			//loop works through each column from left to right or until count of 4.
			{
                 if(grid[c][r] != 0)
                    if(grid[c][r] == grid[c + 1][r]) //checks if next test value and current value are equal
                    {
                         count++;
                         winner = grid[c][r]; //sets the winner to current test value
                    }
				    else
						count = 1; //if we find a 0 value then reset the counter
				
				c++;
			}
			r++;
		}
		if(count != 4) //if we worked through the entire grid then count will be not be 4
			winner = 0; // reset winner
		return(winner);
	}

	/*
	 *checkVertical
	 *Description: Checks each column for four equal values which means there is a winner.
	 */
	int checkVertical(int grid[column_size][row_size])
	{
		//variable declaration;
		int r, winner;
		int c = 0;
		int count = 1;


		while(count < 4 && c < column_size)
		//works through each column from left to right
		{
            count = 1; //resets the count and row for each column to prevent column overflow of winner. 
            r = 0;
			while(count < 4 && r < row_size - 1) //-1 because we check forward a value
			{
				   if(grid[c][r] != 0)
						if(grid[c][r] == grid[c][r + 1]) //if current value and next value are equal
						{
							count++; //increment counter
							winner = grid[c][r]; //winner is current test value.
						}
						else
							count = 1;
						
				r++;
			}
			c++;
		}
		if(count != 4)  //if we worked through the entire grid and found no winner then set winner to 0
			winner = 0;
		return(winner);
	}
	
	/*
	 *forwardDiagonal
	 *Description: Checks through each diagonal that is forward '/' for four equal values which means there is a winner.
	 */
	int forwardDiagonal(int grid[column_size][row_size])
	{
		//variable declaration
		int row_start = row_size -1;
		int col_start = 0;
		int count = 1;
		int r, c, winner;

		while(count < 4 && col_start < column_size - 1)
		{
			//changes the column and row start values starting at the topleft 
			//and moving down the bottom left  then along to the bottom right.
	 		r = row_start;
			c = col_start;
			count = 1;
			while(count < 4 && r < row_size && c < column_size - 1) //-1 because we chack forward
				//loop works forward diagonally
			{
				   if(grid[c][r] != 0)
						if(grid[c][r] == grid[c + 1][r + 1]) //checking forward 
						{
							count++;
							winner = grid[c][r]; //set winner to current test value
						}
						else
						count = 1; //reset count

				r++;
				c++;
			}
			// this will move the start decreasing row to 0 then increasing the column until the edge of the grid
			if(row_start > 0) 
				row_start--;
			else
				col_start++;
        }
		if(count != 4) //if no winner found sets winner back to 0
			winner = 0;
		return(winner);
	}

	/*
	 *backwardDiagonal
	 *Description: Checks through each diagonal that is backward '\' for four equal values which means there is a winner.
	 */
	int backwardDiagonal(int grid[column_size][row_size])
	{
		//initailize variables
		int row_start = row_size -1;
		int col_start = column_size -1;
		int count = 1;
		int r, c, winner;

		while(count < 4 && col_start > 0)
		//works through changing the starting value from top right
		// to bottom right then bottom left
		{
			r = row_start;
			c = col_start;
			count = 1;
			
			while(count < 4 && r < row_size - 1 && c > 0)
			{
				//loop works diagonaly backwards
			   if(grid[c][r] != 0) 
					if(grid[c][r] == grid[c - 1][r + 1]) //checks forward
					{
						count++;
						winner = grid[c][r]; // sets winner to current test value
					}
					else
					count = 1; //reset count

				r++;
				c--;
            }

			if(row_start > 0) //this is what allows for us to change the starting value
				row_start--;
			else
				col_start--;
		}
		if(count != 4) //if no winner is found
			winner = 0; //reset winner
		return(winner);
	}

	/*
	 *checkDraw
	 *Description: Checks through the top row of the grid for and '0' value which means that the game is not over.
	 */
	int checkDraw(int grid[column_size][row_size])
	{
	//this function is performed last 
		//variable declaration & initialisation
		int winner = 3; //sets winner to draw
		int r = row_size - 1; // starts check at top row
		int c = 0;
		int found = 0;

		while(found == 0 && c < column_size) 
		{
			//works along each value on the top row.
	        if(grid[c][r] == 0) // if a 0 is found in any position
			{
	            found = 1;  // then we have more moves to make and
				winner = 0; // the game is not over and reset winner.
			}
			c++;
		}
		return(winner);
	}

	/*
	 *continueGame
	 *Description: Asks if the user wishes to play again, validates the input and returns boolean yes or no  depending upon the answer.
	 */
	int continueGame()
	{
		//variable declaration
    	int test;
	    char input;
	    char inputerror[25] = "Please Enter a Y or N: ";

        printf("\n");
		spacer();
        printf("Play again? Y/N : ");
		
		do
		{
            test = 1; // intitalised here for repeated loops
		
			scanf("%c", &input);
			if(input == '\n')
			{
                spacer();
				printf("%s", inputerror); //error msg
				test = 0;
            }
			else
			{
				flush(); // clear input buffer
				input = tolower(input); // convert uppercase into lowercase
				
				if(input != 'n' && input != 'y') //checks that input was valid
				{
					spacer();
					printf("%s", inputerror); //error msg
					test = 0; // flag loop repeat
				}
			}

		}while(test == 0);
		
		if(input == 'y')
		{
			return(1); // returns true 
		}
		else
		{
			return(0); // returns false
		}
	}
	
	/*
	 *spacer
	 *Description: Prints blank space to format my outputs to the middle of the screen
	 */
    void spacer()
    {
	 //spacer used repeatedly throughout the program pushes the test to the middle of the console.
         printf("                            ");
    }
	/*
	 *clearScreen
	 *Description: Uses system dependent commands to clear screen
	 */
    void clearScreen()
    {
      #ifdef _WIN32   
             system("cls");  // system dependant clear screen commands
      #else 
             system("clear");
      #endif
    }
      
	  /*
	   *flush
	   *Desctiption: Clears the input buffer
	   */
     void flush()
     {
		//flush takes the entire input buffer and does not store it 
		// this clears the input buffer
          scanf ( "%*[^\n]" );  
          scanf ( "%*c" );
     }      
// end of program
