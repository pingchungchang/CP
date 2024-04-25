#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,a;
    cin>>n>>k>>a;
    k--;
    while(k--){
        a = a%n+1;
    }
    cout<<a;
}
