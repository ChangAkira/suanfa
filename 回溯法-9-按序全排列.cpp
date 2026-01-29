//按序全排列  （暴力穷举法）但依然是递归和树的思想
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
using namespace std;
int arr[] = { 1,2,3 };
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int>result;
bool state[length];//true表示被选择了
void func(int i) {
	if (i == length) {
		for (int v : result) {
			cout << v << " ";
		}
		cout << endl;
	}
	else {
		for (int j = 0; j <length ; j++) {
			if (!state[j]) {//这个元素可以被选择，才选择，并且向下递归
				state[j] = true;
				result.push_back(arr[j]);
				func(i + 1);
				result.pop_back();//回溯
				state[j] = false;
			}
			
		}
		
	}
}

int main() {
	func(0);
	return 0;
}
