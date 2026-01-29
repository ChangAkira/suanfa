#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
#include <stdbool.h>

int cnt = 0;
void swaparr(int arr[], int a, int b) {
	int temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}

bool judge(int arr[], int i) {
	for (int k = 0; k < i; k++) {
		if (k == i || arr[k] == arr[i] || abs(arr[k] - arr[i]) == abs(k - i)) {//前两个条件其实是没必要的但还是写出来
			return false;
		}
	}
	return true;
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
			if (judge(arr,i)) {//到了该结点意味着前i-1个元素的位置已经被确定下来了，我们要看刚刚交换过来的第i个位置的元素是否满足不在同一行同一列同一斜线，满足我们才有必要继续生成它的孩子结点，否则回溯回去就行了
				func(arr, i + 1, length);
			}
			swaparr(arr, i, k);
		}
	}
}

int main() {
	int arr[] = {1,2,3,4,5,6,7,8};//用一个元素表示一个皇后，该元素的下标（加1）表示所在行，该元素的值表示所在列。这样就可以确保八个皇后永远不在同一行同一列，我们只要考虑在不在同一斜线上即可
	int length = sizeof(arr) / sizeof(arr[0]);
	func(arr, 0, length);
	printf("%d", cnt);//八皇后问题有92个解
	return 0;
}
