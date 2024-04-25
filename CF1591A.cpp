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
	int arr[n+1] = {};
	for(int i = 1;i<=n;i++)cin>>arr[i];
	int ans= 1;
	for(int i = 1;i<=n;i++){
		if(arr[i] == 1){
			ans++;
			if(arr[i-1] == 1)ans += 4;
		}
		else{
			if(i != 1&&arr[i-1] == 0){
				cout<<"-1\n";
				return;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

