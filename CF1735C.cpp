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

int dsu[26];
int root(int k){
	if(k != dsu[k]){
		return dsu[k] = root(dsu[k]);
	}
	else return k;
}
void onion(int a,int b){
	dsu[root(a)] = root(b);
}
void solve(){
	int n;
	string s;
	cin>>n>>s;
	for(int i = 0;i<26;i++)dsu[i] = i;
	bool used[26] = {};
	string change(26,'#');
	for(auto &i:s){
		if(change[i-'a'] == '#'){
			for(char c = 'a';c<='z';c++){
				if(root(c-'a') == root(i-'a') || used[c-'a'])continue;
				onion(c-'a',i-'a');
				change[i-'a'] = c;
				used[c-'a'] = true;
				break;
			}
		}
	}
	char l = 'z';
	for(int i = 0;i<26;i++){
		if(!used[i]){
			l = 'a'+i;
			break;
		}
	}
	for(auto &i:s){
		i = change[i-'a'];
		if(i == '#')i = l;
	}
	cout<<s<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

