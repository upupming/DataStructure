#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

#define MAX_INT 0x7FFFFFFF

void printPath(const vector<int> & path, int v){
    if(path[v]!=-1){
        printPath(path, path[v]);
    }
    cout << v+1 << " ";
}

void solve(int n, vector<vector<int>> matrix){
    //////////////// Dijkstra
    vector<int> dist(n+1); // distance
    vector<bool> visited(n+1);
    vector<int> path(n+1); // precedence
    queue<int> q;

    for(int i=0; i<=n; i++){
        dist[i] = MAX_INT;
        visited[i] = false;
    }
    dist[0] = 0; path[0] = -1;
    q.push(0);

    while(!q.empty()){
        int v = q.front(); q.pop();
        visited[v] = true;

        for(int j=0; j<=n; j++){
            if(!visited[j] && matrix[v][j] < dist[j]-dist[v]){
                dist[j] = dist[v]+matrix[v][j];
                path[j] = v;
                q.push(j);
            }
        }
    }

    cout << "最短时间为: " << dist[n] << endl;
    cout << "购进新设备的时间为: " ;
    printPath(path, path[n]);
    cout << endl;
}

vector<vector<int>> getMatrix(int n, const vector<int> & prices, const vector<int> & repairCost){
    ////////////////// initialize adjacency matrix
    vector<vector<int>> matrix = vector<vector<int>>(n+1);
    for(int i=0; i<=n; i++){
        matrix[i] = vector<int>(n+1);
        for(int j=0; j<=n; j++){
            if(i==j) matrix[i][j] = 0;
            else if(i<j){
                int sum = prices[i];
                for(int k=0; k<j-i; k++)
                    sum += repairCost[k];
                matrix[i][j] = sum;
            }
            else matrix[i][j] = MAX_INT;
        }
    }

    ////////////////// print the matrix
    cout << "构造出的邻接矩阵为: " << endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout << setw(15) << matrix[i][j] ;
        }
        cout << endl;
    }

    return matrix;
}

int main()
{
    /////////////////// input info
//    5
//    11 11 12 12 13
//    5 6 8 11 18
    int n;
    vector<int> prices;
    vector<int> repairCost;
    n = 5;
    prices = vector<int>{11, 11, 12, 12, 13};
    repairCost = vector<int>{5, 6, 8, 11, 18};
    cout << "初始样例为: " << endl;
    cout << "n = " << n << endl;
    cout << "prices = [ ";
    for(int i=0; i<n; i++){
        cout << prices[i] << " ";
    }
    cout << "]" << endl;
    cout << "repairCost = [ ";
    for(int i=0; i<n; i++){
        cout << repairCost[i] << " ";
    }
    cout << "]" << endl;
//    cout << "请输入年数n: " ;
//    cin >> n;
//    int x;
//    cout << "请输入1-" << n << "年年初的设备价格: " << endl;
//    for(int i=0; i<n; i++){
//        cin >> x;
//        prices.push_back(x);
//    }
//    cout << "请输入使用不同时间的设备所需的维修费用: " << endl;
//    for(int i=0; i<n; i++){
//        cin >> x;
//        repairCost.push_back(x);
//    }

    while(true){
        solve(n, getMatrix(n, prices, repairCost));

        prices.clear();
        repairCost.clear();
        cout << endl << "请输入年数n: " ;
        cin >> n;
        if(n<=0) break;
        int x;
        cout << "请输入1-" << n << "年年初的设备价格: " << endl;
        for(int i=0; i<n; i++){
            cin >> x;
            prices.push_back(x);
        }
        cout << "请输入使用不同时间的设备所需的维修费用: " << endl;
        for(int i=0; i<n; i++){
            cin >> x;
            repairCost.push_back(x);
        }
    }

    return 0;
}
