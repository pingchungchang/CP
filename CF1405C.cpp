#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

int n,k;
string s;

void solve(){
	cin>>n>>k>>s;
	int val[k] = {};
	memset(val,-1,sizeof(val));
	for(int i = 0;i<n;i++){
		if(val[i%k] != -1&&s[i] != '?'&&val[i%k] != s[i]-'0'){
			cout<<"NO\n";
			return;
		}
		if(s[i] != '?')val[i%k] = s[i]-'0';
	}
	for(int i = 0;i<n;i++){
		if(val[i%k] != -1)s[i] = '0'+val[i%k];
	}
	int o = 0,z = 0;
	for(int i = 0;i<k;i++){
		o += (s[i] == '1');
		z += (s[i] == '0');
	}
	if(o>k/2||z>k/2){
		cout<<"NO\n";
		return;
	}
	for(int i = k;i<n;i++){
		o -= (s[i-k] == '1');
		z -= (s[i-k] == '0');
		o += (s[i] == '1');
		z += (s[i] == '0');
		if(o>k/2||z>k/2){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
