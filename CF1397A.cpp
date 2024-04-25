#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	int cnt[30] = {};
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		for(auto &j:s)cnt[j-'a']++;
	}
	for(auto &i:cnt){
		if(i%n != 0){
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

