#include <stdio.h>
int main() {
int m;
scanf("%d", &m);
if (m >= 90)
printf("A\n");
else if (m >= 75)
printf("B\n");
else if (m >= 50)
printf("C\n");
else
printf("Fail\n");
return 0;
}