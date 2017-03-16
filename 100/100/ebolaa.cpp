#include<iostream>
using namespace std;
#include<ctime>
int main() {
	srand(time(NULL));
	int average = 0;
	int max = 0;
	int num;

	
	
	for (int poo = 0; poo < 100; poo++) {
		int num = rand() % 1000 + 1;
		cout << num << endl;
		if (num > max) {
			max = num;
		}
		average = average + num;
	}

	cout << endl;
	cout << "the average number is " << average/100 << endl;
	cout <<"the maximum number is "<< max<<endl;

	
}