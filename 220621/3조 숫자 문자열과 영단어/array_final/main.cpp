#include <string>   // C++ STL 문자열 클래스 이용을 위한 헤더파일
#include <iostream> // C++ 입출력을 위한 헤더파일

using namespace std;

int solution(string s) {
    int answer = 0;

    string number[10] = { "zero", "one","two","three","four","five","six","seven","eight","nine" }; // number reference

    for (int idx = 0; idx < 10; idx++)  // iterate 0 to 9
    {
        while (s.find(number[idx]) != string::npos)     // number[i]을 찾으면 시작 인덱스를 반환
                                                        // 못 찾으면 string::npos 반환
                                                        // find() 함수에 의해서 found 되지 못하는 경우 npos값이 리턴

            s.replace(s.find(number[idx]), number[idx].length(), to_string(idx));   // s.find(number[i]) : 찾을 문자열의 위치
                                                                                    // number[i].length() : 찾는 문자열의 길이
                                                                                    // to_string(i) : 교체할 새로운 문자열
    }

    answer = stoi(s);   // string to integer. 반환형이 int
    return answer;
}

int main() {
    cout << solution("twothree45sixtwo") << endl;
}