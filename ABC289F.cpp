#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second
pll s,e;
pll xr,yr;
pll init;
int cnt = 0;

vector<pll> v;
void pv(int dx,int dy){
    v.push_back({dx,dy});
    s.fs = dx*2-s.fs;
    s.sc = dy*2-s.sc;
}
main(){
    cin>>s.fs>>s.sc>>e.fs>>e.sc>>xr.fs>>xr.sc>>yr.fs>>yr.sc;
    init = s;
    bool flag = true;
    if(abs(s.fs-e.fs)&1)flag = false;
    if(abs(s.sc-e.sc)&1)flag = false;
    if(!flag){
        cout<<"No\n";
        return 0;
    }
    if(xr.fs == xr.sc&&yr.fs == yr.sc){
        if(s.fs != e.fs||s.sc != e.sc)pv(xr.fs,yr.fs);
    }
    else if(xr.fs == xr.sc){
        if(s.fs != e.fs)pv(xr.fs,yr.fs);
    }
    else if(yr.fs == yr.sc){
        if(s.sc != e.sc)pv(xr.fs,yr.fs);
    }
    if(xr.fs != xr.sc){
        while(s.fs<e.fs){
            pv(xr.fs,yr.fs);
            pv(xr.fs+1,yr.fs);
        }
        while(s.fs>e.fs){
            pv(xr.fs+1,yr.fs);
            pv(xr.fs,yr.fs);
        }
    }
    if(yr.fs != yr.sc){
        while(s.sc<e.sc){
            pv(xr.fs,yr.fs);
            pv(xr.fs,yr.fs+1);
        }
        while(s.sc>e.sc){
            pv(xr.fs,yr.fs+1);
            pv(xr.fs,yr.fs);
        }
    }
    if(s.fs == e.fs&&s.sc == e.sc){cout<<"Yes\n";for(auto &i:v)cout<<i.fs<<' '<<i.sc<<'\n';}
    else cout<<"No";
}
/*
5 7 15 17
10 10 11 13
*/