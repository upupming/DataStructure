# 实验四

            姓名: 李一鸣                    学号: 1160300625

## 1. 二叉搜索树的查找、插入、建立、删除

结点定义为模板类Node:

|数据域|意义|
|-|-|
|key|关键字大小|
|left|指向左孩子的指针|
|right|指向右孩子的指针|

构造函数:

Node(Comparable value, Node *lchild = nullptr, Node *rchild = nullptr);

<重载函数:

bool operator < (const Comparable & t);


模板类BST:

|数据域|意义|
|-|-|
|root|根结点|
|num|结点个数|

查找函数:

递归
