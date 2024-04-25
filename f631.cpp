#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!= EOF){
        priority_queue<int,vector<int>,less<int>> pq;
        for(int i =0;i<n;i++){
            int k;
            scanf("%d",&k);
            pq.push(k);
        }
        int done = 0;
        int h = pq.top();
        for(int i =0;i<m;i++){
            int k;
            scanf("%d",&k);
            if(done == 0){
                while(!pq.empty()&&k>pq.top()){
                    k -= pq.top();
                    pq.pop();
                }
                if(pq.empty()&&k!=0){
                    done = 1;
                    printf("Oh My God\n");
                    continue;
                }
                int now = pq.top();
                now -=k;
                pq.pop();
                pq.push(now);
            }
        }
        if(done == 0)printf("%d %d\n",h,pq.top());
    }
}