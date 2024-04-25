#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &v,vector<int>choice,int now){
    if(now == choice.size()){
        for(int i = 0;i<choice.size();i++){
            printf("%d",choice[i]);
            if(i != choice.size()-1)printf(" ");
        }
        printf("\n");
    }
    else{
        if(now == 0){
            for(int i = 0;i<=v.size()-choice.size();i++){
                choice[0] =v[i];
                dfs(v,choice,1);
            }
        }
        else{
            for(int i = 0;i<=v.size()-choice.size()+now;i++){
                if(v[i]<=choice[now-1])continue;
                choice[now]=v[i];
                dfs(v,choice,now+1);
            }
        }
    }
}
int main(){
    int n;
    while(scanf("%d",&n)!= EOF){
        if(n == 0)return 0;
        vector<int> v(n,0);
        for(int i =0;i<n;i++){
            int k;
            scanf("%d",&k);
            v[i] = k;
        }
        sort(v.begin(),v.end());
        int m;
        scanf("%d",&m);
        vector<int> choice(m,-1);
        dfs(v,choice,0);
    }
}