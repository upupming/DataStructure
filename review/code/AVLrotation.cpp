typedef struct Node{
    int data;
    Node *lchild, *rchild;
    int bf; // balance factor 平衡因子
}node, *BST;

// T为不平衡点，需要修改T本身的值，所以为引用形式
void LeftRotation(BST &T, int &unbalanced){
    BST gc, lc; // 孙子、左孩子
    lc = T->lchild;
   
    // LL右旋
    //      15(bf==2)
    //    12
    //  11: 新插入结点在左子树的左子树上
    if(lc->bf == 1){
    // 右旋后的BST为
    //   12
    // 11  15
        T->lchild = lc->rchild; // 15->lchild = NULL
        lc->rchild = T; // 12->rchild = 15
        T->bf = 0; // 15->bf
        T = lc; // 更新T为12
    }

    // LR右旋
    //          27(bf==2)
    //    12         30
    // 11    25
    //    18: 新插入节点在左子树的右子树上
    else if(lc->bf == -1){
    // 右旋后的BST为
    //         25
    //   12          27
    //11    18          30
        gc = lc->rchild; // gc = 25
        lc->rchild = gc->lchild; // 12->rchild = 18/NULL
        gc->lchild = lc; // 25->lchild = 12
        T->lchild = gc->rchild; // 27->lchild = NULL/26
        gc->rchild = T; // 25->rchild = 27
        switch(gc->bf){ // 25->bf
            case 1: // 本情况，即插入18
                T->bf = -1; // 27->bf = -1
                lc->bf = 0; // 12->bf = 0
                break;
            case 0: // 想象插入了18以外，还插入了26
                T->bf = lc->bf = 0; // 27->bf = 12->bf = 0
                break;
            case -1: // 想象插入的值为26而不是18
                T->bf = 0; // 27->bf = 0
                lc->bf = 1; // 12->bf = 1
        }
        T = gc; // 更新T为25
    }
   
    // LL和LR均使新的T的bf变为0
    T->bf = 0;
    unbalanced = false;
}

void RightRotation(BST &T, int unbalanced){
    BST gc, rc; // 孙子、右孩子
    rc = T->rchild;
   
    // RR左旋
    // 25(bf==-2)
    //    27
    //       30: 新插入节点在右子树的右子树上
    if(rc->bf==-1){
    // 左旋后的BST为
    //    27
    // 25    30
        T->rchild = rc->lchild; // 25->rchild = NULL
        rc->lchild = T; // 27->lchild = 25
        T->bf = 0; // 25->bf = 0
        T = rc; // 更新T为27
    }
   
    // RL左旋
    //       12(bf==-2)
    // 11          18
    //          14    20
    //             15: 新插入节点在右子树的左子树上
    else if(rc->bf==1){
    // 左旋后的BST为
    //          14
    //    12          18
    // 11          15    20
        gc = rc->lchild; // gc = 14
        T->rchild = gc->lchild; // 12->rchild = NULL/13
        gc->lchild = T; // 14->lchild = 12
        rc->lchild= gc->rchild; // 18->lchild = 15/NULL
        gc->rchild = rc; // 14->rchild = 18
        switch(gc->bf){
            case 1: // 想象插入的是13而不是15
                T->bf = 0; // 12->bf = 0
                rc->bf = -1; // 18->bf = -1
                break;
            case 0: // 想象除了插入13以外，还插入15
                T->bf = rc->bf = 0;
            case -1: // 本情况，即插入15
                T->bf = 1; // 12->bf = 1;
                rc->bf = 0; // 18->bf = 0
        }
        T = gc; // 更新T为14
    }

    // RR和RL均使新的T的bf变为0
    T->bf = 0;
    unbalanced = false;
}
