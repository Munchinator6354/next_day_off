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


// You can alter the file name here for where this program gathers data from.
const char* FILE_NAME = "holidays3.txt";

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
  } else if(d->day == full_month && d->month == 12){
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
  FILE* file = fopen(FILE_NAME, "r");
  fscanf(file, "%d", holiday_count);
  Date* holidays = (Date*) malloc(*holiday_count * sizeof(Date));
  int index = 0;
  char reason[100];
  // Goes through the file and grabs the holiday date from each line.
  while(fscanf(file, "%d %d %d %[^\n]\n", &holidays[index].month,
                  &holidays[index].day, &holidays[index].year, reason) != EOF) {
    index++;
  }
  return holidays;
}

int days_between(Date* d1, Date* d2) {
  int day_count = 0;
  while(d1 != d2) {
    next_day(d1);
    day_count++;
    if(d1->month == d2->month && d1->day == d2->day && d1->year == d2->year) {
      return day_count;
    }
  }
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

  // Reads the holiday data in from another defined document.
  int holiday_count;
  Date* holidays = read_data(&holiday_count);

  // This section figures out when the next holiday is from the date entered for
  // today and prints out when it is.
  int compare_tester = 5;
  int j = 0;
  while(compare_tester > 0 && j < holiday_count) {
    Date current = holidays[j];
    compare_tester = compare(&date_given, &current);
    if(compare_tester == 0) {
      printf("Happy day off!");
    } else if(compare_tester == -1) {
      printf("The next day off is %d/%d/%d.\n", current.month, current.day,
                                                                  current.year);
      int days_until = days_between(&date_given, &current);
      printf("It is %d days away.", days_until);
    }
    j++;
  }
  if(j >= holiday_count) {
    printf("No data available.");
  }
}
