#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 44;
const int mxc = 2e6+10;
int arr[mxn];
int n;
int cnt[mxc];
vector<int> all;

inline bool check(int dif){
	for(int i = 0;i<n;i++){
		if(arr[i]>0)cnt[arr[i]%dif]++;
		else{
			int tmp = dif-abs(arr[i])%dif;
			if(tmp == dif)tmp = 0;
			cnt[tmp]++;
		}
	}
	bool re = false;
	for(int i = 0;i<n;i++){
		int tmp = (arr[i]>0?arr[i]%dif:(dif-abs(arr[i])%dif));
		if(tmp == dif)tmp = 0;
		if(cnt[tmp]*2>=n)re = true;
		cnt[tmp] = 0;
	}
	return re;
}
inline void add(int k){
	for(int i = 1;i*i<=k;i++){
		if(k%i == 0){
			all.push_back(i);
			all.push_back(k/i);
		}
	}
	return;
}

void solve(){
	all.clear();
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	map<int,int> mp;
	for(int i = 0;i<n;i++)mp[arr[i]]++;
	for(auto &i:mp){
		if(i.sc*2>=n){
			cout<<"-1\n";
			return;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(arr[i] == arr[j])continue;
			add(arr[j]-arr[i]);
		}
	}
	sort(all.rbegin(),all.rend());
	for(auto &i:all){
		if(check(i)){
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
