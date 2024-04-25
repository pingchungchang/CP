#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    int ans = 0;
    cint>>n>>m;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i =0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(b == 1) pq.push(a);
        ans +=a;
    }
    int s = pq.size();
    for(int i = 0;i<s-m;i++){
        ans -=2*pq.top();
        pq.pop();
    }
    cout<<ans;
}
