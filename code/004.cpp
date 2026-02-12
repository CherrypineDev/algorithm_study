/*
Title: 算法 - 三大排序
Description: 本源文件实现了选择排序、冒泡排序和插入排序。
Author: DevCherry
Time: 2026-02-12
Links: https://www.bilibili.com/video/BV12P41147to
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
    for (int x : arr) printf("%d ", x);
}

void swap(int& a, int& b) {
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < (int)arr.size(); i++) {
        int arrMinIndex = i;
        for (int j = i; j < (int)arr.size(); j++) {
            if (arr[j] < arr[arrMinIndex]) arrMinIndex = j;
        }
        swap(arr[i], arr[arrMinIndex]);
    }
}

void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < (int)arr.size() - 1; i++) {
        for (int j = 0; j < (int)arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < (int)arr.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {

    userInput_arr();
	insertionSort(arr);
    userInput_test();

    return 0;
}