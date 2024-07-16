//Today I have solved three questions of ARSH DSA CHALLENGE 
//leetcode-287(Find duplicate number)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
    int hare = nums[0];
    
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Phase 2: Finding the entrance to the cycle
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
        
    }
};

// sort colors 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
        
    }
};

//remove duplicates from sorted array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=0;
        while(i<nums.size()){
            if(nums[i]==nums[j]) ++i;
            else{
                
                nums[++j] = nums[i++];
            }
            
        }
        return j+1;

        
    }
};
