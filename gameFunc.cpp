/* 
 * Copyright (c) 2017 The Gupta Empire - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Aryan Gupta <me@theguptaempire.net>
 * 
 * =============================================================================
 * @author 			Aryan Gupta
 * @project 		Console Tower of Hanoi
 * @title 			Game Functions
 * @date			2017-02-18(YYYY-MM-DD)
 * @fversion		1.4.0
 * @description 	Contain the functions needed to play the game
 * =============================================================================
 */

#include <iostream> 

#include ".\h\gameFunc.h"
#include ".\h\board.h"
#include ".\h\main.h"
 
/* 
	@summary		Determines if a player has won or not. Checks each pole after
					the first one to see if all of the blocks are on there. If the
					user successfully moved all the blocks on to another pole then
					return true (player has won) else false (player has lost)
	
	@param			VOID
	@return			VOID
 */
bool playerWin() {
	if(diff == Xeasy) { // EXTRA EASY
		return 	((peices[1][1] + peices[2][1]) == 3) ||
				((peices[1][2] + peices[2][2]) == 3);
	} else if(diff == easy) { // EASY
		return 	((peices[1][1] + peices[2][1] + peices[3][1]) == 6) ||
				((peices[1][2] + peices[2][2] + peices[3][2]) == 6);
	} else if(diff == medium) { // MEDIUM
		return 	((peices[1][1] + peices[2][1] + peices[3][1] + peices[4][1]) == 10) || 
				((peices[1][3] + peices[2][3] + peices[3][3] + peices[4][3]) == 10);
	} else if(diff == hard) { // HARD
		return  ((peices[1][1] + peices[2][1] + peices[3][1] + peices[4][1] + peices[5][1]) == 15) ||
				((peices[1][4] + peices[2][4] + peices[3][4] + peices[4][4] + peices[5][4]) == 15);
	} else if(diff == Xhard) { // EXTRA HARD
		return  ((peices[1][1] + peices[2][1] + peices[3][1] + peices[4][1] + peices[5][1] + peices[6][1]) == 21) ||
				((peices[1][2] + peices[2][2] + peices[3][2] + peices[4][2] + peices[5][2] + peices[6][1]) == 21);
	} else {
		return false;
	}
}

/* 
	@summary		Displays the help text
	
	@param			VOID
	@return			VOID
 */
void displayHelp() {
	std::cout << "THERE IS NO HELP AVAILABLE" << std::endl;
}

/* 
	@summary		Clears the screen depending on platform
	
	@param			VOID
	@return			VOID
 */
void clear() {
	#if defined(_WIN32) || defined(WIN32)
		system("cls");
	#elif defined(LINUX) || defined(_UNIX_)
		system("clear");
	#endif

}

/* 
	@summary		Pre-Game prompt - ask the user what difficulty s/he would like to play at
	
	@param			VOID
	@return			VOID
 */
void pre() {
	std::cout 	<< "Welcome to the Tower of Hanoi Game. Please choose a level\n"
				<< "For Extra Easy: 2\n"
				<< "For Easy      : 3\n"
				<< "For Medium    : 4\n"
				<< "For Hard      : 5\n"
				<< "For Extra Hard: 6\n"
				<< ":: ";
	int d = 0;
	std::cin	>> d;
	diff = (difficulty)d;
}