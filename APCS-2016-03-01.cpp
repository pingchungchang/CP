#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    int highest = -1;
    int lowest = 101;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        pq.push(k);
    }
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        printf("%d",now);
        if(pq.size()!=0)printf(" ");
        if(now<60)highest = now;
        else lowest = min(lowest,now);
    }
    if(highest != -1) printf("\n%d\n",highest);
    else printf("\nbest case\n");
    if(lowest != 101) printf("%d",lowest);
    else printf("worst case");
}