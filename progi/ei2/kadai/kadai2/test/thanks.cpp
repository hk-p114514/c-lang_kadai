#include <bits/stdc++.h>
using namespace std;

int main() {
	string message = "だいすきです、ありがとう";
	vector<int> messageNum;

	for (int i = 0; i < message.size(); i++) {
		cout << (int)message[ i ];
        messageNum.push_back((int)message[ i ]);
	}

	putchar('\n');

	return (0);
}