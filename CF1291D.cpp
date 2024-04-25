#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
int pref[mxn][26];
string s;
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n = s.size();
	s = "#"+s;
	for(int i = 1;i<=n;i++){
		pref[i][s[i]-'a']++;
		for(int j = 0;j<26;j++)pref[i][j] += pref[i-1][j];
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		if(l == r){
			cout<<"Yes\n";
			continue;
		}
		int tmp[26];
		for(int i = 0;i<26;i++)tmp[i] = pref[r][i]-pref[l-1][i];
		vector<int> v;
		for(int i = 0;i<26;i++)if(tmp[i])v.push_back(i);
		if(v.size()>2){
			cout<<"Yes\n";
		}
		else if(v.size() == 2){
			if(s[l] == s[r])cout<<"No\n";
			else cout<<"Yes\n";
		}
		else cout<<"No\n";
	}
	return 0;
}
