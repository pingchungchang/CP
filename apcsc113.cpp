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

struct node{
	ll id,cnt,f,val;
	node(){
		val = id = cnt = 0;
		f = -1;
	}
	node(ll k){
		val = k;
	}
	bool operator<(node b){
		return val<b.val;
	}
};
bool cmp(node a,node b){
	return a.id<b.id;
}
int main(){
	ll n,q;
	cin>>n>>q;
	map<ll,vector<ll>> mp;
	for(int i = 1;i<=n;i++){
		ll k;
		cin>>k;
		mp[k].push_back(i);
	}
	for(int i = 0;i<q;i++){
		ll k;
		cin>>k;
		if(mp[k].empty()){
			cout<<"-1 0\n";
		}
		else cout<<mp[k][0]<<" "<<mp[k].size()<<'\n';
	}
	return 0;
}

