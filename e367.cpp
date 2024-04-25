#include <bits/stdc++.h>
using namespace std;

const int lim = 1e5+1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> v(lim,0);
	vector<int> pref(lim,0);
	for(int i =1;i<lim;i++){
		v[i] = v[i-1]^i;
		pref[i+1] = pref[i]^v[i];
	}
	int a,b;
	while(cin>>a>>b){
		cout<<(pref[b+1]^pref[a])<<'\n';
	}
}


//#include <bits/stdc++.h>
//using namespace std;
//
//int lim = 1e5+1;
//int segtree[400004] = {0};
//void maketree(int val,int pos,int now,int l,int r){
//	if(l==r){
//		segtree[now]=val;
//		return;
//	}
//	int mid = (l+r)/2;
//	if(mid<pos){
//		maketree(val,pos,now*2+2,mid+1,r);
//	}
//	else{
//		maketree(val,pos,now*2+1,l,mid);
//	}
//	segtree[now] = segtree[now*2+1]^segtree[now*2+2];
//	return;
//}
//int findval(int s,int e,int now,int l,int r){
//	if(s ==e&&l==r){
//		return segtree[now];
//	}
//	int mid = (l+r)/2;
//	if(mid<s){
//		return findval(s,e,now*2+2,mid+1,r);
//	}
//	else if(mid>=e){
//		return findval(s,e,now*2+1,l,mid);
//	}
//	else{
//		return findval(s,mid,now*2+1,l,mid)^findval(mid+1,e,now*2+2,mid+1,r);
//	}
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	vector<int> v(lim,0);
//	for(int i =1;i<lim;i++){
//		v[i] = v[i-1]^i;
//		maketree(v[i],i,0,0,lim-1);
//	}
//	int a,b;
//	cout<<endl;
//	while(cin>>a>>b){
//		cout<<findval(a,b,0,0,lim-1)<<'\n';
//	}
//}


