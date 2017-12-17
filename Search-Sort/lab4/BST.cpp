/* Binary Search Tree: 建立、查找、插入、删除
 * 李一鸣      1160300625
 *
 */
#include <iostream>
#include <vector>

using namespace std;

template<typename Comparable>
struct Node{
    Comparable key;
    Node<Comparable> *left, *right;

    Node(Comparable value, Node<Comparable> *lchild = nullptr, Node<Comparable> *rchild = nullptr):key(value), left(lchild), right(rchild){}
    bool operator < (const Comparable & t){
        return key < t.key;
    }
};

template<typename Comparable>
class BST{
private:
    Node<Comparable> *root = nullptr;
    size_t num;

Node<Comparable>* search(const Comparable & key, const Node<Comparable>* node){
        if(key==node->key) return node;
        if(key < node->key){
            if(node->left == nullptr) return nullptr;
            return search(key, node->left);
        }
        if(key > node->key){
            if(node->right == nullptr) return nullptr;
            return search(key, node->right);
        }
    }
    void insert(const Comparable & key, Node<Comparable>* & node){
        if(node == nullptr){
            node = new Node<Comparable>(key, nullptr, nullptr);
        }
        else if(key < node->key){
            return insert(key, node->left);
        }
        else if(key > node->key){
            return insert(key, node->right);
        }
    }
    void deleteMin(Comparable & minKey, Node<Comparable>* & node){
        if(node->left == nullptr){
            minKey = node->key;
            node = node->right;
        }
        else return deleteMin(minKey, node->left);
    }
    void deleteB(const Comparable & key, Node<Comparable>* & node){
        if(node != nullptr){
            if(key < node->key)
                return deleteB(key, node->left);
            else if(key > node->key)
                return deleteB(key, node->right);
            else{// key == node->key
                if(node->left == nullptr)
                    node = node->right;
                else if(node->right == nullptr)
                    node = node->left;
                else
                    return deleteMin(node->key, node->right);
            }
        }
    }
public:
    BST(const vector<Comparable> keyArray){
        num = keyArray.size();
        for(auto key : keyArray){
            insert(key);
        }
    }

    bool empty(){
        return root==nullptr;
    }
    void insert(const Comparable & key){
        insert(key, root);
    };
    void deleteMin(Comparable & minKey){
        deleteMin(minKey, root);
    }
    void deleteB(const Comparable & key){
        deleteB(key, root);
    }
};

int main(){
    vector<int> arr = {10, 14, 3, 1, 5, 12, 2, 7, 16, 15, 18};

    cout << "Constructing BST using int:{10, 14, 3, 1, 5, 12, 2, 7, 16, 15, 18}..." << endl;
    BST<int> bst(arr);
    cout << "Deleting 10 from BST..." << endl;
    bst.deleteB(10);
    int tmp;
    cout << "Deleting min sequentially..." << endl;
    while(!bst.empty()){
        bst.deleteMin(tmp);
        cout << tmp << " ";
    }
    cout << endl;
    return 0;
}
