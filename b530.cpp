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
const int mxn = 3003;
bitset<mxn> a[mxn],b[mxn],c[mxn];
int main(){
//	auto s = clock();
	io
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			bool x;
			cin>>x;
			a[i][j] = x;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			bool x;
			cin>>x;
			b[j][i] = x;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			bool x;
			cin>>x;
			c[i][j] = x;
		}
	}
	for(int i = 0;i<n;i++){
		for(int j= 0;j<n;j++){
			int tmp = (a[i]&b[j]).count();
//			cout<<i<<' '<<j<<' '<<tmp<<endl;
			tmp = (tmp&1);
			if(tmp != c[i][j]){
			auto e = clock();
//			cout<<(ld)(e-s)/(CLOCKS_PER_SEC);
			cout<<"NO\n";
			return 0;
			}
		}
	}
//	auto e = clock();
//	cout<<(ld)(e-s)/(CLOCKS_PER_SEC);
	cout<<"YES\n";

}

