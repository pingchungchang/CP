#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	string s;
	for(auto &i:arr)cin>>i;
	cin>>s;
	int pl = 0,pr = n-1;
	for(auto &i:s)if(i == 'L')pl++;else pr--;
	int ans[n];
	int now = 1;
	for(int i = n-1;i>=0;i--){
		if(s[i] == 'L')now = now*arr[--pl]%m;
		else now = now*arr[++pr]%m;
		ans[i] = now;
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
