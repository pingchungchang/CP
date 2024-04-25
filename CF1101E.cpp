#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	io
	int t;
	cin>>t;
	pll now = make_pair(0,0);
	for(int i = 0;i<t;i++){
		char c;
		cin>>c;
		if(c == '?'){
			pll tmp;
			cin>>tmp.fs>>tmp.sc;
			if(tmp.fs<tmp.sc)swap(tmp.fs,tmp.sc);
			if(tmp.fs>=now.fs&&tmp.sc>=now.sc){
				cout<<"YES\n";
			}
			else cout<<"NO\n";
		}
		else{
			pll tmp;
			cin>>tmp.fs>>tmp.sc;
			if(tmp.fs<tmp.sc)swap(tmp.fs,tmp.sc);
			now.fs = max(now.fs,tmp.fs);
			now.sc = max(now.sc,tmp.sc);
		}
	}
}

