#include <stdio.h>

float calculateMean(float readings[], int count)
{
    float sum = 0;
    int i;

    for (i = 0; i < count; i++)
    {
        sum = sum + readings[i];
    }

    return sum / count;
}

float calculateRange(float readings[], int count){
    float smallest = readings[0];
    float largest = readings[0];
    int i;
    for (i = 1; i < count; i++)
    {
        if (readings[i] < smallest)
        {
            smallest = readings[i];
        }

        if (readings[i] > largest)
        {
            largest = readings[i];
        }
    }
    return largest - smallest;
}

int countAboveLimit(float readings[], int count, float limit)
{
    int aboveCount = 0;
    int i;

    for (i = 0; i < count; i++)
    {
        if (readings[i] > limit)
        {
            aboveCount++;
        }
    }

    return aboveCount;
}

int main()
{
    float readings[100];
    float limit;
    int count;
    int choice;
    int i;

    printf("Enter number of Bit-Error Rate readings (1 to 100): ");

    if (scanf("%d", &count) != 1 || count < 1 || count > 100)
    {
        printf("Invalid number of records.\n");
        return 1;
    }

    for (i = 0; i < count; i++)
    {
        printf("Enter Bit-Error Rate reading %d (0 to 1): ", i + 1);

        if (scanf("%f", &readings[i]) != 1 ||
            readings[i] < 0 || readings[i] > 1)
        {
            printf("Invalid Bit-Error Rate value. Enter a value from 0 to 1.\n");
            return 1;
        }
    }

    do
    {
        printf("\n--- Bit-Error Rate Statistics Menu ---\n");
        printf("1. Calculate Mean BER\n");
        printf("2. Calculate BER Range\n");
        printf("3. Count readings that exceed a specified limit\n");
        printf("4. Display all readings\n");
        printf("5. Exit\n");
        printf("Enter your choice from above: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid menu input.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                printf("Mean BER: %.4f\n",
                       calculateMean(readings, count));
                break;

            case 2:
                printf("BER range: %.4f\n",
                       calculateRange(readings, count));
                break;

            case 3:
                printf("Enter the BER limit (0 to 1): ");

                if (scanf("%f", &limit) != 1 ||
                    limit < 0 || limit > 1)
                {
                    printf("Invalid limit. Enter a value from 0 to 1.\n");
                    return 1;
                }

                printf("Readings above the limit: %d\n",
                       countAboveLimit(readings, count, limit));
                break;

            case 4:
                printf("BER readings: ");

                for (i = 0; i < count; i++)
                {
                    printf("%.4f ", readings[i]);
                }

                printf("\n");
                break;

            case 5:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice. Select a number from 0 to 4.\n");
        }

    } while (choice != 0);

    return 0;
}
