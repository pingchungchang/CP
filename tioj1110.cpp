#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		int biggest =0;
		int v[26] = {};
		int x;
		cin>>x;
		for(int i =0;i<x;i++){
			char c;
			cin>>c;
			v[c-'a']++;
			biggest = max(biggest,v[c-'a']);
		}
		for(int i =0;i<26;i++){
			if(v[i] == biggest)cout<<(char)('a'+i);
		}
		cout<<'\n';
	}
}
