#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n;
	cin>>n;
	vector<int> v(n+2,INT_MAX);
	v[0] = 0;
	for(int i = 1;i<=n;i++){
		cin>>v[i];
	}
	int s = -1,e = -1;
	for(int i = 1;i<=n;i++){
		if(v[i]>v[i-1]&&v[i]>v[i+1])s = i;
		else if(v[i]<v[i-1]&&v[i]<v[i+1])e = i;
	}
	reverse(v.begin()+s,v.begin()+e+1);
	for(int i = 1;i<=n;i++){
		if(v[i]<v[i-1]){
			cout<<"no";
			return 0;
		}
	}
	cout<<"yes\n";
	if(s == -1)cout<<1<<' '<<1;
	else cout<<s<<' '<<e;
	
}

