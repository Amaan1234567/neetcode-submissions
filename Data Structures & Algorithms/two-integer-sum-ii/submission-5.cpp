#pragma optimise("O3");

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size()-1; i++) {
            int l = i+1;
            int r = numbers.size() - 1;
            int m;
            int true_target = target-numbers[i];
            while (l <= r) {
                m = (l + r) / 2;
                // std::cout << "numbers[m]: " << numbers[m] << "   " << "true_target: " << true_target
                //           << std::endl;
                if (numbers[m] == true_target) {
                    return {std::min(m + 1, i + 1), std::max(m + 1, i + 1)};
                } else if (numbers[m] < true_target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return {0, 1};
    }
};
