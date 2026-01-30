/*

整数选择问题：给定2N个整数，从里面挑选N个整数，让选择的整数和和，和剩下的整数的和的差最小

*/

#include<iostream>
#include<vector>
using namespace std;

int arr[] = { 12,6,7,11,16,3,8,9 };//原始序列
const int length = sizeof(arr) / sizeof(arr[0]);
vector <int>x;	//记录子集中选择的元素
vector <int>bestx;	//记录最优解
int sum = 0;	//记录子集中所选数字的和
int r = 0;	//记录未选择数字的和
unsigned int min_n = 0xFFFFFFFF;//记录最小差值
int cnt = 0;//记录遍历的子集的个数，用于测试；

void func(int i) {
	if (i == length) {//到达子集树的一个解，对应一个叶子结点
		if (x.size() != length / 2) {
			return;
		}
		int result = abs(sum - r);
		if (result < min_n) {
			min_n = result;
			bestx = x;
		}
		cnt++;
	}
	else {
		if (x.size() < length / 2) {//左树枝表示被选择，剪左树枝
			x.push_back(arr[i]);
		r -= arr[i];
		sum += arr[i];
		func(i + 1);//遍历i的左孩子，表示选择i号位元素

		

		x.pop_back();
		r += arr[i];
		sum -= arr[i];
		}
		
		
		
		//已选择的数字的个数+剩余层数<N个，剪掉
		if (x.size() + length - i > length / 2) {//右树枝表示未被选择，剪右树枝
			func(i + 1);//遍历i的右孩子，表示不选择i号位元素
		}
		
	}
}


int main() {
	for (int v : arr) {
		r += v;
	}
	func(0);
	for (int v : bestx) {
		cout << v << " ";
	}
	cout << endl;
	cout << "min:" << min_n << endl;
	cout << "cnt:" << cnt << endl;
	return 0;
}
