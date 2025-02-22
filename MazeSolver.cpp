#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;
const char WALL = '#';
const char EMPTY = '.';
const char START = 'S';
const char END = 'E';
const char PATH = '*';

int Directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void GenerateMaze(vector<vector<char>>& Maze) {
    srand(time(0));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Maze[i][j] = (rand() % 4 == 0) ? WALL : EMPTY;
        }
    }
    Maze[0][0] = START;
    Maze[HEIGHT - 1][WIDTH - 1] = END;
}

void PrintMaze(const vector<vector<char>>& Maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << Maze[i][j] << " ";
        }
        cout << endl;
    }
}

bool BFSSolveMaze(vector<vector<char>>& Maze) {
    vector<vector<bool>> Visited(HEIGHT, vector<bool>(WIDTH, false));
    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> Parent(HEIGHT, vector<pair<int, int>>(WIDTH));

    q.push({ 0, 0 });
    Visited[0][0] = true;

    while (!q.empty()) {
        auto Current = q.front();
        q.pop();
        int x = Current.first, y = Current.second;

        if (x == HEIGHT - 1 && y == WIDTH - 1) {
            pair<int, int> p = { x, y };
            while (p != make_pair(0, 0)) {
                Maze[p.first][p.second] = PATH;
                p = Parent[p.first][p.second];
            }
            Maze[0][0] = START;
            Maze[HEIGHT - 1][WIDTH - 1] = END;
            return true;
        }

        for (auto& Dir : Directions) {
            int nx = x + Dir[0], ny = y + Dir[1];

            if (nx >= 0 && ny >= 0 && nx < HEIGHT && ny < WIDTH && !Visited[nx][ny] && Maze[nx][ny] != WALL) {
                Visited[nx][ny] = true;
                q.push({ nx, ny });
                Parent[nx][ny] = { x, y };
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> Maze(HEIGHT, vector<char>(WIDTH));

    GenerateMaze(Maze);
    cout << "Generated Maze :\n";
    PrintMaze(Maze);

    cout << "\nSolving Maze...\n";
    if (BFSSolveMaze(Maze)) {
        cout << "\nSolved Maze :\n";
        PrintMaze(Maze);
    }
    else {
        cout << "\nNo Path Found!\n";
    }

    cout << "\nPress Enter to Exit...";
    cin.get();
    return 0;
}