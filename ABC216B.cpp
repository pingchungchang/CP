#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<string,int>m;
    int done = 0;
    for(int i =0;i<n;i++){
        string a,b;
        cin>>a>>b;
        a +=' ';
        a+=b;
        if(m.count(a) == 0){
            m[a] = 1;
        }
        else{
            if(done == 0){
                cout<<"Yes";
                done=1;
            }
        }
    }
    if(done == 0)cout<<"No";
}
