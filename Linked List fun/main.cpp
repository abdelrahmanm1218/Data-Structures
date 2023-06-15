#include <iostream>

using namespace std;
class Node{
public:

    int data;
    Node *next;
};

class LinkedList{
public:
    Node *head ;
    LinkedList(){
        head = NULL ;
    }
    bool isEmpty(){
        if(head == NULL)
            return true;
        else
            return false ;
    }
    void insertFirst(int newval){
        Node* newnode = new Node();
        newnode->data = newval;

        if (isEmpty()){ // the list empty and we will create a new node
           // Node* newnode;
            // newnode->data = newval;
            newnode->next = NULL;
            head = newnode;
        }
        else { // else the list not empty
           // Node* newnode;
            //newnode->data = newval;
            newnode->next = head;
            head = newnode;
        }
    }
    void display(){
        Node *temp; // start treaversing // creating a temp pointer instead of head pointer to traverse the list and not to lost the address of the first node
        temp = head;
        cout << "the LIST : " << endl;
        while(temp != NULL){
            cout<< temp->data << " ";
            temp = temp->next;
        }   //end treaversing
        cout << endl;
    }
    int Count(){
        Node *temp; // creating a temp pointer instead of head pointer to traverse the list and not to lost the address of the first node
        temp = head;
        int counter;
        while(temp != NULL){
            counter++ ;
            temp = temp->next;

        }
        return counter;
    }
    bool Search(int key){
        bool found = false;
        Node* temp = head;
        while(temp != NULL) {
            if (temp->data == key) {
                found = true;
                temp = temp->next ;
            }
        }
        return found;
    }
    void insertbefore(int beforeitem, int newval){
        if(isEmpty())
            insertFirst(newval);
        if(Search(beforeitem)) {
            Node *newnode = new Node();
            newnode->data = newval;
            Node* temp = head;
            while(temp != NULL && temp->next->data != beforeitem) {
                temp = temp->next ;
            }
            newnode->next = temp->next ;
            temp->next = newnode ;
        }
        else {
            cout<< "item is not found! \n" ;
        }

    }
    void append(int value) {
        if(isEmpty())
            insertFirst(value);
        else {
            Node*temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            Node* newnode = new Node();
            newnode->data = value;
            temp->next = newnode;
            newnode->next = NULL;
        }
    }
    void Delete(int item){
        if(isEmpty())
            cout<< "the list is empty, can not delete items! \n";
        Node* delete_pointer ;
        if (head->data == item ) { // if node in the start of the list
            delete_pointer = head ;
            head = head->next ;
            delete delete_pointer ;
        }
        else {
            delete_pointer = head;
            Node *previous = NULL;
            while(delete_pointer->data != item) {
                previous = delete_pointer;
                delete_pointer = delete_pointer->next;
            }
            previous->next = delete_pointer->next;
            delete delete_pointer;

        }
    }
};
int main()
{
   LinkedList List;
   if(List.isEmpty())
    cout << " the linked list is empty \n" ;
   else
    cout<< "the list contains: " << List.Count() << " nodes \n";
    int item;
    cout<< "enter the item you want to insert: \n" ;
    cin >> item;
    List.insertFirst(item);
    List.display();


    int no_of_nodes;
    cout<< "enter the number of nodes you want to create: \n";
    cin>> no_of_nodes;
    for(int i=0 ; i< no_of_nodes ; i++) {
        int value;
        cout<< "enter the value of " << i+1 << " node \n" ;
        cin>> value;
        List.insertFirst(value);


    }
    List.display();
    int value;
    cout<< "enter the value to append : " ;
    cin >> value;
    List.append(value);
    List.display();

    cout<< "enter the value to delete: " ;
    cin >> value;
    List.Delete(value);
    List.display();
   /* int valueb;
    cout<< "enter the node yo want to insert before:  " ;
    cin >> valueb ;
    cout<< "enter the new you value to insert: " ;
    cin >> value ;
    List.insertbefore(valueb, value) ;
    List.display();
*/

    return 0;
}
