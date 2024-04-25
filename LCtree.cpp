#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
typedef long double ld;
typedef long long ll;

const int mod1 = 39989;
const int mod2 = 1e9;
const int mxn = 40000;
struct line{
	bool used;
	ld a;
	ld b;
	line(){
		used = false;
	}
	line(int sx,int sy,int ex,int ey){
		used = true;
		a = (sx == ex?INT_MAX:(double)(sy-ey)/(sx-ex));
		b = (sx == ex?max(sy,ey):(ld)sy-sx*a);
	}
	ld operator()(ld x){
		return (a == INT_MAX?b:a*x+b);
	}
	ld operator()(int x){
		return (a == INT_MAX?b:a*x+b);
	}
};
line segtree[mxn*4];
void add(int now,int l,int r,int s,int e,line v){
	if(s<l||e>r)return;
	int mid = (l+r)/2;
	if(l>=s&&e<=r){
		if(segtree[now].used ==false){
			segtree[now] = v;
			segtree[now].used = true;
			return;
		}
		else if(segtree[now](l)>v(l)&&segtree[now](r)>v(r)){
			segtree[now] = v;
		}
		else if(segtree[now](l)>v(l)||segtree[now](r)>v(r)){
			ld p1 = segtree[now](mid),p2 = v(mid);
			if(p2>p1){
				swap(segtree[now],v);
				if(segtree[now].a>v.a){
					add(now*2+1,l,mid,s,e,v);
				}
				else{
					add(now*2+2,mid+1,r,s,e,v);
				}
			}
			else{
				if(v.a>segtree[now].a){
					add(now*2+2,mid+1,r,s,e,v);
				}
				else add(now*2+2,l,mid,s,e,v);
			}
		}
		return;
	}
	else{
		add(now*2+1,l,mid,s,e,v);
		add(now*2+2,mid+1,r,s,e,v);
	}
}
int getval(int now,int l,int r,int pos){
	if(l == r)return (int)segtree[now](pos);
	int mid = (l+r)/2;
	if(mid>=pos){
		return max((int)segtree[now](pos),getval(now*2+1,l,mid,pos));
	}
	else{
		return max((int)segtree[now](pos),getval(now*2+2,mid+1,r,pos));
	}
}
int main(){
	int n;
	cin>>n;
	int lastans = 0;
	for(int i = 0;i<n;i++){
		int op;
		cin>>op;
		if(op == 1){
			int sx,sy,ex,ey;
			cin>>sx>>sy>>ex>>ey;
			sx = (lastans+sx)%mod1+1,ex = (lastans+ex)%mod1+1;
			sy = (lastans+sy)%mod2+1,ey = (lastans+ey)%mod2+1;
			add(0,0,mxn,sx,ex,line(sx,sy,ex,ey));
		}
		else{
			int pos;
			cout<<getval(0,0,mxn,pos)<<'\n';
		}
	}
}
/*
6 
1 8 5 10 8 
1 6 7 2 6 
0 2 
0 9 
1 4 7 6 7 
0 5
*/ 
