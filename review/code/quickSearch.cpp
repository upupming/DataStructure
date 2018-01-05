/* 在无序记录A[1]-A[n]中找到从小到大排在第j位的记录
 * 快排划分思想：一次划分将基准元素定位于k，如果k==j，找到第j小的元素，否则，递归地在k的左边或右边进行划分直到k==j
 */

#include <iostream>

using namespace std;

// 分块，返回分块基准值所处的下标
int partition(int A[], int i, int j){
    int pivot = A[j]; // 末尾元素作为基准值
    int l = i; 
    for(int r = i; r<=j-1; r++){
        if(A[r] <= pivot){ // 小于等于pivot，放左边
            swap(A[l++], A[r]);
        }
    }
    swap(A[l], A[j]); // 放置基准值
    return l;
}

// 
int search(int A[], int n, int j){
    int s = 1, t = n;
    int k = partition(A, s, t);
    while(k!=j){ // 直到基准值刚好为A[j]
        if(k<j) k = partition(A, k+1, t);
        else k = partition(A, s, k-1);
    }
    return A[j];
}

int main(){
   int A[] = { 0xFFFFFFFF, 2, 54, 23, 78, 82, 96, 72};
   int result = search(A, 7, 3);
   cout << "第3小的元素是" << result << endl; 
   return 0;
} 
