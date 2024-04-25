#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int arr[mxn];
bitset<mxn> vis;
int n,k;

void solve(){
	for(int i = 0;i<=n;i++)vis[i] = false;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int now = n;
	while(k&&!vis[now]){
		k--;
		if(arr[now]>n){
			cout<<"NO\n";
			return;
		}
		vis[now] = true;
		now -= arr[now];
		if(now<=0)now += n;
	}
	if(k<=0||vis[now])cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
