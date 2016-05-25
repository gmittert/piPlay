#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <time.h>
#define EN 3
#define PH 4

int main (int argc, char** argv) {
	wiringPiSetup();
	pinMode (EN, OUTPUT);
	pinMode (PH, OUTPUT);

  struct timespec secs;
  secs.tv_sec = 0;
  secs.tv_nsec = 500000000;

  while (1) {
    char c = getchar();
    if (c == 'p') { 
      digitalWrite (EN, LOW);
    } else if (c == '['){
      digitalWrite (PH, LOW);
      digitalWrite (EN, HIGH);
    } else if (c == ']'){
      digitalWrite (PH, HIGH);
      digitalWrite (EN, HIGH);
    } else if (c == '\''){
      digitalWrite (EN, LOW);
      break;
    }
  }
  return 0;
}
