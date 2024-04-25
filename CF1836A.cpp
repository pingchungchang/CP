#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int cnt[101] = {};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		cnt[k]++;
	}
	for(int i = 1;i<=100;i++){
		if(cnt[i]>cnt[i-1]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
