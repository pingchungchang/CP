#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	s = "#"+s;
	set<char> st;
	while(k--){
		char c;
		cin>>c;
		st.insert(c);
	}
	int p = 1;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(p<i)p = i;
		while(p<=n&&st.find(s[p]) != st.end())p++;
		ans += p-i;
	}
	cout<<ans;
}
