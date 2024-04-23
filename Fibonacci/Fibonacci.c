#include <stdio.h>

int Dyna(int num){

int a = 0;
int b = 1;
int result = 0;

for(int i = 2; i <= num; i++){
        result = a + b;
        a = b;
        b = result;
    }
return result;

}

int main() {
int number;
    scanf("%d", &number);
    printf("%d\n", Dyna(number)); // 수정된 부분
    return 0;
}
