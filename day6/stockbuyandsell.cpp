class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int minprice = arr[0];
        int maxprofit = 0;
        for(int i=0;i<arr.size();i++)
        {
            minprice = min(arr[i],minprice);
            int profit = arr[i]-minprice;
            maxprofit = max(maxprofit,profit);
        }
        return maxprofit;
    }
};

