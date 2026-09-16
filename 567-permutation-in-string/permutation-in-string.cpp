class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        map<char,int>map1;
        map<char,int>map2;

        
        for(int i = 0;i < s1.size();i++)
        {
            map1[s1[i]]++;
        }
        
        int left  = 0;
        int windowsize = s1.size();
        for(int right = 0;right < s2.size(); right++)
        {
            map2[s2[right]]++;

            if(right - left + 1  > windowsize)
            {
                map2[s2[left]]--;

                if(map2[s2[left]] == 0)
                {
                    map2.erase(s2[left]);
                   
                }
                 left++;
            }


            if(right - left + 1  == windowsize)
            {
                if(map1 == map2)
                {
                    return true;
                }
            }

             
        }
        return false;
    }
};