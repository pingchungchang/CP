#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	int arr[n];
	ll total =0;
	for(auto &i:arr)cin>>i,total += i;
	total/=n;
	ll pref = 0;
	ll sum = 0;
	for(int i = 0;i<n;i++){
		sum += arr[i];
		if(sum<total*(i+1)){
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
