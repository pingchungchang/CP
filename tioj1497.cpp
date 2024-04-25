#include <bits/stdc++.h>
using namespace std;

struct node{
    int start;
    pair<int,int> val;
    node(){
        val = make_pair(0,0);
    }
};

bool cmp(const node &a,const node &b){
    return a.val<b.val;
}
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getline(cin,s);
    int n = s.size();
    vector<node> v(n,node());
    for(int i = 0;i<n;i++){
        v[i].start = i;
    }
    for(int i = 0;i<n;i++)v[i].val.first = (int)s[i]+1;
    for(int i = 0;(1LL<<i)<=n;i++){
        map<int,map<int,int>> all;
        for(int j = 0;j<n;j++){
            if(j+(1LL<<i)>=n)v[j].val.second = 0;
            else v[j].val.second = v[(j+(1LL<<i))].val.first;
            all[v[j].val.first][v[j].val.second] = 1;
        }

        int t = 1;
        for(auto &i1:all){
            for(auto &i2:i1.second){
                i2.second = t;
                t++;
            }
        }
        for(auto &now:v){
            now.val.first = all[now.val.first][now.val.second];
            now.val.second = 0;
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(auto &now:v)cout<<now.start<<'\n';
}
