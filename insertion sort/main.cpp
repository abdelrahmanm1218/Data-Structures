#include <iostream>

using namespace std;
int sum( int n){
    if (n== 0)
        return n;
    else
        return n + sum(n-1);
}
int main()
{
    int N;
    cout<<"enter number: \n";
    cin>> N;
    int result = sum(N);
    cout<<" result: " << result << endl;
    return 0;
}
