#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int arr[mxn],pre[mxn];
int n;

void solve(){
	for(int i = 0;i<=n;i++)pre[i] = -mxn;
	cin>>n;
	int ans = mxn;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		ans = min(ans,i-pre[k]+1);
		pre[k] = i;
	}
	if(ans>n)cout<<"-1\n";
	else cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:pre)i = -mxn;
	int t;cin>>t;
	while(t--)solve();
}
