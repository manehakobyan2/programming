#include <stdio.h>

int main (){
	int digit;
	int num1 = 0;
	int num2=1;
	printf("Enter your number here: ");
	if (scanf("%d", &digit) != 1) {
		printf("Wrong input.\n");
		return 0;
	}
	while (digit != 0){
		num1 = num1*10 +digit%10;
		digit= digit /10;
	}
	printf("%d\n", num1);

return 0;
}
