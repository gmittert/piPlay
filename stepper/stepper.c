#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#define P1 0
#define P2 1
#define P3 3
#define P4 4

void setStep(int w1, int w2, int w3, int w4) {
  digitalWrite (P1, w1);
  digitalWrite (P2, w2);
  digitalWrite (P3, w3);
  digitalWrite (P4, w4);
}

int main (int argc, char** argv) {
	wiringPiSetup();
	pinMode (P1, OUTPUT);
	pinMode (P2, OUTPUT);
	pinMode (P3, OUTPUT);
	pinMode (P4, OUTPUT);

  while (1) {
    setStep(1,0,1,0);
    usleep(10000);
    setStep(0,1,1,0);
    usleep(10000);
    setStep(0,1,0,1);
    usleep(10000);
    setStep(1,0,0,1);
    usleep(10000);
    break;
  }


  digitalWrite (P1, 0);
  digitalWrite (P2, 0);
  digitalWrite (P3, 0);
  digitalWrite (P4, 0);
  return 0;
}
