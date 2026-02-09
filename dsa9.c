#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, len;
    char temp;

    // Input string
    scanf("%s", s);

    len = strlen(s);

    // Reverse string in-place
    for (i = 0; i < len / 2; i++) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }

    // Output reversed string
    printf("%s", s);

    return 0;
}
