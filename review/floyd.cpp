// Floyd算法，A[i][j]为i到j的最短路径长度，C为邻接矩阵
// P[i][j]为i到j路径的中间一点，0表示路<i, j>
void floyd(costtype A[][], costtype C[][], int P[][], int n){
    // 初始化A、P
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            A[i][j] = C[i][j];
            P[i][j] = -1;
        }

    // k、i、j三重循环
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                // < 求最短路径；> 求最长路径
                if(A[i][k] + A[k][j] < A[i][j]){
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k;
                }
}

// 递归打印从i到j的最短路径
void printPath(int i, int j, int P[][]){
    int k = P[i][j];
    if(k == 0){
        cout << i << "->" << j << endl;
    }
    else{
        printPath(i, k, P); // 左半段
        cout << " -> k ->";
        printPath(k, j, P); // 右半段
    }
}
