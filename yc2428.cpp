#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

map<int,int> dec(int k){
	bool flag = true;
	map<int,int> re;
	while(flag){
		flag = false;
		for(int i = 2;i*i<=k;i++){
			if(k%i == 0){
				while(k%i == 0){
					k/=i;
					re[i]++;
				}
				flag = true;
				break;
			}
		}
	}
	if(k != 1)re[k]++;
	return re;
}

const int mxn = 1e6+10;
const ll mod = 998244353;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}

bitset<mxn> vis;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	int arr[n+1];
	for(int i = 1;i<=n;i++)arr[i] = i;
	for(int i = 0;i<m;i++){
		int t;
		cin>>t;
		int brr[t];
		for(int j = 0;j<t;j++)cin>>brr[j];
		for(int j = t-1;j>=1;j--){
			swap(arr[brr[j-1]],arr[brr[j]]);
		}
	}
	map<int,int> now;
	vector<map<int,int>> v;
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		int C = 0,now = i;
		do{
			vis[now] = true;
			C++;
			now = arr[now];
		}while(!vis[now]);
		v.push_back(dec(C));
	}
	for(auto &i:v){
		for(auto &j:i){
			now[j.fs] = max(now[j.fs],j.sc);
		}
	}
	ll ans = 1;
	for(auto &i:now)ans = ans*pw(i.fs,i.sc)%mod;
	cout<<ans;
	return 0;
}
