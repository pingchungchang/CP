#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int loops = 0;
    for(int i = 0;i<=n;i++){
        if(2*i*(i+1)>n){
            loops = i-1;
            break;
        }
    }
    n -= loops*(loops+1)*2;
    if(n == 0){
        n = (loops+1)*3+1;
    }
    loops++;
    vector<string> v = {"Pen","Pineapple","Apple","Pineapple pen"};
    cout<<v[(n-1)/loops];
}