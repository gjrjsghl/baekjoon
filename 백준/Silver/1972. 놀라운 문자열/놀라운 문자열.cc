#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    while(1) {
            
        std::string s;
        std::cin >> s;
        if(s == "*") return 0;
        bool surprise = 1;
        for(int d = 0;d<=(int)s.size()-2;d++) {
            std::set<std::string> cnt;
            for(int i = 0;i+d+1 < s.size();i++) {
                int before = cnt.size();
                std::string t = "";
                t += s[i];
                t += s[i+d+1];
                cnt.insert(t);
                if(cnt.size() == before) {
                    surprise = 0;
                    break;
                }
            }
            if(surprise == 0) break;
        }
        std::cout << s <<" is " << (surprise==0?"NOT ":"") <<"surprising.\n";  
    }
    return 0;
}