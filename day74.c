#include <stdio.h>

int main() {
    char s[1000];
    int freq[26] = {0};

    scanf("%s", s);

    // Step 1: count frequency
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: find first non-repeating
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // if none found
    printf("$\n");

    return 0;
}