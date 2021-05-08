#include <string>
#include <vector>
#include <queue>

using namespace std;

// 상, 좌, 하, 우
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int cost[26][26];

int solution(vector<vector<int>> board) {
    int answer = 100000000;
    int N = board[0].size();
    for(int i = 0; i < N; i++) {
        fill(cost[i], cost[i] + N, N*N*500);
    }

    queue<pair<int, pair<int, int>>> q;

    cost[0][0] = 0;
    q.push({7, {0, 0}});
    while(!q.empty()) {
        int cur_dir = q.front().first;
        int cur_y = q.front().second.first;
        int cur_x = q.front().second.second;
        q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int ny = cur_y + dy[dir];
            int nx = cur_x + dx[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue; // 범위 벗어나는 경우
            if(board[nx][ny]) continue; // 벽이 있는 경우
            // 최초 설정 - ny, nx의 검증이 끝난 후에 실행 + 반대 방향 거르는 로직이 먼저 나올 경우 4-2 == 2, 즉 최초 아래 방향으로는 안 가버림. (cur_dir 최초 수를 좀 더 크게 설정하면 순서 상관x)
            // if(cur_dir == 4) {
            //     if(dir == 2 || dir == 3) {
            //         cost[ny][nx] = 100;
            //         q.push({dir, {ny, nx}});
            //     }
            //     continue;
            // }
            if(abs(cur_dir - dir) == 2) continue; // 반대 방향

            // 최초 설정 - ny, nx의 검증이 끝난 후에 실행 + 반대 방향 거르는 로직이 먼저 나올 경우 4-2 == 2, 즉 최초 아래 방향으로는 안 가버림. (cur_dir 최초 수를 좀 더 크게 설정하면 순서 상관x)
            if(cur_dir == 7) {
                if(dir == 2 || dir == 3) {
                    cost[ny][nx] = 100;
                    q.push({dir, {ny, nx}});
                }
                continue;
            }

            // ** cost의 대소비교를 >, < 로만 하면, 같은 값이 배제됨 -> 입출력#3의 경우 최적 경로(아래, 오른쪽, 오른쪽, ...)가 배제되고 다른 경로(오른쪽, 아래, 오른쪽, ...)가 채택. 체크 잘 하기!
            // 같은 방향
            if(cur_dir == dir) {
                if(cost[ny][nx] >= cost[cur_y][cur_x] + 100) {
                    cost[ny][nx] = cost[cur_y][cur_x] + 100;
                    q.push({dir, {ny, nx}});
                }
                else continue;
            }
            // 다른 방향
            else {
                if(cost[ny][nx] >= cost[cur_y][cur_x] + 600) {
                    cost[ny][nx] = cost[cur_y][cur_x] + 600;
                    q.push({dir, {ny, nx}});
                }
                else continue;
            }
        }
    }
    answer = cost[N-1][N-1];
    return answer;
}