#include <bits/stdc++.h>
using namespace std;

const float eps = 1e-6;
int main(){
    int n;
    while(cin>>n){
        bool flag = false;
        for(int j = 0;j<=1024;j++){
            if(j+j/100 == n){
                cout<<j<<'\n';
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<"stupid\n";
        }
    }
}