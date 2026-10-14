#include <stdio.h>

struct Student { int roll; char name[30]; float sgpa; };

int main() {
    struct Student s[15], temp;
    for (int i = 0; i < 15; i++) {
        printf("Enter roll, name, SGPA: ");
        scanf("%d %29s %f", &s[i].roll, s[i].name, &s[i].sgpa);
    }

    for (int i = 0; i < 14; i++) {
        int max = i;
        for (int j = i + 1; j < 15; j++)
            if (s[j].sgpa > s[max].sgpa) max = j;
        temp = s[i]; s[i] = s[max]; s[max] = temp;
    }

    printf("\\nTop 10 Students\\nRoll\\tName\\tSGPA\\n");
    for (int i = 0; i < 10; i++)
        printf("%d\\t%s\\t%.2f\\n", s[i].roll, s[i].name, s[i].sgpa);
    return 0;
}
