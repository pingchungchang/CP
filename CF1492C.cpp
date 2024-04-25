#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	string a,b;
	cin>>a>>b;
	int l[m] = {};
	int r[m] = {};
	int p = 0;
	for(int i = 0;i<n;i++){
		if(p == m)break;
		if(a[i] == b[p]){
			l[p] = i;
			p++;
		}
	}
	p = m-1;
	for(int i = n-1;i>=0;i--){
		if(p == -1)break;
		if(a[i] == b[p]){
			r[p] = i;
			p--;
		}
	}
	int ans = 0;
	for(int i = 1;i<m;i++){
		ans = max(ans,r[i]-l[i-1]);
	}
	cout<<ans;
}
