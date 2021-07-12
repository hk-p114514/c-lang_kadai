#include <stdio.h>
union sensor_def {
	unsigned int word;
	struct bit {
		unsigned int FL : 3;
		unsigned int CT : 3;
		unsigned int FR : 3;
	} bit;
};

int main() {
	union sensor_def sensor;

	return (0);
}