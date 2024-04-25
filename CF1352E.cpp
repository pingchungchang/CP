#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 8080;
bitset<mxn> sp;
int n;

void solve(){
	for(int i = 0;i<=n;i++)sp[i] = false;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n;i++){
		int sum = arr[i];
		for(int j = i+1;j<n;j++){
			sum+=arr[j];
			if(sum>n)break;
			sp[sum] = true;
		}
	}
	int ans = 0;
	for(auto &i:arr)if(sp[i])ans++;
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
