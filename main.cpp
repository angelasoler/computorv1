#include <iostream>
#include "computorv1.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Too much arguments" << endl;
		return 1;
	}
	string expression = argv[1];
	try {
		Solution(ReduceForm(expression));
	} catch (string &e) {
		cerr << e << endl;
	}
	return 0;
}
