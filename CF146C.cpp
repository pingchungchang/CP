#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int ca = 0,cb =0;
    for(int i = 0;i<a.size();i++){
        if(a[i] != b[i]){
            if(a[i] == '4')ca++;
            else cb++;
        }
    }
    cout<<max(ca,cb);
}
