/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let maxBuyPrevDays = prices[0];
    let maxProfit = 0;
    for(let i=1; i<prices.length; i++) {
        const profitSellingToday = prices[i] - maxBuyPrevDays;
        if(profitSellingToday > maxProfit) {
            maxProfit = profitSellingToday;
        }
        if(prices[i] < maxBuyPrevDays) {
            maxBuyPrevDays = prices[i];
        }
    }
    return maxProfit;
};