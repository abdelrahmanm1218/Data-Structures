#include <iostream>

using namespace std;
class Node {
public:
    Node* next;
    int data;
    Node(){
        data= 0 ;
        next= NULL;
    }
};
class Queue{
public:
    Node* Front ;
    Node*rear;
    int size;
    Queue(int qsize){

        Front =rear =  NULL;
    }
    bool isEmpty(){
        if (Front == NULL && rear == NULL)
            return true;
        else
            return false;
    }
    int  Count(){
        Node* temp = Front;
        int counter;
        while(temp != NULL){
            counter++ ;
            temp = temp->next;
        }
        return counter;
    }
    bool Search(int item){
        Node *temp = Front;
        while(temp != NULL) {
            temp = temp->next;
            if(temp->data == item)
            return true;
        else
            return false;
        }

    }
    void enqueue(int item){
        Node *newnode = new Node();
        newnode->data = item;
        if(isEmpty()){
            newnode->next= NULL;
            Front = rear = newnode;
        }
        else{
            rear->next = newnode;
            rear= newnode;
        }
    }
    void dequeue(){
        Front = Front->next;
    }
    void display(){
        Node* temp = Front;
        cout<< "QUEUE :\n";
        while(temp!= NULL){
            cout<< temp->data << " " ;
            temp = temp->next;
        }
        cout<< endl;
    }
    void GetFront(){
        cout<< "FRONT = " << Front->data << endl;
    }
    void GetRear(){
        cout << "REAR = " << rear->data << endl;
    }
};
int main()
{
    int value ;
    cout<<" enter the size of the queue: " ;
    cin>> value;
    Queue run_queue(value);
    if (run_queue.isEmpty())
        cout<< "queue is empty: \n";
    else
        cout<< "queue has "<< run_queue.Count() << " elements'n" ;

    for(int i=0; i<value; i++) {
        int num;
        cout<< "enter number to enqueue: \n" ;
        cin >> num;
        run_queue.enqueue(num);
    }
    run_queue.display();
    int cnt = run_queue.Count();
    cout<< "element in queue: " << cnt << endl;
    run_queue.GetFront();
    run_queue.GetRear();
    run_queue.dequeue();
    run_queue.display();
    run_queue.GetFront();
    run_queue.GetRear();
    cnt = run_queue.Count();
    cout<< "element in queue: " << cnt << endl;
    int ser;
    cout << "enter the value you want to search in the list: ";
    cin >> ser;
    bool check = run_queue.Search(ser);
    if (check == true)
        cout<< "element is found \n";
    else
        cout << "element is not found \n";
     return 0;
}
