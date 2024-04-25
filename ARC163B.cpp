#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


vector<int> v;
int l,r;
int n,k;

int check(int x){
	auto pos = lower_bound(v.begin(),v.end(),x)-v.begin();
	if(pos+k>v.size())return INT_MAX;
	else return max(0LL,v[pos+k-1]-r);
}

void solve(){
	cin>>n>>k;
	cin>>l>>r;
	for(int i = 2;i<n;i++){
		int k;
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	int ans = check(l);
	for(auto &i:v)ans = min(ans,max(0LL,l-i)+check(i));
	/*
	ans = min(ans,checkr(r));
	for(auto &i:v)ans = min(ans,max(0,l-i)+checkr(i));

   */
	cout<<ans;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
