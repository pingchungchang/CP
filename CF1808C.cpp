#include <bits/stdc++.h>
using namespace std;

#define ll long long
#pragma GCC optimize("O3")
pair<int,string> ans;
string sl,sr;
string now;
int cnt = 0;
set<string> done;

int calc(string &s){
    return *max_element(s.begin(),s.end())-*min_element(s.begin(),s.end());
}

void dfs(){
    cnt++;
    done.insert(now);
    // cout<<now<<endl;
    assert(cnt<=5000);
    if(now.size() == sl.size()){
        ans = min(ans,{calc(now),now});
        return;
    }
    char low = '0',high = '9';
    bool isl = false,ish = false;
    if(sl.substr(0,now.size()) == now)low = sl[now.size()],isl = true;
    if(sr.substr(0,now.size()) == now)high = sr[now.size()],ish = true;
    for(char i = low+isl;i<=high-ish;i++){
        now += i;
        ans = min(ans,{calc(now),now+string(sl.size()-now.size(),i)});
        now.pop_back();
    }
    if(isl){
        now += low;
        if(done.find(now) == done.end())dfs();
        now.pop_back();
    }
    if(ish){
        now += high;
        if(done.find(now) == done.end())dfs();
        now.pop_back();
    }
    return;
}

void solve(){
    ll l,r;
    cin>>l>>r;
    done.clear();
    if(to_string(l).size() != to_string(r).size()){
        cout<<string(to_string(l).size(),'9')<<'\n';
        return;
    }
    sl = to_string(l),sr = to_string(r);
    ans = {*max_element(sl.begin(),sl.end())-*min_element(sl.begin(),sl.end()),sl};
    if(sr[0]-sl[0]>2){
        cout<<string(sl.size(),(char)((int)sl[0]+sr[0])/2)<<'\n';
        return;
    }
    string tmp = string(sl.size(),sl[0]);
    if(tmp>=sl&&tmp<=sr){
        cout<<tmp<<'\n';
        return;
    }
    now = "";
    cnt = 0;
    dfs();
    cout<<ans.second<<'\n';
    return;
}
/*
ans = 0:done
ans = 1:
*/

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}