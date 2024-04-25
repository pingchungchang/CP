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


vector<int> v;
void dc(int l,int r){
	if(l == r)return;
	int mid = (l+r)/2;
	dc(l,mid);
	dc(mid+1,r);
	vector<int> lv,rv;
	for(int i = l;i<=mid;i++)lv.push_back(v[i]);
	for(int i = mid+1;i<=r;i++)rv.push_back(v[i]);
	int p1= l,p2 = mid+1;
	int now =l;
	while(p1 <= mid&&p2 <= r){
		if(lv[p1-l]<=rv[p2-mid-1]){
			v[now++] = lv[p1-l];
			p1++;
		}
		else{
			v[now++] = rv[p2-mid-1];
			p2++;
		}
	}
	for(;p1 <= mid;p1++)v[now++] = lv[p1-l];
	for(;p2<=r;p2++)v[now++] = rv[p2-mid-1];
//	cout<<l<<' '<<r<<endl;
//	for(int i = 0;i<v.size();i++)cout<<v[i]<<" ";cout<<","<<now;cout<<endl;
	return;
}

int main(){
	io
	ll n;
	cin>>n;
	v = vector<int>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	dc(0,n-1);
	for(int i = 0;i<n;i++)cout<<v[i]<<' ';
}

