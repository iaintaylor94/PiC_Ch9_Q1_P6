// Program to illustrate arrays of structures

#include <stdio.h>

// Define Structures
struct time {
int hour;
int minute;
int seconds;
};

// Declare Functions
struct time timeUpdate (struct time);

int main(void) {

  struct time testTimes[5] = {
  { 11, 59, 59 },
  { 12, 0, 0 },
  { 1, 29, 59 },
  { 23, 59, 59 },
  { 19, 12, 27 }
  };

  int i;

  for (i = 0; i < 5; i++) {
    // Print initial time
    printf ("Time is %.2d:%.2d:%.2d", testTimes[i].hour, testTimes[i].minute, testTimes[i].seconds);
    
    // Update time
    testTimes[i] = timeUpdate (testTimes[i]);

    // Print updated time
    printf ("...one second later it is %.2d:%.2d:%.2d\n", testTimes[i].hour, testTimes[i].minute, testTimes[i].seconds);
  }
  
  return 0;
}

// Define Functions
struct time timeUpdate (struct time now) {
  now.seconds++;
  if (now.seconds == 60) { // Next minute
    now.seconds = 0;
    now.minute++;
  }
  if (now.minute == 60) { // Next hour
    now.minute = 0;
    now.hour++;

    if (now.hour == 24) { // Midnight
      now.hour = 0;
    }
  }

  return now;
}