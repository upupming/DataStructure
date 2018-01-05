#include <stack>
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
class queue{
private:
    stack<T> s1, s2, maxVals;
public:
    queue(){}
    void Enqueue(const T & v){
        s2.push(v);
        cout << "Enqueue(" << v << ")..." << endl;
        // 存放最大值
        if(maxVals.empty()){ // 栈空
            maxVals.push(v);
        }
        else if(maxVals.top() <= v){ // 新的最大值，可能多个相同的最大值
            maxVals.push(v);
        }
        else if(v < maxVals.top()){ // v不是当前最大，可能成为以后的最大，压入到合适的位置
            stack<T> tmp;
            while(!maxVals.empty() && v < maxVals.top()){ // 弹出所有比v大的值
                tmp.push(maxVals.top()); maxVals.pop();
            }
            if(maxVals.top() <= v){ // 压入v
                maxVals.push(v);
            }
            while(!tmp.empty()){ // 还原被弹出的值
                maxVals.push(tmp.top()); tmp.pop();
            }
        }
    }
    T Dequeue(){
        // s1 非空：从s1弹出
        if(!s1.empty()){
            T tmp = s1.top(); s1.pop();
            //弹出的元素会导致最大值在队列中的出现次数减一或者消失（maxTimes==0）
            if(maxVals.top() == tmp) maxVals.pop();
            cout << "Dequeued(" << tmp << ")" << endl;
            return tmp;
        }

        // s1空，将s2中所有元素弹出到s1
        while(!s2.empty()){
            T tmp = s2.top(); s2.pop();
            s1.push(tmp);
        }
        T tmp = s1.top(); s1.pop();
        cout << "Dequeued(" << tmp << ")" << endl;
        return tmp;
    }
    T Maxelement(){
        return maxVals.top();
    }
};

int main(){
    queue<int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    cout << q.Maxelement() << endl;
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(10);
    cout << q.Maxelement() << endl;
    q.Enqueue(9);
    q.Enqueue(8);
    q.Enqueue(7);
    q.Enqueue(6);
    cout << q.Maxelement() << endl;
    q.Dequeue();
    q.Dequeue();
    cout << q.Maxelement() << endl;
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    cout << q.Maxelement() << endl;
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    cout << q.Maxelement() << endl;
    return 0;
}
