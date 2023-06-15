#include <iostream>

using namespace std;
class Array {
private:
    int size;
    int *items;
    int length;
public:
    Array(int arrsize){
        size = arrsize ;
        length = 0;
        items = new int[arrsize];
    }
    void Fill() {
        int desired_items;
        cout << "how many elements you want to enter \n";
        cin >> desired_items ;
        if (desired_items > size) {
            cout << "array overflow \n" ;
            return;
        }
        else {
            for (int i =0; i<desired_items; i++) {
                cout << "enter the " << i << " element \n" ;
                cin >> items[i];
                length++ ;
            }
        }
    }
    void Display () {
        cout << "the ARRAY: \n" ;
        for (int i=0 ; i<length ; i++) {
            cout << items[i] << "\t";
        }
        cout << endl ;
    }
    int GetSize () {
        return size ;

    }
    int Getlength () {
        return length;
    }
    int Search(int key) {
        int index= -1;
        for (int i=0 ; i < length ; i++ ) {
            if (items[i] == key ) {
                    index = i ;
                    break;
                }
        }
        return index ;
    }
    void append (int newitem) {
        if (length >= size) {
            cout << "array overflow can't append new item \n" ;
        }
        else {
            items[length] =  newitem ;
            length++ ;
        }
    }
    void Insert(int index, int value) {
         if ( index >= 0 && index < size) {
            int temp;
            for (int i = length ; i > index ; i--) {
                items[i] = items[i-1];
         }
         items[index] = value ;
         length++ ;
         }
         else {
            cout<< "index out of range \n" ;
         }

    }
    void Delete(int index) {
        if (index >= 0 && index < size)  {
            int temp = items[index];
            for(int i= index ; i< length; i++){
                items[i] = items[i+1] ;
            }
            length-- ;
        }

    }
    void Enlarge(int newsize) {
        if (newsize <= size) {
            cout << "the new Size must be larger than old size \n" ;
            return;
        }
        else {
            size = newsize;
            int *old = items ;
            items = new int[newsize];
            for(int i=0; i<length ; i++) {
                items[i] = old[i];
            }
            delete[]old ;
        }
    }
    void Merge(Array other){
        int newsize;
        newsize = size + other.GetSize();
        size = newsize;
        int *old = items ;
        items = new int[newsize];
        int i;
        for(i=0; i<length; i++) {
            items[i] = old[i];
        }
        delete[]old;
        int j = i;
        for(int i=0; i<other.Getlength(); i++) {
            items[j++] = other.items[i];
            length++;
        }
    }
};

int main()
{
    int runsize;
    cout << "enter the size of the array \n";
    cin >> runsize ;
    Array mainarray(runsize) ;
    mainarray.Fill();
    int x ;
    cout<< "enter the element you want to append \n" ;
    cin >> x ;
    mainarray.append(x) ;
    mainarray.Display();
    int in;
    int val;
    cout << "enter the index you want to insert in : ";
    cin >> in ;
    cout << "enter the value :  " ;
    cin >> val;
    mainarray.Insert(in, val) ;
    mainarray.Display();
    int in1;
    cout << "enter the index you want to delete \n";
    cin >> in1 ;
    mainarray.Delete(in1);
    mainarray.Display();
    int getsize = mainarray.GetSize();
    cout<< "array size =  \n" << getsize << endl;
    int getlength = mainarray.Getlength();
    cout<< "array length: \n" << getlength << endl;
    int item ;
    cout<< "enter the search value \n" ;
    cin >> item ;
    int index = mainarray.Search(item);
    if (index == -1 )
        cout<< "element is not found \n" ;
    else
        cout << "element is found at : " << index << endl;

    int newsize;
    cout << "enter new array size \n";
    cin>> newsize;
    mainarray.Enlarge(newsize) ;
    mainarray.Display();
    int getlength1=mainarray.Getlength();
    cout<< "array length:  " << getlength1 << endl;
    int getsize1= mainarray.GetSize();
    cout<< "array size: "  <<getsize1 << endl;
    Array other(3);
    cout<< "NEW ARRAY \n" ;
    other.Fill();
    other.Display();
    int getlength2 = other.Getlength();
    cout << "other array length:  " << getlength2 << endl ;
    int getsize2 = other.GetSize();
    cout<< "other array size:  "<<getsize2 <<endl;
    mainarray.Merge(other);
    cout<< "NEW MERGED ARRAY : \n" ;
    mainarray.Display();


    return 0;
}
