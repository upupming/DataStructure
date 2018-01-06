/* 半径(跟到叶子的最大距离、深度-1)最小的生成树
 * 
 * 采用广度优先搜索，邻接点均已遍历的结点是叶子结点
 * 记下节点的半径
 */

#include <queue>
using namespace std;

int miniRadius(adjLiat g, int v){
    // 图g：邻接表，顶点信息就是编号，从v开始遍历
    typedef struct {int v, level;} Node;
    int MAX = 100; // 设最大层次数
    int visited[MAX] = 0; 
    Node *R; 
    queue<Node> Q;// Q为队列，容量足够大
    int v, level; 
    R->level = 1; Q.push(R);
    while(!Q.empty()){
        R = Q.front(); Q.pop();
        v = R.v; level = R.level;
    }
