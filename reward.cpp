#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> oprnd;
vector<char> op;

void mul() {
    for(int i = 0; i < op.size(); i++) {
        if(op[i] == '*') {
            oprnd[i] = oprnd[i] * oprnd[i+1];
            vector<long long>::iterator oprnd_iter = oprnd.begin();
            oprnd_iter += i+1;
            oprnd.erase(oprnd_iter);
            vector<char>::iterator op_iter = op.begin();
            op_iter += i;
            op.erase(op_iter);
            i--;
        }
    }
}

void add() {
    for(int i = 0; i < op.size(); i++) {
        if(op[i] == '+') {
            oprnd[i] = oprnd[i] + oprnd[i+1];
            vector<long long>::iterator oprnd_iter = oprnd.begin();
            oprnd_iter += i+1;
            oprnd.erase(oprnd_iter);
            vector<char>::iterator op_iter = op.begin();
            op_iter += i;
            op.erase(op_iter);
            i--;
        }
    }
}

void sub() {
    for(int i = 0; i < op.size(); i++) {
        if(op[i] == '-') {
            oprnd[i] = oprnd[i] - oprnd[i+1];
            vector<long long>::iterator oprnd_iter = oprnd.begin();
            oprnd_iter += i+1;
            oprnd.erase(oprnd_iter);
            vector<char>::iterator op_iter = op.begin();
            op_iter += i;
            op.erase(op_iter);
            i--;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;

    int exp_i = 0;
    for(int i = 0; i < expression.size(); i++) {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            op.push_back(expression[i]);
            oprnd.push_back(stoll(expression.substr(exp_i, i)));
            exp_i = i+1;
        }
    }
    oprnd.push_back(stoll(expression.substr(exp_i, expression.size()))); // 마지막 피연산자 배열에 담기

    long long ans = 0;
    
    // 전역변수로 하면 한번에 값이 망가지니까 임시 변수로 6가지 경우 다 해줄 것.
    vector<long long> tmp_oprnd = oprnd;
    vector<char> tmp_op = op;
    mul();
    add();
    sub();
    ans = abs(oprnd[0]);
    if(answer < ans) answer = ans;

    oprnd = tmp_oprnd;
    op = tmp_op;
    mul();
    sub();
    add();
    ans = abs(oprnd[0]);
    if(answer < ans) answer = ans;

    oprnd = tmp_oprnd;
    op = tmp_op;
    add();
    mul();
    sub();
    ans = abs(oprnd[0]);
    if(answer < ans) answer = ans;

    oprnd = tmp_oprnd;
    op = tmp_op;
    add();
    sub();
    mul();
    ans = abs(oprnd[0]);
    if(answer < ans) answer = ans;

    oprnd = tmp_oprnd;
    op = tmp_op;
    sub();
    mul();
    add();
    ans = abs(oprnd[0]);
    if(answer < ans) answer = ans;

    oprnd = tmp_oprnd;
    op = tmp_op;
    sub();
    add();
    mul();
    ans = abs(oprnd[0]);
    if(answer < ans) answer = ans;
    

    return answer;
}