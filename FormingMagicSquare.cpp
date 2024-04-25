#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> m;
    for(int i = 0;i<9;i++){
        int k;
        cin>>k;
        m.push_back(k);
    }
    vector<pair<int,int>> p;
    for(int i = 1;i<=9;i++){
        if(i==5)continue;
        p.push_back(make_pair(i,10-i));
    }
    vector<int> used(p.size(),0);
    for(int i = 0;i<p.size()/2;i++){

    }
}