#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

struct node{
	pii ran;
	int id;
	int ans;
	node(){}
};
int g;
int val;
unordered_map<int,int> mp;
int n,A,B;
int v[(int)2*100000+7] = {};
int l,r;
inline bool cmp(const node& a,const node& b){
	if(a.ran.f/g != b.ran.f/g)return a.ran.f<b.ran.f;
	else{
		if(((a.ran.f/g)&1)){
			return a.ran.s<b.ran.s;
		}
		else return a.ran.s>b.ran.s;
	}
}
inline bool cmp2(const node& a,const node& b){
	return a.id<b.id;
}
inline void add(int a){
	if(mp.count(v[a]) == 0)mp[v[a]] =1;
	else mp[v[a]]++;
	int k = mp[v[a]];
	if(k == A){
		val+= v[a];
	}
	else if(k == B+1)val -= v[a];
}
inline void sub(int a){
	mp[v[a]]--;
	int k = mp[v[a]];
	if(k == A-1)val -= v[a];
	else if(k == B)val += v[a];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>A>>B;
	g = sqrt(n);
	for(int i = 1;i<=n;i++)cin>>v[i];
	int q;
	cin>>q;
	node req[q];
	for(int i =0 ;i<q;i++){
		cin>>req[i].ran.f>>req[i].ran.s;
		req[i].id = i;
	}
	sort(req,req+q,cmp);
	l = 0;
	r = 0;
	mp[0] = 1;
	val =0;
	for(int i = 0;i<q;i++){
		node& now = req[i];
		while(l > now.ran.f)add(--l);
		while(l < now.ran.f)sub(l++);
		while(r < now.ran.s)add(++r);
		while(r > now.ran.s)sub(r--);
		now.ans = val;
	}
	sort(req,req+q,cmp2);
	for(int i = 0;i<q;i++){
		cout<<req[i].ans<<'\n';
	}
	return 0;
}
