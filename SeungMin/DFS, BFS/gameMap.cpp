#include<vector>
#include<queue>
using namespace std;

bool visited[101][101];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 1));
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) return cnt;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // �̷� ã�� ������ ��� ��� ����
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // ���� ��� ����
            if (maps[nx][ny] == 0) continue;
            if (visited[nx][ny] == false && maps[nx][ny] == 1)
            {
                visited[nx][ny] = true;
                q.push(make_pair(make_pair(nx, ny), cnt + 1));
            }
        }

    }
    return -1;
}