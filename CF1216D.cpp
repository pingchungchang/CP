#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int G = -1;
	for(int i = 1;i<n;i++){
		if(arr[i] == arr[i-1])continue;
		if(G == -1)G = arr[i]-arr[i-1];
		else G = __gcd(G,arr[i]-arr[i-1]);
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ans += (arr[n-1]-arr[i])/G;
	}
	cout<<ans<<' '<<G<<'\n';
}
