#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


const int mxn = 1e5+10;
int n,q;
string s;
ll pref[mxn];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	cin>>s;
	s = "#"+s;
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1]+(s[i]-'a'+1);
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<pref[b]-pref[a-1]<<'\n';
	}
	return 0;
}
