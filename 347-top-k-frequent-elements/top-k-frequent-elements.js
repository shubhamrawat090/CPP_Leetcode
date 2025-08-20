/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    // add to freq map
    const freqMap = {};
    for(let num of nums) {
        if(freqMap[num]) {
            freqMap[num]++;
        } else {
            freqMap[num] = 1;
        }
    }

    const returnVal = [];

    // Sort the map desc based on freq
    const entries = Object.entries(freqMap).sort((a,b) => b[1] - a[1]);
    for(let i=0; i<k; i++) {
        returnVal.push(Number(entries[i][0]));
    }

    return returnVal;
};