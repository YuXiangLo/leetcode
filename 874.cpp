class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool check(int coord[], int dir, vector<vector<int>>& obstacles) {
        int left = 0, right = obstacles.size(), mid, cmp1, cmp2;
        while (left < right) {
            mid = (left + right) / 2;
            cmp1 = obstacles[mid][0] - coord[0] - dx[dir];
            cmp2 = obstacles[mid][1] - coord[1] - dy[dir];
            if (cmp1 == 0 && cmp2 == 0)
                return false;
            else if (cmp1 > 0 || cmp1 == 0 && cmp2 > 0)
                right = mid;
            else
                left = mid + 1;
        }
        return true;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        sort(obstacles.begin(), obstacles.end());
        int dir = 0, tmp;
        int coord[] = {0, 0};
        int ret = 0;
        for (int i : commands) {
            if (i == -1) // turn right
                dir = (dir + 1) % 4;
            else if (i == -2) // turn left
                dir = (dir - 1 + 4) % 4;
            else {
                tmp = i;
                while (tmp-- && check(coord, dir, obstacles)) {
                    coord[0] += dx[dir],
                    coord[1] += dy[dir];
                    ret = max(ret, coord[0] * coord[0] + coord[1] * coord[1]);
                }
            }
        }
        return ret;
    }
};
