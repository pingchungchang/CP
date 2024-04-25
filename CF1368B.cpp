#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll k;
	cin>>k;
	string s = "codeforces";
	int cnt[s.size()] = {};
	for(auto &i:cnt)i = 1;
	ll now = 1;
	int pt = 0;
	while(now<k){
		now = now/cnt[pt]*(cnt[pt]+1);
		cnt[pt++]++;
		if(pt == s.size())pt = 0;
	}
	for(int i = 0;i<s.size();i++){
		while(cnt[i]--)cout<<s[i];
	}
}
