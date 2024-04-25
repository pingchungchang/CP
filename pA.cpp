#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vector<char> ans(n,'X');
	multiset<char> st;
	for(int i = 0;i<n;i++){
		if(b[i] == a[i]){
			ans[i] = 'M';
		}
		else st.insert(a[i]);
	}
	for(int i = 0;i<n;i++){
		if(ans[i] == 'X'){
			if(st.find(b[i]) != st.end()){
				st.erase(st.find(b[i]));
				ans[i] = 'P';
			}
			else ans[i] = 'N';
		}
	}
	for(char c:ans)cout<<c;
}
