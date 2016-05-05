#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#define EN 0
#define PH 1

int main (int argc, char** argv) {
	wiringPiSetup();
	pinMode (EN, OUTPUT);
	pinMode (PH, OUTPUT);

  digitalWrite (EN, HIGH);
  digitalWrite (PH, LOW);

  sleep(2);
  digitalWrite (EN, LOW);
  return 0;
}
