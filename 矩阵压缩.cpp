#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

// ��ȡ PGM �ļ� (P5 ��ʽ)
int* readPGM(const char* filename, int& width, int& height) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "�޷����ļ���" << endl;
        return nullptr;
    }

    // ��ȡħ���ַ��� P5
    string magic;
    file >> magic;
    if (magic != "P5") {
        cerr << "�ļ����� P5 ��ʽ�� PGM ͼ��" << endl;
        return nullptr;
    }

    // �����ļ��е�ע�ͣ��� # ��ͷ���У�
    char ch;
    file.get(ch);  // ��ȡ��һ�ַ�����ֹ��ȡ�������������з�
    while (ch == '#') {
        file.ignore(1000, '\n');  // ����ע����
        file.get(ch);  // �ٴλ�ȡ��һ�ַ�
    }

    // ��ȡ��Ⱥ͸߶�
    file >> width >> height;
    if (width <= 0 || height <= 0) {
        cerr << "ͼ��ߴ��ȡ���󣡿��: " << width << ", �߶�: " << height << endl;
        return nullptr;
    }

    // ��ȡ�������ֵ
    int maxVal;
    file >> maxVal;
    if (maxVal != 255) {
        cerr << "ֻ֧���������ֵΪ 255 ��ͼ��" << endl;
        return nullptr;
    }

    // �������з�
    file.get();

    // ������������
    int n = width * height;
    int* p = new int[n + 1]; // �±�� 1 ��ʼ
    for (int i = 1; i <= n; ++i) {
        unsigned char pixel;
        file.read(reinterpret_cast<char*>(&pixel), 1);
        p[i] = static_cast<int>(pixel); // �洢����ֵ
    }

    file.close();
    return p;
}

// ѹ������������ֻ�Ǽ�ģ��ѹ����Ĵ�С��
void simpleCompression(int* p, int n) {
    int originalSize = n * 8; // ԭͼ���С�����أ�
    int compressedSize = n * 4; // �����ѹ����ԭͼ��С���ķ�֮һ

    cout << "δѹ��ͼ���С: " << originalSize << " ����" << endl;
    cout << "ѹ����Ĵ�С: " << compressedSize << " ����" << endl;

    double compressionRatio = static_cast<double>(originalSize) / compressedSize;
    cout << "ѹ���ȣ�ԭʼ " << originalSize << " ���� / ѹ�� " << compressedSize << " ���� = " << compressionRatio << endl;
}

// ����������дΪPGMͼ��
void writePGM(const char* filename, int* p, int width, int height) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "�޷�д���ļ���" << endl;
        return;
    }

    file << "P2\n" << width << " " << height << "\n255\n";
    int n = width * height;
    for (int i = 1; i <= n; ++i) {
        file << p[i];
        if (i % width == 0)
            file << "\n";
        else
            file << " ";
    }

    file.close();
}

// === ������ ===
int main() {
    const char* inputFile = "C:\\Users\\xy\\Pictures\\bridge.pgm";  // ����ͼ��·��
    const char* outputFile = "C:\\Users\\xy\\Pictures\\compressed_bridge.pgm";  // ���ͼ��·��

    int width, height;

    // ��ȡ PGM ͼ������
    int* p = readPGM(inputFile, width, height);
    if (!p) return -1;

    // ���ͼ���ԭʼ��С
    int n = width * height;
    cout << "ͼ����: " << width << ", �߶�: " << height << endl;
    cout << "ͼ���С: " << n << " ����" << endl;

    // ִ��ѹ��
    simpleCompression(p, n);

    // д��ѹ�����ͼ������ֻ�Ǽ�ģ��ѹ�����̣�д��ԭͼ�����ݣ�
    writePGM(outputFile, p, width, height);

    // �ͷ��ڴ�
    delete[] p;

    return 0;
}
