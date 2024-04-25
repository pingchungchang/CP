#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
ll arr[mxn],pref[mxn],ans[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++)pref[i] = pref[i-1]+arr[i];
	for(int i = 0;i<m;i++){
		ans[i] = pref[i];
		ll tans = pref[i],sum = pref[i];
		for(int j = i+m;j<=n;j+=m){
			sum += pref[j]-pref[j-m];
			tans += sum;
			ans[j] = tans;
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
}
