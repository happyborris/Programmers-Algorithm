#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> s_root;
    int len = gems.size();

    // 집합 만들기
    
    for(int i = 0; i < gems.size(); i++) {
        s_root.insert(gems[i]);
    }

    for(int i = 0; i < gems.size() - s_root.size() + 1; i++) {
        set<string> s(s_root);
        for(int j = i; j < gems.size(); j++) {
            if(s.end() != s.find(gems[j])) s.erase(s.find(gems[j]));
            if(s.empty()) {
                if(len > j - i) {
                    len = j - i;
                    answer.clear();
                    answer.push_back(i+1);
                    answer.push_back(j+1);
                    break;
                }
            }
        }
    }

    return answer;
}

int main() {
    vector<string> test = {"DIA", "EM", "EM", "RUB", "DIA"};
    cout << solution(test)[0] << ", " << solution(test)[1];
}