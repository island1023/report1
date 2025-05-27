//�Ŵ����Ŵ洢����
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

// �Ŵ��ṹ��
struct Tape {
    int length;  // �Ŵ�����
    int prob;    // �Ŵ�����
    double weight; // �Ŵ�Ȩ�� = length * prob

    // ���캯����ʼ��������Ȩ��
    Tape(int l = 0, int p = 0) : length(l), prob(p), weight(l * p) {}
};

// �ȽϺ�������������
bool cmp(Tape a, Tape b) {
    return a.weight < b.weight;  // ��Ȩ�ش�С��������
}

// ������С����ʱ��
double greedy(int N, Tape* tapes, long long sum) {
    double totalTime = 0.0;  // ��ʱ��
    double accumulatedTime = 0.0;  // �ۻ�ʱ��

    // ���������ĴŴ��������Ȩƽ������ʱ��
    for (int i = 0; i < N; i++) {
        accumulatedTime += tapes[i].weight / (double)sum;  // �ۼƷ��ʴ���
        totalTime += accumulatedTime;  // ��ʱ��
    }

    return totalTime;
}

int main() {
    int N;
    long long sum = 0;

    // �����ļ�·��������·����
    string inputFilePath = "C:\\Users\\islan\\Desktop\\input.txt";
    string outputFilePath = "C:\\Users\\islan\\Desktop\\output.txt";

    // �������ļ�
    ifstream inputFile(inputFilePath);
    if (!inputFile) {
        cout << "�޷��������ļ�!" << endl;
        return 1; // �˳�����
    }

    // ��ȡ�Ŵ�����
    inputFile >> N;

    // �����Ŵ�����
    Tape tapes[100];  // ���������100���Ŵ�

    // ��ȡÿ���Ŵ��ĳ��Ⱥ͸���
    for (int i = 0; i < N; i++) {
        int length, prob;
        inputFile >> length >> prob;
        tapes[i] = Tape(length, prob);
        sum += prob;  // �ۼӸ���
    }

    inputFile.close(); // �ر������ļ�

    // ���Ŵ���Ȩ�أ�length * prob������
    sort(tapes, tapes + N, cmp);

    // ʹ��̰���㷨������С����ʱ��
    double result = greedy(N, tapes, sum);

    // ������ļ�
    ofstream outputFile(outputFilePath);
    if (!outputFile) {
        cout << "�޷�������ļ�!" << endl;
        return 1; // �˳�����
    }

    // ���������ļ����������������
    outputFile << fixed << setprecision(4) << result;
    outputFile.close(); // �ر�����ļ�

    // ����̨��ʾ
    cout << "������" << endl;

    system("pause");
    return 0;
}
