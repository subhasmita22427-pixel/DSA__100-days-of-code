#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left, right, flag = 1;

    printf("Enter the string: ");
    scanf("%s", s);   // reads string without spaces

    left = 0;
    right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    if (flag == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}
