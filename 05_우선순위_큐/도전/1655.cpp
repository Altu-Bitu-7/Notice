#include <iostream>
#include <queue>

using namespace std;

/*
HINT : 가운데를 찾기 위해 현재까지 입력된 숫자중 비교적 작은 값과 큰 값을 따로 저장하면 좋을 것 같네요!
*/

void balance(priority_queue<int>& max_pq, priority_queue<int, vector<int>, greater<>>& min_pq) {
	int top_max, top_min; // 각 힙의 top 값을 저장할 변수

	top_max = max_pq.top();
	top_min = min_pq.top();

	// max_pq의 top이 min_pq의 top보다 큰 경우 서로 바꿔서 저장
	if (top_max > top_min) {
		max_pq.pop();
		min_pq.pop();

		max_pq.push(top_min);
		min_pq.push(top_max);
	}
	return;
}

/*
입력된 수들 중 비교적 작은 값은 최대힙에 저장하고 큰 값은 최소힙에 저장하자
가운데를 찾기 위해서는 최대힙과 최소힙의 개수 차이가 0이나 1이어야 한다
최대힙의 top값이 가운데이도록 하기 위해 최대힙의 사이즈가 최소힙의 사이즈와 같거나 1만큼 크게 저장하자
개수를 기준으로 저장했기에 저장 위치가 잘못되었을 수도 있다. -> 균형을 맞춰주자 (balance)
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, num;
	priority_queue<int> max_pq; 						// 비교적 작은 값을 저장해둔 Max Heap
	priority_queue<int, vector<int>, greater<>> min_pq; // 비교적 큰 값을 저장해둔 Min Heap

	// 입력
	cin >> n;
	while (n--) {
		cin >> num;

		// max_pq의 사이즈가 min_pq의 사이즈와 같거나 하나 더 많도록 저장
		if (max_pq.size() > min_pq.size()) {
			min_pq.push(num);
		}
		else {
			max_pq.push(num);
		}

		// 두 개의 pq 모두 원소가 존재할 때 균형 맞추기
		if (!max_pq.empty() && !min_pq.empty()) {
			balance(max_pq, min_pq);
		}

		// 출력
		cout << max_pq.top() << "\n";
	}

	return 0;
}