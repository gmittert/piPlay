#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#define EN 3
#define PH 4

#define TRIG 1
#define ECHO 0
#define SPEED_OF_SOUND 34300
struct timeval tv_s;
struct timeval tv_f;

int main (int argc, char** argv) {
  // Setup the pins
	wiringPiSetup();
	pinMode (TRIG, OUTPUT);
	pinMode (ECHO, INPUT);
	pinMode (EN, OUTPUT);
	pinMode (PH, OUTPUT);

  struct timespec secs;
  secs.tv_sec = 0;
  secs.tv_nsec = 500000000;

  digitalWrite (TRIG, LOW);
  sleep(1);
  printf("\n");

  digitalWrite (PH, HIGH);
  digitalWrite (EN, HIGH);
  while (1) {
    usleep(50000);
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
    fprintf(stderr, "Dist: %5dcm\n", distance);
    if (distance < 40) {
      digitalWrite (EN, LOW);
      digitalWrite (PH, LOW);
      break;
    }
  }
  return 0;
}
