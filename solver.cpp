// Tower of Hanoi
// Aryan Gupta

/*
2. (Challenge problem; do not turn in)
Towers of Hanoi: The puzzle consists of three rods and a number of disks of different sizes, which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
a) There are n disks labelled 1, 2, 3, ...., n and three towers labeled A, B, and C.
b) No disk can be on top of a smaller disk at any time. 
c) All the disks are initially placed on tower A
d) Only one disk can be moved at a time, and it must be the top disk of the tower.
The objective is to move all the disks from A to B with the assistance of C. 
Write a recursive solution to solve the puzzle. 

Hint:
i) The base case of the problem is n = 1. If n == 1, you could simply move the disk from A to B. 
ii) If n > 1, you could split the original problem into three subproblems and solve them sequentially.
iii) Move the first n-1 disks from A to C recursively with the assistance of tower B.
iv) Move disk n from A to B.
v) Move n-1 disks from C to B recursively with the assistance of tower A.n  

To know more about the puzzle see - https://en.wikipedia.org/wiki/Tower_of_Hanoi
*/

#include <iostream>
using namespace std;

enum Towers {
	TOWER_A = 1, 
	TOWER_B,
	TOWER_C
};

// ostream& operator << (ostream& out, Towers t) {
	// const char lbl[] = "ABC";
	// out << lbl[t];
// }

void TOH_Solver(int disk, Towers source, Towers dest, Towers spare) {
	if(disk == 0) {
		cout << source << ' ' << dest << endl;
		return;
	}
	
	TOH_Solver(disk - 1, source, spare, dest);
	cout << source << ' ' << dest << endl;
	TOH_Solver(disk - 1, spare, dest, source);
}


int main(int argc, char* argv[]) {
	int diff;
	clog << "Please enter the difficulty from [2,6]" << endl;
	cin >> diff;
	cout << diff << endl;
	TOH_Solver(diff, TOWER_A, TOWER_B, TOWER_C);
	
	return 0;
} 