/*------------------------------------------------------------------------------
 * Programmer: Edwin Melendez
 * Name: hw3.c
 * Description: To learn the maze and re-run through it with a shortcut
        *Pseudocode:
        * First the program will ask you to resize screen and press s to start.
        * Then it will prompt you to enter station number.
        * Then program will only run if number entered is between 1 and 9.
        * If it's true then the function will run as long as number entered is less than the station.
        * The function will test to see if it can enter left hand mode or right hand mode from the main loop.
        * If any of these are possible then it will make the correct movement to stay on track.
        * If it enters left hand mode, it will add a station number when a U-turn is made.
        * If it enters right hand mode, it will ask for an administrative code when a U-turn is made.
 -------------------------------------------------------------------------------*/

/* NOTE: ALL STARTING CODE HAS BEEN PROVIDED FOR YOUR CONVENIENCE.
   YOU MAY DELETE/MODIFY ANY/ALL OF IT IF YOU WISH. */

#include <stdio.h>
#include <stdlib.h>
#include "useCurses.h"

#include "robotModel.h"
#include "maze.h"

/* function prototype for initializing maze and robot from command line arguments */
int initMazeAndRobotFromCLArgs(int argc, char *argv[], Maze *maze, RobotModel *robot);

/* function prototype for simplifying the turns */
void simplifyTurns(char *turns, int *numTurns);

/* function prototype to navigate through the maze and "solve" it*/
int learn_track(Maze *maze, RobotModel *robot, char *turns, int *curTurnIndex, int *code, int targetStation);

int copyAndSimplify(char *inturns, char *outturns, int numturns);

int main( int argc, char *argv[] )
{
    Maze maze;              /* strucutre to store maze */
    RobotModel robot;       /* structure to model robot (current position + direction) */
    char turns[300];        /* saves 'intersection' choices */
    int curTurnIndex = 0;   /* next turn index */
    int station=0;
    int targetStation=0;
    int i,j,optturns;
    char input;
    int code = -1;
    int done = 0;
    char outturns[100];
    
    /* initialize curses mode */
    initscr();

    printw("\n Resize screen first \n");
    printw("\n Then press s to start \n");
    do {
        scanw("%c", &input);
    } while (input != 's');

    /* if successfully have initialized robot and maze, solve maze */
    if (initMazeAndRobotFromCLArgs(argc, argv, &maze, &robot))
    {
        while(!done)
        {
        	/* display maze and obtain desired end point */
        	clear();
        	printMazePlusCurrentPos(maze, robot);
            /*
            TODO: implement the main functionality of the robot
             	correctly read station number
             	If the user does not indicate to quit the program
                   traverse the track searching for the target station (some guidelines are given in function learn_track)
                   if target station is found
	                   	print turns made and administrative code (if any)
                   		go back to packing station (for full credit it is enough to reinitialize maze and robot)
                   		simplify the path
                   		go to the target station again following the shortest path
                   otherwise
                   		print appropriate message
             	reinitialize robot, maze, and relevant variables
            */
            printw("Please enter the station number destination\n"); /* Asks user to enter station number */
            scanw("%d", &targetStation);            /* scans user input for targetstation */
            if (targetStation<=0)                   /* if station is 0 or negative, program will stop */
            {
                done = 1;
            }
            else
            {
                station = learn_track(&maze, &robot, turns, &curTurnIndex, &code, targetStation);   /* calls function to learn the track */
            if (targetStation == station)
            {
                printw("Hey! You have arrived to your station\n");      /* if station = target station, it will print that you have arrived */
                for(i=0; i<curTurnIndex; i++)                           /* array that stores the turns */
                {
                    printw("%c ", turns[i]);                            /* prints the turns */
                }
                printw ("\n");
                printw("Administration code =%d", code);
                
                
                initMazeAndRobotFromCLArgs(argc, argv, &maze, &robot);          /* reinitializes the maze and position */
                optturns = copyAndSimplify(turns, outturns, curTurnIndex);      /* simplifies turns */
                getch();
            }
            
            }

        }
        

     }
    printw("Press any key to quit");
    getch();

    endwin();
    return 0;
}

/*-----------------------------------------------------------------------------
 * Function name: learn_track
 * Description: This function navigates through the maze and solves it
 * Inputs: maze = Maze * = pointer to Maze structure
 *         robot = RobotModel * = pointer to RobotModel
 *		   turns = char * = array of characters to store the turns made to solve
 *							the maze (passed by simulated reference)
 *		   curTurnIndex = int * = the index position where the next turn
 *                        made by the robot will be stored in turns array
 *                        (passed by simulated reference)
 *         code = int * = the last administrative code collected
 *                        (passed by simulated reference)
 *		   targetStation = int = the targetStation input by the user
 * Output: int = 0 if the targetStation is not found
 *               targetStation otherwise
 *----------------------------------------------------------------------------*/
int learn_track(Maze *maze, RobotModel *robot, char *turns, int *curTurnIndex, int *code, int targetStation)
{
    int done = 0;
    int traversalMode = 0; /* e.g. 0: leftHandOnWallMode, 1: rightHandOnWallMode, 2: mainLoopMode */
    int station = 0; // returns the station reached
    int bToL, bToR, bInF; // valiables indicating black to left(L), right(R), or frontF)
    int onB; // valiables indicating on black

    while (!done)
    {


        clear();
        printMazePlusCurrentPos(*maze, *robot);

        /*
         TODO:
         	Determine the values of bToL, bToR, bInF, onB
         	Determine if the robot has reached the packing station (which means learn track is done but the targetStation was not found)
         	If the robot is not at a junction and can only move straight, move straight
         	otherwise
         	    if traversalMode indicates mainLoopMode
                    decide the appropriate turn following mainLoopMode
                    NOTE: since the main loop has no dead-end, it is always posible to make a L, R, or S turn
                    apply the turn on the robot and save it into turns array
         	    else if traversalMode indicates leftHandOnWallMode
                    decide the appropriate turn following leftHandOnWallMode
                    decide u-turn when neither of L, R, or S turn is possible (i.e., a dead-end and a new storage station has been reached)
                    apply the turn on the robot and save it into turns array
         	    else if traversalMode indicates rightHandOnWallMode
                    decide the appropriate turn following rightHandOnWallMode
                    decide u-turn when neither of L, R, or S turn is possible (i.e., a dead-end and a new administrative station has been reached)
                    apply the turn on the robot and save it into turns array
                Update the current traversalMode
        */
        onB = onBlack(*maze, *robot);
        bToL = blackToLeft(*maze, *robot);
        bToR = blackToRight(*maze, *robot);
        bInF = blackInFront(*maze, *robot);
        if(bToR == 1 && bToL == 1 && bInF == 1 && onB == 1)
        {
            printw("Invalid Station number!\n Try again.");     /* if it reaches packing station, it will say invalid station */
            done = 1;
        }
        else if (bToR == 0 && bToL == 0 && onB == 1)
        {
            moveStraight(robot);
        }

        else
        {
            /* main loop mode */
        if (traversalMode == 0)
        {
            if (bToL == 1 && onB == 1 && bInF == 1)
            {
                turnLeft(robot);
                turns[*curTurnIndex] = 'L';
                (*curTurnIndex)++;
                traversalMode = 1;
            }
            else if (bToR == 1 && onB == 1 && bInF)
            {
                turnRight(robot);
                turns[*curTurnIndex] = 'R';
                (*curTurnIndex)++;
                traversalMode = 2;
            }
            else if (bToL == 1 && bToR == 1 && onB == 1)
            {
                turnLeft(robot);
                turns[*curTurnIndex] = 'L';
                (*curTurnIndex)++;
                traversalMode = 1;
            }
            else if (bInF == 1 && onB == 1)
            {
                moveStraight(robot);
            }
            else if (bToL == 1 && onB == 1)
            {
                turnLeft(robot);
            }
            else if (onB == 1 && bToR == 1)
            {
                turnRight(robot);
            }
            else
            {
                printw("bad track\n");
            }
        }
        
            /* left hand mode */
        else if (traversalMode == 1)
        {
            if(bToL == 1 && onB == 1 && bToR == 1)
            {
                turnLeft(robot);
                turns[*curTurnIndex] = 'L';
                (*curTurnIndex)++;
                traversalMode = 0;
            }
            else if (bInF == 1 && bToR == 1 && onB == 1)
            {
                moveStraight(robot);
                traversalMode = 0;
            }
            else if(bInF == 1 && onB == 1)
            {
                moveStraight(robot);
            }
            else if(bToR == 1 && onB == 1)
            {
                turnRight(robot);
            }
            else if(bToL == 1 && onB == 1)
            {
                turnLeft(robot);
            }
            else
            {
                uTurn(robot);
                turns[*curTurnIndex] = 'U';
                (*curTurnIndex)++;
                station = station + 1;
            }
        }
       
            /* right hand mode */
        else if (traversalMode == 2)
        {
            if(bToR == 1 && onB == 1 && bToL == 1)
            {
                turnRight(robot);
                turns[*curTurnIndex] = 'R';
                (*curTurnIndex)++;
                traversalMode = 0;
            }
            else if(bInF == 1 && onB == 1)
            {
                moveStraight(robot);
            }
            else if(bToL == 1 && onB == 1)
            {
                turnLeft(robot);
            }
            else if(bToR == 1 && onB == 1)
            {
                turnRight(robot);
            }
            else
            {
                printw("Enter an administrative code >0");
                scanw("%d", code);
                while (*code <= 0)
                {
                    printw("Enter a valid code");
                    scanw("%d", code);
                }
                if (*code > 0)
                {
                    uTurn(robot);
                    turns[*curTurnIndex] = 'U';
                    (*curTurnIndex)++;
                }
            }
            
        }
        }
        if (station == targetStation)
        {
            done = 1;
        }
        getch();
    }

    return station;
}


/*-----------------------------------------------------------------------------
 * Function name: initMazeAndRobotFromCLArgs
 * Description: This function uses the specified command-line arguments to
 *              initialize the given Maze and RobotModel variables. If the
 *              incorrect number of command-line arguments is passed, an
 *              error message is displayed (and 0 is returned).
 * Inputs: argc = int = number of command-line arguments
 *         argv = array of strings = command-line arguments, with argv[1]
 *                                   being the input file name
 *         m = Maze * = pointer to Maze structure that should be initialized
 *                      in this function (passed by simulated reference)
 *         robot = RobotModel * = pointer to RobotModel that should be
 *                                initialized in this function (passed by
 *                                simulated reference)
 * Outputs: m = Maze * = pointer to initialized Maze
 *          robot = RobotModel * = pointer to initialized RobotModel
 *          int = 1 if initialization successful
 *                0 if error encountered
 ----------------------------------------------------------------------------*/
int initMazeAndRobotFromCLArgs(int argc, char *argv[], Maze *maze, RobotModel *robot)
{
    int success = 1;
    char *inputFileName;    /* input file name containing maze */
    /* obtain input filename from command line */
    if (argc >= 2) /* require at least two command-line arguments */
    {
        inputFileName = argv[1];
    }
    else
    {
        /* when incorrect number of command-line arguments are passed,
           print message indicating proper usage of program  */
        printf("Usage: %s inputFileName.txt\n", argv[0]);
        success = 0;
    }

    if (success)
    {
        success = readMaze(inputFileName, maze, robot);
    }

    return success;
}


/* ---------------------------------------------
 void simplifyTurns(char *turns, int *numTurns)

 This function optimize a local track segment around a U turn.
 Specifically, a path LUR or RUL is optimized to U
 while a path LUL is optimized to S.
 It may be better understood if we consider the following diagrams

 R ----- <     or, U |
 | L                | R
 |                 L ------ <
 U
 the paths are LUR and RUL and after optimization it become

 U ---- <

 U -----<

 On the other if the turn sequence is LUL then the path looks like the following

 |
 L |
 U ----- L
 |
 |
 ^
 and it is optimized to


 |s
 |
 S
 |
 |
 The trick is solve using the variable total_angle.
 Although, this function is giving to you,
 we stringly recommend that you follow it for different examples
 of tracks around an U turn and see how it is solved
 ---------------------------------------------------*/
void simplifyTurns(char *turns, int *numTurns)
{
    int n = *numTurns;
    if (n >= 3 && turns[n-2] == 'U')
    {
        int total_angle = 0;
        int i;
        for (i=1; i<=3; i++)
        {
            switch(turns[n-i])
            {
                case 'R':
                    total_angle += 90;
                    break;
                case 'L':
                    total_angle += 270;
                    break;
                case 'U':
                    total_angle += 180;
                    break;
                    /* Note that no change in total_angle is need for case 'S'; therefore the case is omitted */
            }
        }

        total_angle = total_angle % 360;

        switch(total_angle)
        {
            case 0:
                turns[n-3] = 'S';
                break;
            case 90:
                turns[n-3] = 'R';
                break;
            case 180:
                turns[n-3] = 'U';
                break;
            case 270:
                turns[n-3] = 'L';
                break;
        }

        *numTurns = *numTurns - 2;
    }
}
int copyAndSimplify(char *inturns, char *outturns, int numturns)
{
    int i;
    int optturns = 0;
    
    for (i=0; i<numturns; i++)
    {
        outturns[optturns] = inturns[i]; optturns++;
        simplifyTurns(outturns, &optturns);
    }
    return(optturns);
}





