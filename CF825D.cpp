#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int rest = 0;
string s,t;
int cnt[26];
int cnt2[26];

bool check(int tar){
	ll C = 0;
	for(int i = 0;i<26;i++){
		C += max(0ll,1ll*cnt2[i]*tar-cnt[i]);
	}
	//cout<<tar<<":"<<C<<'\n';
	return C<=rest;
}

void getans(int tar){
	string need;
	for(int i = 0;i<26;i++){
		while(1ll*cnt2[i]*tar>cnt[i]){
			need += 'a'+i;
			cnt[i]++;
		}
	}
	for(auto &i:s){
		if(i == '?'){
			if(need.empty())i = 'a';
			else{
				i = need.back();
				need.pop_back();
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>t;
	for(auto &i:s)if(i != '?')cnt[i-'a']++;else rest++;
	for(auto &i:t)cnt2[i-'a']++;
	int l = 0,r = s.size();
	while(l != r){
		int mid = (l+r+1)>>1;
		if(check(mid))l = mid;
		else r = mid-1;
	}
	getans(l);
	cout<<s;
}
