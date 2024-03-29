// 0-1背包问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
void Knapsack(int v[], int w[], int c, int n, int m[][20]);
void Traceback(int m[][20], int w[], int c, int n);
int main() {
	int c = 10, n = 5;
	int m[20][20] = { 0 };
	int v[20] = { 0 }, w[20] = { 0 };
	//int x[20];
	cout << "请输入背包重量:";
	cin >> c;
	cout << endl;
	cout << "请输入物品个数：";
	cin >> n;
	cout << endl;
	cout << "请输入每个物品重量：";
	for (int i = 1; i <= n; i++) cin >> w[i];
	cout << endl;
	cout << "请输入每个物品价值：";
	for (int i = 1; i <= n; i++) cin >> v[i];
	Knapsack(v, w, c, n, m);
	return 0;
}
void Knapsack(int v[], int w[], int c, int n, int m[][20]) {
	int jMax = min(w[n] - 1, c);
	for (int j = 0; j <= jMax; j++) m[n][j] = 0;//最后一个物品不放入 
	for (int j = w[n]; j <= c; j++) m[n][j] = v[n];//最后一个物品放入 
	for (int i = n - 1; i > 1; i--) {
		jMax = min(w[i] - 1, c);
		for (int j = 0; j < jMax; j++) m[i][j] = m[i + 1][j];//不放入
		for (int j = w[i]; j <= c; j++) m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);//放入 
	}
	m[1][c] = m[2][c];//最后一个物品不放入
	if (c >= w[1]) m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);//寻找最优解
	Traceback(m, w, c, n);
}
void Traceback(int m[][20], int w[], int c, int n) {
	cout << c << endl;
	cout << n << endl;
	int x[20] = { 0 };
	for (int i = 1; i < n; i++) {
		if (m[i][c] == m[i + 1][c]) x[i] = 0;
		else {
			x[i] = 1;
			c -= w[i];
		}
	}
	x[n] = (m[n][c]) ? 1 : 0;
	cout << "物品放入方案为:";
	for (int i = 1; i <= n; i++) cout << x[i] << " ";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
