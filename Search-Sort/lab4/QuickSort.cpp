/* 快排的优化
 *
 * 李一鸣          1160300625
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <time.h>

using namespace std;

template<typename Comparable>
class QuickSort{
private:
    int find(int i, int j){
        Comparable first = arr[i];
        for(int k=i+1; k<=j; k++){
            if(arr[k] > first) return k;
            else if(arr[k] < first) return i;
        }
        return -1;
    }
    int parti(int i, int j, int pivot){
        int ii=i, jj=j;
        Comparable cp = arr[pivot];
        while(ii<jj){
            //ii = i; jj = j;
            while(arr[ii] < cp) ii++;
            while(arr[jj] >= cp) jj--;
            if(ii<jj) swap(arr[ii], arr[jj]);

            //cout << (*this) << endl;
        }
        return ii;
    }
    void sortWithOutTail(int i, int j){
        if(i>=j) return;
        int pivot = find(i, j);
        if(pivot != -1){
            //cout << (*this) << endl;
            int k = parti(i, j, pivot);

            sortWithOutTail(i, k-1);// left
            sortWithOutTail(k, j);// right
        }
    }
    void sort(int i, int j){
        if(i>=j) return;
        while(i<j){
            int pivot = find(i, j);
            if(pivot != -1){
                //cout << (*this) << endl;
                int k = parti(i, j, pivot);

                if(k-i >= j-k){
                    sort(i, k-1);// left
                    i = k;
                }
                else{
                    sort(k, j);// right
                    j = k-1;
                }
            }
            else break;
        }
    }
public:
    vector<Comparable> arr;
    QuickSort(const vector<Comparable> & arrayToBeSort):arr(arrayToBeSort){}

    void sort(){
        sort(0, arr.size()-1);
    }

    void sortWithOutTail(){
        sortWithOutTail(0, arr.size()-1);
    }
};

template<typename Comparable>
ostream& operator<< (ostream& os, const QuickSort<Comparable>& qs){
    for(auto x: qs.arr){
        os << x << endl;
    }
    os << endl;
    return os;
}

int main()
{
    int N = 50000;
    vector<int> arr(N);
    srand(time(nullptr));

    ofstream out("output.txt");

    int T = 10;
    clock_t total = 0;
    for(int t=0; t<T; t++){
        cout << "testing " << t+1 << "..." << endl;
        for(int j=0; j<N; j++)
            arr[j] = rand();

        QuickSort<int> qs(arr);
        clock_t start = clock();
        qs.sortWithOutTail();
        clock_t finish = clock();
        total += finish-start;
        out << qs;
    }
    cout  << endl << T << " test cases, for each test " << N <<  "integers" << endl;
    cout << "on everage " << (total)/(CLOCKS_PER_SEC/1e6)/T << " us = " << (total)/(CLOCKS_PER_SEC/1e3)/T << " ms per case" << endl;

    cout << endl << endl;

    total = 0;
    for(int t=0; t<T; t++){
        cout << "testing " << t+1 << "..." << endl;
        for(int j=0; j<N; j++)
            arr[j] = rand();

        QuickSort<int> qs(arr);
        clock_t start = clock();
        qs.sort();
        clock_t finish = clock();
        total += finish-start;
        out << qs;
    }
    cout  << endl << T << " test cases, for each test " << N <<  "integers" << endl;
    cout << "After optimizing, on everage " << (total)/(CLOCKS_PER_SEC/1e6)/T << " us = " << (total)/(CLOCKS_PER_SEC/1e3)/T << " ms per case" << endl;
    out.close();
    return 0;
}
