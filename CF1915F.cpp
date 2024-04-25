#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 4e5+10;
int bit[mxn];
vector<int> all;
int n;
pii arr[mxn];

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
	all.clear();
	all.push_back(INT_MIN);
	ll ans = 0;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		all.push_back(arr[i].fs);
		all.push_back(arr[i].sc);
	}
	sort(all.begin(),all.end());
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		int l = lower_bound(all.begin(),all.end(),arr[i].fs)-all.begin();
		int r = lower_bound(all.begin(),all.end(),arr[i].sc)-all.begin();
		ans += getval(r,mxn-1);
		modify(r,1);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
