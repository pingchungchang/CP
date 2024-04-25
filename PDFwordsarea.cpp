#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int arr[26];
    for (int i = 0; i < 26;i++){
        cin >> arr[i];
    }
    string s;
    cin >> s;
    int m=0;
    for (int i = 0; i < s.size();i++){
         m = max(arr[s[i] - 'a'], m);
    }
    cout << m * s.size();
}