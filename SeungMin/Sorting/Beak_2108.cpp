#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, input;
    int range, middle = 0, most_val, mean = 0;
    int most = -9999;
    int number[8001] = { 0, };
    bool not_first = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
        mean += input;
        //�迭 ������ �׳� 4000���س��� ��ġ �����ϰ� ���߿� ����
        number[input + 4000]++;
    }
    sort(nums.begin(), nums.end());
    //�ֺ� ���ϱ�
    for (int i = 0; i < 8001; i++) {
        //�ѹ��� �ȳ��Դ� ���̸� �н�
        if (number[i] == 0) continue;
        //�ֺ��� ��ġ�� ���
        if (number[i] == most) {
            //not_first�� true�ΰ�� �ι�°�� ū �ֺ���
            //�׷��� �״��� ������������ �ֺ� �����ϱ� ����
            //false�� ����
            if (not_first) {
                most_val = i - 4000;
                not_first = false;
            }
        }
        //�ֺ� ���ϱ�, not_first�� ���� ū �ֺ����� üũ
        if (number[i] > most) {
            most = number[i];
            most_val = i - 4000;
            not_first = true;
        }
    }
    //�߾Ӱ� ���ϱ�
    middle = nums[nums.size() / 2];
    //������ ���ϱ�
    mean = round((float)mean / n);
    //���� ���ϱ�
    range = nums.back() - nums.front();
    //������, �߾Ӱ�, �ֺ�(��ġ�� �ι�°�� ������), ���� ���
    cout << mean << '\n'
        << middle << '\n'
        << most_val << '\n'
        << range;
    return 0;
}