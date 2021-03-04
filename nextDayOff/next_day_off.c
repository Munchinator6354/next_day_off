// Ryan Isaacson, CS&131, Winter 2021
// Programming Assignment #7, Next Day Off 03/05/2021
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


// Asks the user for the current date in a month/dat/year format.
void ask_for_date(int *month_given, int *day_given, int *year_given) {
  printf("What is the current date (month day year)? ");
  scanf("%d %d %d", month_given, day_given, year_given);
}

int main() {
  int month_given;
  int day_given;
  int year_given;

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
  char reason[500];

  while(fscanf(file, "%d %d %d %[^\n]\n", &month, &day, &year, reason) != EOF) {
    Date current = {month, day, year};
    holidays[index] = current;
    printf("----> %d %d %d\n", holidays[index].month, holidays[index].day, holidays[index].year);
    index++;
  }

}
