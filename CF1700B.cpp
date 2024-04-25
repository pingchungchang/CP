#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
string _minus(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	while(a.size()<b.size())a += "0";
	while(b.size()<a.size())b += '0';
	string returns;
	int mv= 0;
	for(int i = 0;i<a.size();i++){
		if(a[i]>=b[i]+mv){
			returns += (char)('0'+(a[i]-b[i]-mv));
			mv = 0;
		}
		else{
			returns += (char)('0'+(10+a[i])-b[i]-mv);
//			cout<<(int)10+a[i]-b[i]-mv<<endl;
			mv = 1;
		}
	}
	while(returns.back() == '0')returns.pop_back();
	reverse(returns.begin(),returns.end());
	return returns;
}
void solve(){
	int n;
	string s;
	cin>>n>>s;
	bool flag = true;
	if(s[0] != '9'){
		for(auto i:s){
			cout<<'9'-i;
		}
		cout<<'\n';
		return;
	}
	string ans = string(s.size()+1,'1');
	cout<<_minus(ans,s)<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

