#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	char pre = s[0];
	int cnt = 1;
	for(auto &i:s)if(i != pre){
		pre = i;
		cnt++;
	}
	if(s[0] == '0')cnt--;
	if(cnt<=1){
		cout<<"0\n";
		return;
	}
	int k = s.back()-'0';
	cout<<cnt-1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}