#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int checksum;
ifstream file;
string line;
stringstream stringStream;
vector<int> lineValues;

int main() {
	file.open("input.txt");
	while (getline(file,line)){
		stringStream.str(line);
		int tmp = 0;
		while (stringStream >> tmp) lineValues.push_back(tmp);
		checksum += *max_element(lineValues.begin(), lineValues.end()) - *min_element(lineValues.begin(), lineValues.end());
		lineValues.clear();
		stringStream.clear();
	}
	file.close();
	cout << checksum << endl;
	system("pause");
	return 0;
}