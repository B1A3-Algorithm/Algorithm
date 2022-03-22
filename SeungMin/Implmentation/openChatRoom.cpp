#include <sstream>
#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

map<string, string> m;
vector<string> word, ids;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for (int i = 0; i < record.size(); i++) {
        //string�ɰ���, istringstream�� ���鿡 ���� �ܾ� ©����
        istringstream s(record[i]);
        string act, uid, name;
        s >> act >> uid >> name;

        //�������� ������ Ȯ���ϱ�
        if (act == "Enter") word.push_back("���� ���Խ��ϴ�.");
        else if (act == "Leave") word.push_back("���� �������ϴ�.");

        //���� ������ �ϴ� uid �α� �����ϱ�
        if (act == "Enter" || act == "Leave") ids.push_back(uid);
        //�����°� �ƴϸ� �к��ߴ��� �׻� üũ
        if (act != "Leave") m[uid] = name;
    }
    for (int i = 0; i < ids.size(); i++) {
        answer.push_back(m[ids[i]] + word[i]);
    }
    return answer;
}