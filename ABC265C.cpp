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
	int h,w;
	cin>>h>>w;
	vector<string> v(h);
	for(int i = 0;i<h;i++){
		cin>>v[i];
	}
	bool flag = true;
	pii now = {0,0};
	while(1){
		if(v[now.fs][now.sc] == '#'){
			flag = false;
			break;
		}
		pii pre = now;
		if(v[now.fs][now.sc] == 'U'){
			if(now.fs != 0)now.fs--;
			else break;
		}
		if(v[now.fs][now.sc] == 'D'){
			if(now.fs != h-1)now.fs++;
			else break;
		}
		if(v[now.fs][now.sc] == 'L'){
			if(now.sc != 0)now.sc--;
			else break;
		}
		if(v[now.fs][now.sc] == 'R'){
			if(now.sc != w-1)now.sc++;
			else break;
		}
		v[pre.fs][pre.sc] = '#';
	}
	if(flag){
		cout<<now.fs+1<<' '<<now.sc+1;
	}
	else cout<<-1;
}

