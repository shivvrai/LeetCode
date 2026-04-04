class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=INT_MAX,profit=0;
        for(auto price: prices){
            if(sell>price)sell=price;
            profit=max(profit,price-sell);
        }
        return profit;
    }
};