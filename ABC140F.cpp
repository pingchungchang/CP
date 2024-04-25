#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[1<<n];
	int sz = 1<<n;
	multiset<int> st;
	for(int i = 0;i<sz;i++){
		cin>>arr[i];
		st.insert(arr[i]);
	}
	vector<int> v;
	v.push_back(*st.rbegin());
	st.erase(st.find(*st.rbegin()));
	for(int i = 0;i<n;i++){
		auto it = st.rbegin();
		vector<int> choose;
		for(auto &j:v){
			while(it != st.rend()&&*it>=j){
				it++;
			}
			if(it == st.rend()){
				cout<<"No";
				return 0;
			}
			choose.push_back(*it);
			it++;
		}
		for(auto &j:choose){
			v.push_back(j);
			st.erase(st.find(j));
		}
		sort(v.rbegin(),v.rend());
	}
	cout<<"Yes";
	return 0;
}
