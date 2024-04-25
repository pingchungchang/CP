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
#pragma GCC optimize("O3")
int n;
const int mxn = 3e5+10;
int arr[mxn],buf[mxn],mx[mxn];
struct node{
	int dp;
	node* pl,*pr;
	node(){
		pl = pr = 0;
		dp = 0;
	}
};
void clean(node* now){
	if(!now)return;
//	if(!now||(rand()&1))return;
	clean(now->pl);clean(now->pr);
	free(now);
	return;
}
node * trie;
ll ans = 0;

void add(int k){
	node* now = trie;
	for(int i = 24;i>=0;i--){
		if(k&(1<<i)){
			if(!now->pr){
				now->pl = new node();
				now->pr = new node();
			}
			now = now->pr;
		}
		else{
			if(!now->pl){
				now->pl = new node();
				now->pr = new node();
			}
			now = now->pl;
		}
		now->dp++;
	}
	return;
}
const int sz = 500;
void dc(int l,int r){
	if(l == r)return;
	if(r-l+1<=sz){
		for(int i = l;i<=r;i++){
			int big = arr[i];
			for(int j = i+1;j<=r;j++){
				big = max(big,arr[j]);
				if((arr[i]^arr[j])>=big)ans++;
			}
		}
		return;
	}
	int mid = (l+r)>>1;
	dc(l,mid);
	dc(mid+1,r);
	trie = new node();
	int big = 0;
	int p = mid+1;
	for(int i = mid;i>=l;i--){
		big = max(big,arr[i]);
		while(p<=r&&arr[p]<=big)p++;
		buf[i] = p;
		mx[i] = big;
	}
	p = mid+1;
	for(int i = mid;i>=l;i--){
		while(p<buf[i]){
			add(arr[p]);
			p++;
		}
		auto now = trie;
		for(int j = 24;j>=0;j--){
			if(!now->pl)break;
			if(mx[i]&(1<<j)){
				if(arr[i]&(1<<j))now = now->pl;
				else now = now->pr;
			}
			else{
				if(arr[i]&(1<<j)){
					ans += now->pl->dp;
					now = now->pr;
				}
				else{
					ans += now->pr->dp;
					now = now->pl;
				}
			}
			if(j == 0)ans += now->dp;
		}
	}
	clean(trie);
	trie = new node();
	big = 0;
	p = mid;
	for(int i = mid+1;i<=r;i++){
		big = max(big,arr[i]);
		while(p>=l&&arr[p]<big)p--;
		buf[i] = p;
		mx[i] = big;
	}
	p = mid;
//	cout<<l<<' '<<r<<' '<<ans<<":";
	for(int i = mid+1;i<=r;i++){
		while(p>buf[i]){
			add(arr[p]);
			p--;
		}
		auto now = trie;
		for(int j = 24;j>=0;j--){
			if(!now->pl)break;
			if(mx[i]&(1<<j)){
				if(arr[i]&(1<<j))now = now->pl;
				else now = now->pr;
			}
			else{
				if(arr[i]&(1<<j)){
					ans += now->pl->dp;
					now = now->pr;
				}
				else{
					ans += now->pr->dp;
					now = now->pl;
				}
			}
			if(j == 0)ans += now->dp;
		}		
	}
	clean(trie);
//	for(int i = mid+1;i<=r;i++)cout<<buf[i]<<' ';cout<<endl; 
	return;
}
int main(){
	io
	srand(time(NULL));
	cin>>n;
	for(int i= 0;i<n;i++)cin>>arr[i];
	dc(0,n-1);
	cout<<ans;
	
}
/*
7
61 40 8 87 56 53 66
*/
