#include <stdio.h>

int main() {
    int n;
    
    // Input the size of the array
    scanf("%d", &n);
    
    // Input the sorted array
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Handle the edge case where the array is empty
    if (n == 0) {
        return 0;
    }

    // Variable to keep track of the position of unique elements
    int uniqueIndex = 1;

    // Iterate through the array starting from the second element
    for (int i = 1; i < n; i++) {
        // If the current element is different from the previous one
        if (nums[i] != nums[i - 1]) {
            nums[uniqueIndex] = nums[i];  // Place the unique element
            uniqueIndex++;  // Increment the index for the next unique element
        }
    }

    // Print all unique elements
    for (int i = 0; i < uniqueIndex; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
