#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	string s;
	cin>>s;
	int n = s.size();
	int p[n] = {};
	if(n>1&&s[0] == s[1])p[1] = 1;
	for(int i = 2;i<n;i++){
		int pt = p[i-1];
		while(pt>0&&s[pt] != s[i]){
			pt = p[pt-1];
		}
		if(pt<=0&&s[i] == s[0])p[i] = 1;
		else if(pt <= 0)p[i] = 0;
		else p[i] = pt+1;
	}
	int now = n-1;
	vector<int> ans;
	while(now > 0){
		ans.push_back(p[now]);
		now = p[now]-1;
	}
//	for(auto i:p)cout<<i<<' ';cout<<'\n';
	
	for(int i = ans.size()-1;i>=0;i--){
		if(ans[i] == 0)continue;
		else cout<<ans[i]<<' ';
	}return 0;
}

