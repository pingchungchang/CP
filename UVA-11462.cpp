#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0)return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i =0;i<n;i++){
            int k;
            scanf("%d",&k);
            pq.push(k);
        }
        while(!pq.empty()){
            printf("%d",pq.top());
            pq.pop();
            if(pq.empty())printf("\n");
            else printf(" ");
        }
    }
}