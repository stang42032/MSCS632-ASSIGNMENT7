#include <stdio.h>
#include <stdlib.h>

// Function prototypes
double calculate_mean(int arr[], int n);
double calculate_median(int arr[], int n);
void calculate_mode(int arr[], int n);

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    printf("Mean: %.2f\n", calculate_mean(arr, n));
    printf("Median: %.2f\n", calculate_median(arr, n));
    printf("Mode(s): ");
    calculate_mode(arr, n);

    free(arr);
    return 0;
}

double calculate_mean(int arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

double calculate_median(int arr[], int n) {
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

void calculate_mode(int arr[], int n) {
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
        if (count > max_count) max_count = count;
    }

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
        if (count == max_count)
            printf("%d ", arr[i]);
    }
    printf("\n");
}
