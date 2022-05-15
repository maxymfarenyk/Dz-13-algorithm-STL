#include <iostream>
#include<list>
#include<vector>
#include <algorithm>
#include<fstream>
using namespace std;

ifstream fin("Data.txt");
ofstream fout("File1.txt");

struct sum {
	int result;
	sum() {
		result = 0;
	}
	void operator()(int n) {
		if (n % 2 == 0) result += n;
	}
};

ostream& operator<<(ostream& out, sum a) {
	out << a.result << endl;
	return out;
}


int m;
void increase(int& n) {
	if (n % 2) n *= m;
}


void input_file(list<int>& d, ofstream& file) {
	for (auto i = d.begin(); i != d.end(); i++) {
		file << *i << " ";
	}
}

struct func {
	vector<int>result;
	func(list<int>a) {
		for (auto it : a) result.push_back(it);
	}
	void operator()() {
		int count = 0;
		for (int i = 1; i < result.size(); i++) {
			if (result[i] == result[i - 1]) {
				count++;
			}
		}
		cout << "Neighbor numbers: " << count << endl;
	}
};



struct compare {
	int x;
	compare(int _x = 0) {
		x = _x;
	}
	bool operator()(int n) {
		return n < x;
	}
};

int main() {

	int n;
	fin >> n ;

	list<int> a(n);
	for (auto it = a.begin(); it != a.end(); it++){
		fin >> *it;
		cout << *it << ' ';
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++//

	cout << endl;
	cout << "Sum of even elements: " << for_each(a.begin(), a.end(), sum());

	//++++++++++++++++++++++++++++++++++++++++++++++++++++//


	cout << "Input number: ";
	cin >> m;
	for_each(a.begin(), a.end(), increase);



	for (auto it = a.begin(); it != a.end(); it++)
		cout << *it << ' ';
	cout << endl;

	input_file(a, fout);

	//++++++++++++++++++++++++++++++++++++++++++++++++++++//

	func Neighbor(a);
	Neighbor();

	//++++++++++++++++++++++++++++++++++++++++++++++++++++//

	list<int> b(n);
	cout << "Input 2 list: \n";
	vector<int>vec(n);
	for (int i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}
	cout << "Check :\n";

	for (int i = 0; i < n;i++) {
		auto it = find_if(a.begin(), a.end(), compare(vec[i]));
		if (it == a.end()) {
			cout << "There is no such element" << endl;
		}
		else {
			cout << "The first element in list less than " << vec[i] << " is " << *it << endl;
		}
	}

}