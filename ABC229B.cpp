#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    a = string(20-a.size(),'0')+a,b = string(20-b.size(),'0')+b;
    for(int i =0;i<a.size();i++){
        auto ta = a[i]-'0',tb = b[i]-'0';
        if((ta+tb)>=10){
            cout<<"Hard";
            return 0;
        }
    }
    cout<<"Easy";
    return 0;
}