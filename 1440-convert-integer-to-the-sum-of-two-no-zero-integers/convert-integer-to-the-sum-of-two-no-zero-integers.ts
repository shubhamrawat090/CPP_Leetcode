function getNoZeroIntegers(n: number): number[] {
    for(let num1=1; num1<n; num1++) {
        if(isNoZero(num1)) {
            const num2 = n - num1;
            if(isNoZero(num2)) {
                return [num1, num2];
            }
        }
    }
    return [];
};

function isNoZero(num: number): boolean {
    while(num) {
        const rem = num % 10;
        if(rem === 0) return false;
        num = Math.floor(num / 10);
    }
    return true;
}