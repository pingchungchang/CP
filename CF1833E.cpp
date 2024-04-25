#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
int dsu[mxn],cnt[mxn],sz[mxn];
int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	cnt[a]++;
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	sz[a] += sz[b];
	cnt[a] += cnt[b];
	dsu[b] = a;
	return;
}

void solve(){
	int n;
	cin>>n;
	int arr[n+1];
#define pii pair<int,int>
	set<pii> st;
	for(int i = 1;i<=n;i++)dsu[i] = i,sz[i] = 1,cnt[i] = 0;
	for(int i =1;i<=n;i++){
		cin>>arr[i];
		if(st.find({min(arr[i],i),max(arr[i],i)}) != st.end())continue;
		st.insert({min(arr[i],i),max(arr[i],i)});
		onion(i,arr[i]);
	}
	int chain = 0,cycle = 0,sp = 0;
	for(int i = 1;i<=n;i++){
		if(dsu[i] == i){
			//cout<<i<<":"<<cnt[i]<<',';
			if(cnt[i] != sz[i]){
				if(sz[i] == 2)sp++;
				else chain++;
			}
			else cycle++;
		}
	}
	//cout<<cycle<<','<<chain<<'\n';
	cout<<cycle+min(chain+sp,1)<<' '<<cycle+sp+chain<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
