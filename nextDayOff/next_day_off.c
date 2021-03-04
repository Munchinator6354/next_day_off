// Ryan Isaacson, CS&131, Winter 2021
// Programming Assignment #7, Next Day Off 03/05/2021
//
//

#include <stdio.h>

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



void ask_for_date(int *month_given, int *day_given, int *year_given) {
  printf("What is the current date (month day year)? ");
  scanf("%d %d %d", month_given, day_given, year_given);
  // printf("INSIDE%d %d %d\n", *month_given, *day_given, *year_given);
}

int main() {
  int month_given;
  int day_given;
  int year_given;

  ask_for_date(&month_given, &day_given, &year_given);

  // printf("OUTSIDE%d %d %d\n", month_given, day_given, year_given);

  Date date_given = {month_given, day_given, year_given};

  printf("%d %d %d", date_given.month, date_given.day, date_given.year);




}
