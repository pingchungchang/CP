#include<bits/stdc++.h>
using namespace std;

void solve(){
	vector<int> v(2,0);
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++){
		v[s[i]-'0']++;
	}
	if(v[0]!= v[1])cout<<min(v[0],v[1])<<'\n';
	else cout<<v[0]-1<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
