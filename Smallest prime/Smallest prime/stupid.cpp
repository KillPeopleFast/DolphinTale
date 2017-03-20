#include<iostream>
using namespace std;
int main() {
	int input;
	bool prime = true;
	cout << "Enter a number" << endl;
	cin >> input;
	while (1) {
		prime = true;
		input++;
		for (int i = 2; i < input; i++)
			if (input % i == 0)
				prime = false;

		if (prime) {
			cout << input << " prime" << endl;
			return 0;
		}
	}
}