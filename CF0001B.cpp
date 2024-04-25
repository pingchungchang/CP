#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int n = s.size();
	int lst = 0;
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(s[i]>='A'&&s[i]<='Z')cnt++,lst = i;
	}
	if(cnt == lst+1){
		string row = s.substr(0,cnt);
		string col = s.substr(cnt,n-cnt);
		ll tmp = 0;
		ll p = 1;
		while(!row.empty()){
			tmp += p*(row.back()-'A');
			if(row.size() == 1)tmp += p;
			p *= 26;
		}
		cout<<"R"<<tmp<<"C"<<col<<'\n';
	}
	else{
		string row,col;
		ll p = 0;
		for(p = 1;p<n&&s[p] != 'C';p++)row += s[p];
		p++;
		for(;p<n;p++)col += s[p];
		string tmp;
		p = stoi(row);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
