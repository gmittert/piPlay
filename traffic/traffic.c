#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#define stop 0
#define warn 1
#define go 2

int main (int argc, char** argv) {
	if (argc != 2) {
		printf("%s [stop|go]\n", argv[0]);
		return 1;
	}
	wiringPiSetup();
	pinMode (go, OUTPUT);
	pinMode (stop, OUTPUT);
	pinMode (warn, OUTPUT);
	if (strcmp(argv[1], "go") == 0) {
		digitalWrite (stop, LOW);
		digitalWrite (warn, LOW);
		digitalWrite (go, HIGH);
	} else if (strcmp(argv[1], "stop") == 0) {
		digitalWrite (go, LOW);
		digitalWrite (stop, LOW);
		digitalWrite (warn, HIGH);
		delay(2000);
		digitalWrite (warn, LOW);
		digitalWrite (stop, HIGH);
	} else {
		printf("%s [stop|go]\n", argv[0]);
		return 1;
	}
	return 0;
}
