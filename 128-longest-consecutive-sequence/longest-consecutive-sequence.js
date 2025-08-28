/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    // dump all in a set
    const set = new Set();
    for(let num of nums) {
        set.add(num);
    }

    // iterate in set
    // check if a possible start
    // keep on checking till you find the next one and update highest streak
    let highestStreak = -1;
    for(let num of set) {
        if(!set.has(num-1)) { // POSSIBLE START
            let n = num, streak = 1;
            while(set.has(n+1)) {
                streak++;
                n++;
            }
            highestStreak = Math.max(streak, highestStreak);
        }
    }

    return highestStreak == -1 ? 0 : highestStreak;
};