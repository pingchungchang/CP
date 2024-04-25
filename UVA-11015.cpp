#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    int num = 1;
    while(cin>>n>>m){
        if(n==m&&m==0)return 0;
        vector<string> names(n);
        for(int i = 0;i<n;i++){
            string s;
            cin>>s;
            names[i] = s;
        }
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i = 0;i<n;i++){
            dist[i][i] = 0;
        }
        for(int i = 0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            dist[a-1][b-1] = c;
            dist[b-1][a-1] = c;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k =0;k<n;k++){
                    if(dist[j][i] != INT_MAX&&dist[i][k] != INT_MAX){
                        dist[j][k] = min(dist[j][i]+dist[i][k],dist[j][k]);
                        dist[k][j] = dist[j][k];
                    }
                }
            }
        }
        pair<int,int> winner = make_pair(0,INT_MAX);
        for(int i = 0;i<n;i++){
            int now = 0;
            for(int j = 0;j<n;j++){
                now+=dist[i][j];
            }
            if(winner.second>now){
                winner.first = i;
                winner.second = now;
            }
        }
        printf("Case #%d : %s\n",num,names[winner.first].c_str());
        num++;
    }
}