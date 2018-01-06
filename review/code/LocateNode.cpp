
struct Node{
    int data; // 数据域
    Node *prior, *next; // 前后指针
    int freq; // 访问频度
};

typedef struct Node *LinkedList;

void LocateNode(LinkedList L, int x){
    // 假设L不存储数据信息，只存储指向表头的指针
    // 这样我们就无需修改L了
    Node *p = L->next, *q;     
    while(p && p->data!=x) p = p->next;
    if(!p) return; // 未找到x
    
    // 寻找p结点应该被插入的位置
    q = p->prior; int freq = p->freq;
    while(q!=L && (q->freq) < freq)
        q = q->prior;
    // 插入到表头
    if(q==L){
        // 处理p原来的前后结点
        Node *prior = p->prior, *next = p->next;
        prior->next = next; next->prior = prior;
        // 处理p现在的前后结点
        p->next = L->next; L->next->prior = p;
        L->next = p; p->prior = L;
    }
    // 插入到非表头
    else{
        // 就是把上面的L换成q就行了
        // 实际上两者可以合并
        
        // 处理p原来的前后结点
        Node *prior = p->prior, *next = p->next;
        prior->next = next; next->prior = prior;
        // 处理p现在的前后结点
        p->next = q->next; q->next->prior = p;
        q->next = p; p->prior = q;
    }
}
