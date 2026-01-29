/*

整数选择问题：给定一组整数，从里面挑选一组整数，让选择的整数和和，和剩下的整数的和的差最小

可以选出子集，记录差值的最小值

*/

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int arr[] = { 12,6,7,11,16,3,9 };//原始序列
const int length = sizeof(arr) / sizeof(arr[0]);
int x[length] = { 0 };//子集树辅助数组，记录左孩子还是右孩子，代表i节点在不在子集中
int bestsets[length] = { 0 };

unsigned int min = 0xFFFFFFFF;//最小的差值，初始设为最大值
int sum = 0;//所选子集的和
int sum2 = 0;//未选子集的和

void func(int i) {//生成子集
	if (i == length) {//访问到了子集树的一个叶子结点了
		int result = abs(sum - sum2);
		if (result < min) {
			min = result;
			//记录此时的子集
			for (int j = 0; j < length; j++) {
				bestsets[j] = x[j];
			}

		}
	}
	else {
		x[i] = 1;
		sum += arr[i];
		sum2 -= arr[i];
		func(i + 1);

		x[i] = 0;
		sum -= arr[i];//回溯到父结点再向下，该结点不被选择要减掉
		sum2 += arr[i];
		func(i + 1);
	}
}

int main() {
	for (int j = 0; j < length; j++) {
		sum2 += arr[j];
	}
	func(0);
	for (int j = 0; j < length; j++) {
		if (bestsets[j] == 1) {
			printf("%d ", arr[j]);
		}
	}
	printf("\n%d\n", min);

	return 0;
}
