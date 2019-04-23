#include <stdio.h>

struct Student {
	char name[30];
	double ap;
	double oop;
	double math;
	double eng;
	double rating;
};

void print(struct Student *arr, int count);
void input(struct Student *arr, int count);
void rat(struct Student *arr, int count);
void success(struct Student *arr, int count);
void quick_struct(struct Student *arr, int count);
void qs_struct(struct Student *arr, int left, int right);

int main()
{
	struct Student *arr;
	int i, n;

	printf("Enter number of persons: ");
	scanf("%d", &n);

	arr = (struct Student*) malloc(n * sizeof(struct Student));

	input(arr, n);
	rat(arr, n);
	qs_struct(arr, 0, n);
	print(arr, n);
	success(arr, n);
	return 0;
}
void input(struct Student *arr, int count)
{
	for (int i = 0; i < count; ++i)
	{
		printf("Enter name of student as char. Ap, oop, math, eng double value: ");
		scanf("%s %lf %lf %lf %lf", &(arr + i)->name, &(arr + i)->ap, &(arr + i)->oop, &(arr + i)->math, &(arr + i)->eng);
	}
}

void print(struct Student *arr, int count)
{
	puts("Displaying Information:");
	for (int i = 0; i < count; ++i)
		printf("%s %lf %lf %lf %lf %lf \n", (arr + i)->name, (arr + i)->ap, (arr + i)->oop, (arr + i)->math, (arr + i)->eng, (arr + i)->rating);
}

void rat(struct Student *arr, int count)
{
	for (int i = 0; i < count; ++i) {
		(arr + i)->rating = ((arr + i)->ap + (arr + i)->oop + (arr + i)->math + (arr + i)->eng) / 4;
	}
}

void success(struct Student *arr, int count)
{
	int t;
	int all_stud = count;
	int x_stud = 0;
	int rezult;
	for (t = 0; t < count; ++t) {
		if ((arr + t)->rating > 0 && (arr + t)->rating < 71)
		{
			x_stud++;
			printf("x_stud %d \n", x_stud);
		}
	}
	rezult = ((x_stud * 100) / all_stud);

	puts("---------------------------------------------------------------------------");
	printf("Відсоток студентів у котрих рейтинговий бал нижчий 71 складає  %d \n", rezult);
}

void quick_struct(struct Student *arr, int count)
{
	qs_struct(arr, 0, count - 1);
}

void qs_struct(struct Student *arr, int left, int right)
{
	register int i, j;
	double x;
	struct Student temp;
	i = left; j = right + 1;

	x = arr[(left + right) / 2].rating;
	do {
		while (((arr + i)->rating > x) && (i < right)) i++;
		while ((x >(arr + j)->rating) && (j > left)) j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs_struct(arr, left, j);
	if (i < right) qs_struct(arr, i, right);
}