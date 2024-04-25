#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        if(!(k&1))cout<<k<<' ';
    }
    return 0;
}