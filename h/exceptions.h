
#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <exception>

class NoPeiceOnPole: public std::exception {
	public:
		char* what() throw();
};

class ToBigToFit: public std::exception {
	public:
		char* what() throw();
};

#endif