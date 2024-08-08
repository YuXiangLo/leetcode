class Solution {
public:
    bool check(int r, int c, int x, int y) {
        return r > x && x >=0 && c > y && y >= 0;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ret;
        int dx = 1, dy = 1, dirx = 1, diry = 1;
        while (ret.size() < rows * cols) {
            for (int i = 0; i < dx; i++) {
                if (check(rows, cols, rStart, cStart))
                    ret.push_back({rStart, cStart});
                cStart += dirx;
            }
            ++dx, dirx *= -1;
            for (int i = 0; i < dy; i++) {
                if (check(rows, cols, rStart, cStart))
                    ret.push_back({rStart, cStart});
                rStart += diry;
            }
            ++dy, diry *= -1;
        }
        return ret;
    }
};
