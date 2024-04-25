#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;
map<ll,ll> mp;
map<ll,ll> ans;
ll arr[mxn];
ll n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		mp[arr[i]]++;
	}
	mp[INT_MAX] = 0;
	for(auto it = mp.rbegin();it != mp.rend();it++){
		if(it->fs > 1e9)continue;
		ans[it->fs] = ans[prev(it)->fs]+prev(it)->fs*prev(it)->sc;
	}
	for(int i = 1;i<=n;i++)cout<<ans[arr[i]]<<' ';
}
