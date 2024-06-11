function solution(m, n, puddles) {
    // dp 배열 초기화
    const dp = new Array(n).fill().map(() => new Array(m).fill(0));

    // 물웅덩이 위치 설정
    for (let [a, b] of puddles) {
        dp[b - 1][a - 1] = -1; // (b-1, a-1)로 설정
    }

    // 시작점 초기화
    dp[0][0] = 1;

    // DP를 이용해 경로의 수를 계산
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (dp[i][j] === -1) {
                dp[i][j] = 0; // 물웅덩이는 경로 수를 0으로 설정
                continue;
            }
            if (i > 0) dp[i][j] += dp[i - 1][j] % 1000000007; // 위에서 오는 경로 추가
            if (j > 0) dp[i][j] += dp[i][j - 1] % 1000000007; // 왼쪽에서 오는 경로 추가
            dp[i][j] %= 1000000007; // 결과를 1000000007로 나눈 나머지로 업데이트
        }
    }

    return dp[n - 1][m - 1];
}




//테이블 설정


//점화식 설정


//초기값 설정