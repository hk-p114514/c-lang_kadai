#include <iostream>
using namespace std;

class User {
  public:
	int level;
	int age;
	User(); // コンストラクタのプロトタイプ宣言

  public:
	void sayHello() {
		cout << "Hello, my level is " << this->level << ", age is " << this->age << endl;
	}
};

User::User() {
	level = 100;
	age = 25;
}

int main() {
	User bob;
	bob.sayHello();

	return (0);
}