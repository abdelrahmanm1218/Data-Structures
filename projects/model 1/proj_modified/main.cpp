#include<iostream>
using namespace std;
void bitonicSort(int *arr, int n) {
    int k, j, c, i, temp;
    for (k = 2; k <= n; k *= 2) {
        for (j = k/2; j > 0; j /= 2) {
            for (i = 0; i < n; i++) {
                c = i ^ j;
                if (c > i) {
                    if ( ((i&k)==0) && (arr[i] > arr[c]) || ( ( (i&k)!=0) && (arr[i] < arr[c])) )  {
                        temp = arr[i];
                        arr[i] = arr[c];
                        arr[c] = temp;
                    }
                }
            }
        }
    }
}
int main()
{
     int n;
    cout<<"Enter the size of array to be sorted:\n";     //(number should be in the order of 2^n)
    cin>>n;
    cout<<"\nEnter the elements\n";
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
  bitonicSort(arr,n);
  cout<<"\nSorted array\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
