#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	multiset<int> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
	}
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		if(st.find(k) == st.end()){
			cout<<"No";
			return 0;
		}
		st.erase(st.find(k));
	}
	cout<<"Yes";
	return 0;
}
