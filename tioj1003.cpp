#include <iostream>
using namespace std;
int recursive(int N,int start,int k){
    int c = start + k;
    k += 1;
    if(k>=N) return start;
    else return recursive(N, c, k);
}

int main(){
    int N;
    cin >> N;
    cout<<recursive(N+2,1,1);
}