#include <stdio.h>
union sensor_def {
	unsigned int word;
	struct bit {
		unsigned char FL : 3;
		unsigned char CT : 3;
		unsigned char FR : 3;
		unsigned int PD : 7;
	} bit;
};

int main() {
	union sensor_def sensor;

	return (0);
}