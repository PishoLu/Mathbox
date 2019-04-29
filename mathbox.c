#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char* argv[])
{
	int count;
	//printf("The command line has %d arguements:\n", argc - 1);
	//for (count = 1; count < argc; count++)
	//{
		//printf("%d:%s\n", count, argv[count]);
	//}
	//printf("\n");
	if (strcmp(argv[1], "calc") == 0)
	{
		char calculate[10] = { '\0' };
		char parameter1[10] = { '\0' };
		char parameter2[10] = { '\0' };
		int sign;
		for (count = 1; count < argc; count++)
		{
			if (strcmp(argv[count], "-s") == 0)
			{
				sign = strcmp(argv[count], "-s");
				//printf("count = %d and sign = %d\n", count, sign);
				//printf("%s is copying to calulate", argv[count + 1]);
				strcpy_s(calculate, 10, argv[count + 1]);
				//printf(" %s and calculate is %s\n", argv[count], calculate);
			}
			else if (strcmp(argv[count], "-o") == 0)
			{
				sign = strcmp(argv[count], "-o");
				//printf("count = %d and sign = %d\n", count, sign);
				//printf("%s is copying to parameter1", argv[count + 1]);
				strcpy_s(parameter1, 10, argv[count + 1]);
				//printf(" %s and parameter1 is %s\n", argv[count], parameter1);
			}
			else if (strcmp(argv[count], "-p") == 0)
			{
				sign = strcmp(argv[count], "-p");
				//printf("count = %d and sign = %d\n", count, sign);
				//printf("%s is copying to parameter2", argv[count + 1]);
				strcpy_s(parameter2, 10, argv[count + 1]);
				//printf(" %s and parameter2 is %s\n", argv[count], parameter2);
			}
		}
		//double parameter1_double = 0;
		//double parameter2_double = 0;
		int  parameter1_int = 0;
		int  parameter2_int = 0;
		sscanf_s(parameter1, "%d", &parameter1_int);
		sscanf_s(parameter2, "%d", &parameter2_int);
		//printf("parameter1_int is %d\n", parameter1_int);
		//printf("parameter2_int is %d\n", parameter2_int);
		float reason_temp = 0;
		if (strcmp(calculate, "add") == 0) {
			reason_temp = parameter1_int + parameter2_int;
			printf("%d + %d = %.2f", parameter1_int, parameter2_int, reason_temp);
		}
		else if (strcmp(calculate, "sub") == 0) {
			reason_temp = parameter1_int - parameter2_int;
			printf("%d - %d = %.2f", parameter1_int, parameter2_int, reason_temp);
		}
		else if (strcmp(calculate, "mul") == 0) {
			reason_temp = parameter1_int * parameter2_int;
			printf("%d * %d = %.2f", parameter1_int, parameter2_int, reason_temp);
		}
		else if (strcmp(calculate, "div") == 0) {
			if (parameter2_int == 0) {
				printf("做除法时，第二个参数不能为0!\n");
				return 0;
			}
			reason_temp = (float)parameter1_int / parameter2_int;
			printf("%d / %d = %.2f", parameter1_int, parameter2_int, reason_temp);
		}
	}
	else if (strcmp(argv[1], "exam") == 0) {
		time_t t;
		int count = 0;
		int rand1 = 0;
		int rand2 = 0;
		int rand3 = 0;
		float reason = 0;
		float answser = 0;
		int correct = 0;
		int error = 0;
		for (count = 0; count < 10; count++) {
			srand((unsigned)time(&t));
			rand1 = rand() % 10 + 1;
			rand2 = rand() % 10 + 1;
			rand3 = rand() % 4 + 1;
			//rand3 = rand() % 3 + 1;
			//printf("rand1=%d,rand2=%d,rand3=%d\n", rand1, rand2, rand3);
			switch (rand3)
			{
			case 1:
				printf("%d + %d = ", rand1, rand2);
				reason = rand1 + rand2;
				//printf("%.2f", reason);
				break;
			case 2:
				printf("%d - %d = ", rand1, rand2);
				reason = rand1 - rand2;
				//printf("%.2f", reason);
				break;
			case 3:
				printf("%d * %d = ", rand1, rand2);
				reason = rand1 * rand2;
				//printf("%.2f", reason);
				break;
			case 4:
				while (1)
				{
					if (rand1 % rand2 == 0 ||
						rand1 % rand2 == (float)rand2 / 2 ||
						rand1 % rand2 == (float)rand2 / 4 ||
						rand2 % rand1 == 0 && (float)rand2 / rand1 < 4)
					{
						printf("%d / %d = ", rand1, rand2);
						reason = (float)rand1 / rand2;
						//printf("%.2f", reason);
						break;
					}
					else {
						rand1 = rand() % 10 + 1;
						rand2 = rand() % 10 + 1;
					}
				}
				break;
			}
			scanf_s("%f", &answser);
			if (reason == answser) {
				correct++;
			}
			else {
				error++;
			}
		}

		printf("正确了 %d 道题，错了 %d 道题\n", correct, error);
	}
	else {
		printf("请使用正确的参数输入。calc/exam -s add/sub/mul/div -o parameter1 -p parameter2\n");
	}
	return 0;
}