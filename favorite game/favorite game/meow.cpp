#include<iostream>
using namespace std;
#include<string>
int main() {
	string games[5];

	cout << " What are your five favorite games?" << endl;
	getline(cin, games[0]);
	getline(cin, games[1]);
	getline(cin, games[2]);
	getline(cin, games[3]);
	getline(cin, games[4]);
	for (int i = 0; i < 5; i++) {
		if (games[i].compare("Rocket League") == 0) {
			cout << " That's a very good game, excellent choice!" << endl;

		}
		else if (games[i].compare("7 Days to Die") == 0) {
			cout << "There is absolutely no point to that game. Try again" << endl;

		}
		else
			cout << " NEAT" << endl;
	}
}