#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

struct point{
	int x,y,z;
	point(){}
	point(int xx,int yy,int zz){
		x = xx,y = yy,z = zz;
	}
	bool operator<(point b){
		return x != b.x?x<b.x:y != b.y?y<b.y:z<b.z;
	}
};

inline bool inter(pair<pii,pii> a,pair<pii,pii> b){
	if(a.fs.fs>b.fs.fs)swap(a,b);
	if(a.sc.fs>=b.fs.fs&&a.sc.fs<=b.sc.fs&&a.fs.sc>=b.fs.sc&&a.fs.sc<=b.sc.sc)return true;
	if(a.sc.fs>=b.fs.fs&&a.sc.fs<=b.sc.fs&&a.sc.sc>=b.fs.sc&&a.sc.sc<=b.sc.sc)return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	pair<point,point> arr[n];
	for(auto &i:arr)cin>>i.fs.x>>i.fs.y>>i.fs.z>>i.sc.x>>i.sc.y>>i.sc.z;
	vector<int> v[101];
	for(int i = 0;i<n;i++){
		v[arr[i].sc.x].push_back(i);
	}
	int ans[n] = {};
	for(int i = 0;i<n;i++){
		for(auto &j:v[arr[i].fs.x]){
			pair<pii,pii> ta,tb;
			ta = make_pair(make_pair(arr[i].fs.y,arr[i].fs.z),make_pair(arr[i].sc.y,arr[i].sc.z));
			tb = make_pair(make_pair(arr[j].fs.y,arr[j].fs.z),make_pair(arr[j].sc.y,arr[j].sc.z));
			if(inter(ta,tb)){
				ans[i]++;
				ans[j]++;
			}
		}
	}
	for(auto &i:v)i.clear();
	for(int i = 0;i<n;i++)v[arr[i].sc.y].push_back(i);
	for(int i = 0;i<n;i++){
		for(auto &j:v[arr[i].fs.y]){
			pair<pii,pii> ta,tb;
			ta = make_pair(make_pair(arr[i].fs.x,arr[i].fs.z),make_pair(arr[i].sc.x,arr[i].sc.z));
			tb = make_pair(make_pair(arr[j].fs.x,arr[j].fs.z),make_pair(arr[j].sc.x,arr[j].sc.z));
			if(inter(ta,tb)){
				ans[i]++;
				ans[j]++;
			}
		}
	}
	for(auto &i:v)i.clear();
	for(int i = 0;i<n;i++)v[arr[i].sc.z].push_back(i);
	for(int i = 0;i<n;i++){
		for(auto &j:v[arr[i].fs.z]){
			pair<pii,pii> ta,tb;
			ta = make_pair(make_pair(arr[i].fs.x,arr[i].fs.y),make_pair(arr[i].sc.x,arr[i].sc.y));
			tb = make_pair(make_pair(arr[j].fs.x,arr[j].fs.y),make_pair(arr[j].sc.x,arr[j].sc.y));
			if(inter(ta,tb)){
				ans[i]++;
				ans[j]++;
			}
		}
	}
	for(auto &i:ans)cout<<i<<'\n';
	return 0;
}
