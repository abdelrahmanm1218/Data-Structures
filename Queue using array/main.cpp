#include <iostream>

using namespace std;
class Queue{
private:

    int *items;
    int size;
    int Front;
    int rear;
public:
    Queue(int qsize) {
        size = qsize;
        items = new int[qsize];
        Front = rear = -1 ;

    }
    void enqueue(int item) {
        if(rear != size -1 ){
            if (Front == -1 && rear == -1) {
                Front++;
                rear++ ;
                items[rear] = item ;
            }
            else {
                rear++;
                items[rear] = item ;
            }
        }
        else {
            cout << "Queue is full \n" ;
        }
    }
    void dequeue() {
        if (Front != -1 && rear != -1 && Front <= rear) {
            Front++ ;
        }
        else {
            cout << "Queue is empty! \n" ;
        }

    }
    void display() {
        cout<< " QUEUE :\n" ;
        for(int i=Front ; i<= rear ; i++) {
            cout<< items[i] << "\t";
        }
        cout<< endl;
        cout<< "index of Front: " << Front << endl;
        cout<< "index of Rear:  " << rear << endl;

    }
};

int main()
{
    int newsize;
    cout<<"enter the size of Queue \n" ;
    cin >> newsize;
    Queue mqueue(newsize);
    int no_of_items;
    cout<< "enter the number of items you want to enqueue \n" ;
    cin>> no_of_items;
    for(int i=0 ; i<no_of_items ; i++) {
        int val;
        cout<< "enter " << i+1 << " value \n" ;
        cin>> val;
        mqueue.enqueue(val);
    }
    mqueue.display();
    mqueue.dequeue();
    mqueue.display();
    return 0;
}
