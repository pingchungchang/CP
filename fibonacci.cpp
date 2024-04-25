#include <iostream>
#include <vector>

using namespace std;

int fib(int n,vector<int> counted){
    if(counted[n] != -1){
        return counted[n];
    }
    else{
        counted[n] = fib(n-1,counted)+fib(n-2,counted);
        return counted[n];
    }

}
int main(){
    int n;
    vector<int> v(n,-1);
    v[0] = 1;
    v[1] = 1;
    cin>>n;
    cout<<fib(n,v);
    return 0;
}
