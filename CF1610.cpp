#include <bits/stdc++.h>
using namespace std;

vector<int> v;
bool rec(int p1,int p2,int c){
//	cout<<p1<<' '<<p2<<' '<<c<<endl;
	if(p1>p2)return true;
	if(v[p1] == v[p2])return rec(p1+1,p2-1,c);
//	cout<<"001";
	if(v[p1] == c)return rec(p1+1,p2,c);
//	cout<<"002";
	if(v[p2] == c)return rec(p1,p2-1,c);
//	cout<<"003";
	if(c == -1){
		return (rec(p1,p2,v[p1])||rec(p1,p2,v[p2]));
	}
//	cout<<"004";
	return false;
}
void solve(){
	int n;
	cin>>n;
	set<int> st;
	v.resize(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	int p1 =0,p2 = n-1;
	bool ans = rec(0,n-1,-1);
	if(ans == true)cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		solve();
	}
}
