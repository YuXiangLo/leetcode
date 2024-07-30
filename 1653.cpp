class Solution {
public:
    int minimumDeletions(string s) {
        int ret, cnt;
        ret = cnt = 0;
      for (char c : s) {
        if (c == 'b')
            cnt++;
        else if (cnt)
            ret++, cnt--; 
      } 
      return ret; 
    }
};
