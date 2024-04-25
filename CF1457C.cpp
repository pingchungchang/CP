#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,p,k;
	cin>>n>>p>>k;
	string s;
	cin>>s;
	int arr[k] = {};
	for(int i = 0;i<n;i++){
		arr[i%k] += (s[i] == '0'?1:0);
	}
	int x,y;
	cin>>x>>y;
	int pt = 0;
	int ans = 1e9;
	p--;
	for(int i = 0;i<n-p;i++){
		while(pt<n&&pt<i+p){
			arr[pt%k]-=(s[pt] == '0');
			pt++;
		}
		ans = min(ans,y*i+x*arr[(i+p)%k]);
		//cout<<i<<":"<<y*i+x*arr[(i+p)%k]<<'\n';
	}
	cout<<ans<<'\n';
	return;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
