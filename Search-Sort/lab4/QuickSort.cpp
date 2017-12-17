/* 快排的优化
 *
 * 李一鸣          1160300625
 */
#include <iostream>
#include <vector>

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
    void sort(int i, int j){
        if(i>=j) return;
        while(i<j){
            int pivot = find(i, j);
            if(pivot != -1){
                //cout << (*this) << endl;
                int k = parti(i, j, pivot);
                sort(i, k-1);// left
                //sort(k, j);// right
                i = k;
            }
        }
    }
public:
    vector<Comparable> arr;
    QuickSort(const vector<Comparable> & arrayToBeSort):arr(arrayToBeSort){}

    void sort(){
        sort(0, arr.size()-1);
    }

};

template<typename Comparable>
ostream& operator<< (ostream& os, const QuickSort<Comparable>& qs){
    for(auto x: qs.arr){
        os << x << " ";
    }
    os << endl;
    return os;
}

int main()
{
    vector<int> arr{-32, 3, 4354, 2, 45, -86, 24, 324, -459, 21, 123};
    QuickSort<int> qs(arr);
    qs.sort();
    cout << qs;
    return 0;
}
