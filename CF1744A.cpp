#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	int n;
	cin>>n;
	int arr[n];
	string s;
	map<int,char> mp;
	for(int i= 0;i<n;i++)cin>>arr[i];
	cin>>s;
	for(int i = 0;i<n;i++){
		if(mp.find(arr[i]) == mp.end()){
			mp[arr[i]] = s[i];
		}
		else if(mp[arr[i]] != s[i]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

