#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int cnt[101] = {};
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		cnt[k]++;
	}
	int a = 0,b = 0;
	for(int i = 0;i<=100;i++){
		if(cnt[i]){
			cnt[i]--;
			a = i+1;
		}
		else break;
	}
	for(int i = 0;i<=100;i++){
		if(cnt[i]){
			cnt[i]--;
			b = i+1;
		}
		else break;
	}
	cout<<a+b<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
