#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 44;
int n;
int arr[mxn];
pii trie[20*(1<<16)];
int ppp = 0;
int root;

int newnode(){
	ppp++;
	trie[ppp].fs = trie[ppp].sc = 0;
	return ppp;
}

void add(int k){
	int now = root;
	for(int i = 20;i>=0;i--){
		if((1<<i)&k){
			if(!trie[now].fs)trie[now].fs = newnode();
			now = trie[now].fs;
		}
		else{
			if(!trie[now].sc)trie[now].sc = newnode();
			now = trie[now].sc;
		}
	}
	return;
}

int getval(int k){
	int re = 0;
	int now = root;
	for(int i = 20;i>=0;i--){
		if((1<<i)&k){
			if(trie[now].sc)now = trie[now].sc,re^=1<<i;
			else now = trie[now].fs;
		}
		else{
			if(trie[now].fs)now = trie[now].fs,re^=1<<i;
			else now = trie[now].sc;
		}
	}
	return re;
}

void solve(){
	if(!n)exit(0);
	ppp = 0;
	root = newnode();
	int ans = 0;
	int mid = (n-1)/2;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<(1<<(mid+1));i++){
		int tmp = 0;
		for(int j = 0;j<=mid;j++){
			if((1<<j)&i)tmp^=arr[j];
		}
		add(tmp);
		ans = max(ans,tmp);
	}
	int len = n-mid;
	for(int i = 0;i<(1<<len);i++){
		int tmp = 0;
		for(int j = mid+1;j<n;j++){
			if((1<<(j-mid-1))&i)tmp^=arr[j];
		}
		ans = max(ans,tmp);
		ans = max(ans,getval(tmp));
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
