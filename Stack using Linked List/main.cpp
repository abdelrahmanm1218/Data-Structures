#include <iostream>

using namespace std;
class Node {
public:
    int data;
    Node *next;
};
class Stack{
public:
    Node *top;
    int size;
    int length;

    Stack(int stacksize){
        size = stacksize;
        length = 0;
        top = NULL;
    }
    bool isEmpty() {
        if(top== NULL)
            return true;
        else
            return false;
    }
    int stacksize(){
        return size;
    }
    void push(int item){
        Node *newnode = new Node();
        newnode->data = item;
        if(isEmpty()){
            newnode->next = NULL;
            top = newnode;
        }
        else {
            newnode->next = top;
            top = newnode;
        }
    }
    void pop() {
        Node*temp = top;
        temp= top->next;
        top = temp;
    }
    int Count(){
        int counter = 0;
        Node*temp = top;
        while(temp != NULL){
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    void display(){
        Node*temp = top;
        cout<< "the STACK: \n";
        while(temp != NULL){
            cout<< temp->data << " ";
            temp = temp->next;

        }
        cout<< endl;
    }
    void peek(){
        cout<<"the top element of the stack = " << top->data << endl;
    }

};
int main()
{
    int value;
    cout<< "enter the stack size: " ;
    cin >> value;
    Stack run_stack(value);
    bool check = run_stack.isEmpty();
    if(check == true)
        cout<< "stack is empty\n";
    else{
        cout<< " stack contains " << run_stack.Count() << " elements \n";
    }
    cout<< "stack size = " << run_stack.stacksize() << endl;
    int number;
    for(int i =0; i< value; i++) {
        cout<< "enter stack[" <<i << "] : " ;
        cin>> number;
        run_stack.push(number);
    }
    run_stack.display();
    run_stack.peek();
    run_stack.pop();
    run_stack.display();
    run_stack.peek();
    return 0;
}
