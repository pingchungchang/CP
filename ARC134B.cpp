#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	string ss = s;
	sort(ss.begin(),ss.end());
	int l = 0,r = n-1;
	while(l <r){
		if(s[l] == ss[l]){
			l++;
		}
		else{
			while(l<r&&s[r] != ss[l])r--;
			swap(s[l],s[r]);
			r--;
			l++;
		}
//		cout<<s;
	}
	cout<<s;
}
