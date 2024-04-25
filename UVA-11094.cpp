#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        vector<string> v;
        for(int i = 0;i<n;i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        int a,b;
        cin>>a>>b;
        queue<pair<int,int>> q;
        q.push(make_pair(a,b));
        char land;
        char water = 'w';
        land = v[a][b];
        if(land == 'w') water = 's';
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            if(v[p.first][p.second] == land){
                v[p.first][p.second] = water;
                q.push(make_pair(p.first,(p.second+1)%m));
                int n2 = (p.second-1)%m;
                if(n2<0)n2+=m;
                q.push(make_pair(p.first,n2));
                if(p.first != 0) q.push(make_pair(p.first-1,p.second));
                if(p.first != n-1) q.push(make_pair(p.first+1,p.second));
            }
        }
        int biggest = 0;
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<v[0].size();j++){
                if(v[i][j] == land){
                    int area = 0;
                    queue<pair<int,int>> finds;
                    finds.push(make_pair(i,j));
                    while(!finds.empty()){
                        pair<int,int> now = finds.front();
                        finds.pop();
                        if(v[now.first][now.second] == land){
                            v[now.first][now.second] = water;
                            area++;
                            int neg = (now.second-1)%m;
                            if(neg<0) neg = m+neg;
                            finds.push(make_pair(now.first,(now.second+1)%m));
                            finds.push(make_pair(now.first,neg));
                            if(now.first != 0) finds.push(make_pair(now.first-1,now.second));
                            if(now.first != n-1) finds.push(make_pair(now.first+1,now.second));
                        }
                    }
                    biggest = max(biggest,area);
                }
            }
        }
        printf("%d\n",biggest);
    }
}
