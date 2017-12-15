#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

vector<unsigned long long> banks_archive2;
vector<unsigned long long>::iterator archive_it2;

set<unsigned long long> banks_archive;
set<unsigned long long>::iterator archive_it;

vector<int> banks = { 14,0,15,12,11,11,3,5,1,6,8,4,9,1,8,4 };
vector<int>::iterator it;

int valueToRedistribute;
int cycles;
int cyclesInLoop;

unsigned long long BankHash(vector<int> &);

int main() {
	while (true){
		//hash from data banks
		banks_archive.insert(BankHash(banks));
		banks_archive2.push_back(BankHash(banks));

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
			//PART TWO
			archive_it2 = find(banks_archive2.begin(), banks_archive2.end(), BankHash(banks));
			cyclesInLoop = distance(archive_it2, banks_archive2.end());

			cout << "Duplicated hash: "<<BankHash(banks) << endl;
			cout << "Data banks: ";
			for (int &value : banks) {
				cout << value << " ";
			}
			cout << endl;
			break;
		}
	}
	cout <<"Cycles: "<<cycles << endl;
	cout << "Cycles in loop: "<<cyclesInLoop << endl;
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