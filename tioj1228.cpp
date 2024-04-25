#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#pragma GCC optimize("O3")
inline char readchar(){
	const int S = 1<<16;
	static char buf[S], *p = buf, *q = buf;
	return p == q and (q = (p = buf) + fread(buf, 1, S, stdin)) == buf ? EOF : *p++;
}
inline int R(int &a){
	static char c;
	while(((c = readchar()) < '0' or c > '9') and c != '-' and c != EOF);
	if(c == '-'){
		a = 0;
		while((c = readchar()) >= '0' and c <= '9') a *= 10, a -= c ^ '0';
	} else {
		a = c ^ '0';
		while((c = readchar()) >= '0' and c <= '9') a *= 10, a += c ^ '0';
	}
}

const int mxn= 1e6+10;
ll bit[mxn*2];
void modify(int p,int v){
	for(;p<mxn*2;p += p&-p)bit[p]+=v;
	return;
}
ll getval(int s,int e){
	ll re= 0;
	for(;e>0;e -= e&-e){
		re += bit[e];
	}
	s--;
	for(;s>0;s -= s&-s)re -= bit[s];
	return re;
}
vector<int> tree[mxn];
ll arr[mxn];
pll stamp[mxn];
ll p = 1;
int lst = 0;
int pt[mxn];
struct edge{
	int dir,next;
	edge(){
		dir = next = 0;
	}
} E[mxn];
void insert(int s,int e){
	lst++;
	E[lst].dir = e;
	E[lst].next = pt[s];
	pt[s] = lst;
	return;
}
void dfs(int now){
	stamp[now].fs = p++;
	modify(stamp[now].fs,arr[now]);
	int tmp = pt[now];
	while(tmp > 0){
		dfs(E[tmp].dir);
		tmp = E[tmp].next;
	}
	stamp[now].sc = p++;
	modify(stamp[now].sc,arr[now]);
	return;
}
int main(){
	io
	int n,q;
	R(n);
	R(q);
	for(int i = 0;i<n-1;i++){
		int a,b,c;
		R(a);R(b),R(c);
		insert(a,b);
		arr[b] = c;
	}
	dfs(0);
	while(q--){
		int t;
		R(t);
		if(t == 1){
			int k;
			R(k);
			cout<<getval(stamp[k].fs,stamp[k].sc)-arr[k]*2<<'\n';
		}
		else{   
			ll a,b;
			R(a);R(b);
			modify(stamp[a].fs,b-arr[a]);
			modify(stamp[a].sc,b-arr[a]);
			arr[a] = b;
		}
	}
//	cout<<lst<<endl;
	return 0;
}

