#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }
};

int map[6][6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        Point startPoint(1, 1);
        Point endPoint(5, 5);
        vector<vector<bool>> visited(6, vector<bool>(6, false));
        
        for (int r = 1; r <= 5; r++) {
            for (int c = 1; c <= 5; c++) {
                cin >> map[r][c];
                if (map[r][c] == 1) {
                    visited[r][c] = true;
                }
            }
        }
        
        map[5][5] = 0;
        visited[5][5] = false;
        
        queue<Point> Q;
        if (map[1][1] == 0) {
            Q.push(startPoint);
        }
        
        bool isFound = false;
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        
        while (!Q.empty()) {
            Point p = Q.front();
            Q.pop();
            
            if (p == endPoint) {
                isFound = true;
                break;
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i], ny = p.y + dy[i];
                if (nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5 && map[nx][ny] == 0 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    Q.push(Point(nx, ny));
                }
            }
        }
        
        cout << (isFound ? "COPS" : "ROBBERS") << "\n";
    }
    
    return 0;
}

