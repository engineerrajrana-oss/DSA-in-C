#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefix = 0;
    long long count = 0;

    // Frequency array for prefix sums
    // Offset used to handle negative sums
    int size = 2 * MAX + 1;
    long long *freq = (long long*)calloc(size, sizeof(long long));

    int offset = MAX;

    // Important: prefix sum 0 initially appears once
    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(prefix + offset >= 0 && prefix + offset < size) {
            count += freq[prefix + offset];
            freq[prefix + offset]++;
        }
    }

    printf("%lld\n", count);

    free(freq);
    return 0;
}