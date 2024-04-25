#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


map<vector<int>,int> mp;
ll ans = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int C = 0;
	for(auto &i:s)C|=1<<(i-'a');
	C = __builtin_popcount(C);
	vector<int> v(26,0);
	mp[v] = 1;
	for(int i = 0;i<s.size();i++){
		if(!v[s[i]-'a'])C--;
		v[s[i]-'a']++;
		auto tmp = v;
		int k = 1e9;
		for(auto &i:tmp)if(i)k = min(k,i);
		for(auto &i:tmp)if(i)i -= k;
		int &t = mp[tmp];
		if(!C)ans += t;
		cout<<i<<":";for(auto &j:tmp)cout<<j;cout<<' '<<t;cout<<endl;
		t++;
	}
	cout<<ans;
}
