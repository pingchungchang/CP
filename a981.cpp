#include <bits/stdc++.h>
using namespace std;
int dfs(int arr[],int now,int m,int ans[],int position,int n){
    if(m == 0){
        for(int i = 0;i<position-1;i++){
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[position-1]);
        return 1;
    }
    else if(m<0||now>=n||arr[now]>m) return 0;
    else{
        int ans2[n] = {-1};
        int j = 0;
        while(j<n&&ans[j] != -1){
            ans2[j] = ans[j];
            j++;
        }
        ans2[position] = arr[now];
        return dfs(arr,now+1,m-arr[now],ans2,position+1,n)|dfs(arr,now+1,m,ans,position,n);
    }
}
int main(){
    int n,m;
    scanf("%d %d\n",&n,&m);
    int arr[n];
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    for(int i = 0;i<n-1;i++){
        scanf("%d ",&k);
        pq.push(k);
    }
    scanf("%d",&k);
    pq.push(k);
    for(int i = 0;i<n;i++){
        arr[i] = pq.top();
        pq.pop();
    }
    int ans[n] = {-1};
    int a = dfs(arr,0,m,ans,0,n);
    if(a == 0) printf("-1\n");
}