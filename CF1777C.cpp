#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
vector<int> fac[mxn];
int n,m;
int arr[mxn];
int cnt[mxn];
int sum = 0;

inline void add(int k){
	for(auto &j:fac[k]){
		if(!cnt[j]&&j<=m)sum++;
		cnt[j]++;
	}
	return;
}
inline void del(int k){
	for(auto &j:fac[k]){
		cnt[j]--;
		if(!cnt[j]&&j<=m)sum--;
	}
	return;
}

inline bool check(int r){
	for(int i = 0;i<=m;i++)cnt[i] = 0;
	sum = 0;
	int pl = 0;
	for(int i = 0;i<n;i++){
		add(arr[i]);
		while(arr[i]-arr[pl]>r)del(arr[pl++]);
		if(sum == m)return true;
	}
	return false;
}

void solve(){
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i];
	int l = 0,r = 1e5;
	sort(arr,arr+n);
	while(l != r){
		int mid = (l+r)>>1;
		if(check(mid))r = mid;
		else l = mid+1;
	}
	if(!check(l))cout<<"-1\n";
	else cout<<l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 1;i<mxn;i++){
		for(int j = i;j<mxn;j+=i){
			fac[j].push_back(i);
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
