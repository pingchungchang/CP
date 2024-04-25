#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 2e6+10;
int bit[mxn];
pii range[mxn];
int arr[mxn];
int n;
int ans[mxn];

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

vector<pair<pii,int>> v;
void solve(){
	v.clear();
	for(int i = 1;i<=n*2;i++){
		modify(i,-getval(i,i));
	}
	for(int i = 1;i<=n;i++)ans[i] = 1e9;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++){
		if(i<=arr[i]){
			range[arr[i]] = make_pair(i,-arr[i]);
			v.push_back(make_pair(range[arr[i]],arr[i]));
			v.push_back(make_pair(make_pair(range[arr[i]].fs+n,range[arr[i]].sc-n),arr[i]));
		}
		else range[arr[i]] = make_pair(i,-arr[i]-n),v.push_back(make_pair(range[arr[i]],arr[i]));
	}
	sort(v.rbegin(),v.rend());
	for(auto &i:v){
		i.fs.sc = -i.fs.sc;
		ans[i.sc] = min(ans[i.sc],i.fs.sc-i.fs.fs-getval(i.fs.fs,i.fs.sc));
		modify(i.fs.sc,1);
		ans[i.sc] = max(0ll,ans[i.sc]);
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	for(auto &i:ans)i = 1e9;
	while(t--)solve();
}
