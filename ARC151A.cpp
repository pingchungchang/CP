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
const int mxn = 2e5+10;
bitset<mxn> same;
int main(){
	io
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == t[i])same[i] = true;
		else cnt++;
	}
	if(cnt&1){
		cout<<"-1";
		return 0;
	}
	pii p = {0,0};
	cnt /=2;
	string re(n,'0');
	for(int i = 0;i<n;i++){
		if(s[i] == t[i]){
			re[i] = '0';
		}
		else{
			if(p.fs == cnt){
				p.sc++;
				re[i] = s[i];
			}
			else if(p.sc == cnt){
				p.fs++;
				re[i] = t[i];
			}
			else{
				re[i] = '0';
				if('0' != s[i])p.fs++;
				else if('0' != t[i])p.sc++;
//				cout<<i<<',';
			}
		}
	}
	cout<<re;
}

