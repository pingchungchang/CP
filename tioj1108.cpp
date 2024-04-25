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
string a,b;
int n;
struct node{
	char val;
	node *pl,*pr;
	node(){
		pl = pr = 0;
		val = '#';
	}
	node(char c){
		val = c;
		pl = pr = 0;
	}
};
void clean(node* now){
	if(!now)return;
	clean(now->pl);
	clean(now->pr);
	free(now);
	return;
}
node* build(int l,int r,int &p1){
	if(r<l)return 0;
	int p2 = l;
	p1++;
//	cout<<l<<' '<<r<<' '<<p1<<endl;
	auto tmp = new node(a[p1]);
	while(b[p2] != a[p1])p2++;
	tmp->pl = build(l,p2-1,p1);
	tmp->pr = build(p2+1,r,p1);
	return tmp;
}
void postdfs(node* now){
	if(!now)return;
	postdfs(now->pl);
	postdfs(now->pr);
	cout<<now->val;
	return;
}
void pv(node* now){
	if(!now)return;
	cout<<now->val;if(now->pl)cout<<now->pl->val;if(now->pr)cout<<now->pr->val;
	cout<<endl;
	pv(now->pl);pv(now->pr);
	return;
}
void indfs(node* now){
	if(!now)return;
	indfs(now->pl);cout<<now->val;indfs(now->pr);return;
}
void predfs(node* now){
	if(!now)return;
	cout<<now->val;
	predfs(now->pl);predfs(now->pr);
	return;
}
void solve(){
	n = a.size();
	int p1 = -1;
	auto now = build(0,n-1,p1);
	postdfs(now);cout<<'\n';
//	pv(now);
	clean(now);
	return;
}
int main(){
	while(cin>>a>>b)solve();
}

