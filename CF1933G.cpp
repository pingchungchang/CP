#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

/*
8 kinds:
ooxx

xxoo

oxxo

xoox

oxox
oxox
xoxo
xoxo

oxox
xoxo
xoxo
oxox


xoxo
xoxo
oxox
oxox

xoxo
oxox
oxox
xoxo

*/

inline bool check(int num,int r,int c,int t){
	int tar = 0;
	switch(num){
		case 1:
			if((r%2==0&&c%4>=2)||(r%2==1&&c%4<=1))tar=1;
			break;
		case 2:
			if((r%2==0&&c%4<=1)||(r%2==1&&c%4>=2))tar=1;
			break;
		case 3:
			if((r%2==0&&(c%4==1||c%4==2))||(r%2==1&&(c%4==0||c%4==3)))tar=1;
			break;
		case 4:
			if((r%2==0&&(c%4==0||c%4==3))||(r%2==1&&(c%4==1||c%4==2)))tar=1;
			break;
		case 5:
			if(((r%4==0||r%4==1)&&(c%2==1))||((r%4==2||r%4==3)&&(c%2==0)))tar=1;
			break;
		case 6:
			if(((r%4==0||r%4==3)&&(c%2==1))||((r%4==1||r%4==2)&&(c%2==0)))tar=1;
			break;
		case 7:
			if(((r%4==0||r%4==1)&&(c%2==0))||((r%4==2||r%4==3)&&(c%2==1)))tar=1;
			break;
		case 8:
			if(((r%4==0||r%4==3)&&(c%2==0))||((r%4==1||r%4==2)&&(c%2==1)))tar=1;
			break;
	}
	//cout<<num<<','<<r<<' '<<c<<":"<<tar<<':'<<t<<'\n';
	return tar == t;
}

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	vector<int> v;
	for(int i = 1;i<=8;i++){
		v.push_back(i);
	}
	cout<<v.size()<<'\n';
	while(q--){
		int r,c,t;
		string s;
		cin>>r>>c>>s;
		r--,c--;
		t = (s[0] == 'c'?0:1);
		vector<int> vv;
		for(auto &i:v){
			if(check(i,r,c,t))vv.push_back(i);
		}
		swap(vv,v);
		//for(auto &i:v)cout<<i<<',';
		cout<<v.size()<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
