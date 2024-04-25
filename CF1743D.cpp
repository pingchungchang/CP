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
const int mxn = 1e6+10;
string ans;
string calc(string a,int l,int len){
	if(l+len>a.size())return "0";
//	cout<<a<<' '<<a.substr(l,len)<<endl;
	for(int i = a.size()-1;i>=a.size()-len;i--){
		a[i] = max(a[i],a[l+len-(a.size()-i)]);
	}
//	cout<<endl;
//	cout<<a<<endl;
	return a;
}
int main(){
	io
	int n;
	cin>>n;
	string a,b;
	cin>>a;
	ans = "0";
	bool done = false;
	bool flag = false;
	for(int i = 0;i<n&&!done;i++){
		if(a[i] == '1')flag = true;
		if(flag&&a[i] == '0'){
//			cout<<i;
			for(int j = 0;j<i;j++){
				ans = max(ans,calc(a,j,n-i));
//				cout<<a.substr(j,n-i)<<endl;
			}
			done = true;
		}
	}
	flag = false;
	for(int i = 0;i<n;i++){	
		if(a[i] == '1')flag = true;
		if(flag)cout<<ans[i];
	}
	if(!flag)cout<<"0";
}

