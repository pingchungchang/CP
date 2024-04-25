#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int n,m;
string s,t;
queue<int> q;

inline bool check(int st){
	bool re = false;
	for(int i = 0;i<m;i++){
		if(s[st+i] == t[i])re = true;
		if(s[st+i] == t[i]||s[st+i] == '#')continue;
		else return false;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s>>t;
	for(int i = 0;i+m<=n;i++){
		if(s.substr(i,m) == t)q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(int i = 0;i<m;i++){
			s[now+i] = '#';
		}
		for(int i = -m*2;i<=m*2;i++){
			if(now+i<0||now+i+m>n)continue;
			if(check(i+now)){
				for(int j = 0;j<m;j++)s[i+now+j] = '#';
				q.push(i+now);
			}
		}
	}
	for(auto &i:s){
		if(i != '#'){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
