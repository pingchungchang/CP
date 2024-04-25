#include <bits/stdc++.h>
using namespace std;


map<tuple<int,int>,int> mp;
int a,b,c;

queue<pair<int,int>> q;
void add(pair<int,int> tmp,int x){
    if(mp.count(make_tuple(tmp.first,tmp.second)) != 0)return;
    mp[make_tuple(tmp.first,tmp.second)] = x;
    q.push(tmp);
    return;
}
void solve(){
    while(!q.empty())q.pop();
    mp.clear();
    cin>>a>>b>>c;
    mp[make_tuple(0,0)] = 0;
    q.push(make_pair(0,0));
    while(!q.empty()&&q.front().first != c&&q.front().second != c){
        pair<int,int> now = q.front();
        int k = mp[make_tuple(now.first,now.second)];
        //cout<<now.first<<' '<<now.second<<endl;
        q.pop();
        if(now.first+now.second<a)add(make_pair(now.first+now.second,0),k+1);
        else add(make_pair(a,now.first+now.second-a),k+1);
        if(now.first+now.second<b)add(make_pair(0,now.first+now.second),k+1);
        else add(make_pair(now.first+now.second-b,b),k+1);
        add(make_pair(a,now.second),k+1);
        add(make_pair(now.first,b),k+1);
        add(make_pair(0,now.second),k+1);
        add(make_pair(now.first,0),k+1);
    }
    if(!q.empty()){
        cout<<mp[make_tuple(q.front().first,q.front().second)]<<'\n';
    }
    else cout<<-1<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i= 0;i<t;i++)solve();
}
