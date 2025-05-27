//���Ϻ���n��Ԫ�أ����ܴ����ظ�Ԫ�أ��г����ϵ����в�ͬ����
//���룺input.txt
//��һ�У�n
//�ڶ����Ǵ����е�n��Ԫ��   aacc
//�����output.txt

#include<iostream>
#include<string>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int get(char b[], int xx[], int n, string c);
long factorial(int n);
int count(int xx[], int n);
void issort(char b[], int xx[], int n);

int get(char b[], int xx[], int n, string c) {
    int ct = 0;
    // �ҵ���ͬ�ַ�������ִ���
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < ct; j++) {
            if (c[i] == b[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            b[ct++] = c[i];
        }
    }
    // ����ÿ���ַ��ĳ��ִ���
    for (int i = 0; i < ct; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i] == c[j]) {
                xx[i]++;
            }
        }
    }
    return ct;
}


long factorial(int n) {
    long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int count(int xx[], int n) {
    // ���������ַ������������� n!
    long sum = factorial(n);
    // ����ÿ���ַ����ִ����Ľ׳�
    for (int i = 0; i < 100; i++) {
        if (xx[i] > 1) {
            sum /= factorial(xx[i]);
        }
    }
    return sum;
}




void issort(char b[], int xx[], int n) {
    string s = "";
    // �����ַ����ִ��������ַ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < xx[i]; j++) {
            s += b[i];
        }
    }
    sort(s.begin(), s.end());  // ���������ɱ�׼����
    set<string> unique_permutations;
    do {
        unique_permutations.insert(s);  // ʹ�� set ȥ��
    } while (next_permutation(s.begin(), s.end()));

    // ���ÿ��Ψһ����
    for (const auto& perm : unique_permutations) {
        cout << perm << " ";
    }
}



int main() {
    ifstream inFile("C:\\Users\\xy\\Desktop\\input.txt");
    if (!inFile.is_open()) {
        cout << "����ʧ��";
        return 1;
    }

    int n;
    string c;
    inFile >> n >> c;
    inFile.close();

    char b[100];
    for (int i = 0; i < 100; i++) {
        b[i] = '\0';
    }
    int xx[100] = {0};
    int ct = get(b, xx, n, c);
    int sum = count(xx, n);  // �޸�Ϊ����n
    cout << "�������" << endl;
    cout << "��ͬ���и���: " << sum << endl;
    issort(b, xx, n);
    return 0;
}
