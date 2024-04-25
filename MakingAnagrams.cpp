#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    priority_queue<char,vector<int>,less<int>()> pq1;
    priority_queue<char,vector<int>,less<int>()> pq2;
    for(int i =0;i<a.size();i++){
        pq1.push(a[i]);
    }
    for(int i = 0;i<b.size();i++){
        pq2.push(b[i]);
    }
    int ans = 0;
    while(!pq1.empty()&&!pq2.empty()){
        if(pq1.top()-pq2.top()>0){
            pq1.pop();
            ans++;
        }
        else if(pq1.top()-pq2.top()<0){
            pq2.pop();
            ans++;
        }
        else{
            pq2.pop();
            pq1.pop();
        }
    }
    while(!pq1.empty()){
        pq1.pop();
        ans++;
    }
    while(!pq2.empty()){
        pq2.pop();
        ans++;
    }
    cout<<ans<<"\n";
}
























