struct Node{
    int data;
    Node *lchild, *rchild;
};
typedef struct Node *BST;

bool judgeBST(const BST t){
    if(t->lchild && t->rchild) // 有左右子树
        return (t->lchild->data < t->data 
                && t->data < t->rchild->data) 
               && judgeBST(t->lchild) 
               && judgeBST(t->rchild);
    else if(t->lchild) // 只有左子树
        return (t->lchild->data < t->data) 
               && judgeBST(t->lchild);
    else if(t->rchild) // 只有右子树
        return (t->data < t->rchild->data) 
               && judgeBST(t->rchild);
}

