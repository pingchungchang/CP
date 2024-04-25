#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;
    priority_queue<int,vector<int>,less<int>> pq;
    for(int i =0;i<n;i++){
        int j;
        cin>>j;
        pq.push(j);
    }
    int ans = 0;
    int times = 1;
    for(int i =1;i<=n;i++){
        if(i%m == 0) times++;
        ans +=pq.top()*times;
        pq.pop();
    }
    cout<<ans;
    return 0;
}
