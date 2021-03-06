#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>    // sqrt를 사용하기 위해

using namespace std;

set<int> numberSet; // set 클래스로 정의

bool isPrime(int number)
{
    // 3-1. 0과 1은 소수가 아님
    if (number == 0 || number == 1)
        return false;

    // 3-2. 에라토스테네스의 체
    int lim = sqrt(number);
    for (int i = 2; i <= lim; i++)
        if (number % i == 0)
            return false;

    return true;
}

void recursive(string comb, string others)  // (현재까지 만들어진 조합, 현재까지 사용되지 않는 스트링)
{
    // 2-1. 현 조합을 numberSet에 추가.
    if (comb != "")
        numberSet.insert(stoi(comb));   // string 자료형을 int형으로 변환
    cout << comb << endl;

    // 2-2. 현 조합 + others[i]를 조합하여 새로운 조합을 만듬.
    for (int i = 0; i < others.size(); i++)
        recursive(comb + others[i], others.substr(0, i) + others.substr(i + 1));

}

int solution(string numbers)
{
    // 1. 모든 숫자 조합을 만듬
    recursive("", numbers); // 재귀함수 사용 --> set이라는 자료구조 사용

    // 2. 소수의 개수를 센다
    int answer = 0;
    for (int number : numberSet)
        if (isPrime(number))
            answer++;

    // 3. 소수의 개수를 반환.
    return answer;
}

int main(void)
{
    cout << solution("132");
}