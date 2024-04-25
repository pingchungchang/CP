#include <bits/stdc++.h>
using namespace std;

bool v[200001] = {};
int main(){
	for(int i = 1;i<2*1000;i++){
		for(int j = i+1;j<1000;j++){
			for(int k = j+1;k<1000;k++){
				if(i*j+j*k+i*k>200000)break;
				v[i*j+j*k+i*k] = true;
			}
		}
	}
	int now = 0;
	vector<int> ans;
	for(int i =1;i<=200000;i++){
		if(v[i] == false){
			ans.push_back(i);
			if(ans.size()>=65)break;
		}
	}
	int n;
	cin>>n;
	cout<<ans[n-1];
	return 0;
}
