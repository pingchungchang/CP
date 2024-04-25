#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
int n,q;
string s;
int pref[mxn],suf[mxn];;

struct node{
	int stag,ptag,sval,pval;
	node(){}
};
node segtree[mxn*4];

void addval(int now,int l,int r,int s,int e,int v,int tp){
	if(l>=s&&e>=r){
		if(tp)segtree[now].stag += v;
		else segtree[now].ptag += v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=s)addval(now*2+1,l,mid,s,e,v,tp);
	if(mid<e)addval(now*2+2,mid+1,r,s,e,v,tp);
	segtree[now].pval = 
		min(segtree[now*2+1].pval+segtree[now*2+1].ptag,segtree[now*2+2].pval+segtree[now*2+2].ptag);
	segtree[now].sval = 
		min(segtree[now*2+1].sval+segtree[now*2+1].stag,segtree[now*2+2].sval+segtree[now*2+2].stag);
	return;
}

int getp(int now,int l,int r,int tar){
	if(segtree[now].ptag+segtree[now].pval>=tar)return mxn;
	if(l == r)return l;
	int mid = (l+r)>>1;
	if(tar-segtree[now].ptag>segtree[now*2+1].ptag+segtree[now*2+1].pval){
		return getp(now*2+1,l,mid,tar-segtree[now].ptag);
	}
	else return getp(now*2+2,mid+1,r,tar-segtree[now].ptag);
}
int gets(int now,int l,int r,int tar){
	if(segtree[now].stag+segtree[now].sval >= tar)return -1;
	if(l == r)return l;
	int mid = (l+r)>>1;
	if(tar-segtree[now].stag>segtree[now*2+2].stag+segtree[now*2+2].sval){
		return gets(now*2+2,mid+1,r,tar-segtree[now].stag);
	}
	else return gets(now*2+1,l,mid,tar-segtree[now].stag);
}

void pdfs(int now,int l,int r,int sh){
	if(l == r){
		cout<<sh+segtree[now].ptag+segtree[now].pval<<' ';
		return;
	}
	int mid = (l+r)>>1;
	pdfs(now*2+1,l,mid,sh+segtree[now].ptag);
	pdfs(now*2+2,mid+1,r,sh+segtree[now].ptag);
	return;
}

void sdfs(int now,int l,int r,int sh){
	if(l == r){
		cout<<sh+segtree[now].stag+segtree[now].sval<<' ';
		return;
	}
	int mid = (l+r)>>1;
	sdfs(now*2+1,l,mid,sh+segtree[now].stag);
	sdfs(now*2+2,mid+1,r,sh+segtree[now].stag);
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q>>s;
	for(int i = 0;i<n;i++){
		if(s[i] == '(')pref[i] = 1;
		else pref[i] = -1;
		if(i)pref[i] += pref[i-1];
		addval(0,0,n-1,i,i,pref[i],0);
	}
	for(int i = n-1;i>=0;i--){
		if(s[i] == ')')suf[i] = 1;
		else suf[i] = -1;
		if(i != n-1)suf[i] += suf[i+1];
		addval(0,0,n-1,i,i,suf[i],1);
	}
	set<int> sl,sr;
	for(int i = 1;i<n;i++){
		if(s[i] == s[i-1]&&s[i] == '(')sl.insert(i-1);
		if(s[i] == s[i-1]&&s[i] == ')')sr.insert(i-1);
	}
	while(q--){
		int c;
		cin>>c;
		if(n&1){
			cout<<"NO\n";
			continue;
		}
		c--;
		if(s[c] == ')'){
			addval(0,0,n-1,c,n-1,2,0);
			addval(0,0,n-1,0,c,-2,1);
		}
		else{
			addval(0,0,n-1,c,n-1,-2,0);
			addval(0,0,n-1,0,c,2,1);
		}
		if(c != n-1&&s[c] == s[c+1]){
			if(s[c] == '(')sl.erase(c);
			else sr.erase(c);
		}
		if(c != 0&&s[c] == s[c-1]){
			if(s[c] == '(')sl.erase(c-1);
			else sr.erase(c-1);
		}
		if(s[c] == '(')s[c] = ')';
		else s[c] = '(';
		//cout<<s<<':';
		//sdfs(0,0,n-1,0);
		if(c != n-1&&s[c] == s[c+1]){
			if(s[c] == '(')sl.insert(c);
			else sr.insert(c);
		}
		if(c != 0&&s[c] == s[c-1]){
			if(s[c] == '(')sl.insert(c-1);
			else sr.insert(c-1);
		}
		int a = getp(0,0,n-1,0);
		bool flag = true;
		//cout<<a<<' ';
		if(a != mxn&&(sl.empty()||*sl.begin()>a))flag = false;
		a = gets(0,0,n-1,0);
		if(a != -1&&(sr.empty()||*sr.rbegin()<a))flag = false;
		/*
		cout<<a<<' ';
		cout<<":";for(auto &i:sl)cout<<i<<',';cout<<":";for(auto &i:sr)cout<<i<<',';
		for(auto &i:sl)assert(s[i] == s[i+1]);

	   */
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
