#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> odd;
	vector<int> even;
	int n;
	cin>>n;
	for(int i  =0;i<n;i++){
		int k;
		cin>>k;
		if(k%2 == 0)even.push_back(i+1);
		else odd.push_back(i+1);
	}
	if(even.size()== 1)cout<<even[0];
	else cout<<odd[0];
}
