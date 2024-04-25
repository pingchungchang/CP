#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> dq;
    int n,m;
    cin>>n>>m;
    for(int i= 0;i<n;i++){
        int k;
        cin>>k;
        dq.push_back(k);
    }
    while(m--){
        dq.pop_front();
        dq.push_back(0);
    }
    for(auto &i:dq)cout<<i<<' ';
    return 0;
}