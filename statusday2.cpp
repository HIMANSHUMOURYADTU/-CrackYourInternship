// leetcode-73(set matrix zero)
// My approach- saare rows aur column ko nikal kr i aur j ki help se jo zero hoga uski i aur j ki value 
// nikal denge andn then i aur j ka for loop chlake sbko zero daal denge eith the help of operator 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
    int n = matrix[0].size();
    std::set<int> zeroRows;
    std::set<int> zeroCols;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                zeroRows.insert(i);
                zeroCols.insert(j);
            }
        }
    }
    for(int row : zeroRows) {
        for(int j = 0; j < n; j++) {
            matrix[row][j] = 0;
        }
    }
    for(int col : zeroCols) {
        for(int i = 0; i < m; i++) {
            matrix[i][col] = 0;
        }
    }
}
};


// leetcode-283(Move zeroes)
// I have used teo pointer approach for this 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }
    for (int i = j; i < n; ++i) {
        nums[i] = 0;
    }
        
    }
};


// two sum
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_index;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if (num_to_index.find(complement) != num_to_index.end()) {
                return {num_to_index[complement], i};
            }
            
            num_to_index[nums[i]] = i;
        }
        return {};
    }
};
// leetcode - 121 (best time to bus and sell stocks)
//naive approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int price : prices) {
            min_price = min(min_price, price);
            int profit = price - min_price;
            max_profit = max(max_profit, profit);
        }
        
        return max_profit;
    }
};
//optimal sol 
int init = [] {
	//disable sync of I/O to speed it up
    cin.tie(nullptr)->sync_with_stdio(false);

    //redirect output to file "user.out"
    freopen("user.out", "w", stdout);

    //get input line-by-line as a string, example [7,1,5,3,6,4]
    for (string s; getline(cin, s);) {
        //initialize vars
        int maxProfit = 0, minPrice = INT_MAX;

        //iterate through string, skipping brackets and commas  
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {

            //&15 converts character to int value
            int currentPrice = s[_i++] & 15;

            //converts multi-digit string numbers to int
            while ((s[_i] & 15) < 10) {
                currentPrice = currentPrice * 10 + (s[_i++] & 15);
            }

            if (currentPrice < minPrice) {
                //store lowest price seen
                minPrice = currentPrice;
            } else if (currentPrice - minPrice > maxProfit) {
                //check max profit IF not less
                maxProfit = currentPrice - minPrice;
            }
        }
        cout << maxProfit << '\n';
    }
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        //finds largest positive difference in prices vector
        return 0;
    }
};

// leetcode - 974(subaaray sum divisible by k)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
          std::unordered_map<int, int> remainderCount;
    remainderCount[0] = 1;
    int prefixSum = 0;
    int result = 0;

    for (int num : nums) {
        prefixSum += num;
        int remainder = prefixSum % k;
        if (remainder < 0) {
            remainder += k;
        }
        if (remainderCount.find(remainder) != remainderCount.end()) {
            result += remainderCount[remainder];
        }
        remainderCount[remainder]++;
    }
    return result;
    }
};

