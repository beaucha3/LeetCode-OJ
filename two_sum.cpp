class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int> sol; /* Final vector of indices to return. Note: we assume that a unique solution exists */
            sol.resize(0); /* Paranoia */
            
            unordered_map<int, int> numToIndex; /* maps array elements to indices in the array. Used to get O(n) running time */
            
            for(int i = 0; i < (int)nums.size(); i++)
            {
                numToIndex[nums[i]] = i; /* Set up the hash table. Don't worry about duplicate elements as we assume a unique solution */
            }
            
            /*
            ** Idea: Iterate through the array indices.
            ** On each pass, check whether target - the value at the current index is a key in the hash table.
            ** If it is, then i must be one of the correct indices, and the index mapped to by target-nums[i] is the other.
            ** In fact, since i starts from 0, it will always be the smaller index!
            */
            for(int i = 0; i < (int)nums.size(); i++)
            {
               /* If the correct condition is met. Note: "count" returns the number of instances of the given key */
               /* Another note: the second condition ensures the key found isn't nums[i] itself */
               if( (numToIndex.count(target - nums[i]) != 0) && (numToIndex[target-nums[i]] != i) )
                {
                    sol.push_back(i+1); /* Push the two indices to the back of the solution vector */
                    sol.push_back(numToIndex[target - nums[i]]+1); /* Note: the indices are not zero-based */
                    break; /* We don't want to push duplicates */
                }
            }
            
            return sol; /* Return solution vector */
        }
};
