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
	string s,t;
	cin>>s>>t;
	int tar = t.size();
	s = t+"$"+s;
	int n = s.size();
//	s = t;
	int z[n] = {};
	int l = -1,r = -1;
	z[0] = n;
	for(int i = 1;i<n;i++){
//		cout<<i<<' '<<l<<' '<<r<<endl;
		if(r<i){
			l = r = i;
		}
		if(i+z[i-l]<=r){
			z[i] = z[i-l];
			continue;
		}
		z[i] = r-i;
		while(z[i]+i<n&&s[z[i]+i] == s[z[i]])z[i]++;
		if(r<z[i]+i){
			l = i;
			r = z[i]+i-1;
		}
	}
//	cout<<s<<endl;
//	for(auto &i:z)cout<<i<<' ';
	int ans = 0;
	for(auto i:z)if(i == tar)ans++;
	cout<<ans;
	return 0;
}

