/*

Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution,
and you may not use the same element twice.
You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 105
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

*/


// Method #1: Brute Force

class Solution
{
    public:
    vector<int> twoSum(vector<int>& Nums, int Target)
    {
        int len = Nums.size();
        for(int i = 0; i < len; i++)
        {
            for(int j = i+1; j < len; j++)
            {
                if(Nums[j] == Target - Nums[i])
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

//Time complexity : O(n^2). For each element, we try to find its complement by looping through the rest of array which takes O(n) time. Therefore, the time complexity is O(n^2).
//Space complexity : O(1).


// Method #2: Two Pointer

class Solution
{
    public:
    vector<int> twoSum(vector<int>& Nums, int Target)
    {
        int front = 0, rear = Nums.size() - 1;
        while(front <= rear)
        {
            int sum = Nums[front] + Nums[rear];
            if(sum == Target)
            {
                return {front, rear};
            }
            rear -= 1;
            if (front == rear)
            {
                front += 1;
                rear = Nums.size() - 1;
            }
        }
        return {};
    }
};

// or

class Solution
{
    public:
    vector<int> twoSum(vector<int>& Nums, int Target)
    {
        vector<pair<int, int>> pairs;
        for(int i=0; i<Nums.size(); i++)
        {
            pairs.push_back({Nums[i], i});
        }
        int front = 0, rear = Nums.size() - 1;
        sort(pairs.begin(), pairs.end());
        while(front < rear)
        {
            int sum = pairs[front].first + pairs[rear].first;
            if(sum == Target)
            {
                return {pairs[front].second, pairs[rear].second};
            }
            else if(sum > Target)
            {
                rear--;
            }
            else
            {
                front++;
            }
        }
        return{};
    }
};


//Time complexity : O(nlog(n)). sort function takes nlog(n) time.
//Space complexity : O(1).




// Method #3: Hash Table
class Solution
{
    public:
    vector<int> twoSum(vector<int>& Nums, int Target)
    {
        map<int, int> table;
        vector<int> res;
        for(int i=0; i<Nums.size(); i++)
        {
            int complement = Target - Nums[i];
            if(table.find(complement) != table.end())
            {
                res.push_back(table.find(complement)->second);
                res.push_back(i);
                break;
            }
            table.insert(pair<int, int>(Nums[i], i));
        }
        return res;
    }
};

//Time complexity : O(n). We traverse the list containing n elements only once.
//Each look up in the table costs only O(1) time.
//Space complexity : O(n). The extra space required depends on the number of
//items stored in the hash table, which stores at most n elements.
