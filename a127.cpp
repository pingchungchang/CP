#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	multiset<int> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
	}
	int pre = *st.begin()-1;
	bool ans= true;
	for(auto it:st){
		if(it-pre != 1)ans = false;
		pre = it;
	}
	cout<<*st.begin()<<' '<<*st.rbegin()<<" ";
	if(ans)cout<<"yes";
	else cout<<"no";
}

