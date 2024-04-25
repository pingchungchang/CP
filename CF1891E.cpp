#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
int arr[mxn];

void solve(){
	int n,k;
	int ans = 0;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 2;i<n;i++){
		if(!k)break;
		if(__gcd(arr[i-1],arr[i])==__gcd(arr[i],arr[i+1])&&__gcd(arr[i],arr[i-1])==1&&arr[i-1]!=1&&arr[i+1]!=1){
			k--;
			arr[i] = 0;
		}
	}
	for(int i = 2;i<=n;i++){
		if(__gcd(arr[i],arr[i-1]) == 1)ans++;
	}
	int s = 1;
	while(s<=n&&arr[s] == 1)s++;
	int e = n;
	while(e>=1&&arr[e] == 1)e--;
	int len = 0;
	vector<int> v;
	for(int i = s;i<=e;i++){
		if(arr[i] == 1)len++;
		else{
			if(!len)continue;
			v.push_back(len);
			len = 0;
		}
	}
	bool z = false;
	for(int i = 1;i<=n;i++)if(arr[i] != 1)z = true;
	sort(v.begin(),v.end());
	for(auto &i:v){
		if(i<=k){
			k -= i;
			ans -= i+1;
		}
		else break;
	}
	ans -= k-1+z;
	ans = max(0,ans);
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
