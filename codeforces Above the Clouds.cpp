#include <bits/stdc++.h>
using namespace std;

//a1~an-1 must be identical
int main(){
    int tc, n;
    
    string s;
    cin>>tc;
    while(tc--){
        cin>>n;
        cin>>s;

        map<char, bool> map;
        bool no_duplicate = true;
        for(int i = 1 ; i < s.size()-1 ; i++){
            if(map[s[i]]){
                no_duplicate = false;
                break;
            }
            map[s[i]] = true;
        }
        for(int i = 1 ; i < s.size()-1 ; i++){
            if(s[i] == s[0] || s[i] == s[s.size()-1]){
                no_duplicate = false;
                break;
            }
        }

        if(no_duplicate)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}