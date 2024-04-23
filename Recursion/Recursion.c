#include <stdio.h>

int factorial(int number){
if(number==0)
return 1;
else
        return number * factorial((number-1));
}
int main() {

int number;
    scanf("%d", &number);
    printf("%d! = %d ", number, factorial(number));
return 0;
}

2.
#include <stdio.h>

int Dynamic(int num){
int result = 1;

for(int i = 1; i <= num; i++){
        result *= i;
    }

return result;
}

int main() {
int number;
    scanf("%d", &number);
    printf("%d! = %d", number ,Dynamic(number));
return 0;
}
