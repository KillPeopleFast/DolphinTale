#include<iostream>
using namespace std;
int main() {
	int input;
	int boo = 0;
	cout << "SAY SUMTHIN WITH #" << endl;

	for (int poo = 0; poo < 10; poo++) {
		cin >> input;
		if (boo < input)
			boo = input;
	}
	cout << boo;
}