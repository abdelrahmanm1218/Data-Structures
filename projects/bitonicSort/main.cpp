#include <iostream>

using namespace std;

void compare_swap(int a[], int i, int j, int direction)
{
    if (direction==(a[i]>a[j]))
        swap(a[i],a[j]);
}
void BitonicMerge(int a[], int low, int counter, int direction){
    if (counter > 1) {
        int k = counter / 2 ;
        for(int i = low; i<low+k; i++) {
            compare_swap(a,i,i+k,direction);
        }
            BitonicMerge(a, low,k,direction);
            BitonicMerge(a, low+k, k, direction);
    }
}



void BitonicSort(int a[], int low, int counter, int direction){
    if (counter > 1) {
        int k = counter / 2 ;
        BitonicSort(a, low, k, 1);
        BitonicSort(a, low+k , k, 0);
        BitonicMerge(a, low,counter, direction);
    }
}
void Sort(int a[], int N, int up) {
    BitonicSort(a,0,N,up);
}
int main()
{
   int a[] = {3,7,4,8,6,2,1,5};
   int N = sizeof(a) / sizeof(a[0]);
   int up = 0 ;
   Sort(a,N,up);
   cout<< "Sorted array: \n" ;
   for (int i=0; i<=N; i++) {
    cout<< a[i] << "\t"  ;
   }

    return 0;
}

