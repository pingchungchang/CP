#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e9+7;
const int mxn = 5e5+10;
bitset<mxn> alone;
vector<int> ans;
int dsu[mxn],sz[mxn];
vector<int> arr[mxn];
ll n,m;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b,int id){
	a = root(a),b = root(b);
	if(a == b)return;
	ans.push_back(id);
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += b;
	alone[a] = alone[a]|alone[b];
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		sz[i] = 1;
		dsu[i] = i;
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		while(k--){
			int c;
			cin>>c;
			arr[i].push_back(c);
		}
	}
	for(int i = 0;i<n;i++){
		if(arr[i].size() == 1){
			if(!alone[root(arr[i][0])]){
				ans.push_back(i+1);
				alone[root(arr[i][0])] = true;
			}
		}
		else{
			if(alone[root(arr[i][0])]&&alone[root(arr[i][1])])continue;
			onion(arr[i][0],arr[i][1],i+1);
		}
	}
	ll sum = 1;
	sort(ans.begin(),ans.end());
	for(auto &i:ans)sum = sum*2%mod;
	cout<<sum<<' '<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';return 0;
}
