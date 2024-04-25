//undone
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll pref[n],suf[n];
	for(int i = 0;i<n;i++){
		pref[i] = arr[i];
		if(i)pref[i] -= pref[i-1];
	}
	for(int i = n-1;i>=0;i--){
		suf[i] = arr[i];
		if(i != n-1)suf[i] -= suf[i+1];
	}
	for(int i = 0;i<n;i++){
		if(pref[i]<0)break;
		if(i == n-1){
			cout<<"YES\n";
			return;
		}
	}
	int pl = 0,pr = n-2;
	for(int i = 1;i<n;i++)rcnt += (suf[i]<0);
	bool flag = false;
	for(int i = 1;i<n;i++){
		if(pref[i]<0){
			pr = min(pr,i);
			break;
		}
	}
	for(int i = n-2;i>=0;i--)if(suf[i]<0){
		pl = max(pl,i-1);
		break;
	}
	bool flag = false;
	for(int i = pl;i<=pr;i++){
		swap(arr[i],arr[i+1]);
		bool f = true;
		if(i != 0&&arr[i]<pref[i-1])f = false;
		if(arr[i]<arr[i+1]-(i+2<n?suf[i+2]:0LL))f = false;;
		if(i )
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
