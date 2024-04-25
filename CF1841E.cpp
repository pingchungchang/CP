#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
int dsu[mxn],sz[mxn],done[mxn];
vector<int> act[mxn];
ll n;
ll m;
pll ans = {0,0};
pll sum = {0,0};
ll tar;

int root(int k){
	return k == dsu[k]?k:dsu[k]=root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[b]>sz[a])swap(a,b);
	if(sz[a]>=tar)sum.fs -= sz[a],sum.sc--;
	if(sz[b]>=tar)sum.fs -= sz[b],sum.sc--;
	sz[a] += sz[b];
	if(sz[a]>=tar)sum.fs += sz[a],sum.sc++;
	dsu[b] = a;
	return;
}

pll f(){
	ans = {0,0},sum = {0,0};
	for(int i = 1;i<=n;i++){
		dsu[i] = i;
		sz[i] = 1;
		done[i] = 0;
	}
	for(int i = 0;i<=n;i++){
		ans.fs += sum.fs;
		ans.sc += sum.sc;
		for(auto &j:act[i]){
			done[j] = 1;
			if(tar==1){
				sum.fs++;
				sum.sc++;
			}
			if(j != 1&&done[j-1])onion(j,j-1);
			if(j != n&&done[j+1])onion(j,j+1);
		}
	}
	return ans;
}

void solve(){
	cin>>n;
	int arr[n+1] = {};
	for(int i = 1;i<=n;i++)cin>>arr[i],act[arr[i]].push_back(i);
	cin>>m;
	int l = 1,r = n;
	while(l != r){
		int mid = (l+r+1)>>1;
		tar = mid;
		if(f().fs>=m)l = mid;
		else r = mid-1;
	}
	tar = l;
	auto total = f();
	//cout<<l<<":"<<total.fs<<' '<<total.sc<<' ';
	total.sc -= (total.fs-m)/l;
	cout<<m-total.sc<<'\n';
	for(int i = 0;i<=n;i++){
		act[i].clear();
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
