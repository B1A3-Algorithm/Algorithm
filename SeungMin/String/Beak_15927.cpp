#include <bits/stdc++.h>

using namespace std;

int palindrome(const string& str) {
    string word = str;
    //ȸ������ üũ
    for (int i = 0; i < (int)word.size() / 2; i++) {
        if (word[i] != word[word.size() - i - 1]) {
            return word.size();
        }
    }
    //��� ���� ������ �߰��� �ϳ��� ������ ȸ���� ����
    for (int i = 0; i < (int)word.size(); i++) {
        if (word[0] != word[word.size() - i - 1]) return word.size() - 1;
    }
    //��� ���ٸ� -1
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    cout << palindrome(str);

    return 0;
}