#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!= EOF){
        vector<vector<int>> v(101,vector<int>(n,0));
        vector<pair<int,int>> items(n);
        for(int i =0;i<n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            items[i] = make_pair(a,b);
        }
        for(int i =0;i<=100;i++){
            for(int j =0;j<n;j++){
                if(j == 0){
                    if(items[0].first>i)continue;
                    else v[i][j] = items[0].second;
                    continue;
                }
                if(i == 0)continue;
                if(i<items[j].first) v[i][j] = v[i][j-1];
                else{
                    v[i][j] = max(v[i][j-1],v[i-items[j].first][j-1]+items[j].second);
                }
            }
        }
        printf("%d\n",v[100][n-1]);
    }
}