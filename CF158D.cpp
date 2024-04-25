#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	int ans = -1e9;
	for(auto &i:arr)cin>>i;
	for(int i = 3;i<=n;i++){
		if(n%i == 0){
			int step = n/i;
			for(int j = 0;j<step;j++){
				int tmp = 0;
				int now = j;
				while(now<n){
					tmp += arr[now];
					now += step;
				}
				ans = max(ans,tmp);
			}
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
