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
map<char,int> mp;
int main(){
	io
	int cnt = 10;
	for(char c = 'A';c <= 'H';c++){
		mp[c] = cnt++;
	}
	mp['I'] = 34;
	for(char c = 'J';c <='N';c++)mp[c] = cnt++;
	mp['O'] = 35;
	for(char c = 'P';c<='Z';c++)mp[c] = cnt++;
	mp['W'] = 32;mp['X'] = 30;mp['Y'] = 31;mp['Z'] = 33;
	string s;
	cin>>s;
	cnt = 8;
	int total = 0;
	for(auto i:s){
		total += (int)(i-'0')*cnt;
		cnt--;
	}
//	for(auto i:mp)cout<<i.fs<<' '<<i.sc<<endl;
	for(auto i:mp){
		int tmp = i.sc/10+i.sc%10*9;
		if((10-(tmp+total)%10)%10 == s.back()-'0')cout<<i.fs;
	}
	return 0;
}

