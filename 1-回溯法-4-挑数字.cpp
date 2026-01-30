/*
挑数字
在给定的整数中挑选一组数字使和等于指定的值，存在解打印，不存在也打印
*/
//子集树

#include<iostream>
#include<vector>
using namespace std;

int arr[] = { 4,8,12,16,7,9,3 };
int number = 18;
vector<int>x;//记录选择的数字
int sum = 0;//记录所选择数字的和
int length = sizeof(arr) / sizeof(arr[0]);
int sum_left = 0;

void func(int i) {
	if (i == length) {
		if (sum != number) {
			return;
		}
		for (int v : x) {
			cout << v << " ";
		}
		cout << endl;
	}
	else {
		sum_left -= arr[i];//处理
		if (sum + arr[i] <= number) {//剪左树枝  已选择的数字的和加上即将要选择的数字
			sum += arr[i];
			x.push_back(arr[i]);
			func(i + 1);
			sum -= arr[i];
			x.pop_back();
		}
		
		
		if (sum + sum_left >= number) {//剪右树枝  已选择的数字的和加上剩余的可以被选择的数字的和
			func(i + 1);
		}
		sum_left += arr[i];//回溯
	}
}


int main() {
	for (int v :arr) {
		sum_left += v;
	}
	func(0);
	return 0;
}
