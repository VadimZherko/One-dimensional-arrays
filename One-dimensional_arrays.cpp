#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

void task1();
void task2();

bool is_full_square(int);
bool is_odd(int);
bool is_power_of_two(int);
bool is_divisiblee_by_three(int);

void fill_random(int*, int);
int* create_array(int);
int* concenate_arrays(int*, int, int*, int);
int finde_min_max(int*);
int max(int*, int);
int min(int*, int);

int main()
{
	int number_of_task;

	cout << "List of tasks:\n";
	cout << "\tTask 1 \n";
	cout << "\tTask 2 \n";

	cin >> number_of_task;
	system("cls");

	switch (number_of_task)
	{
	case 1:
	{
		task1();
		break;
	}
	case 2:
	{
		task2();
		break;
	}
	default:
	{
		cout << "I think you're confused." << endl;
	}
	}
}

void task1()
{
	srand(time(NULL));

	int size, sum1 = 0, sum2 = 0, sum3 = 0;

	cout << "Enter the number of elements in the array" << endl;
	cin >> size;

	int* array = new int[size];


	for (int i = 1; i <= size; i++)
	{
		array[i] = rand();

		if (is_odd(array[i]) == 1 && is_full_square(i)) { sum1 += array[i]; }
		if (is_odd(i) == 0 && is_power_of_two(array[i])) { sum2 += array[i]; }
		if (is_odd(array[i]) == 0 && is_divisiblee_by_three(i) == 1) { sum3 += array[i]; }
	}

	cout << "First amount: " << sum1 << endl;
	cout << "Second amount: " << sum2 << endl;
	cout << "Third amount: " << sum3 << endl;

	delete[] array;
}

bool is_full_square(int number)
{
	if (pow((trunc(sqrt(number))), 2) == number) { return 1; }
	else { return 0; }
}

bool is_odd(int number)
{
	if (number % 2 == 0) { return 0; }
	else { return 1; }
}

bool is_power_of_two(int number)
{
	double a = (double)number;

	for (; a >= 1; a = a / 2)
	{
		if (a == 1) {
			return 1;
		}
	}

	return 0;
}

bool is_divisiblee_by_three(int number)
{
	if (number % 3 == 0) { return 1; }
	else return 0;
}

void task2()
{
	srand(time(NULL));

	int size1, size2;

	cout << "Enter two numbers, the sizes of the arrays." << endl;
	cin >> size1 >> size2;


	int* array1 = new int[size1];
	int* array2 = new int[size2];

	fill_random(array1, size1);
	fill_random(array2, size2);

	int* mergedArray = concenate_arrays(array1, size1, array2, size2);

	cout << "Merged array values:" << endl;
	for (int i = 0; i <= (size1 + size2); i++)
	{
		cout << mergedArray[i] << endl;
	}

	cout << "Maximum: " << max(mergedArray, size1 + size2) << endl;
	cout << "Minimum: " << min(mergedArray, size1 + size2) << endl;

}

void fill_random(int* array, int size)
{
	for (int i = 0; i <= size; i++)
	{
		array[i] = ((rand() % 1000) / 10);
	}
}

int* concenate_arrays(int* array1, int size1, int* array2, int size2)
{
	int newSize = size1 + size2;
	int* mergedArray = new int[newSize];

	for (int i = 0; i <= size1; i++)
	{
		mergedArray[i] = array1[i];
	}

	for (int i = 0; i <= size2; i++)
	{
		mergedArray[size1 + i] = array2[i];
	}

	return mergedArray;
}

int min(int* array, int size)
{
	int min;
	min = array[0];

	for (int i = 0; i <= size; i++)
	{
		if (array[i] < min) { min = array[i]; }
	}

	return min;
}

int max(int* array, int size)
{
	int max;
	max = array[0];

	for (int i = 0; i <= size; i++)
	{
		if (array[i] > max) { max = array[i]; }
	}
	return max;
}