
#ifndef

#include <exception>

class NoPeiceOnPole: public std::exception {
	public:
		what() throw();
};

class ToBigToFit: public std::exception {
	public:
		what();
};