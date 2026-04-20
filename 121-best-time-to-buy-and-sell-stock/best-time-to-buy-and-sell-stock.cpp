class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, sell=0;int profit=0;
        for(int i=0;i<prices.size();i++){
            if(buy>prices[i])buy=prices[i];
            else{
                sell=prices[i];
                profit=max(profit,sell-buy);

            }
        }
        return profit;
        

    }
};