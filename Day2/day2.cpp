#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int checksum;
int tmp;
ifstream file;
string line;
stringstream stringStream;
vector<int> lineValues;
pair<vector<int>::iterator, vector<int>::iterator> MinMax;

int main() {
	file.open("input.txt");
	while (getline(file,line)){
		stringStream.str(line);
		while (stringStream >> tmp) lineValues.push_back(tmp);
		MinMax = minmax_element(lineValues.begin(), lineValues.end());
		checksum += *MinMax.second - *MinMax.first;

		lineValues.clear();
		stringStream.clear();
	}
	file.close();
	cout << checksum << endl;
	system("pause");
	return 0;
}