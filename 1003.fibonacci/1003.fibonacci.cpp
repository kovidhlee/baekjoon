/*
URL: https://www.acmicpc.net/problem/1003
문제:
	  fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.
	  fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
	  fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
	  두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
	  fibonacci(0)은 0을 출력하고, 0을 리턴한다.
	  fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
	  첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
	  fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
	  이 때, 1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.
제공함수:
	int fibonacci(int n) {
		if (n==0) {
			printf("0");
			return 0;
		} else if (n==1) {
			printf("1");
			return 1;
		} else {
			return fibonacci(n‐1) + fibonacci(n‐2);
		}
	}
입력: 첫째 줄에 N이 주어진다. (N <= 40, N == 0)
출력: 각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.
예제 입력:
  3
  0
  1
  3
예제 출력:
  1 0
  0 1
  1 2
결과: 성공
*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Fib01Counter {
public:
        Fib01Counter(int n) {
                table_.resize(n + 1, make_pair(0, 0));
                table_[0].first = 1;
                table_[0].second = 0;
                table_[1].first = 0;
                table_[1].second = 1;
                for (int i = 2; i < n + 1; ++i) {
                        table_[i].first = table_[i-1].first+ table_[i-2].first;
                        table_[i].second = table_[i-1].second + table_[i-2].second;
                }
        }
        pair<int, int> Count(int n) {
                return table_[n];
        }
private:
        vector<pair<int, int> > table_;
};

int main()
{
        Fib01Counter counter(40);
	int nInput = 0;
	cin >> nInput;

	for (int i = 0; i < nInput; i++)
	{
                int n;
                cin >> n;
                auto result = counter.Count(n);
		cout << result.first << " " << result.second << endl;
	}

	return 0;
}
