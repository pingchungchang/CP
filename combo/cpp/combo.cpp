#include "combo.h"
#include <iostream>
using namespace std;

string ans;

int ask(string &s){
	return press(s);
}

void BIN(string s,string pool){
	int l = 0,r = pool.size()-1;
	while(l != r){
		int mid = (l+r)>>1;
		string tmp;
		for(int i = l;i<=mid;i++)tmp += s+pool[i];
		if(ask(tmp) != s.size())r = mid;
		else l = mid+1;
	}
	ans += pool[l];
	return;
}

std::string guess_sequence(int N) {
	string pool = "ABXY";
	BIN(ans,pool);
	string tt;
	for(auto &i:pool){
		if(i != ans[0])tt += i;
	}
	swap(tt,pool);
	for(int i = 1;i+1<N;i++){
		string tmp = ans+pool[0]+pool[0]+ans+pool[0]+pool[1]+ans+pool[0]+pool[2]+ans+pool[1];
		int re = ask(tmp);
		if(re == i)ans += pool[2];
		else if(re == i+1)ans += pool[1];
		else ans += pool[0];
	}
	if(N != 1)BIN(ans,pool);
	return ans;
}
