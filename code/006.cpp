/*
Title: 算法 - 二分搜索
Description: 本源文件实现了二分搜索的基础应用，并完成了本系列课程第一道真正意义的算法题。
Author: DevCherry
Time: 2026-02-12
Links: https://www.bilibili.com/video/BV1bX4y177uT; https://leetcode.cn/problems/find-peak-element/
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<int> arr;

void userInput_arr() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string line; int num = 0;

	getline(cin, line);
	stringstream ss(line);

	while (ss >> num) {
		arr.push_back(num);
	}
}

void userInput_test() {
	for (int x : arr) {
		printf("%d ", x);
	}
	printf("\n");
}

// Q1: 在有序数组中确定某个数是否存在. (in: arr[], num; out: bool)
bool sortedSearch_isexist(vector<int>& arr, int num) {
	int l = 0, r = (int)arr.size() - 1, m = 0;
	while (l <= r) {
		m = l + ((r - l) >> 1);
//		m = l + ((r - l) >> 1);		更底层的写法。
//		m = l + (r - l) / 2;		防溢出的写法。
//		m = (l + r) / 2;			当问题规模很大时，即r是一个大数，再加某数可能导致溢出。
		if (arr[m] == num) {
			return true;
		}
		else if (arr[m] < num) {
			l = m + 1;
		}
		else if (arr[m] > num) {
			r = m - 1;
		}
	}
	return false;
}

// Q2: 在有序数组中找大于等于某个数的最左位置. (in: arr[], num; out: int)
int sortedSearch_findleft(vector<int> arr, int num) {
	int ans = -1; // 用于暂存更新的答案。
	int l = 0, r = (int)arr.size() - 1, m = 0;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (arr[m] >= num) {
//		当前中间数在问题数右侧，说明可能未到达最左位置，即向左二分搜索；更新答案。
			r = m - 1;
			ans = m;
		}
		else {
//		反之则在问题数左侧，说明已经过了最左位置，即向右二分搜索；没有更新答案的必要。
			l = m + 1;
		}
	}
	return ans;
}

// Q3: 在有序数组中找小于等于某个数的最右位置. (in: arr[], num; out: int)
int sortedSearch_findright(vector<int>& arr, int num) {
	int ans = -1;
	int l = 0, r = (int)arr.size() - 1, m = 0;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (arr[m] <= num) {
			l = m + 1;
			ans = m;
		}
		else {
			r = m - 1;
		}
	}
	return ans;
}

// Problem: Leetcode-162 寻找峰值
// Description: 峰值元素是指其值严格大于左右相邻值的元素; 给你一个整数数组 nums，找到峰值元素并返回其索引; 数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可; 你可以假设 nums[-1] = nums[n] = -∞ 。
// Link: https://leetcode.cn/problems/find-peak-element/
int unsortedSearch_findpeak(vector<int>& arr) {
	int n = (int)arr.size() - 1;
	if (arr.size() == 1) {
		return 0;
	}
	else if (arr[0] > arr[1]) {
		return 0;
	}
	else if (arr[n] > arr[n - 1]) {
		return n;
	}
	else {
		int l = 1, r = n - 1, m = 0;
		while (l <= r) {
			m = l + (r - l) / 2;
			if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1]) {
				return m;
			}
			else if (arr[m - 1] > arr[m]) {
				r = m - 1;
			}
			else if (arr[m] > arr[m - 1] && arr[m + 1] > arr[m]) {
				l = m + 1;
			}
		}
		return -1; // 每个分支必须有一个返回值。
	}
}



int main() {

	userInput_arr();
	userInput_test();
	printf("%d", unsortedSearch_findpeak(arr));

	return 0;
}