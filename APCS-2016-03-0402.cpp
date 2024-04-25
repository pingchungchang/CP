#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    vector<Node*> child;
    int depth = -1;
}Node;

int dfs(Node* root,int &ans,int nowdepth){
    if(root->depth != -1)return root->depth;
    if(root->child.size()==1){
        root->depth = dfs(root->child[0],ans,nowdepth+1);
        ans = max(ans,root->depth-nowdepth);
        return root->depth;
    }
    if(root->child.size()==0)return nowdepth;
    priority_queue<int,vector<int>,less<int>> pq;
    while(!pq.empty())pq.pop();
    for(int i =0;i<root->child.size();i++){
        pq.push(dfs(root->child[i],ans,nowdepth+1));
    }
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    ans = max(ans,a-nowdepth+b-nowdepth);
    root->depth = a;
    return a;
}

int main(){
    int n;
    int times = 0;
    while(scanf("%d",&n)!= EOF){
        if(times !=0)printf("\n");
        times= 1;
        long long sum = n*(n-1)/2;
        unordered_map<int,Node*> v;
        for(int i =0;i<n;i++)v[i] = new Node;
        // for(int i =0;i<n;i++)cout<<v[i];
        for(int i =0;i<n-1;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            sum -=b;
            v[a]->child.push_back(v[b]);
        }
        int ans = 0;
        int rootid = (int)sum;
        dfs(v[sum],ans,0);
        printf("%d",ans);
    }
}