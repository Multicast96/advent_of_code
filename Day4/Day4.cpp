#include<fstream>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

fstream file;
string line;
stringstream parser;
vector<string> lineValues;
vector<string>::iterator it;
int valid;
int valid2;

int main() {
	file.open("input.txt");
	while (getline(file, line)) {
		//Part One
		parser.str(line);
		while (parser >> line) lineValues.push_back(line);
		sort(lineValues.begin(), lineValues.end());
		it = adjacent_find(lineValues.begin(), lineValues.end());
		if (it == lineValues.end())  valid++;

		//Part two
		for_each(lineValues.begin(), lineValues.end(), [](string &s) {sort(s.begin(), s.end()); });
		sort(lineValues.begin(), lineValues.end());
		it = adjacent_find(lineValues.begin(), lineValues.end());
		if (it == lineValues.end())  valid2++;

		lineValues.clear();
		parser.clear();
	}
	cout << valid << endl;
	cout << valid2 << endl;
	system("pause");
}