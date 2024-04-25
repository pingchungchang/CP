#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a,b;
	cin>>a>>b;
	vector<int> v(26,0);
	for(int i = 0;i<a;i++){
		char c;
		cin>>c;
		v[c-'a']++;
	}
	int p = 0;
	int sing =0;
	for(int i = 0;i<26;i++){
		p += v[i]/2;
		sing += v[i]%2;
	}
	int len = (p/b)*2;
	p -= (p/b)*b;
	if(2*p+sing>=b){
		cout<<len+1<<'\n';
	}
	else cout<<len<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
