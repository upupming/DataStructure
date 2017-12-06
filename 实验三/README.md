## 实验三：图的遍历和设备更新问题

### 1. 图的遍历

在Graph.h中实现了类模板:

1. AdjList  
    成员变量有:
    + int subscript: 起始点u所在的下边
    + bool visited: 点u是否已访问过
    + vectot<int> adjacencies: 与u邻接的所有点v(即存在边(u, v))
    + int indegree, outdegree: 点u的入度和出度
2. Graph
    成员变量有:
    + 
