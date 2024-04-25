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

void solve(){
	string a,b;
	cin>>a>>b;
	int ta = 1,tb = 1;
	for(auto &i:a){
		if(i == 'X')ta++;
		else if(i == 'M')ta *= 0;
		else if(i == 'S')ta *= -1;
	}
	for(auto &i:b){
		if(i == 'X')tb++;
		else if(i == 'M')tb = 0;
		else if(i == 'S')tb *= -1;
	}
	cout<<(ta == tb?"=\n":(ta>tb?">\n":"<\n"));
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

