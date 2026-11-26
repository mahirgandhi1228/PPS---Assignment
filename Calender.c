#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Sakamoto's algorithm to determine the day of the week
// Returns 0 = Sunday, 1 = Monday, ..., 6 = Saturday
int getDayOfWeek(int day, int month, int year) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3) {
        year -= 1;
    }
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

int main() {
    int year;
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Input the target year
    printf("Enter the year (e.g., 2026): ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Invalid input. Please enter a positive year.\n");
        return 1;
    }

    // Adjust February days for leap years
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    printf("\n  CALENDAR FOR %d  \n", year);

    // Find the starting day of January 1st (0 = Sun, 6 = Sat)
    int startDay = getDayOfWeek(1, 1, year);

    // Loop through all 12 months
    for (int month = 0; month < 12; month++) {
        printf("\n  ------------------- %s -------------------\n", months[month]);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print leading spaces before the 1st of the month
        for (int space = 0; space < startDay; space++) {
            printf("     ");
        }

        // Print all days of the month
        for (int day = 1; day <= daysInMonth[month]; day++) {
            printf("%5d", day);

            // Move to a new line after Saturday
            if ((day + startDay) % 7 == 0) {
                printf("\n");
            }
        }
        printf("\n");

        // Calculate the starting day for the next month
        startDay = (startDay + daysInMonth[month]) % 7;
    }

    return 0;
}
