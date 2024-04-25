#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1010;
const ll mod = 1e9+7;
ll C[mxn][mxn];
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

ll calc(int i,int j){
	if(i<j)return C[i][j] = 0;
	if(i == j||j == 0)return C[i][j] = 1LL;
	if(C[i][j] != -1)return C[i][j];
	return C[i][j] = mad(calc(i-1,j),calc(i-1,j-1));
}

void solve(){
	map<int,int> mp,cnt;
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(auto &i:arr)cin>>i,cnt[i]++;
	sort(arr,arr+n);
	int pt = n-1;
	int c = 0;
	while(c<k){
		mp[arr[pt]]++;
		pt--;
		c++;
	}
	cout<<C[cnt[mp.begin()->fs]][mp.begin()->sc]<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(C,-1,sizeof(C));
	for(int i = 0;i<mxn;i++){
		for(int j = 0;j<mxn;j++){
			if(C[i][j] == -1)calc(i,j);
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
