#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(int a,int b){
        return abs(a)>abs(b);
    }
};
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<int,vector<int>,Compare> pq;
    for(int i =0;i<n;i++){
        int k;
        scanf("%d",&k);
        pq.push(k);
    }
    int ans = 0;
    int x = pq.top();
    pq.pop();
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        if(now*x<0)ans++;
        x = now;
    }
    printf("%d",ans);
}