#include <cstdio>
#include <vector>
using namespace std;

#define mid ((l+r)>>1)

const int mxn = 2.5e6+10;
vector<int>segtree;
vector<int> arr;
vector<int> rl,rr;
int n,m;

int max(int a,int b){
	return a>=b?a:b;
}

void build(int now,int l,int r){
	if(l == r){
		segtree[now] = arr[l];
		return;
	}
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
}
int getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r){
		return segtree[now];
	}
	if(mid>=e)return getval(now*2+1,l,mid,s,e);
	else if(mid<s)return getval(now*2+2,mid+1,r,s,e);
	else return max(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e));
}

int main(){
	scanf("%d%d",&n,&m);
	segtree = vector<int>(n*4);
	arr = vector<int>(n+1);
	rl = rr = vector<int>(m+1);
	for(int i = 0;i<m;i++){
		scanf("%d%d",&rl[i],&rr[i]);
	}
	for(int i = 1;i<=n;i++)scanf("%d",&arr[i]);
	build(0,1,n);
	for(int i = 0;i<m;i++){
		printf("%d\n",getval(0,1,n,rl[i],rr[i]));
	}
	return 0;
}

