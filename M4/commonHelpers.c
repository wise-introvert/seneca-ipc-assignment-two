#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include"commonHelpers.h"
#include<string.h>

// Uses the time.h library to obtain current year information
// Get the current 4-digit year from the system
int currentYear(void) {
  time_t currentTime = time(NULL);
  return localtime(&currentTime)->tm_year + 1900;
}

// Empty the standard input buffer
void clearStandardInputBuffer(void) {
  while (getchar() != '\n') {
    ; // On purpose: do nothing
  }
}

int getInteger() {
  while (1) {
    int tempInt;
    char tempChar = 'x';
    // prompt for a valid int
    scanf("%d%c", &tempInt, &tempChar);

    // check if the input is correct
    if (tempChar != '\n') {
      clearStandardInputBuffer();
      printf("ERROR: Value must be an integer: ");
      // display the error msg ---
    }
    else {
      return tempInt;
    }
  }
}

int getPositiveInteger() {
  while (1) {
    int tempInt;
    char tempChar = 'x';
    // prompt for a valid int
    scanf("%d%c", &tempInt, &tempChar);

    // check if the input is correct
    if (tempChar != '\n') {
      clearStandardInputBuffer();
      // display the error msg ---
      printf("ERROR: Value must be an integer: ");
    }
    else {
      // check if the int is greater than 0
      if (tempInt > 0) {
        return tempInt;
      }
      else {
        printf("ERROR: Value must be a positive integer greater than zero: ");
        // show the not positive int error msg
      }
    }
  }
}

int getIntFromRange(int lowerBound, int upperBound) {
  while (1) {
    int tempInt;
    char tempChar = 'x';
    // prompt for a valid int
    scanf("%d%c", &tempInt, &tempChar);

    // check if the input is correct
    if (tempChar != '\n') {
      clearStandardInputBuffer();
      // display the error msg ---
      printf("ERROR: Value must be an integer: ");
    }
    else {
      if (tempInt >= lowerBound && tempInt <= upperBound) {
        return tempInt;
      }
      else {
        // out of bounds error msg
        printf("ERROR: Value must be between %d and %d inclusive: ", lowerBound, upperBound);
      }
    }
  }
}

double getDouble() {
  while (1) {
    double tempDouble;
    char tempChar = 'x';
    // prompt for a valid int
    scanf("%lf%c", &tempDouble, &tempChar);

    // check if the input is correct
    if (tempChar != '\n') {
      clearStandardInputBuffer();
      // display the error msg ---
      printf("ERROR: Value must be a double floating-point number: ");
    }
    else {
      return tempDouble;
    }
  }
}

double getPositiveDouble() {
  while (1) {
    double tempDouble;
    char tempChar = 'x';
    // prompt for a valid int
    scanf("%lf%c", &tempDouble, &tempChar);

    // check if the input is correct
    if (tempChar != '\n') {
      clearStandardInputBuffer();
      // display the error msg ---
      printf("ERROR: Value must be a double floating-point number: ");
    }
    else {
      // check for double positive input
      if (tempDouble > 0) {
        return tempDouble;
      }
      else {
        // print error msg
        printf("ERROR: Value must be a positive double floating-point number: ");
      }
    }
  }
}

char getCharOption(char str[]) {
  while (1) {
    char c;
    char tempChar;

    // get a single character as input
    scanf("%c%c", &c, &tempChar);
    // check if it matches with argument chars
    int isMatched = 0;
    int i = 0;

    if (tempChar == '\n') { // to check if more than one char is in input
      while (1) {
        if (str[i] == '\0') break;

        if (str[i] == c) {
          isMatched = 1;
          break;
        }
        i++;
      }
    }
    else {
      clearStandardInputBuffer();
    }
    if (isMatched == 0) {
      // not found 
      printf("ERROR: Character must be one of [%s]: ", str);
    }
    else if (isMatched == 1) {
      // found
      return c;
    }
  }
  clearStandardInputBuffer();
}

void getCString(char* c, int lowerBound, int upperBound) {
  while (1) {
    char str[1000];
    // prompt  for input
    scanf("%[^\n]s", str);

    int len = strlen(str);
    if (len >= lowerBound && len <= upperBound) {
      // string is in range
      strcpy(c, str);
      clearStandardInputBuffer();
      break;
    }
    else {
      // prompt error : string out of bounds
      if (lowerBound == upperBound) {
        printf("ERROR: String length must be exactly %d chars: ", upperBound);
      }
      else if (len > upperBound) {
        printf("ERROR: String length must be no more than %d chars: ", upperBound);
      }
      else {
        printf("ERROR: String length must be between %d and %d chars: ", lowerBound, upperBound);
      }
      clearStandardInputBuffer();
    }
  }
}

void getPassword(char* c) {
  char str[1000];
  // prompt  for input
  scanf("%[^\n]s", str);

  //int len = strlen(str);
  strcpy(c, str);
  clearStandardInputBuffer();
}
