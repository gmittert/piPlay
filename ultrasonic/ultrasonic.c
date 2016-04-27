#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define TRIG 4
#define ECHO 5
#define SPEED_OF_SOUND 34300
struct timeval tv_s;
struct timeval tv_f;

int main (int argc, char** argv) {
  // Setup the pins
	wiringPiSetup();
	pinMode (TRIG, OUTPUT);
	pinMode (ECHO, INPUT);
  digitalWrite (TRIG, LOW);
  sleep(1);
  printf("\n");

  while (1) {
    sleep(1);
    // Pulse the sensor for 10us to start the ranging program
    digitalWrite (TRIG, HIGH);
    usleep(10);
    digitalWrite (TRIG, LOW);

    // Listen on the input (ECHO) pin, it stays high for the amount
    // of time it takes for the pulse to return.
    while (!digitalRead(ECHO));
    gettimeofday(&tv_s, NULL);
    while (digitalRead(ECHO));
    gettimeofday(&tv_f, NULL);
    int duration = tv_f.tv_usec - tv_s.tv_usec;
    int distance = duration * SPEED_OF_SOUND / 2000000;
    printf("Dist: %5dcm\n", distance);
  }
  return 0;
}
