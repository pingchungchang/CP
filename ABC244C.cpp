#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	set<int> st;
	for(int i = 2;i<=2*n+1;i++)st.insert(i);
	int k;
	cout<<1<<endl;
	while(cin>>k){
		if(k == 0)return 0;
		st.erase(k);
		cout<<*st.begin()<<endl;
		st.erase(st.begin());
	}
}

