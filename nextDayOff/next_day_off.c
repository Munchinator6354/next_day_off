// Ryan Isaacson, CS&131, Winter 2021
// Programming Assignment #7, Next Day Off 03/05/2021
//
// This program will prompt the user for a date and than look in an associated
// holidays list file in the same folder and tell the user what the date of the
// next holiday is and how many days until that holiday.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Defines the fields of a Date structure/struct.
typedef struct Date {
  int month;
  int day;
  int year;
} Date;

// Compares two dates, returns -1 if Date1 before Date 2, returns 0 if Date1 is
// equal to Date2, returns 1 if Date2 is before Date1.
int compare(Date* d1, Date* d2) {
  if(d1->year < d2->year || d1->year == d2->year && d1->month < d2->month ||
          d1->year == d2->year && d1->month == d2->month && d1->day < d2->day) {
    return -1;
  } else if(d1->year == d2->year && d1->month == d2->month &&
                                                          d1->day == d2->day) {
    return 0;
  } else {
    return 1;
  }
}

// Given a pointer to a Date struct, returns the amount of days in that month.
int days_in_month(Date* d) {
  if(d->month == 2 && d->year % 4 == 0 && d->year % 100 != 0) {
    return 29;
  } else if(d->month == 2) {
    return 28;
  } else if(d->month == 4 ||d->month == 6 ||d->month == 9 ||d->month == 11) {
    return 30;
  } else {
    return 31;
  }
}

// Increments the day up by 1, accounting for month and year turnovers.
void next_day(Date* d) {
  int full_month = days_in_month(d);
  if(d->day < full_month) {
    d->day++;
  } else if(d->day == full_month && d->month != 12) {
    d->day = 1;
    d->month++;
  } else {
    d->day = 1;
    d->month = 1;
    d->year++;
  }
}

// Asks the user for the current date in a month/dat/year format.
void ask_for_date(int *month_given, int *day_given, int *year_given) {
  printf("What is the current date (month day year)? ");
  scanf("%d %d %d", month_given, day_given, year_given);
}


// Reads a file and returns an array of holiday dates. Also sets holiday_count
// back in main.
Date* read_data(int* holiday_count) {
  FILE* file = fopen("holidays.txt", "r");
  fscanf(file, "%d", holiday_count);
  Date* holidays = (Date*) malloc(*holiday_count * sizeof(Date));
  int index = 0;
  char reason[100];
  // Goes through the file and grabs the holiday date from each line.
  while(fscanf(file, "%d %d %d %[^\n]\n", &holidays[index].month, &holidays[index].day, &holidays[index].year, reason) != EOF) {
    // holidays[index] = (Date) {month, day, year};
    printf("----> %d %d %d\n", holidays[index].month, holidays[index].day, holidays[index].year);
    index++;
  }
  return holidays;
}

int main() {
  // Defines spaces for information given by the user.
  int month_given;
  int day_given;
  int year_given;

  // Asks the user for the current date.
  ask_for_date(&month_given, &day_given, &year_given);

  // Turns the date given into and creates a whole date structure.
  Date date_given = {month_given, day_given, year_given};

  // Prints the Date that the user gave.
  printf("USER GAVE DATE: %d %d %d\n", date_given.month, date_given.day, date_given.year);

  // Reads the holday data in from another defined document.
  int holiday_count;
  Date* holidays = read_data(&holiday_count);

  // Proves I can print data from returned holidays array back in main.
  // printf("----> %d %d %d\n", holidays[0].month, holidays[0].day, holidays[0].year);

}
