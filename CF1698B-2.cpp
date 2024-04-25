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
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	if(k == 1){
		cout<<(n-1)/2<<'\n';
		return;
	}
	else{
		int ans = 0;
		for(int i = 1;i< n-1;i++){
			if(arr[i-1]+arr[i+1]<arr[i])ans++;
		}
		cout<<ans<<'\n';
		return;
	}
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

