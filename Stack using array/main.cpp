#include <iostream>

using namespace std;
class Stack {
private:
    int top ;
    int*stack1;
    int size;
    int length;
public:
    Stack(int stacksize) {
        size = stacksize;
        stack1 = new int[stacksize];
        length= 0 ;
        top = 0;
    }
    void push(int item){
        if (length == size) {
            cout << "stack overflow \n" ;
        }
        else {
            top++;
            length++ ;
            stack1[top] = item;
        }
    }
    void display() {
        cout<< "STACK : \n" ;
        for(int i = length; i > 0 ; i--) {

            cout<< stack1[i] << endl ;
        }
    }
    int stack_length(){
        return length;
    }
    int stack_size() {
        return size ;
    }
    void stack_top(){
        cout << "index of the top element: " << top << endl;
        cout << "the top element: " << stack1[top] << endl;

    }
    void pop(){
        if (top == 0 ) {
            cout << "stack underflow \n" ;
        }
        else {
            int temp;
            temp = stack1[top];
            top --;
            length-- ;
        }
    }

};
int main()
{
    int runsize;
    cout<< "enter the stack size \n" ;
    cin >> runsize;
    Stack mainstack(runsize);
    int val1 ;
    cout << "how many value you want to add \n";
    cin>> val1;
    for(int i=0; i<val1; i++) {
        int val2 ;
        cout << "enter "<< i<<" value \n";
        cin>> val2;
        mainstack.push(val2);
    }
    int size1 = mainstack.stack_size();
    cout << "stack size = " << size1 << endl;
    int length1 = mainstack.stack_length();
    cout << "length = " << length1 << endl ;
    mainstack.stack_top();


   // mainstack.push(val2);
    mainstack.display();
    mainstack.pop();
    mainstack.display();
    int size2 = mainstack.stack_size();
    cout << "stack size = " << size2 << endl;
    int length2 = mainstack.stack_length();
    cout << "length = " << length2 << endl ;
    mainstack.stack_top();
    return 0;
}
