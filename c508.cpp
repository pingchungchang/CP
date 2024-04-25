#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,less<int>> pq;
    priority_queue<int,vector<int>,greater<int>> pq1;
    unordered_map<int,int> m;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        pq1.push(k);
        if(m.count(k) == 0){
            pq.push(k);
            m[k] = 1;
        }
    }
    while(!pq1.empty()){
        cout<<pq1.top()<<' ';
        pq1.pop();
    }
    cout<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<' ';
        pq.pop();
    }

}
