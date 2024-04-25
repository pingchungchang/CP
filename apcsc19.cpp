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


void f(string &ss,int l,int r){
	if((r-l+1)&1)return;
	int mid = (l+r)/2;
	f(ss,l,mid);
	f(ss,mid+1,r);
	string s = ss.substr(l,mid-l+1);
	string t = ss.substr(mid+1,r-mid);
	if(s+t>t+s){
		for(int i = l;i<=mid;i++)swap(ss[i],ss[i+mid-l+1]);
	}
	return;
}
int main(){
	string a,b;
	cin>>a>>b;
	f(a,0,a.size()-1);
	f(b,0,b.size()-1);
//	cout<<a<<' '<<b<<endl;
	if(a == b)cout<<"YES";
	else cout<<"NO";
}

