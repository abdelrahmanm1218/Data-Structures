#include <iostream>

using namespace std;
void Bubble_sort(int arr[], int size, int key){
    int temp;
    for(int i=0; i< size; i++){
        for(int j=0; j< size-i-1 ; j++){
            if(key== arr[j]> arr[j+1]){
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int size;
    cout<< " enter the array size: \n" ;
    cin>> size;
    int arr[size];
    int direction;
    cout<< " enter the direction ascending(1) OR descending(0) : \n";
    cin>> direction;
    for(int i=0; i<size; i++){
        cout<<"enter " << i+1 << " element: \n";
        cin>> arr[i];
    }
    cout<< endl;
    cout<< "THE ARRAY: \n";
    for(int i=0; i<size; i++){
        cout<<arr[i] << " " ;

    }
    cout<< endl;
    Bubble_sort(arr, size, direction);
    cout<< "SORTED ARRAY: \n" ;
    for(int i=0; i<size; i++){
        cout<<arr[i] << " " ;

    }
    cout<< endl;


    cout << "Hello world!" << endl;
    return 0;
}
