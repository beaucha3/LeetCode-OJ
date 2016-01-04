class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        /* Idea: A hash table can be used to keep track of which characters have been seen so far in a given substring */
        
        unordered_map<char, int> charTrack; /* Declare hash table */
        
        int maxLength = 0; /* Length of longest substring w/out repeating characters. Initially set to 0 */
        int start = -1; /* Used to help keep track of length of current substring (note: i - start will be this length) */
        
        int i; /* Used to index characters in the string */
        
        for(i = 0; i < s.length(); i++) /* Iterate through characters in the string */
        {
            /* If the character is already in the hashmap, then we process the substring */
            if(charTrack.count(s[i]) != 0)
            {
                if((i-1-start) > maxLength) /* Update with the new maximum length if necessary. i-1-start is the current length */
                    maxLength = (i-1-start);
                    
                /*
                ** Update the value of start.
                ** It should be the larger of the index of the previous occurrence of s[i]
                ** and its current value (as this accounted for previous duplicates).
                */

                if(charTrack[s[i]] > start)
                    start = charTrack[s[i]]; /* This value is given by the hash map */
            }
            
            charTrack[s[i]] = i; /* Add the character to the map */
        }
        
        if((i-1-start) > maxLength) /* Update with the new maximum length one more time (necessary if longest substring is at the end) */
                    maxLength = (i-1-start);
        
        return maxLength; /* Return the maximum length */
    }
};
