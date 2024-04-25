#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve(){
	int n;
	cin>>n;
	if(n>45){
		cout<<"-1\n";
		return;
	}
	string s;
	for(int i = 9;i>=1;i--){
		if(n>=i){
			n -= i;
			s += '0'+i;
		}
	}
	sort(s.begin(),s.end());
	cout<<s<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
