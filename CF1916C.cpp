#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int f(int e,int o){
	if(e+o==1)return 0;
	if(!o)return 0;
	int re = 0;
	return o/3+(o%3 == 1);
}

void solve(){
	int n;
	cin>>n;
	int cnt[2] = {};
	int arr[n];
	ll sum = 0;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++){
		cnt[arr[i]&1]++;
		sum += arr[i];
		cout<<sum-f(cnt[0],cnt[1])<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
