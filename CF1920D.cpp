#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ll __int128_t
#define int long long


struct node{
	ll val,sum;
	node(){}
	node(ll vv,ll ss):val(vv),sum(ss){}//val=0:copy
};

int n,q;
vector<node> v;

void solve(){
	v.clear();
	cin>>n>>q;
	v.push_back(node(0,0));
	for(int i = 1;i<=n;i++){
		int t,p;
		cin>>t>>p;
		if(v.back().sum>1e18)continue;
		if(t == 1){
			v.push_back(node(p,v.back().sum+1));
		}
		else{
			v.push_back(node(0,v.back().sum+v.back().sum*p));
		}
	}
	for(auto &i:v){
		//cout<<(int)i.val<<','<<(int)i.sum<<endl;
	}
	while(q--){
		int p;
		cin>>p;
		int now = v.size()-1;
		do{
			int l = 0,r = v.size()-1;
			while(l != r){
				int mid = (l+r+1)>>1;
				if(v[mid].sum<p)l = mid;
				else r = mid-1;
			}
			now = l+1;
			if(!v[now].val){
				p = p%v[now-1].sum;
				if(!p)p=v[now-1].sum;
			}
			//cout<<p<<":"<<now<<' '<<(int)v[now].val<<endl;
		}while(v[now].val == 0);
		//cout<<p<<":"<<now<<' '<<(int)v[now].val<<endl;
		cout<<(int)v[now].val<<' ';
	}
	cout<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
