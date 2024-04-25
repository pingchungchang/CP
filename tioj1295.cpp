#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=0;
    cin>>n;
    for(int i =n-1;i>=1;i--){
        n *=i;
    }
    cout<<n;
}
