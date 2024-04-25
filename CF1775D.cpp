#include <bits/stdc++.h>
using namespace std;

const int mxn = 3e5+10;
int lpf[mxn];
vector<int> paths[mxn];
bitset<mxn> vis;
int dist[mxn];

int main(){
    for(int i = 2;i<mxn;i++){
        if(!lpf[i]){
            for(int j = i;j<mxn;j+=i)lpf[j] = i;
        }
    }
    int n;
    cin>>n;
    int arr[n+1] = {};
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        int k = arr[i];
        unordered_set<int> st;
        while(k != 1){
            st.insert(lpf[k]);
            k /= lpf[k];
        }
        for(auto &j:st)paths[j].push_back(i);
    }
    queue<int> q;
    fill(dist,dist+mxn,-1);
    int s,e;
    cin>>s>>e;
    q.push(s);
    dist[s] = s;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        int k = arr[now];
        unordered_set<int> st;
        while(k != 1){
            st.insert(lpf[k]);
            k/=lpf[k];
        }
        for(auto &i:st){
            if(vis[i])continue;
            vis[i] = true;
            for(auto nxt:paths[i]){
                if(dist[nxt] == -1){
                    dist[nxt] = now;
                    q.push(nxt);
                }
            }
        }
    }
    if(dist[e] == -1){
        cout<<-1;
        return 0;
    }
    vector<int> v;
    while(e != dist[e]){
        v.push_back(e);
        e = dist[e];
    }
    v.push_back(s);
    reverse(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(auto &i:v)cout<<i<<' ';
    return 0;
}