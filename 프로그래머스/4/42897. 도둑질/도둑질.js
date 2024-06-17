function solution(money) {
    let n = money.length;
    
    if (n === 1) {
        return money[0];
    }
    
    function rob(nums) {
        let prev1 = 0, prev2 = 0;
        for (let num of nums) {
            let temp = prev1;
            prev1 = Math.max(prev1, prev2 + num);
            prev2 = temp;
        }
        return prev1;
    }
    
    // 첫 번째 집을 털고 마지막 집을 털지 않는 경우
    let max1 = rob(money.slice(0, n - 1));
    
    // 첫 번째 집을 털지 않고 마지막 집을 터는 경우
    let max2 = rob(money.slice(1));
    
    // 두 경우의 최대값 비교
    return Math.max(max1, max2);
}