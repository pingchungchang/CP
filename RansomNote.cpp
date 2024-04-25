#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    string word1,word2;
    unordered_map<string,int> map;
    for(int i =0;i<a;i++){
        cin>>word1;
        if(map.count(word1) == 0){
            map[word1] =1;
        }
        else{
            map[word1] ++;
        }
    }
    for(int i =0;i<b;i++){
        cin>>word2;
        if(map.count(word2) == 0||map[word2] <=0){
            cout<<"No";
            return 0;
        }
        else{
            map[word2]--;
        }
    }
    cout<<"Yes";
    return 0;
}
