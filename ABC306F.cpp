#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 1e4+10;
ll bit[mxn];
vector<pll> arr;
ll sum = 0;
ll ans = 0;
int n,m;

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
ll getval(int s,int e){
	ll re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<m;j++){
			ll k;
			cin>>k;
			arr.push_back({k,i});
		}
	}
	sort(arr.begin(),arr.end());
	for(auto &i:arr){
		modify(i.sc,1);
		ans = ans+getval(i.sc+1,n)+getval(i.sc,i.sc)*(n-i.sc);
	}
	cout<<ans;
}
