// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;
void selection_sort(int arr[], int size){
    int minimum;
    for(int i=0 ; i<size ; i++){
        minimum = i ;
        for(int j=i+1; j<size ;j++){
            if(arr[j] < arr[minimum])
                minimum = j ;
                swap(arr[minimum],arr[i]);

        }
    }
}
int main()
{
   int size;
   cout<< "enter the size of the array: \n";
   cin>> size;
   int arr[size];
   for(int i=0; i<size; i++){
       cout<< "enter " << i+1 <<" element: \n";
       cin>> arr[i];
   }
   cout<< endl;
   cout<<" the ARRAY: \n" ;
   for(int i=0; i<size; i++){
       cout<< arr[i] << " ";
   }
   cout<<endl;
   selection_sort(arr, size);
   cout<< "SORTED ARRAY: \n" ;
  for(int i=0; i<size; i++){
       cout<< arr[i] << " ";
   }
   cout<<endl;

    return 0;
}
