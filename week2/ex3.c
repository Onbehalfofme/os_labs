#include"stdio.h"
int main()
{
	int n;
	printf("Введите высоту треугольника\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2*n - 1; j++)
		{
			if (j <= (2*n - 1)/2 + i && j >= (2*n - 1)/2 - i)
			{
			       printf("*");
			}
			else
			{
				printf(" ");
			}
	 		
		}
		printf("\n");
	}

	return 0;
}

