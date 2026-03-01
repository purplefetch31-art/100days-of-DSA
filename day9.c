#include <stdio.h>
#include <string.h>


void reverse(char str[], int index) {
    
    if (index < 0)
        return;

    printf("%c", str[index]);


    reverse(str, index - 1);
}

int main() {
    char str[1001];


    scanf("%s", str);

    int length = strlen(str);


    reverse(str, length - 1);

    return 0;
}
