#include <iostream>

using namespace std;
int main()
{
    int temp;
    int size;
    cout<< "enter the size: \n" ;
    cin>> size;
    int arr[size] ;
    for(int i=0; i<size; i++){
        cout<< "enter " << i+1 << " element \n";
        cin>> arr[i];
    }
//printing array
    cout<< "ARRAY: \n";
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;
// taking no. rotations from user
    int d;
    cout<<"enter the amount of rotations: \n ";
    cin>> d;
    // check if number of rotations = size of array or multiple of size it will return the same array without rotaating
    if (d == size || d%size == 0){
        cout<< "The Rotated ARRAY: \n";
        for(int i=0; i<size; i++){
            cout<< arr[i]<< " ";
        }
        cout<< endl;
    }
    else {
        // rotating process
        for(int i=0; i< d ; i++){
            temp = arr[0]; // save first element of the array and store it in temporary int
            // shifting each element of the array  starting from the second element
            for(int j=1 ; j< size ; j++){
                arr[j-1] = arr[j];
            }
            arr[size-1] = temp; //the first element we saved we put it in the last index in the array
            }
            //Rotated array
        cout<< "The Rotated ARRAY: \n";
        for(int i=0; i<size; i++){
            cout<< arr[i]<< " ";
        }
        cout<< endl;
    }
return 0;
}
