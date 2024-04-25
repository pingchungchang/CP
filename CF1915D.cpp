#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	string s;
	int n;
	cin>>n;
	cin>>s;
	vector<int> v;
	for(int i = 0;i<n;i++){
		if(s[i] == 'a'||s[i] == 'e')v.push_back(i);
	}
	int pt = n-1;
	string ans;
	for(auto it = v.rbegin();it != v.rend();it++){
		string tmp;
		while(pt>=*it-1){
			tmp += s[pt];
			pt--;
		}
		if(!ans.empty())ans += '.';
		ans += tmp;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
