#include<fstream>
#include<iostream>
#include<vector>

using namespace std;

fstream file;
vector<int> jumps;
int pointer;
int steps;
int offset;

int main() {
	file.open("input.txt");

	while (file >> pointer) jumps.push_back(pointer);
	pointer = 0;
	while (pointer >= 0 && pointer < jumps.size()) {
		offset = jumps.at(pointer);
		if (offset >= 3) jumps.at(pointer)--;
		else jumps.at(pointer)++;

		pointer += offset;
		steps++;
	}

	file.close();
	cout << steps << endl;
	system("pause");
	return 0;
}