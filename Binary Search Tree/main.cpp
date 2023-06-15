#include <iostream>

using namespace std;
class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node(int val){
        data = val;
        right = left = NULL ;
    }
};
class BST{
public:
    Node *root;
    BST(){
        root = NULL ;
    }
    Node *insertion(Node* root_node, int item){
        if(root_node == NULL){ // tree is empty
            Node* newnode = new Node(item);
            root_node = newnode;
        }
        else if(item < root_node->data) { // item is smaller than root then go left
            root_node->left = insertion(root_node->left , item);
        }
        else { // item is larger than root node then go right
            root_node->right = insertion(root_node->right , item);
        }
        return root_node ;
    }
    void insertion(int item){
        root = insertion(root, item);
    }
    void preorder(Node* root_node){
        if(root_node == NULL)
            return;
        cout<< root_node->data << "\t" ;
        preorder(root_node->left);
        preorder(root_node->right) ;
    }
    void inorder(Node*root_node){
        if(root_node == NULL)
            return;

        inorder(root_node->left);
        cout<< root_node->data << "\t" ;
        inorder(root_node->right) ;

    }
    void postorder(Node* root_node){
        if(root_node == NULL)
            return;
        postorder(root_node->left);
        postorder(root_node->right) ;
        cout<< root_node->data << "\t" ;
    }
    Node* Search(Node *root_node ,int key){
        if(root_node == NULL)
            return NULL ;
        else if(root_node->data == key)
            return root_node ;
        else if (key < root_node->data)
            return Search(root_node->left, key);
        else
            return Search(root_node->right , key);
    }
    bool Search(int key){
        Node* result = Search(root, key);
        if (result == NULL)
            return false;
        else
            return true;
    }
    Node *findmax(Node* rooot){

    }
    Node *Findmin(Node * rooot){
        if(rooot== NULL)
            return NULL;
        else if (rooot->left == NULL)
            return rooot;
        else
            return Findmin(rooot->left);
    }
    Node *Findmax(Node *rooot){
        if (rooot == NULL)
            return NULL;
        else if (rooot->right == NULL)
            return rooot;
        else
            return Findmax(rooot->right);
    }
    Node* Delete(Node* rooot, int key) {
        if(rooot == NULL)
            return NULL;
        else if (key < rooot->data)
            rooot->left = Delete(rooot->left, key);
        else if(key >rooot->data)
            rooot->right = Delete(rooot->right , key);
        else {
            if( rooot->left == NULL && rooot->right == NULL){
                rooot = NULL;
            }
            else if (rooot->left != NULL && rooot->right == NULL){
                rooot->data = rooot->left->data;
                delete rooot->left;
                rooot->left = NULL;
            }
            else if (rooot->left == NULL && rooot->right != NULL){
                rooot->data = rooot->right->data;
                delete rooot->right;
                rooot->right = NULL;
            }
            else {
                Node *pre = Findmax(rooot->left);
                rooot->data = pre->data;
                rooot->left = Delete(rooot->left, pre->data) ;
            }
        }
        return rooot;
    }

};


int main()
{
    BST tree;
    // 45, 15, 79, 90, 10, 55, 12, 20, 50
    tree.insertion(45);
    tree.insertion(15);
    tree.insertion(79);
    tree.insertion(90);
    tree.insertion(10);
    tree.insertion(55);
    tree.insertion(12);
    tree.insertion(20);
    tree.insertion(50);
    cout<< "INORDER: \n" ;
    tree.inorder(tree.root);
    cout<<endl;

    cout<< "PREORDER: \n";
    tree.preorder(tree.root);
    cout<<endl;
    cout<< "POSTORDER: \n";
    tree.postorder(tree.root);
    cout<< endl;
    int val;
    cout<< "enter the value you want to search: \n";
    cin>> val;
    if(tree.Search(val))
        cout<< " item FOUND \n";
    else
        cout<< "item NOT FOUND \n";

    cout<< "Find MINIMUM: \n" ;
    Node *check = tree.Findmin(tree.root);
    if (check == 0)
        cout<< "no minimum found \n";
    else
        cout<< "MINIMUM = "<< check->data << endl;
    cout<< "Find MAXIMUM: \n" ;
    Node *check1 = tree.Findmax(tree.root);
    if (check == 0)
        cout<< "no Maximum found \n";
    else
        cout<< "MAXIMUM = "<< check1->data << endl;

    cout<< "delete items \n";
    Node *result = tree.Delete(tree.root,12);
    cout<<"preorder after delete 12 \n";
    tree.preorder(result);

    result = tree.Delete(tree.root,15);
    cout<<"preorder after delete 15 \n";
    tree.preorder(result);

    return 0;
}
