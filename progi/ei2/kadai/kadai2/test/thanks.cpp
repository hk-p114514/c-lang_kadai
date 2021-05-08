#include <bits/stdc++.h>
using namespace std;

int main() {
	string message = "だいすきです、ありがとう";
	vector<int> messageNum;

	for (int i = 0; i < message.size(); i++) {
        messageNum.push_back((int)message[ i ]);
	}

    for (int i = 0; i < messageNum.size(); i++) {
        cout << messageNum[ i ] << endl;
    }

	putchar('\n');

	return (0);
}