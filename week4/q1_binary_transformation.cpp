// Author: Juyoung Moon
// https://school.programmers.co.kr/learn/courses/30/lessons/70129
// 이진 변환 반복하기

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int zeros = 0;
    int counter = 0;
    while (s != "1") {
        counter++;
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                len++;
            } else {
                zeros++;
            }
        }
        
        // change len to binary
        s = "";
        while (len > 0) {
            if (len % 2 == 1) {
                s = "1" + s;
            } else {
                s = "0" + s;
            }
            len /= 2;
        }
    }
    return {counter, zeros};
}