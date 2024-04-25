#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
const int inf = 1e9+10;

int dsu[mxn],sz[mxn],mt[mxn];
tlll arr[mxn];
int n,K;
priority_queue<int,vector<int>,less<int>> pq;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	 a = root(a),b = root(b);
	 if(a == b)return;
	 if(sz[a]<sz[b])swap(a,b);
	 sz[a] += sz[b];
	 dsu[b] = a;
	 mt[a] = min(mt[a],mt[b]);
	 return;
}

void solve(){
	while(!pq.empty())pq.pop();
	cin>>n>>K;
	for(int i = 0;i<=n;i++){
		dsu[i] = i;
		mt[i] = -1;
		sz[i] = 1;
	}
	for(int i = 1;i<=n;i++){
		cin>>get<0>(arr[i])>>get<1>(arr[i]);
		cin>>mt[i];
		get<2>(arr[i]) = i;
	}
	sort(arr+1,arr+n+1);
	for(int i = 2;i<=n;i++){
		if(get<0>(arr[i]) == get<0>(arr[i-1])){
			if(get<1>(arr[i])-get<1>(arr[i-1])<=K)onion(get<2>(arr[i-1]),get<2>(arr[i]));
		}
	}
	for(int i = 1;i<=n;i++)swap(get<0>(arr[i]),get<1>(arr[i]));
	sort(arr+1,arr+n+1);
	for(int i = 2;i<=n;i++){
		if(get<0>(arr[i]) == get<0>(arr[i-1])){
			if(get<1>(arr[i])-get<1>(arr[i-1])<=K)onion(get<2>(arr[i-1]),get<2>(arr[i]));
		}
	}
	//for(int i = 1;i<=n;i++)cout<<get<0>(arr[i])<<' '<<get<1>(arr[i])<<' '<<get<2>(arr[i])<<',';cout<<'\n';
	//for(int i = 1;i<=n;i++)cout<<root(i)<<','<<mt[root(i)]<<' ';cout<<'\n';
	for(int i = 1;i<=n;i++){
		if(i == dsu[i])pq.push(mt[i]);
	}
	for(int i = 0;i<=n;i++){
		if(!pq.empty())pq.pop();
		if(pq.empty()||pq.top()<=i){
			cout<<i<<'\n';
			return;
		}
	}
	assert(false);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
