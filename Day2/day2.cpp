#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int checksum;
int partTwoSum;
int tmp;
ifstream file;
string line;
stringstream stringStream;
vector<int> lineValues;
pair<vector<int>::iterator, vector<int>::iterator> MinMax;

int PartTwo(vector<int>&);

int main() {
	file.open("input.txt");
	while (getline(file,line)){
		stringStream.str(line);
		while (stringStream >> tmp) lineValues.push_back(tmp);
		MinMax = minmax_element(lineValues.begin(), lineValues.end());
		checksum += *MinMax.second - *MinMax.first;

		partTwoSum += PartTwo(lineValues);

		lineValues.clear();
		stringStream.clear();
	}
	file.close();
	cout << checksum << endl;
	cout << partTwoSum << endl;
	system("pause");
	return 0;
}

int PartTwo(vector<int> &lineValues) {
	for (vector<int>::iterator it = lineValues.begin(); it != lineValues.end(); it++){
		for (vector<int>::iterator it2 = it+1; it2 != lineValues.end(); it2++){
			if (*it % (*it2) == 0) return *it / (*it2);
			if (*it2%(*it) == 0) return *it2 / (*it);
		}
	}
}