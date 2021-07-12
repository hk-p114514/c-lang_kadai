#include <stdio.h>
union sensor_def {
	unsigned int byte;
	struct bit_def {
		unsigned int FL : 3;
		unsigned int CT : 3;
		unsigned int FR : 3;
	} bit;
} sensor;

int main() {

	return (0);
}