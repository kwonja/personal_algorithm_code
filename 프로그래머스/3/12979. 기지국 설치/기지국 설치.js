function solution(n, stations, w) {
    let answer = 0;
    let start = 1; // Starting point for checking coverage
    let s = 0; // Index for stations array
    
    while (start <= n) {
        if (s < stations.length && start >= stations[s] - w && start <= stations[s] + w) {
            // If the current start is within the coverage of the current station
            start = stations[s] + w + 1;
            s++;
        } else {
            // Calculate the new station placement
            answer++;
            start += 2 * w + 1;
        }
    }

    return answer;
}