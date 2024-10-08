// 2615번 오목: https://www.acmicpc.net/problem/2615
#include <iostream>
#include <vector>

using namespace std;

// 1. 바둑판 2차원 벡터로 받아줄 것
typedef vector<vector<int>> matrix;
// 2. 바둑판 개수를 상수로 선언 - 19개인데 index 가 1번부터 시작되므로
const int SIZE = 20, EMPTY = 0;

// 10. 방향에 따른 좌표 증가량
// 맨 왼쪽 위 돌을 기준으로 검사하기 때문에 오른쪽+아래쪽으로 향하는 방향만 정의
const vector<int> dx = {-1, 0, 1, 1};
const vector<int> dy = {1, 1, 1, 0};

/**
 * 16. 범위와 돌의 종류가 유효한지 확인한다.
*/
bool isValid(matrix &board, int x, int y, int color) {
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color);
}

/**
 * 9. 해당 좌표(x, y)부터 연속적으로 5알이 놓이는지 확인한다.
*/
bool checkWin(matrix &board, int x, int y) {
    int color = board[x][y]; // 기준 색

    // 11. 방향에 대해 검사
    for (int idx = 0; idx < 4; idx++) {
        int cnt = 1;    // 12. cnt: 같은 방향에 놓인 같은 색 돌의 수
        int prev_x = x - dx[idx], prev_y = y - dy[idx]; // 13. 탐색하는 반대 방향
        int next_x = x + dx[idx], next_y = y + dy[idx]; // 14. 탐색하는 방향

        // 15. 같은 방향에서 그 이전에도 같은 색 돌이 있었다면 패스 (-> 여섯 알 이상 놓이는 경우를 제외하기 위함)
        if (isValid(board, prev_x, prev_y, color)) {
            continue;
        }

        // 16. 연속적으로 놓인 5알이 같은 색인지 확인
        while (isValid(board, next_x, next_y, color) && cnt < 6) {
            next_x += dx[idx];
            next_y += dy[idx];
            cnt++;
        }
        // 17. cnt가 5일 때만 true 리턴 (-> 다섯 알보다 적거나 다섯 알보다 많이 놓이는 경우를 제외)
        if (cnt == 5) {
            return true;
        }
    }
    // 18. 승리하지 않았을 경우
    return false;
}

int main() {
    // 입력
    // 3. 바둑판 선언 
    matrix board(SIZE, vector<int>(SIZE, 0)); // 바둑판
    // 4. 입력 받기 - 1번부터 시작
    for (int i = 1; i < SIZE; i++)
        for (int j = 1; j < SIZE; j++)
            cin >> board[i][j];

    // 5. 연산 및 출력
    for (int y = 1; y < SIZE; y++) {
        for (int x = 1; x < SIZE; x++) {
            // 6. 빈 칸이면 패스
            if (board[x][y] == EMPTY) {
                continue;
            }
            // 7. 해당 좌표(x, y)부터 연속적으로 5알이 놓였다면 정답 출력
            if (checkWin(board, x, y)) {
                cout << board[x][y] << '\n' // 어떤 색깔이 이겼는지
                     << x << ' ' << y; // 위에 있는 좌표 출력
                return 0;
            }
        }
    }
    cout << 0; // 8. 승리가 결정되지 않았다면

    return 0;
}
