/* 
 * Copyright (c) The Gupta Empire - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Aryan Gupta <me@theguptaempire.net>, February 2017
 * 
 * =============================================================================
 * @author 			Aryan Gupta
 * @project 		Console Tower of Honai
 * @title 			Board Header
 * @date 			2017-02-18 (YYYY-MM-DD)
 * @fversion 		1.0.0
 * @description 	
 * =============================================================================
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>

#include "main.h"

// VARS
extern std::string board_Xeasy[];
extern std::string board_easy[];
extern std::string board_medium[];
extern std::string board_hard[];
extern std::string board_Xhard[];

extern std::string* board;

extern int* pHeight;
extern int** peices;

extern int B_HEIGHT;
extern int B_WIDTH;
extern int* POLE_INDEX;
extern int* HEIGHT_INDEX;
extern int* HALF_WIDTH;
extern int PEICE_HEIGHT;
// END VARS

// FUNCTIONS
void createBoard(difficulty d);

void printBoard();

void movePeice(const int polei, const int polef);

void removePeice(const int pole);

void addPeice(const int pole, const int width);
// END FUNCTIONS

#endif