#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define ld long double


ld solve(){
	int a,b,c;
	cin>>a>>b>>c;
	ld ans = max((ld)0.0,(ld)b/(-a*2));
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	ld ans = 0;
	while(t--)ans = max(solve(),ans);
	string s = to_string(ans);
	int dot = -1;
	for(int i = 0;i<s.size();i++)if(s[i] == '.')dot = i;
	for(int i = dot+7;i<s.size();i++)s[i] = '#';
	while(!s.empty()&&s.back() == '#')s.pop_back();
	cout<<s;
}
