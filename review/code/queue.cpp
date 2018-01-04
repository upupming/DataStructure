#include <stack>
#include <cstdlib>

using namespace std;

template <typename T>
class queue{
private:
    T maxVal; int maxTimes;
    stack<T> s1, s2;
public:
    queue(){
        maxTimes = 0;
    }
    void Enqueue(const T & v){
        s2.push_back(v);

        // 存放最大值
        if(!maxTimes)
            maxVal = v;
        else if(maxVal < v){
            maxVal = v;
            maxTimes++;
        }
    }
    T Dequeue(){
        // s1 非空：从s1弹出
        if(!s1.empty()){
            T tmp = s1.top(); s1.pop();
            //弹出的元素会导致最大值在队列中的出现次数减一或者消失（maxTimes==0）
            if(maxVal == tmp) maxTimes--;
            return tmp;
        }

        // s1空，将s2中所有元素弹出到s1
        while(!s2.empty()){
            T tmp = s2.top(); s2.pop();
            s1.push_back(tmp);
        }
        T tmp = s1.top(); s1.pop();
        return tmp;
    }
    T Maxelement(){
        if(maxTimes)
            return maxVal;
        else
            exit(-1);
    }
};

int main(){
    return 0;
}
