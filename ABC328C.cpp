#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e5+10;
string s;
int pref[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	cin>>s;
	s = "#"+s;
	for(int i = 2;i<=n;i++){
		pref[i] += pref[i-1];
		if(s[i] == s[i-1])pref[i]++;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<pref[r]-pref[l]<<'\n';
	}
	return 0;
}
