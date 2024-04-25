#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define fs first
#define sc second
#define ll long long

void solve(){
    pll range = {0,1e18};
    int q;
    cin>>q;
    while(q--){
        int tp;
        cin>>tp;
        if(tp == 1){
            ll a,b,c;
            cin>>a>>b>>c;
            pll tmp;
            if(c == 1)tmp = {0,a};
            else tmp = {(a-b)*(c-2)+a+1,(a-b)*(c-1)+a};
            if(tmp.sc<range.fs||tmp.fs>range.sc)cout<<"0 ";
            else{
                range.fs = max(range.fs,tmp.fs);
                range.sc = min(range.sc,tmp.sc);
                cout<<"1 ";
            }
        }
        else{
            ll a,b;
            cin>>a>>b;
            pll tmp;
            if(a>range.fs)tmp.fs = 1;
            else{
                tmp.fs = range.fs-a;
                tmp.fs = (tmp.fs+a-b-1)/(a-b)+1;
            }
            if(a>range.sc)tmp.sc = 1;
            else{
                tmp.sc = range.sc-a;
                tmp.sc = (tmp.sc+a-b-1)/(a-b)+1;
            }
            if(tmp.fs != tmp.sc){
                cout<<"-1 ";
            }
            else cout<<tmp.fs<<' ';
        }
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}