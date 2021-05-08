#include <string>
#include <vector>

using namespace std;

pair<int, int> lf = {3, 0};
pair<int, int> rf = {3, 2};

bool isLeft(int n, string hand) {
    int left, right, left_r = lf.first, left_c = lf.second, right_r = rf.first, right_c = rf.second;
    switch(n) {
        case 2:
            left = left_r + 1-left_c;
            right = right_r + right_c-1;
            if(left < right) {
                lf = {0, 1};
                return true;
            }
            if(left > right) {
                rf = {0, 1};
                return false;
            }
            if(hand == "left") {
                lf = {0, 1};
                return true;
            }
            rf = {0, 1};
            return false;

        case 5:
            left = abs(left_r-1) + 1-left_c;
            right = abs(right_r-1) + right_c-1;
            if(left < right) {
                lf = {1, 1};
                return true;
            }
            if(left > right) {
                rf = {1, 1};
                return false;
            }
            if(hand == "left") {
                lf = {1, 1};
                return true;
            }
            rf = {1, 1};
            return false;

        case 8:
            left = abs(left_r-2) + 1-left_c;
            right = abs(right_r-2) + right_c-1;
            if(left < right) {
                lf = {2, 1};
                return true;
            }
            if(left > right) {
                rf = {2, 1};
                return false;
            }
            if(hand == "left") {
                lf = {2, 1};
                return true;
            }
            rf = {2, 1};
            return false;

        case 0:
            left = abs(left_r-3) + 1-left_c;
            right = abs(right_r-3) + right_c-1;
            if(left < right) {
                lf = {3, 1};
                return true;
            }
            if(left > right) {
                rf = {3, 1};
                return false;
            }
            if(hand == "left") {
                lf = {3, 1};
                return true;
            }
            rf = {3, 1};
            return false;
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    for(int i = 0; i < numbers.size(); i++) {
        switch(numbers[i]) {
            case 1:
                answer.append("L");
                lf = {0, 0};
                break;
                
            case 4:
                answer.append("L");                
                lf = {1, 0};
                break;

            case 7:
                answer.append("L");               
                lf = {2, 0};
                break;

            case 3:
                answer.append("R");               
                rf = {0, 2};
                break;

            case 6:
                answer.append("R");               
                rf = {1, 2};
                break;

            case 9:
                answer.append("R");              
                rf = {2, 2};
                break;

            default :
                if(isLeft(numbers[i], hand)) answer.append("L");
                else answer.append("R");
                break;
        }
    }
    return answer;
}