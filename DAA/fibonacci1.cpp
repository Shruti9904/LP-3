#include <iostream>
using namespace std;

int fib_recursive(int n){
    if(n<=1) return n;
    return fib_recursive(n-1)+fib_recursive(n-2);
}

void fib_nonRecursive(int n){
    int a=0;
    int b=1;

    cout<<a<<" "<<b<<" ";
    int c;
    for(int i=2;i<n;i++){
        c = a + b;
        cout<<c<<" ";
        a = b;
        b = c;
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter no of terms: ";
    cin>>n;

    cout<<"Fibonacci series using recursion: "<<endl;
    
    for(int i=0;i<n;i++){
        cout<<fib_recursive(i)<<" ";
    }

    cout<<"\nFibonacci series without recursion: "<<endl;
    fib_nonRecursive(n);

}