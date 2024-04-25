#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 4e5+10;
int n;
int bit[mxn];
vector<int> all;
void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
int getval(int s,int e){
	int re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

void solve(){
	for(int i = 1;i<=all.size();i++){
		modify(i,-getval(i,i));
	}
	all = {0};
	cin>>n;
	pii arr[n];
	for(auto &i:arr){
		cin>>i.fs>>i.sc;
		all.push_back(i.fs);
		all.push_back(i.sc);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(auto &i:arr){
		i.fs = lower_bound(all.begin(),all.end(),i.fs)-all.begin();
		i.sc = lower_bound(all.begin(),all.end(),i.sc)-all.begin();
	}
	sort(arr,arr+n);
	int cnt[n] = {};
	for(int i = n-1;i>=0;i--){
		modify(arr[i].fs,1);
		cnt[i] += getval(arr[i].fs,arr[i].sc);
	}
	for(int i = 1;i<=all.size();i++)modify(i,-getval(i,i));
	for(int i = 0;i<n;i++){
		cnt[i] += getval(arr[i].fs,all.size());
		modify(arr[i].sc,1);
	}
	int ans = n-1;
	for(auto &i:cnt)ans = min(ans,n-i);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
