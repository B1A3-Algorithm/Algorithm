#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> check(n, 1);
    for (int i = 0; i < lost.size(); i++) check[lost[i] - 1]--;
    for (int i = 0; i < reserve.size(); i++) check[reserve[i] - 1]++;

    for (int i = 0; i < check.size(); i++) {
        if (check[i] == 0) {
            //������ ����� �ջ������ ������
            if (i == check.size() - 1 && check[i - 1] == 2) {
                check[i]++;
                check[i - 1]--;
            }
            //ù��°��� �����ϰ� �ջ������ ������
            else if (i != 0 && check[i - 1] == 2) {
                check[i]++;
                check[i - 1]--;
            }
            //�޻������ ������, �ڿ� ��� ���� üũ�ϰ� �Ǹ� �ջ���� �ִ��� üũ ���� ����
            else if (check[i + 1] == 2) {
                check[i]++;
                check[i + 1]--;
            }
        }
    }
    for (int i = 0; i < check.size(); i++) {
        if (check[i] != 0) answer++;
    }

    return answer;
}