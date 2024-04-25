#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

ll mod = 1e9+7;
ll n;
struct mat{
	ll vals[2][2];
	mat(){
		for(int i = 0;i<2;i++)for(int j = 0;j<2;j++)vals[i][j] = 0;
	}
	mat(int a,int b,int c,int d){
		vals[0][0] =a,vals[0][1] = b,vals[1][0] = c,vals[1][1] = d;
	}
	mat operator=(const mat& b){
		for(int i = 0;i<2;i++)for(int j = 0;j<2;j++)vals[i][j] = b.vals[i][j];
		return b;
	}
	mat operator*(const mat& b){
		mat re(0,0,0,0);
		for(int i = 0;i<2;i++){
			for(int j = 0;j<2;j++){
				for(int k = 0;k<2;k++){
					re.vals[i][j] += vals[i][k]*b.vals[k][j];
					re.vals[i][j]%= mod;
				}
			}
		}
		return re;
	}
};
ostream& operator<<(ostream& out,const mat& m){
	for(int i = 0;i<2;i++){
		for(int j = 0;j<2;j++)out<<m.vals[i][j]<<' ';
		out<<'\n';
	}
	return out;
}
struct node{
	mat val;
	node *pl,*pr;
	ll l,r;
	node(ll s,ll e){
		l = s;r = e;
		pl = pr = 0;
		val = mat();
	}
};


void addval(node* now,ll p,mat v){
	if(now->l == now->r){
		now->val = v;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(!now->pr){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p)addval(now->pl,p,v);
	else addval(now->pr,p,v);
	now->val = now->pl->val*now->pr->val;
	return;
	
}
mat getval(node* now,ll s,ll e){
	if(now->l>=s&&now->r<=e)return now->val;
	ll mid = (now->l+now->r)/2;
	if(mid>=e)return getval(now->pl,s,e);
	else if(mid<s)return getval(now->pr,s,e);
	else return getval(now->pl,s,e)*getval(now->pr,s,e);
}
int main(){
	io
	ll q;
	cin>>mod>>n>>q;
	node* segtree = new node(1,n);
	for(int i = 1;i<=n;i++){
		mat tmp;
		for(auto &a:tmp.vals)for(auto &b:a){
			cin>>b;
			b %= mod;
		}
		addval(segtree,i,tmp);
	}
	
	while(q--){
		ll s,e;
		cin>>s>>e;
		cout<<getval(segtree,s,e)<<'\n';
	}
}

