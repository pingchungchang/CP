#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> init(m,vector<int>(26,0)),final(m,vector<int>(26,0));
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		for(int j = 0;j<m;j++)init[j][s[j]-'a']++;
	}
	for(int i = 0;i<n-1;i++){
		string s;
		cin>>s;
		for(int j  =0;j<m;j++)final[j][s[j]-'a']++;
	}
	string ans;
	for(int i = 0;i<m;i++){
		for(int j = 0;j<26;j++){
			if(final[i][j] != init[i][j]){
				ans+= (char)('a'+j);				
				break;
			}
		}
	}
	cout<<ans;
	cout<<endl;
//	cout<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

