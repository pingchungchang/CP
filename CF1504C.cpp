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
	int n;
	cin>>n;
	string s;
	cin>>s;
	n = s.size();	
	string a(n,'#'),b(n,'#');
	int cnt = 0;
	bool flag = true;
	for(int i = 0;i<n;i++)if(s[i] == '1')cnt++;
	if(cnt&1)flag = false;
	if(n&1)flag = false;
	cnt /=2;
	for(int i = 0;i<s.size();i++){
		if(s[i] == '1'&&cnt>0)a[i] = b[i] = '(';
		else if(s[i] == '1')a[i] = b[i] = ')';
		else cnt++;
		cnt--;
	}
	bool now = false;
	for(int i = 0;i<n;i++){
		if(s[i] == '0'){
			if(now){
				a[i] = '(';
				b[i] = ')';
			}
			else{
				a[i] = ')';
				b[i] = '(';
			}
			now ^=1;
		}
	}
//	cout<<a<<' '<<b<<' '<<flag<<'\n';return;
	cnt = 0;
	for(int i = 0;i<n;i++){
		if(a[i] == '(')cnt++;
		else cnt--;
		if(cnt<0)flag = false;
	}
	if(cnt != 0)flag = false;
	cnt = 0;
	for(auto i:b){
		if(i == '(')cnt++;
		else cnt--;
		if(cnt<0)flag = false;
	}
	if(cnt != 0)flag = false;
	if(flag){
		cout<<"YES\n"<<a<<'\n'<<b<<'\n';
	}
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

