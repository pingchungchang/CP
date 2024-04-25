#include <bits/stdc++.h>
using namespace std;

// #define cout fout
// ofstream fout("output.txt");
const int mxn = 2e5+10;
const int shift = 1e5+5;
const int sq = sqrt(1e5);
struct Q{
    int id,l,r;
    Q(){}
    bool operator<(Q &b){
        if(l/sq == b.l/sq)return (l/sq&1?r<b.r:r>b.r);
        else return l/sq<b.l/sq;
    }
};
Q req[mxn];
int cnt[mxn];
int cntcnt[mxn];
int ans[mxn];
int arr[mxn];
int n,q;
int pt = 1;

void add(int now){
    cntcnt[cnt[arr[now]]]--;
    cnt[arr[now]]++;
    cntcnt[cnt[arr[now]]]++;
    if(cntcnt[pt+1] != 0)pt++;
    return;
}
void out(int now){
    cntcnt[cnt[arr[now]]]--;
    cnt[arr[now]]--;
    cntcnt[cnt[arr[now]]]++;
    if(!cntcnt[pt])pt--;
    return;
}

void solve(){
    cin>>q;
    for(int i = 1;i<=n;i++)cin>>arr[i],arr[i]+= shift;
    for(int i = 0;i<q;i++){
        cin>>req[i].l>>req[i].r;
        req[i].id = i;
    }
    sort(req,req+q);
    int pl = 1,pr = 1;
    cnt[arr[1]] = 1;
    cntcnt[1] = 1;
    pt = 1;
    for(int i = 0;i<q;i++){
        while(pr < req[i].r)add(++pr);
        while(pl>req[i].l)add(--pl);
        while(pr>req[i].r)out(pr--);
        while(pl<req[i].l)out(pl++);
        ans[req[i].id] = pt;
    }
    for(int i = 0;i<=pt;i++)cntcnt[i] = 0;
    for(auto &i:arr)cnt[i] = 0;
    for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n&&n != 0)solve();
}