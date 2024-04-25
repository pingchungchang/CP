#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    for(int i = 1;i<10;i++){
        if(k%i == 0&&k/i<10){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}