#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    string str;
    int total=0;
    getline(cin, str);
    getline(cin, str);
    unordered_map<string, int> dict;
    while(getline(cin,str)){
        if(str.size()==0){
            for(auto it = dict.begin(); it!=dict.end(); it++){
                
            }   
        }
        else{
            dict[str]++;
            total++;
        }
    }
}