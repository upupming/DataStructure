struct Node{
    int data;
    Node *lchild, *rchild;
};
typedef struct Node *BST;

bool judgeBST(const BST t){
    if(t->lchild && t->rchild) 
        return (t->lchild->data < t->data && t->data < t->rchild->data) && judgeBST(t->lchild) && judgeBST(t->rchild);
    else if(t->lchild)
        return (t->lchild->data < t->data) && judgeBST(t->lchild);
    else if(t->rchild)
        return (t->data < t->rchild->data) && judgeBST(t->rchild);
}

