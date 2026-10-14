#include <stdio.h>
#include <string.h>

struct Student { int roll; char name[30]; float sgpa; };

int main() {
    struct Student s[15], key;
    for (int i = 0; i < 15; i++) {
        printf("Enter roll, name, SGPA: ");
        scanf("%d %29s %f", &s[i].roll, s[i].name, &s[i].sgpa);
    }

    for (int i = 1; i < 15; i++) {
        key = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }

    printf("\\nRoll\\tName\\tSGPA\\n");
    for (int i = 0; i < 15; i++)
        printf("%d\\t%s\\t%.2f\\n", s[i].roll, s[i].name, s[i].sgpa);
    return 0;
}
