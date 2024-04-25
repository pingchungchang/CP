#include <bits/stdc++.h>
using namespace std;

#define ll long long
#pragma GCC optimize("O3")
const int sq = sqrt(2e5+10);
struct Q{
    int l,r;
    int id;
    Q(){}
    bool operator<(Q &b){
        if(l/sq == b.l/sq)return ((l/sq)&1?r<b.r:r>b.r);
        else return l/sq<b.l/sq;
    }
};
ll mp[200005];
ll total = 0;
int arr[200005];
void add(int k){
    ll pre = mp[arr[k]];
    total -= pre*(pre-1)*(pre-2)/6;
    pre = (++mp[arr[k]]);
    total += pre*(pre-1)*(pre-2)/6;
    return;
}
void kick(int k){
    ll pre = mp[arr[k]];
    total -= pre*(pre-1)*(pre-2)/6;
    pre = (--mp[arr[k]]);
    total += pre*(pre-1)*(pre-2)/6;
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    ll ans[q];
    Q req[q];
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 0;i<q;i++){
        req[i].id =i;
        cin>>req[i].l>>req[i].r;
    }
    sort(req,req+q);
    int l = 1,r = 1;
    mp[arr[1]] = 1;
    for(auto &i:req){
        // cout<<l<<' '<<r<<' '<<total<<endl;
        while(r<i.r){
            r++;
            add(r);
        }
        while(l>i.l){
            l--;
            add(l);
        }
        while(r>i.r){
            kick(r);
            r--;
        }
        while(l<i.l){
            kick(l);
            l++;
        }
        // cout<<l<<' '<<r<<' '<<total<<endl;
        ans[i.id] = total;
    }
    for(auto &i:ans)cout<<i<<'\n';
}