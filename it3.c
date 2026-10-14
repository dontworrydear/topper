#include <stdio.h>

struct Student { int roll; char name[30]; float sgpa; };

int main() {
    struct Student s[15], temp;
    for (int i = 0; i < 15; i++) {
        printf("Enter roll, name, SGPA: ");
        scanf("%d %29s %f", &s[i].roll, s[i].name, &s[i].sgpa);
    }

    for (int i = 0; i < 14; i++)
        for (int j = 0; j < 14 - i; j++)
            if (s[j].roll > s[j + 1].roll) {
                temp = s[j]; s[j] = s[j + 1]; s[j + 1] = temp;
            }

    printf("\\nRoll\\tName\\tSGPA\\n");
    for (int i = 0; i < 15; i++)
        printf("%d\\t%s\\t%.2f\\n", s[i].roll, s[i].name, s[i].sgpa);
    return 0;
}
