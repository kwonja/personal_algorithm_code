function solution(sequence) {
    let n = sequence.length;
    let maxPulse1 = -Infinity; // 1로 시작하는 펄스 수열의 최대 합
    let maxPulse2 = -Infinity; // -1로 시작하는 펄스 수열의 최대 합

    let currentPulse1 = 0; // 1로 시작하는 현재 펄스 수열의 합
    let currentPulse2 = 0; // -1로 시작하는 현재 펄스 수열의 합

    for (let i = 0; i < n; i++) {
        let sign = (i % 2 === 0) ? 1 : -1; // 짝수 인덱스이면 1, 홀수 인덱스이면 -1
        currentPulse1 = Math.max(sequence[i] * sign, currentPulse1 + sequence[i] * sign);
        currentPulse2 = Math.max(sequence[i] * -sign, currentPulse2 + sequence[i] * -sign);

        maxPulse1 = Math.max(maxPulse1, currentPulse1);
        maxPulse2 = Math.max(maxPulse2, currentPulse2);
    }

    return Math.max(maxPulse1, maxPulse2);
}
