#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define ll long long
#define fs first
#define sc second

ll cross(pll a,pll b){
    return a.fs*b.sc-a.sc*b.fs;
}
bool cmp(pll &a,pll &b){
    if(cross(a,b) == 0)return a.sc<b.sc;
    return cross(a,b)>0;
}
deque<pll> up,down;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        pll tmp;
        cin>>tmp.fs>>tmp.sc;
        if(tmp.sc == 0){
            if(tmp.fs>=0)up.push_back(tmp);
            else down.push_back(tmp);
            continue;
        }
        if(tmp.sc>=0)up.push_back(tmp);
        else down.push_back(tmp);
    }
    // for(auto &i:up)cout<<i.fs<<' '<<i.sc<<endl;cout<<endl;
    // for(auto &i:down)cout<<i.fs<<' '<<i.sc<<endl;cout<<endl;
    sort(up.begin(),up.end(),cmp);
    sort(down.begin(),down.end(),cmp);
    while(!down.empty()&&down.front().sc == 0){up.push_back(down.front());down.pop_front();}
    for(auto &i:down)cout<<i.fs<<' '<<i.sc<<'\n';
    for(auto &i:up)cout<<i.fs<<' '<<i.sc<<'\n';
}