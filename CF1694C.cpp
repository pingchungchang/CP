#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	vector<ll> v(n);
	int st = 0;
	for(int i = 0;i<n;i++)cin>>v[i];
	for(int i = n-1;i>=0;i--){
		if(v[i] != 0){
			st = i;
			break;
		}
	}
	for(int i = 0;i<st;i++){
		v[i]--;
	}
	ll pref[n];
	for(ll i = 0;i<n;i++){
		if(i == 0)pref[i] = abs(v[i]);
		else pref[i] = pref[i-1]+abs(v[i]);
	}
	for(ll i = st;i>0;i--){
		if(v[i]>0){
			v[0] = INT_MAX;
			break;
		}
		else if(v[i] == 0){
			if(pref[i-1] == 0){
				break;
			}
			else{
				v[0] = INT_MAX;
				break;
			}
		}
		else{
			v[i-1] += v[i]+1;
		}
	}
	if(v[0] == 0)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

