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
 * @title 			Tower of Hanoi
 * @date			2017-02-18(YYYY-MM-DD)
 * @fversion		1.3.3
 * @description 	(FROM WIKIPEDIA) TOH consists of three rods, and a number of
						disks of different sizes which can slide onto any rod. The
						puzzle starts with the disks in a neat stack in ascending 
						order of size on one rod, the smallest at the top, thus
						making a conical shape.
					The objective of the puzzle is to move the entire stack to
						another rod, obeying the following simple rules:
							Only one disk can be moved at a time.
							Each move consists of taking the upper disk from one of
								the stacks and placing it on top of another stack i.e.
								a disk can only be moved if it is the uppermost disk
								on a stack.
							No disk may be placed on top of a smaller disk.
					The minimum number of moves required to solve a Tower of Hanoi
						puzzle is 2^n – 1, where n is the number of disks.
 * =============================================================================
 */
#include "info.h"
#define _PRINTINFO std::cout << '\n' << R_PROJNAME << " v" << R_PVERSION << " by " << R_AUTHOR << '\n' << R_COPYRIGHT << '\n' << R_COMMENTS << "\n\n\n" // Legal and Informational

#include <iostream>
#include <string>
#include <cmath>

#include ".\h\board.h"
#include ".\h\main.h"
#include ".\h\gameFunc.h"
#include ".\h\exceptions.h"

difficulty diff; // stores the difficulty we are playing at

/* 
	@summary		Program entry point
	
	@param			1: Number of Command line arguments
					2: Command line arguments
	@return			Exit code
 */
int main(int argc, char* argv[]) {
	_PRINTINFO;
	
	using std::cout;
	using std::endl;
	using std::cin;
	
	int turns = 0; // how many turns
	std::string msg; // stores messages for the reader so s/he can read it the next turn
	
	pre(); // get info from user before starting game
	createBoard(diff);
	
	while(!playerWin()) {
		clear();
		printBoard();
		cout << msg << endl; // display any messages
		cout << "Please pick 2 pegs, seperated by a space." << endl << ":: ";
		int pegi, pegf;
		
		try {
			cin >> pegi >> pegf;
			//cin.ignore(1);
		} catch(...) {
			displayHelp();
			cin.clear();
			cin.ignore(1);
		}
		
		try {
			movePeice(pegi, pegf);
			msg = "";
			turns++;
		} catch(std::exception &e) {
			msg = e.what();
		} catch(...) {
			cout << "Uncaught Exception... exiting" << endl; exit(-1);
		}
	}
	
	clear();
	printBoard();
	cout << "You won in " << turns << " moves. " << "The minumum possible is " << (pow(2, (int)diff) - 1) << " moves.\nPress enter to exit...";
	cin.ignore(1); // ignore the new line in the buffer
	cin.get();
	return 0;
}