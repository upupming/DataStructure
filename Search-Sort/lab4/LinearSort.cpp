#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <random>
#include <fstream>

using namespace std;

ofstream out("ls-output.txt");

void countSort(const vector<int> & arr){
    int len = arr.size();
    if(len==0) return;
    vector<int> result(arr);

    out << "Calculating max..." ;
    int maxOfArr = arr[0];
    for(int i=1; i<len; i++) maxOfArr = max(maxOfArr, arr[i]);
    out << endl << "max is: " << maxOfArr << endl;

    out << endl << "Creating tmp map of size " << maxOfArr+1 << "... ";
    map<int, int> tmp;

    out << endl << "Counting times of each value...";
    for(int i=0; i<len; i++)
        tmp[arr[i]]++;

    out << endl << "Accelerating...";
    for(int i=1; i<=maxOfArr; i++)
        tmp[i] += tmp[i-1];

    out << endl << "Placing elements...";
    for(int i=len-1; i>=0; i--){
        result[tmp[arr[i]]-1] = arr[i];
    }

    out << endl << "Printing result..." << endl;
    for(int i=0; i<len; i++){
        out << result[i] << " ";
    }
    out << endl;
}



void radixSort(const vector<int> & arr){
    int len = arr.size();
    if(len==0) return;
    vector<int> result(arr);

    out << "Calculating max bits of elements...";
    int maxOfArr = arr[0];
    for(int i=1; i<len; i++) maxOfArr = max(maxOfArr, arr[i]);
    int d = 0;
    while(maxOfArr > 0){
        maxOfArr /= 10;
        d++;
    }
    out << endl << "Done! d = " << d ;

    vector<int> tmp(len, 0);
    vector<int> cnt(10, 0);

    int radix = 1;
    for(int i=1; i<=d; i++){
        cnt.assign(10, 0); // reset
        for(int j=0; j<len; j++){
            int k = (result[j]/radix)%10; // bit to be sort
            cnt[k]++; // how many k?
        }
        for(int j=1; j<10; j++)
            cnt[j] += cnt[j-1]; // accelerate
        for(int j=len-1; j>=0; j--){
            int k = (result[j]/radix)%10;
            tmp[cnt[k]-1] = result[j];
            cnt[k]--;
        }
        for(int j=0; j<len; j++){
            result[j] = tmp[j];
        }

        radix *= 10;
    }

    out << endl << "Printing result..." << endl;
    for(int i=0; i<len; i++){
        out << result[i] << " ";
    }
    out << endl;
}


void printBuckets(vector<vector<int>> buckets){
    for(size_t i=0; i<buckets.size(); i++){
        for(int x:buckets[i]){
            out << x << " ";
        }
    }
    out << endl;
}

void bucketSort(const vector<int>& arr){
    int len = arr.size();
    if(len==0) return;

    out << "Calculating max bits of elements...";
    int maxOfArr = arr[0];
    for(int i=1; i<len; i++) maxOfArr = max(maxOfArr, arr[i]);

    out << "Every 10 elements a bucket";
    int N = maxOfArr/10 + 1;
    out << endl << "number of buckets is " << N << endl;

    out << "Creating buckets...";
    vector<vector<int>> buckets(N+1);

    for(int i=0; i<len; i++){
        int index = arr[i]/10;
        if(buckets[index].size()==0) buckets[index].assign(1, arr[i]);
        else{
            vector<int>::iterator j=buckets[index].begin();
            while(arr[i] > (*j) && j!=buckets[index].end())j++;
            buckets[index].insert(j, arr[i]);
            //printBuckets(buckets);
        }

    }

    out << endl << "Printing result..." << endl;
    printBuckets(buckets);
}

int main()
{
    int N = 50000;
    vector<int>arr(N);
    srand(time(nullptr));
    clock_t start, finish, total;
    int T = 10;

    cout << "1. Count sort: " << endl << endl;
    total = 0;
    for(int t=0; t<T; t++){
        cout << "testing " << t+1 << "..." << endl;
        for(int i=0; i<N; i++)
        arr[i] = rand() % 100000;

        start = clock();
        countSort(arr);
        finish = clock();
        total += finish-start;
    }
    cout  << endl << T << " test cases, for each test " << N <<  "integers" << endl;
    cout << "on everage " << (total)/(CLOCKS_PER_SEC/1e6)/T << " us = " << (total)/(CLOCKS_PER_SEC/1e3)/T << " ms per case" << endl;


    cout << endl << "2. Radix sort: " << endl << endl;
    total = 0;
    for(int t=0; t<T; t++){
        cout << "testing " << t+1 << "..." << endl;
        for(int i=0; i<N; i++)
        arr[i] = rand() % 100000;

        start = clock();
        radixSort(arr);
        finish = clock();
        total += finish-start;
    }
    cout  << endl << T << " test cases, for each test " << N <<  "integers" << endl;
    cout << "on everage " << (total)/(CLOCKS_PER_SEC/1e6)/T << " us = " << (total)/(CLOCKS_PER_SEC/1e3)/T << " ms per case" << endl;

    cout << endl << "3. Bucket sort: " << endl << endl;
    total = 0;
    for(int t=0; t<T; t++){
        cout << "testing " << t+1 << "..." << endl;
        for(int i=0; i<N; i++)
        arr[i] = rand() % 100000;

        start = clock();
        bucketSort(arr);
        finish = clock();
        total += finish-start;
    }
    cout  << endl << T << " test cases, for each test " << N <<  "integers" << endl;
    cout << "on everage " << (total)/(CLOCKS_PER_SEC/1e6)/T << " us = " << (total)/(CLOCKS_PER_SEC/1e3)/T << " ms per case" << endl;

    out.close();
    return 0;
}
