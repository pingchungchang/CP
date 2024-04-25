#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	vector<char> v(n+2,'#');
	for(int i = 1;i<=n;i++)cin>>v[i];
	v.back() = v[1];
	v[0] = v[n];
	char c = '#';
	for(int i = 1;i<=n;i++){
		if(v[i] != '-'&&c == '#')c = v[i];
		else if(v[i] != c&&v[i] != '-')break;
		if(i == n){
			cout<<n<<'\n';
			return;
		}
	}
	int ans= 0;
	for(int i = 1;i<=n;i++){
		if(v[i] == '-'||v[i-1] == '-')ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

