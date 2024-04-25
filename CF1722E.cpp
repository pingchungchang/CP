#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
const ll mxn = 1010;
ll bit[mxn][mxn];

void modify(int r,int c,ll val){
	for(;r<mxn;r += r&-r){
		int tmp = c;
		for(;tmp<mxn;tmp += tmp&-tmp){
			bit[r][tmp] += val;
		}
	}
	return;
}
ll getval(int sr,int er,int sc,int ec){
	ll re  = 0;
	for(;er>0;er -= er&-er){
		int tmp = ec;
		for(;tmp>0;tmp -= tmp&-tmp){
			re += bit[er][tmp];
		}
		tmp = sc-1;
		for(;tmp>0;tmp -= tmp&-tmp){
			re -= bit[er][tmp];
		}
	}
	sr--;
	for(;sr>0;sr -= sr&-sr){
		int tmp = ec;
		for(;tmp>0;tmp -= tmp&-tmp){
			re -= bit[sr][tmp];
		}
		tmp = sc-1;
		for(;tmp>0;tmp -= tmp&-tmp){
			re += bit[sr][tmp];
		}
	}
	return re;
}
void solve(){
	memset(bit,0LL,sizeof(bit));
	ll n,q;
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		ll h,w;
		cin>>h>>w;
		modify(h,w,h*w);
	}
	while(q--){
		ll sr,sc,er,ec;
		cin>>sr>>sc>>er>>ec;
		cout<<getval(sr+1,er-1,sc+1,ec-1)<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

