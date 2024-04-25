#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <functional>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i =0;i<n;i++){
        int j;
        cin>>j;
        pq.push(j);
    }
    int ans = 0;
    while(!pq.empty()){
        if(k<pq.top()) break;
        else{
            k -=pq.top();
            pq.pop();
            ans ++;
        }
    }
    cout<<ans;
    return 0;
}
