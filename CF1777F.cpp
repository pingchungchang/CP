#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

//testing if this magic works the best of all
const int magic = 960;
const int mxn = 2e5+10;
struct node{
	int pl,pr,sum;
	node(){}
};
node trie[mxn*80];
int ppp = 0;
int arr[mxn];
int n;
int ans = 0;
int mx[mxn],rt[mxn];
int pref[mxn];

int newnode(int src = 0){
	ppp++;
	trie[ppp] = trie[src];
	return ppp;
}

int addval(int r,int val){
	r = newnode(r);
	int now = r;
	for(int i = 30;i>=0;i--){
		if(val&(1<<i)){
			trie[now].pr = newnode(trie[now].pr);
			now = trie[now].pr;
		}
		else{
			trie[now].pl = newnode(trie[now].pl);
			now = trie[now].pl;
		}
		trie[now].sum++;
	}
	return r;
}

int getval(int r,int val){
	int re = 0;
	int now = r;
	for(int i = 30;i>=0;i--){
		if(val&(1<<i)){
			if(trie[now].pl)re^=1<<i,now = trie[now].pl;
			else now = trie[now].pr;
		}
		else{
			if(trie[now].pr)re ^= 1<<i,now = trie[now].pr;
			else now = trie[now].pl;
		}
	}
	return re;
}

void dc(int l,int r){
	/*
	if(r-l<=magic){
		for(int i = l-1;i<=r;i++){
			int big = 0;
			for(int j = i+1;j<=r;j++){
				big = max(big,arr[j]);
				ans = max(ans,pref[i]^pref[j]^big);
			}
		}
		return;
	}

   */
	if(l == r){
		return;
	}

	int mid = (l+r)>>1;
	dc(l,mid);
	dc(mid+1,r);

	mx[mid] = arr[mid];
	for(int i = mid-1;i>=l;i--){
		mx[i] = max(mx[i+1],arr[i]);
	}
	ppp = 0;
	rt[l] = newnode();
	rt[l] = addval(rt[l],pref[l-1]^mx[l]);
	for(int i = l+1;i<=mid;i++){
		rt[i] = addval(rt[i-1],pref[i-1]^mx[i]);
	}
	int pt = mid;
	int big = 0;
	for(int i = mid+1;i<=r;i++){
		big = max(big,arr[i]);
		while(pt>=l&&mx[pt]<big)pt--;
		if(pt>=l)ans = max(ans,getval(rt[pt],pref[i]));
	}

	mx[mid+1] = arr[mid+1];
	for(int i = mid+2;i<=r;i++)mx[i] = max(mx[i-1],arr[i]);
	ppp = 0;
	rt[r] = newnode();
	rt[r] = addval(rt[r],pref[r]^mx[r]);
	for(int i = r-1;i>mid;i--){
		rt[i] = addval(rt[i+1],pref[i]^mx[i]);
	}
	pt = mid+1;
	big = 0;
	for(int i = mid;i>=l;i--){
		big = max(big,arr[i]);
		while(pt<=r&&mx[pt]<big)pt++;
		if(pt<=r){
			int tans = max(ans,getval(rt[pt],pref[i-1]));
			ans = max(ans,tans);
			//cout<<l<<' '<<mid<<' '<<r<<":"<<i<<","<<pt<<':'<<tans<<endl;
		}
	}
	return;
}

void solve(){
	int r = newnode();
	cin>>n;
	ans = 0;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)pref[i] = arr[i]^pref[i-1];
	dc(1,n);
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
