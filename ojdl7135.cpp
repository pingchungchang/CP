#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+10;
int dsu[mxn],sz[mxn];
tlll arr[mxn*2];
int n,m;

int root(int k){
	return k==dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		sz[i] = 1;
		dsu[i] = i;
	}
	for(int i = 0;i<m;i++){
		cin>>get<1>(arr[i])>>get<2>(arr[i])>>get<0>(arr[i]);
	}
	sort(arr,arr+m);
	ll ans = 0;
	for(int i = 0;i<m;i++){
		int a = root(get<1>(arr[i])),b = root(get<2>(arr[i]));
		ll w = get<0>(arr[i]);
		if(a == b)continue;
		ans += w*sz[a]*sz[b];
		onion(a,b);
	}
	cout<<ans;
}
