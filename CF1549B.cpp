#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(b[i] == '0')continue;
		if(i>0&&a[i-1] == '1')ans ++,a[i-1] = '2';
		else if(a[i] == '0')a[i] = '2',ans+= b[i]-'0';
		else if(i+1<n&&a[i+1] == '1')ans ++,a[i+1] = '2';
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
