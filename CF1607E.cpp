#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
void solve(){
	int n,m;
	string s;
	cin>>n>>m>>s;
	int mx = 0,my = 0,sx = 0,sy = 0;
	pii now = make_pair(0,0);
	int k = s.size();
	for(int i = 0;i<k;i++){
		if(s[i] == 'L')now.second--;
		else if(s[i] == 'R')now.second++;
		else if(s[i] == 'U')now.first--;
		else now.first++;
		mx = max(now.first,mx);
		my = max(now.second,my);
		sx = min(now.first,sx);
		sy = min(now.second,sy);
		if(mx+abs(sx)>=n||my+abs(sy)>=m){
			if(s[i] == 'L')sy++;
			else if(s[i] == 'R')my--;
			else if(s[i] == 'U')sx++;
			else mx--;
			break;
		}
	}
	cout<<abs(sx)+1<<' '<<abs(sy)+1<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
