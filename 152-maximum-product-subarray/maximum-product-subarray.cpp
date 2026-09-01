class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProduct = INT_MIN;
        int sufixProd = 1;
        int prefixProd = 1;

        for (int i = 0; i < nums.size(); i++) {
            
            if(sufixProd == 0)
            {
                sufixProd = 1;
            }
            if(prefixProd == 0)
            {
                prefixProd = 1;
            }

            prefixProd *= nums[i];
            sufixProd *= nums[nums.size() - 1 - i];
            maxProduct = max(maxProduct,max(prefixProd,sufixProd));

        }
        return maxProduct;
    }
};