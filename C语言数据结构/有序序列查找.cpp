#include "stdio.h"
#include<iostream>
#define MAX 100
using namespace std;
int Binary_Search(const int* array, int n, int key)
{
    int low = 1;
    int high = n;
    int mid;
    while (low <= high)
    {
        if (array[0] < array[1])
        {
            mid = (low + high) / 2;
            if (key < array[mid])
                high = mid - 1;
            else if (key > array[mid])
                low = mid + 1;
            else
                return  mid;
        }
        if (array[0] > array[1])
        {
            mid = (low + high) / 2;
            if (key > array[mid])
                high = mid - 1;
            else if (key < array[mid])
                low = mid + 1;
            else
                return  mid;
        }
    }
    return 0;
}
int main()
{
    int MAXSIZE;
    int key;
    cout << "请输入序列的大小: ";
    cin >> MAXSIZE;
    int num[MAX];
    cout << "请输入一个有序序列:本程序仅可实现有序序列的查找（即递增或递减）\n";
    for (int i = 0; i < MAXSIZE; i++)
    {
        cin >> num[i];
    }
    cout << '\n' << "请输入关键字= ";
    cin >> key;
    cout << endl;
    int key_find = Binary_Search(num, MAXSIZE, key);
    if (key_find == 0)
        cout << "没找到!";
    else
        cout << key << "在序列的第" << key_find + 1 << "位!";
    system("pause");
    return 0;
}