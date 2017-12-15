#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

//vector<unsigned long long> banks_archive;
set<unsigned long long>::iterator archive_it;
vector<int> banks = { 14,0,15,12,11,11,3,5,1,6,8,4,9,1,8,4 };
//vector<int> banks = { 0,2,7,0 };
vector<int>::iterator it;
set<unsigned long long> banks_archive;
int valueToRedistribute;
int cycles;

unsigned long long BankHash(vector<int> &);

int main() {
	while (true){
		//hash from data banks
		banks_archive.insert(BankHash(banks));

		//finding max then max redistribution
		it = max_element(banks.begin(), banks.end());
		valueToRedistribute = *it;
		*it = 0;
		for (it++;valueToRedistribute; it++,valueToRedistribute--) {
			if (it == banks.end()) it = banks.begin();
			(*it)++;
		}

		cycles++;
		archive_it = banks_archive.find(BankHash(banks));
		if (archive_it != banks_archive.end()) {
			cout << "Duplicated hash: "<<BankHash(banks) << endl;
			cout << "Data banks: ";
			for (int a : banks) {
				cout << a << " ";
			}
			cout << endl;
			break;
		}
	}
	cout <<"Cycles: "<<cycles << endl;
	system("pause");
	return 0;
}

unsigned long long BankHash(vector<int> &bank) {
	unsigned long long tmp = 0;
	for (int &i : bank) {
		tmp += i;
		tmp <<= 4;
	}
	return tmp;
}