#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pii pair<int,int>

map<vector<int>,int> mp;
vector<int> cap;

int main(){
    int n;
    cin>>n;
    cap = vector<int>(n);
    for(int i = 0;i<n;i++)cin>>cap[i];
    int m;
    cin>>m;
    vector<int> now(n,0);
    mp[now] = 1;
    queue<pair<vector<int>,int>>q;
    q.push({now,1});
    auto s = clock();
    while(!q.empty()&&(clock()-s)/(float)CLOCKS_PER_SEC<=2.9){
        auto v = q.front().fs;
        int step = q.front().sc+1;
        // for(auto &i:v)cout<<i<<' ';cout<<":"<<step-2<<'\n';
        q.pop();
        for(int i = 0;i<n;i++){
            if(v[i] == m){
				cout<<step-2;
				return 0;
			}
        }
        for(int i = 0;i<v.size();i++){
            auto tmp = v;
            tmp[i] = cap[i];
            if(mp[tmp] == 0){
                mp[tmp] = step;
                q.push({tmp,step});
            }
        }
        for(int i =0;i<n;i++){
            auto tmp = v;
            tmp[i] = 0;
            if(mp[tmp] == 0){
                mp[tmp] = step;
                q.push({tmp,step});
            }
        }
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<v.size();j++){
                if(i == j)continue;
                auto tmp = v;
                int d = min(tmp[i],cap[j]-tmp[j]);
                tmp[i] -= d;
                tmp[j] += d;
                if(mp[tmp] == 0){
                    mp[tmp] = step;
                    q.push({tmp,step});
                }
            }
        }
    }
    cout<<-1;
    return 0;
}
