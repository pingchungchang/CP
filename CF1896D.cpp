#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 1e5+10;

int n,q;
ll sum = 0;
set<int> st;
set<int> one;
int arr[mxn];

void solve(){
	cin>>n>>q;
	sum = 0;
	one.clear();
	st.clear();
	for(int i = 1;i<=n;i++)cin>>arr[i],sum += arr[i];
	for(int i = 1;i<=n;i++){
		if(arr[i] == 2)st.insert(i);
		else one.insert(i);
	}
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll x;
			cin>>x;
			if(sum<x){
				cout<<"NO\n";
			}
			else if(st.size() == n){
				if(sum%2 == x%2)cout<<"YES\n";
				else cout<<"NO\n";
			}
			else{
				if(sum % 2 == x%2)cout<<"YES\n";
				else{
					ll d = min(*one.begin()-1,n-*one.rbegin());
					if(sum-d*2>=x)cout<<"YES\n";
					else cout<<"NO\n";
				}
			}
		}
		else{
			int p,v;
			cin>>p>>v;
			sum -= arr[p];
			if(arr[p] == 2)st.erase(p);
			else one.erase(p);
			arr[p] = v;
			sum += arr[p];
			if(arr[p] == 2)st.insert(p);
			else one.insert(p);
		}
	}
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
