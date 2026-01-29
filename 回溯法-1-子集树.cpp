#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void func(int arr[], int i, int length, int x[]) {
	if (i == length) {
		for (int j = 0; j < length; j++) {
			if (x[j] == 1) {
				printf("%d ", arr[j]);
			}
		}
		printf("\n");
	}
	else {
		x[i] = 1;
		func(arr, i + 1, length, x);
		x[i] = 0;
		func(arr, i + 1, length, x);
	}
}

int main() {
	int arr[3] = { 1,2,3 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int x[3] = { 0 };
	func(arr, 0, length, x);
	return 0;
}
