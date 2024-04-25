#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(mp.count(k) == 0)mp[k]=1;
        else mp[k]++;
    }
    if(mp.size() != 2){
        cout<<"NO";
    }
    else if(mp.rbegin()->second != mp.begin()->second)cout<<"NO";
    else cout<<"YES"<<'\n'<<mp.begin()->first<<' '<<mp.rbegin()->first;
}
