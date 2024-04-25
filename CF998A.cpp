#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
int main(){
    int n;
    cin>>n;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        pq.push(make_pair(k,i+1));
    }
    if(pq.size()<=1){
        cout<<-1;
        return 0;
    }
    else if(pq.size() == 2){
        int a = pq.top().first;
        pq.pop();
        int b = pq.top().first;
        pq.pop();
        if(a == b)cout<<-1;
        else cout<<1<<'\n'<<1;
        return 0;
    }
    else{
        cout<<1<<'\n'<<pq.top().second;
    }
}
