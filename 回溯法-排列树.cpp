#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

int cnt = 0;
void swaparr(int arr[], int a, int b) {
	int temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}

void func(int arr[], int i, int length) {
	if (i == length) {
		cnt++;
		for (int t = 0; t < length; t++) {
			printf("%d ", arr[t]);
		}
		printf("\n");
	}
	else {
		for (int k = i; k < length; k++) {
			swaparr(arr, i, k);
			func(arr, i + 1, length);
			swaparr(arr, i, k);
		}
	}
}

int main() {
	int arr[] = {1,2,3,4};
	int length = sizeof(arr) / sizeof(arr[0]);
	func(arr, 0, length);
	printf("%d", cnt);
	return 0;
}
