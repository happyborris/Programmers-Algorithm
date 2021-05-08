#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    // answer 초기화
    answer.push_back(0);
    answer.push_back(0);
    set<string> s;

    // 집합 만들기
    for(int i = 0; i < gems.size(); i++) {
        s.insert(gems[i]);
    }

    int kind = s.size(); // 보석 종류

    int l = 0, r = 0;
    int len = 100001;
    map<string, int> m;
    m[gems[0]]++;

    while(true) {
        if(m.size() == kind) { // 보석 종류가 다 있는 경우
            // 더 짧은 길이면 answer 갱신, 같으면 시작 숫자가 더 낮은걸 채택
            if(len > r - l) {
                len = r - l;
                answer[0] = l + 1;
                answer[1] = r + 1;
            }
            m[gems[l]]--;
            if(m[gems[l]] == 0) m.erase(gems[l]); // 0이 됐다 -> 보석이 안 남았다 -> 종류에서 제거.
            l++;
        }
        else if(m.size() < kind) { // 보석 종류가 부족한 경우
            r++;
            if(gems.size() == r) break; // 끝까지 돌았으면 종료
            m[gems[r]]++;
        }
    }
    return answer;
}