#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    vector<pair<int,int>> directions;
    for(int i = -1;i<2;i++){
        for(int j = -1;j<2;j++){
            if(i != 0||j!=0){
                directions.push_back(make_pair(i,j));
            }
        }
    }
    while(cin>>n>>m){
        if(n==m&&m==0)return 0;
        vector<string> v(n);
        for(int i = 0;i<n;i++){
            string s;
            cin>>s;
            v[i] = s;
        }
        int ans =0;
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<m;j++){
                if(v[i][j] == '@'){
                    ans++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        pair<int,int> now = q.front();
                        q.pop();
                        if(now.first>=0&&now.second>=0&&now.first<n&&now.second<m&&v[now.first][now.second] == '@'){
                            v[now.first][now.second] = '*';
                            for(int x = 0;x<8;x++){
                                q.push(make_pair(now.first+directions[x].first,now.second+directions[x].second));
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}