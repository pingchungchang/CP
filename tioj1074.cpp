#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

bitset<404> dp;
int n;

void solve(){
	if(!n)exit(0);
	dp.reset();
	int sum = 0;
	int arr[n];
	for(auto &i:arr)cin>>i,sum += i;
	if(n == sum){
		cout<<"NO\n";
		return;
	}
	for(int l = 0;l<n;l++){
		int ts = 0;
		for(int r = l;r<n;r++){
			ts += arr[r];
			dp[ts] = true;
		}
	}
	//for(int i = 1;i<=sum;i++)cout<<dp[i];cout<<' '<<sum<<' '<<dp.count()<<'\n';
	if(dp.count() == sum)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
