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
	string t = "*";
	for(auto &i:s){
		t += i;
		t += '*';
	}
	int l = -1,r = -1;
	int n = t.size();
	int z[n] = {};
	z[0] = 1;
	int ans = 0;
	for(int i = 1;i<n;i++){
//		cout<<i<<' '<<l<<' '<<r<<',';
		if(r<i){
			l = r = i;
		}
		if(l != i&&i+z[l*2-i]<r){
			z[i] = z[l*2-i];
			continue;
		}
		z[i] = r-i;
		while(i+z[i]<n&&i-z[i]>=0&&t[i+z[i]] == t[i-z[i]])z[i]++;
		if(r<i+z[i]){
			l = i;
			r = z[i]+i-1;
		}
		if(z[i]>=z[ans])ans = i;
	}
//	cout<<endl;
	string re;
	for(int i = ans-z[ans]+1;i<ans+z[ans];i++){
		if(t[i] == '*')continue;
		re += t[i];
	}
//	cout<<t<<endl;
//	for(auto i:z)cout<<i<<' ';cout<<endl;
	cout<<re;
}

