#include<iostream>
using namespace std;

void ascendingSwap(int value_1 , int value_2 , int *arr)  //swap two values such that they appear in ascending order in the array
{
  if(arr[value_2] < arr[value_1])
  {
      int temp = arr[value_2];
      arr[value_2] = arr[value_1];
      arr[value_1] = temp;
  }
}
void decendingSwap(int value_1 , int value_2 , int *arr) //swap two values such that they appear in decending order in the array
{
  if(arr[value_1] < arr[value_2])
  {
      int temp = arr[value_2];
      arr[value_2] = arr[value_1];
      arr[value_1] = temp;
  }
}
void bitonicSortFromBitonicSequence( int starrtIndex ,int lastIndex, int dir , int *arr ) //form a increasing or decreasing array when a bitonic input is given to the function
    {
        if(dir == 1)
        {
            int counter = 0;   //counter to keep track of already swapped elements ,, parallelising this area results in poor performance due to overhead ,,need to fix
            int noOfElements = lastIndex - starrtIndex + 1;
            for(int j = noOfElements/2;j>0;j = j/2)
            {   counter =0;
                for(int i = starrtIndex ; i +j <= lastIndex ; i++)
                {
                        if(counter < j)
                        {
                            ascendingSwap(i,i+j,arr);
                            counter++;

                        }
                        else
                        {
                            counter =0;
                            i = i+ j-1;

                        }
                }
            }
        }
        else                     //Decending sort
        {
            int counter = 0;
            int noOfElements = lastIndex - starrtIndex + 1;
            for(int j = noOfElements/2;j>0;j = j/2)
            {   counter =0;
                for(int i = starrtIndex ; i <= (lastIndex-j) ; i++)
                {
                        if(counter < j)
                        {
                            decendingSwap(i,i+j,arr);
                            counter++;

                        }
                        else
                        {
                            counter =0;
                            i = i+ j-1;

                        }
                }
            }
        }

    }
void bitonicSequenceGenerator(int starrtIndex , int lastIndex , int *arr)                         //generate a bitonic sequence  from a a random order
{
    int noOfElements = lastIndex - starrtIndex +1;
      for(int j = 2;j<=noOfElements;j = j*2)
            {
                #pragma omp parrallel for                                                         //parallel implementation results in most performance gains here
                for(int i=0;i<noOfElements;i=i+j)
                {
                 if(((i/j)%2) ==0)                                                               //extra computation results in drastically lower performance ,need to fix
                 {
                     bitonicSortFromBitonicSequence(i,i+j-1,1,arr);
                 }
                 else
                 {
                     bitonicSortFromBitonicSequence(i,i+j-1,0,arr);
                 }
                }
            }
}
int main()                                                                                        //main driver function
{
                                                      //set the no of threads
    int n;
    cout<<"Enter the size of array to be sorted (The size should be in the order of 2^n):\n";
    cin>>n;
    cout<<"\nEnter the elements\n";
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bitonicSequenceGenerator(0,n-1,arr);
    cout<<"\nSorted array\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }

}
