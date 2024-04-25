#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	string a,b;
	cin>>a>>b;
	int cnt[26] = {};
	int s1 = 0,s2 = 0;
	for(auto &i:a){
		if(i == '@')s1++;
		else cnt[i-'a']++;
	}
	for(auto &i:b){
		if(i == '@')s2++;
		else cnt[i-'a']--;
	}
	set<char> st;
	string tt = "atcoder";
	for(auto &i:tt)st.insert(i);
	for(int i = 0;i<26;i++){
		if(st.find(i+'a') == st.end()&&cnt[i]){
			cout<<"No";
			return;
		}
		if(cnt[i]>0){
			if(s2<cnt[i]){
				cout<<"No";
				return;
			}
			s2 -= cnt[i];
		}
		else if(cnt[i]<0){
			cnt[i] = -cnt[i];
			if(s1<cnt[i]){
				cout<<"No";
				return;
			}
			s1 -= cnt[i];
		}
	}
	cout<<"Yes";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
