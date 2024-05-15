#include <bits/stdc++.h>
using namespace std;

int query(string s);

string guess(int N,int S){
	string tans;
	vector<int> cnt(S,0);
	for(int i = 0;i<S;i++){
		string tmp(N,'a'+i);
		cnt[i] = query(tmp);
	}
	for(int i = 0;i<N;i++){
		char tar;
		for(int j = 0;j<S;j++){
			if(cnt[j]){
				tar = 'a'+j;
				break;
			}
		}
		for(int j = tar-'a'+1;j<S;j++){
			if(!cnt[j])continue;
			string tmp = tans+tar+string(cnt[j],'a'+j);
			if(query(tmp) != tmp.size())tar = 'a'+j;
		}
		tans += tar;
		cnt[tar-'a']--;
	}
	return tans;
}
