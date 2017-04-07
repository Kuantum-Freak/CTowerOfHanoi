
#include ".\h\exceptions.h"

char* NoPeiceOnPole::what() throw() {
	return "That peg has no blocks. Please try again."
}

char* ToBigToFit::what() throw() {
	return "The block is to big to fit over the other block.";
}