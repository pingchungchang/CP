#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,r;
    while(cin>>n>>r){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0;i<r;i++){
            int k;
            cin>>k;
            pq.push(k);
        }
        for(int i = 1;i<=n;i++){
            if(pq.empty()||i != pq.top())printf("%d ",i);
            else if(!pq.empty())pq.pop();
        }
        if(n==r)printf("*");
        printf("\n");
    }
}