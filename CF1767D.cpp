#include <bits/stdc++.h>
using namespace std;


#define mid ((l+r)>>1)
const int mxn = 1<<18;
string s;
int tree[mxn*4],tag[mxn*4];
int c1 = 0,c2 = 0;

void dfs1(int now,int l,int r,int dep){
	if(l == r)return;
	if(tag[now] == 2){
		if(s[dep] == '0')tag[now*2+1] = 2,tag[now*2+2] = 3;
		else tag[now*2+2] = 2,tag[now*2+1] = 1;
		dfs1(now*2+1,l,mid,dep+1);
		dfs1(now*2+2,mid+1,r,dep+1);
	}
	else if(tag[now] == 1){
		tag[now*2+1] = 1;
		dfs1(now*2+1,l,mid,dep+1);
		if(s[dep] == '1'){
			tag[now*2+2] = 1;
			dfs1(now*2+2,mid+1,r,dep+1);
		}
	}
	else{
		tag[now*2+2] = 3;
		dfs1(now*2+2,mid+1,r,dep+1);
		if(s[dep] == '0'){
			tag[now*2+1] = 3;
			dfs1(now*2+1,l,mid,dep+1);
		}
	}
	return;
}
void dfs2(int now,int l,int r){
	if(l == r){
		//cout<<l<<":"<<tag[now]<<'\n';
		if(tag[now] == 1)c1++;
		if(tag[now] == 3)c2++;
		return;
	}
	dfs2(now*2+1,l,mid);
	dfs2(now*2+2,mid+1,r);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n>>s;
	reverse(s.begin(),s.end());
	tag[0] = 2;
	dfs1(0,1,(1<<n),0);
	dfs2(0,1,(1<<n));
	for(int i = c1+1;i<=(1<<n)-c2;i++)cout<<i<<' ';
	return 0;
}
