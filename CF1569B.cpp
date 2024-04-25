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
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<string> v(n,string(n,'#'));
	for(int i = 0;i<n;i++){
		if(s[i] == '1')v[i] = string(n,'=');
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i == j)v[i][j] = 'X';
			if(v[i][j] != v[j][i]){
				v[i][j] = v[j][i] = '=';
			}
		}
	}
	for(int i = 0;i<n;i++){
		if(s[i] == '2'){
			for(int j = 0;j<n;j++){
				if(v[i][j] == '#'){
					v[i][j] = '+';
					v[j][i] = '-';
					break;
				}
				if(j == n-1){
					cout<<"NO\n";
					return;
				}
			}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)if(v[i][j] == '#')v[i][j] = '=';
	}
	cout<<"YES\n";
	for(auto &i:v)cout<<i<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

