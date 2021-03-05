// Ryan Isaacson, CS&131, Winter 2021
// Programming Assignment #7, Next Day Off 03/05/2021
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Date {
  int month;
  int day;
  int year;
} Date;

// void ask_for_date(Date *date_given) ;
// void ask_for_date(Date *date_given) {
//   // int month;
//   // int day;
//   // int year;
//   printf("What is the current date (month day year)? ");
//   scanf("%d %d %d", date_given->month, date_given->day, date_given->year);
//
//   printf("%d %d %d", date_given->month, date_given->day, date_given->year);
//   // printf("%d %d %d", Date.month, Date.day, Date.year);
// }

// Date ask_for_date(*month_given, *day_given, *year_given, Date *date_given) {
//   printf("What is the current date (month day year)? ");
//   scanf("%d %d %d", month_given, day_given, year_given);
//
//   return date_given;
// }

// struct Date date_given;
// // char line[50];
// ask_for_date(&date_given);
//
// printf("%d %d %d", date_given.month, date_given.day, date_given.year);


// Compares two dates, returns -1 if Date1 before Date 2, returns 0 if Date1 is
//  equal to Date2, returns 1 if Date2 is before Date1.
int compare(Date* d1, Date* d2) {
  if(d1->year < d2->year) {
    return -1;
  } else if(d1->year == d2->year d1->month < d2->month) {
    return -1;
  } else if(d1->year == d2->year d1->month == d2->month && d1->day < d2->day) {
    return -1;
  } else if(d1->year == d2->year d1->month == d2->month && d1->day == d2->day) {
    return 0;
  } else {
    return 1;
  }
}

void next_day(Date* d) {
  
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

// Asks the user for the current date in a month/dat/year format.
void ask_for_date(int *month_given, int *day_given, int *year_given) {
  printf("What is the current date (month day year)? ");
  scanf("%d %d %d", month_given, day_given, year_given);
}

int main() {
  int month_given;
  int day_given;
  int year_given;

  // Asks the user for the current date.
  ask_for_date(&month_given, &day_given, &year_given);

  Date date_given = {month_given, day_given, year_given};

  // Prints the Date that the user gave.
  // printf("%d %d %d", date_given.month, date_given.day, date_given.year);

  // This read the first number in the file.
  FILE* file = fopen("holidays.txt", "r");
  int holiday_count;
  fscanf(file, "%d", &holiday_count);
  Date holidays[holiday_count];
  int index = 0;
  int month;
  int day;
  int year;
  char reason[100];

  // Goes through the file and grabs the holiday date from each line.
  while(fscanf(file, "%d %d %d %[^\n]\n", &month, &day, &year, reason) != EOF) {
    Date current = {month, day, year};
    holidays[index] = current;

    // THIS WAS TO TEST DAYS IN MONTH FUNCTION
    // int days = days_in_month(&holidays[index]);
    // printf("DAYS IN MONTH %d", days);

    printf("----> %d %d %d\n", holidays[index].month, holidays[index].day, holidays[index].year);
    index++;
  }

  printf("----> %d %d %d\n", holidays[0].month, holidays[0].day, holidays[0].year);



}
