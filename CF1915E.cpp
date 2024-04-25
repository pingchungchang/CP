#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
ll arr[mxn];
ll n;

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] = arr[i-1]+(i&1?arr[i]:-arr[i]);
	}
	set<ll> st;
	st.insert(0ll);
	for(int i = 1;i<=n;i++){
		if(st.find(arr[i]) != st.end()){
			cout<<"Yes\n";
			return;
		}
		st.insert(arr[i]);
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
