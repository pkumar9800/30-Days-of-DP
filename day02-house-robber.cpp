class Solution {
  public:
      int rob(vector<int>& nums) {
          int rob = 0;
          int notRob = 0;
          for (int i = 0; i < nums.size(); i++) {
              int newRob = notRob + nums[i];
              int newNotRob = max(notRob, rob);
              rob = newRob;
              notRob = newNotRob;
          }
          return max(rob, notRob);
      }
  };