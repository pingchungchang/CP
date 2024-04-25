#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,l,r,s;
	cin>>n>>l>>r>>s;
	l--,r--;
	ll m = r-l+1;
	if(s<m*(m+1)/2||s>(n+n-m+1)*m/2){
		cout<<"-1\n";
		return;
	}
	int total = 0;
	vector<int> tmp(m,0);
	for(int i = 0;i<m;i++){
		total += i+1;
		tmp[i] = i+1;
	}
	int big = n;
	for(int i = m-1;i>=0;i--){
		int diff = big-tmp[i];
		if(diff>=s-total){
			tmp[i] += s-total;
			break;
		}
		else{
			total += diff;
			tmp[i] = big;
			big--;
		}
	}
	vector<int> ans(n);
	set<int> st;
	for(auto i:tmp)st.insert(i);
	int now = 1;
	for(int i = 0;i<l;i++){
		while(st.find(now) != st.end())now++;
		ans[i] = now++;
	}
	for(int i = l;i<=r;i++)ans[i] = tmp[i-l];
	for(int i = r+1;i<n;i++){
		while(st.find(now) != st.end())now++;
		ans[i] = now++;
	}
	for(auto i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

