#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


ll ans = 1e18;
const int mxn =  2e5+10;;
const int mxC = 2e6+10;
const int sh = mxC>>1;
ll pref1[mxC],pref2[mxC];
ll arr[mxn];
vector<ll> all;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++){
		ll k;
		cin>>k;
		arr[i] -= k;
	}
	for(int i = 1;i<=n;i++){
		arr[i] += arr[i-1];
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	for(int i = 1;i<=n;i++)
		arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin(),pref1[arr[i]] += all[arr[i]],pref2[arr[i]]++;
	for(int i = 1;i<mxC;i++){
		pref1[i] += pref1[i-1];
		pref2[i] += pref2[i-1];
	}
	for(int i = 0;i<n;i++){
		ans = min(ans,
	pref1[mxC-1]-pref1[arr[i]]-(pref2[mxC-1]-pref2[arr[i]])*all[arr[i]]+(pref2[arr[i]]*all[arr[i]]-pref1[arr[i]]));
	}
	cout<<ans;
}
