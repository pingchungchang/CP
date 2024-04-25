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
int main(){
	io
	string s;
	cin>>s;
	int n = s.size();
	int pi[n] = {};
	int z[n] = {};
	
	if(n>1&&s[0] == s[1])pi[1] = 1;
	for(int i = 2;i<n;i++){
		int pt = pi[i-1];
		while(pt > 0&&s[pt] != s[i]){
			pt = pi[pt-1];
		}
		if(pt<=0&&s[0]!= s[i])pi[i] = 0;
		else{
			pi[i] = pt+1;
		}
	}
	
	int l = 0,r = 0;
	for(int i = 1;i<n;i++){
		if(r<i){
			l = r = i;
		}
		if(l != i&&r-i>=z[i-l])z[i] = z[i-l];
		else{
			l = i;
			while(s[r] == s[r-i])r++;
			z[i] = r-l;
			r--;
		}
	}
	for(auto &i:z)cout<<i<<' ';cout<<'\n';
	for(auto &i:pi)cout<<i<<' ';
}

