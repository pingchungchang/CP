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

set<string> st;
int ans[3] = {};
string s;
int turn = 0;
int win(){
	for(int i = 0;i<3;i++){
		if(s[i] == s[i+3]&&s[i] == s[i+6]&&s[i] != '-'){
			return (s[i] == 'O'?1:2);
		}
		if(s[i*3] == s[i*3+1]&&s[i*3] == s[i*3+2]&&s[i*3] != '-'){
			return (s[i*3] == 'O'?1:2);
		}
	}
	if(s[0] == s[4] && s[4] == s[8]&&s[0] != '-')return (s[0] == 'O'?1:2);
	if(s[2] == s[4] && s[4] == s[6] && s[2] != '-')	return (s[2] == 'O'?1:2);
	return 0;
}
void inter(){
	for(int i = 0;i<=2;i++){
		for(int j= 0;j<=2;j++)cout<<s[i*3+j];cout<<endl;
	}
	cout<<endl;
}
void dfs(){
	int k = win();
	if(st.find(s) != st.end())return;
	st.insert(s);
//	cout<<turn<<' '<<k<<endl;
//	inter();
	if(k != 0){
		ans[k]++;
//		cout<<k<<endl;
//		inter();
		return;
	}
	bool flag = true;
	for(int i = 0;i<9;i++){
		if(s[i] == '-'){
			flag = false;
			s[i] = (turn == 1?'X':'O');
			turn ^=1;
			dfs();
			turn ^=1;
			s[i] = '-';
		}
	}
	if(flag){
		ans[0]++;
//		cout<<0<<endl;
//		inter();
	}
	return;
}
int main(){
	io
	cin>>s;
	pii cnt = {0,0};
	for(auto &i:s){
		if(i == 'O')cnt.fs++;
		else if(i == 'X')cnt.sc++;
	}
	if(cnt.fs == cnt.sc)turn = 0;
	else turn = 1;
	dfs();
	cout<<ans[0]+ans[1]+ans[2]<<' '<<ans[1]<<' '<<ans[2]<<' '<<ans[0];
}

