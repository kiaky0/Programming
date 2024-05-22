# Sorting

- Bubble Sort
- Selection
- Insertion Sort

Video: [watch](https://www.youtube.com/watch?v=SWLLKLov_qs&t=520s)

Sorting Advance: [Note](https://github.com/kiaky0/C_plusplus_learning/blob/main/Data_struct_C%2B%2B/14_Lec13_Sorting.md)

## Bubble Sort

![image](https://github.com/kiaky0/Programming/assets/109141627/71af33bb-d796-499b-825a-cbf16167fbb9)

```C++
#include <iostream>
using namespace std;

void main() {
	int temp;
	int arr[9] = { 3, 1, 12, 8, 22, 21, 14, 9, 23 };
	cout << "Unsorted array: " << endl;

	for (int k = 0; k < 9; k++)
	{
		cout << arr[k] << "\t";
	}
	cout << endl;

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++) {
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "Sorted elements: " << endl;
	for (int m = 0; m < 9; m++)
	{
		cout << arr[m] << "\t";
	}
}
```

output:
```
Unsorted array:
3       1       12      8       22      21      14      9       23
Sorted elements:
1       3       8       9       12      14      21      22      23
```

## Insertion Sort

![image](https://github.com/kiaky0/Programming/assets/109141627/5bb768e2-af92-471c-9f78-569a89b2254e)


```C++
#include <iostream>
using namespace std;

int main() {
	int i, j, num, temp;
	int arr[20];
	cout << "Enter the number of elements of the array: ";
	cin >> num;
	cout << "Enter the elements: ";
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i <= num-1; i++)
	{
		temp = arr[i];
		j = i - 1;
		while ((temp<arr[j]) && j>=0)
		{
			arr[j + 1] = arr[j]; 
			j = j - 1;
		}
		arr[j + 1] = temp;
	}

	cout << "Sorted elements: ";
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
```

## Selection Sort

![image](https://github.com/kiaky0/Programming/assets/109141627/1c429b15-4ad9-4609-8b4e-a3f475abee2e)


```C++
#include <iostream>
using namespace std;

int main() {
	int i, j, num, p, temp, min, arr[10];
	cout << "Enter the number of element: ";
	cin >> num;
	cout << "\nEnter elements: " << endl;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < num-1; i++)
	{
		min = arr[i]; 
		p = i;
		for (int j = i+1; j < num; j++)
		{
			if (min > arr[j]) {
				min = arr[j];
				p = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[p];
		arr[p] = temp;
	}

	cout << "\nSorted element are: " << endl;
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
```

## Quick Sort

![image](https://github.com/kiaky0/Programming/assets/109141627/a15402f9-3246-47e0-ae68-cd2442b66cf5)

```C++
#include<iostream>
using namespace std;

int divide(int arr[], int start, int end) {
	int pivot = arr[end];
	int index = start;

	for (int i = start; i < end; i++)
	{
		if (arr[i] < pivot) {
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}
	int temp = arr[end];
	arr[end] = arr[index];
	arr[index] = temp;

	return index;
}

void Quick(int arr[], int start, int end) {
	if (start<end)
	{
		int d = divide(arr, start, end);
		Quick(arr, start, (d - 1));
		Quick(arr, (d + 1), end);
	}
}

int main() {
	int num, i, arr[10];
	cout << "Enter the number of element: ";
	cin >> num;
	cout << "\nEnter elements: " << endl;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	Quick(arr, 0, (num - 1));

	cout << "Sorted elements: ";
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
```





