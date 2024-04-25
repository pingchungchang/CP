#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> v(10,0);
    for(auto i:s){
        v[i-'0']++;
    }
    for(int i = 0;i<10;i++){
        if(v[i] == 0)cout<<i;
    }
}
