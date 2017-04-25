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
 * @title 			Board Functions
 * @date			2017-02-19(YYYY-MM-DD)
 * @fversion		3.2.2
 * @description 	Contains functions that manipulates the board
 * =============================================================================
 */
#include <iostream>
#include <string>

#include ".\h\board.h"
#include ".\h\exceptions.h"

#define LOG(a) std::cout << a << std::endl
//#define DEBUG

using std::cout;
using std::endl;

std::string board_Xeasy[] = 
{	
	"           |                      |                      |           ",	
	"           |                      |                      |           ",	
	"       XXXX|XXXX                  |                      |           ",	
	"       XXXX|XXXX                  |                      |           ",	
	"   XXXXXXXX|XXXXXXXX              |                      |           ",	
	"   XXXXXXXX|XXXXXXXX              |                      |           ",	
	" ==========|==========  ==========|==========  ==========|========== ",
	"           1                      2                      3           "
};

std::string board_easy[] = 
{
	"               |                              |                              |               ",	
	"               |                              |                              |               ",	
	"           XXXX|XXXX                          |                              |               ",	
	"           XXXX|XXXX                          |                              |               ",	
	"       XXXXXXXX|XXXXXXXX                      |                              |               ",	
	"       XXXXXXXX|XXXXXXXX                      |                              |               ",	
	"   XXXXXXXXXXXX|XXXXXXXXXXXX                  |                              |               ",	
	"   XXXXXXXXXXXX|XXXXXXXXXXXX                  |                              |               ",	
	" ==============|==============  ==============|==============  ==============|============== ",
	"               1                              2                              3               "
};

std::string board_medium[] = 
{
	"                   |                                      |                                      |                   ",	
	"                   |                                      |                                      |                   ",	
	"               XXXX|XXXX                                  |                                      |                   ",	
	"               XXXX|XXXX                                  |                                      |                   ",	
	"           XXXXXXXX|XXXXXXXX                              |                                      |                   ",	
	"           XXXXXXXX|XXXXXXXX                              |                                      |                   ",	
	"       XXXXXXXXXXXX|XXXXXXXXXXXX                          |                                      |                   ",	
	"       XXXXXXXXXXXX|XXXXXXXXXXXX                          |                                      |                   ",	
	"   XXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXX                      |                                      |                   ",	
	"   XXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXX                      |                                      |                   ",	
	" ==================|==================  ==================|==================  ==================|================== ",
	"                   1                                      2                                      3                   "
};

std::string board_hard[] = 
{
	"                      |                                           |                                           |                      ",	
	"                      |                                           |                                           |                      ",	
	"                  XXXX|XXXX                                       |                                           |                      ",	
	"                  XXXX|XXXX                                       |                                           |                      ",	
	"              XXXXXXXX|XXXXXXXX                                   |                                           |                      ",	
	"              XXXXXXXX|XXXXXXXX                                   |                                           |                      ",	
	"          XXXXXXXXXXXX|XXXXXXXXXXXX                               |                                           |                      ",	
	"          XXXXXXXXXXXX|XXXXXXXXXXXX                               |                                           |                      ",	
	"      XXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXX                           |                                           |                      ",	
	"      XXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXX                           |                                           |                      ",	
	"  XXXXXXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXXXXXX                       |                                           |                      ",	
	"  XXXXXXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXXXXXX                       |                                           |                      ",	
	" =====================|===================== =====================|===================== =====================|===================== ",
	"                      1                                           2                                           3                      "
};

std::string board_Xhard[] = 
{
	"                          |                                                   |                                                   |                          ",	
	"                          |                                                   |                                                   |                          ",	
	"                      XXXX|XXXX                                               |                                                   |                          ",	
	"                      XXXX|XXXX                                               |                                                   |                          ",	
	"                  XXXXXXXX|XXXXXXXX                                           |                                                   |                          ",	
	"                  XXXXXXXX|XXXXXXXX                                           |                                                   |                          ",	
	"              XXXXXXXXXXXX|XXXXXXXXXXXX                                       |                                                   |                          ",	
	"              XXXXXXXXXXXX|XXXXXXXXXXXX                                       |                                                   |                          ",	
	"          XXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXX                                   |                                                   |                          ",	
	"          XXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXX                                   |                                                   |                          ",	
	"      XXXXXXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXXXXXX                               |                                                   |                          ",	
	"      XXXXXXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXXXXXX                               |                                                   |                          ",	
	"  XXXXXXXXXXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXXXXXXXXXX                           |                                                   |                          ",	
	"  XXXXXXXXXXXXXXXXXXXXXXXX|XXXXXXXXXXXXXXXXXXXXXXXX                           |                                                   |                          ",	
	" =========================|========================= =========================|========================= =========================|========================= ",
	"                          1                                                   2                                                   3                          "
};

std::string* board; // points to the board we are using, depends on what level we are playing at

int* pHeight; // stores the height of the peices on the poles
int** peices; // stores all the peices (Non-Grapically)

int B_HEIGHT; // stores the entire board's hight
int B_WIDTH; // stores the entire board's width
int* POLE_INDEX; // stores the loation of the poles from the left side
int* HEIGHT_INDEX; // stores the height of each section of the pole
int* HALF_WIDTH; // stores each peice's half width {0, 5, 9, 13, 17, 21, 25}
int PEICE_HEIGHT = 2; // stores how tall each peice is

/* 
	@summary		Specifys the details of the board we are going to use
	
	@param			The difficulty
	@return			VOID
 */
void createBoard(difficulty d) {
	switch(d) {
		case 2: // EXTRA EASY ====================================
			board = board_Xeasy;
			pHeight = new int[3]{2, 0, 0};
			peices = new int*[3]{new int[3]{3, 3, 3},
								 new int[3]{2, 0, 0},
								 new int[3]{1, 0, 0}}; // THIS IS STORED BACKWARDS FOR EASE OF USE;
			B_HEIGHT = 8;
			B_WIDTH = board[0].size();
			POLE_INDEX = new int[3]{11, 34, 57};
			HEIGHT_INDEX = new int[2]{4, 2};
			HALF_WIDTH = new int[3]{0, 5, 9};
			PEICE_HEIGHT = 2;
			break;
		case 3: // EASY ==========================================
			board = board_easy;
			pHeight = new int[3]{3, 0, 0};
			peices = new int*[4]{new int[3]{4, 4, 4},
								 new int[3]{3, 0, 0},
								 new int[3]{2, 0, 0},
								 new int[3]{1, 0, 0}}; // THIS IS STORED BACKWARDS FOR EASE OF USE;
			B_HEIGHT = 10;
			B_WIDTH = board[0].size();
			POLE_INDEX = new int[3]{15, 46, 77};
			HEIGHT_INDEX = new int[3]{6, 4, 2};
			HALF_WIDTH = new int[4]{0, 5, 9, 13};
			PEICE_HEIGHT = 2;
			break;
		case 4: // MEDIUM =======================================
			board = board_medium;
			pHeight = new int[3]{4, 0, 0};
			peices = new int*[5]{new int[3]{5, 5, 5},
								 new int[3]{4, 0, 0},
								 new int[3]{3, 0, 0},
								 new int[3]{2, 0, 0},
								 new int[3]{1, 0, 0}}; // THIS IS STORED BACKWARDS FOR EASE OF USE;
			B_HEIGHT = 12;
			B_WIDTH = board[0].size();
			POLE_INDEX = new int[3]{19, 58, 97};
			HEIGHT_INDEX = new int[4]{8, 6, 4, 2};
			HALF_WIDTH = new int[5]{0, 5, 9, 13, 17};
			PEICE_HEIGHT = 2;
			break;
		case 5: // HARD =========================================
			board = board_hard;
			pHeight = new int[3]{5, 0, 0};
			peices = new int*[6]{new int[3]{6, 6, 6},
								 new int[3]{5, 0, 0},
								 new int[3]{4, 0, 0},
								 new int[3]{3, 0, 0},
								 new int[3]{2, 0, 0},
								 new int[3]{1, 0, 0}}; // THIS IS STORED BACKWARDS FOR EASE OF USE;
			B_HEIGHT = 14;
			B_WIDTH = board[0].size();
			POLE_INDEX = new int[3]{22, 66, 110};
			HEIGHT_INDEX = new int[5]{10, 8, 6, 4, 2};
			HALF_WIDTH = new int[6]{0, 5, 9, 13, 17, 21};
			PEICE_HEIGHT = 2;
			break;
		case 6: // EXTRA HARD ===================================
			board = board_Xhard;
			pHeight = new int[3]{6, 0, 0};
			peices = new int*[7]{new int[3]{7, 7, 7},
								 new int[3]{6, 0, 0},
								 new int[3]{5, 0, 0},
								 new int[3]{4, 0, 0},
								 new int[3]{3, 0, 0},
								 new int[3]{2, 0, 0},
								 new int[3]{1, 0, 0}}; // THIS IS STORED BACKWARDS FOR EASE OF USE;
			B_HEIGHT = 16;
			B_WIDTH = board[0].size();
			POLE_INDEX = new int[3]{26, 78, 130};
			HEIGHT_INDEX = new int[6]{12, 10, 8, 6, 4, 2};
			HALF_WIDTH = new int[7]{0, 5, 9, 13, 17, 21, 25};
			PEICE_HEIGHT = 2;
			break;
	}// END ====================================================
}

/* 
	@summary		Prints the board out on the console
	
	@param			VOID
	@return			VOID
 */
void printBoard() {
	using std::cout;
	using std::endl;
	cout << endl << endl;
	for(int i = 0; i < B_HEIGHT; ++i) {
		for(int j = 0; j < B_WIDTH; ++j)
			cout << board[i][j];
		cout << endl;
	}
	cout << endl;
}

/* 
	@summary		Moves a peice from one pole/peg to another
	
	@param			1: The pole from which to move from
					2: The pole to which to move the peice to
	@return			VOID
	@excep			int 1: The initial pole has no peices on it
					int 2: The peice is too big to fit over final pole
 */
void movePeice(int polei, int polef) {
	polei--; // decrement so it works well with arrays
	polef--;
	
	// GET INITIAL POLE DATA
	int topPeicei = pHeight[polei]; // get top most peice of initial pole
	if(topPeicei == 0)
		throw NoPeiceOnPole(); // thow excepton that the initial peice has no peices
	int topPeiceWidthi = peices[topPeicei][polei]; // find width of top most peice
	
	#ifdef DEBUG
	LOG("Peice 1 info(topPeicei, topPeiceWidthi): " << topPeicei << " " << topPeiceWidthi);
	#endif
	
	// GET FINAL PEICE DATA
	int topPeicef = pHeight[polef]; // get the index of the topmost peice on the pole
	int topPeiceWidthf = peices[topPeicef][polef]; // get the size of that peice
	
	if(topPeiceWidthf < topPeiceWidthi) { // we cant move a bigger peice on top of a smaller peice
		throw ToBigToFit();
	}
	
	#ifdef DEBUG
	LOG("Final Peice info (topPeicef, topPeiceWidthf): " << topPeicef << " " << topPeiceWidthf);
	#endif
	
	// REMOVE THE PEICE
	removePeice(polei);
	peices[topPeicei][polei] = 0; // set that peice to 0
	pHeight[polei]--; // decrement the height of the blocks on that pole
	
	#ifdef DEBUG
	LOG("Removed a peice. changing internals: " << topPeicei << " " << polei << "to 0");
	#endif
	
	// ADD THE PEICE
	addPeice(polef, topPeiceWidthi);
	peices[topPeicef + 1][polef] = topPeiceWidthi; //set that index to the width of the peice
	pHeight[polef]++; // increment height
	
	#ifdef DEBUG
	cout << endl << endl;
	for(auto &i : peices) {
		for(auto &e: i) {
			cout << e;
		}
		cout << endl;
	}
	cout << endl;
	
	for(auto &i : pHeight) {
		cout << i;
	}
	
	cout << endl << endl;
	#endif
}

/* 
	@summary		Removes a peice from the Graphical board
	
	@param			The pole from wich to remove the peice
	@return			VOID
 */
void removePeice(const int pole) {
	int peice = peices[pHeight[pole]][pole];
	int hWidth = HALF_WIDTH[peice];
	
	#ifdef DEBUG
	LOG("Removing the peice " << peice << " Its half width is: " << hWidth << " pole " << pole);
	#endif
	
	for(int i = HEIGHT_INDEX[pHeight[pole] - 1]; // Start at the height where the peice is
	i < HEIGHT_INDEX[pHeight[pole] - 1] + PEICE_HEIGHT; // Go down 3 (the peices are 3 X's high)
	i++) {
		#ifdef DEBUG
		LOG("i: " << i << " Removing from height : " << HEIGHT_INDEX[pHeight[pole] - 1] << " to " << HEIGHT_INDEX[pHeight[pole] - 1] + 3);
		#endif
		for(int j = POLE_INDEX[pole] + 1; // get pole index (width from left)
		j < POLE_INDEX[pole] + hWidth; // move to the RIGHT half of the peices width
		++j) {
			#ifdef DEBUG
			LOG("j: " << j << "Removing from width : " << POLE_INDEX[pole] << " to " << POLE_INDEX[pole] + hWidth);
			#endif
			board[i][j] = ' ';
		}
		
		for(int j = POLE_INDEX[pole] - 1; // get pole index (width from left)
		j > POLE_INDEX[pole] - hWidth; // move to the LEFT half of the peices width
		--j) {
			#ifdef DEBUG
			LOG("j: " << j << "Removing from width : " << POLE_INDEX[pole] << " to " << POLE_INDEX[pole] + hWidth);
			#endif
			board[i][j] = ' ';
		}
	}
}

/* 
	@summary		Adds a peice to the graphical board
	
	@param			1: Pole to which to add the peice
					2: Size of the peice to add
	@return			VOID
 */
void addPeice(const int pole, const int width) {
	int hWidth = HALF_WIDTH[width];
	
	#ifdef DEBUG
	LOG("Adding from width : " << POLE_INDEX[pole] << " to " << POLE_INDEX[pole] + hWidth);
	#endif
	
	for(int i = HEIGHT_INDEX[pHeight[pole]]; // Start at the height where the peice is
	i < HEIGHT_INDEX[pHeight[pole]] + PEICE_HEIGHT; // Go down 3 (the peices are 3 X's high)
	i++) {
		#ifdef DEBUG
		LOG("i: " << i << " Adding to height : " << HEIGHT_INDEX[pHeight[pole]] << " to " << HEIGHT_INDEX[pHeight[pole]] + 3);
		#endif
		for(int j = POLE_INDEX[pole] + 1; // get pole index (width from left)
		j < POLE_INDEX[pole] + hWidth; // move to the RIGHT half of the peices width
		++j) {
			#ifdef DEBUG
			LOG("j:" << j << " adding to width : " << POLE_INDEX[pole] + 1 << " to " << POLE_INDEX[pole] + hWidth);
			#endif
			board[i][j] = 'X';
		}
		
		for(int j = POLE_INDEX[pole] - 1; // get pole index (width from left)
		j > POLE_INDEX[pole] - hWidth; // move to the LEFT half of the peices width
		--j) {
			#ifdef DEBUG
			LOG("j:" << j << "Adding from width : " << POLE_INDEX[pole] - 1 << " to " << POLE_INDEX[pole] - hWidth);
			#endif
			board[i][j] = 'X';
		}
	}
}