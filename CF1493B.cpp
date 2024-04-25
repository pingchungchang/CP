#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
map<char,char> mp;

int h,m;
pii f(pii tmp){
	string s1 = to_string(tmp.fs);
	while(s1.size()<2)s1 = "0"+s1;
	string s2 = to_string(tmp.sc);
	while(s2.size()<2)s2 = "0"+s2;
	swap(s2[0],s2[1]);
	swap(s1[0],s1[1]);
	swap(s1,s2);
	for(auto &i:s1){
		if(mp.count(i) == 0)return {-1,-1};
		i = mp[i];
	}
	for(auto &i:s2){
		if(mp.count(i) == 0)return {-1,-1};
		i = mp[i];
	}
	tmp.fs = stoi(s1);
	tmp.sc = stoi(s2);
	if(tmp.fs<h&&tmp.sc<m)return tmp;
	else return {-1,-1};
}

void solve(){
	cin>>h>>m;
	string s;
	cin>>s;
	pii now = make_pair(stoi(s.substr(0,2)),stoi(s.substr(3,2)));
	bool flag = true;
	while(flag){
		auto tmp = f(now);
		if(tmp.fs != -1){
			tmp = now;
			cout<<(tmp.fs/10 == 0?"0":"")<<tmp.fs<<":"<<(tmp.sc/10 == 0?"0":"")<<tmp.sc<<'\n';
			flag = false;
			return;
		}
		now.sc++;
		now.fs += now.sc/m;
		now.sc %= m;
		now.fs %= h;
	}
}

int main(){
	io
	mp['1'] = '1';
	mp['2'] = '5';
	mp['5'] = '2';
	mp[':'] = ':';
	mp['0'] = '0';
	mp['8'] = '8';
	int t;
	cin>>t;
	while(t--)solve();
}

