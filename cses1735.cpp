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
int main(){
	io
	string a,b;
	cin>>a>>b;
	a = b+"#"+a;
	int z[a.size()] = {};
	int r = 0;
	int l = 0;
	for(int i = 1;i<a.size();i++){
		if(r>i&&z[i-l]<=r-i+1){
			z[i] = z[i-l];
		}
		else{
			if(r<i){
				l = r = i;
			}
			bool flag = false;
			while(r != a.size()&&a[r] == a[r-i]){
				flag = true;
				r++;
			}
			if(flag){
				r--;
				l = i;
			}
			z[i] = r-i+1;
		}
	}
	int ans = 0;
//	for(auto &i:z)cout<<i<<' ';cout<<endl;
	for(int i = 1;i<a.size();i++)if(z[i] >= b.size())ans++;
	cout<<ans;	
}

