#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

// 读取 PGM 文件 (P5 格式)
int* readPGM(const char* filename, int& width, int& height) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "无法打开文件！" << endl;
        return nullptr;
    }

    // 读取魔术字符串 P5
    string magic;
    file >> magic;
    if (magic != "P5") {
        cerr << "文件不是 P5 格式的 PGM 图像！" << endl;
        return nullptr;
    }

    // 跳过文件中的注释（以 # 开头的行）
    char ch;
    file.get(ch);  // 获取下一字符，防止读取过程中遗留换行符
    while (ch == '#') {
        file.ignore(1000, '\n');  // 跳过注释行
        file.get(ch);  // 再次获取下一字符
    }

    // 读取宽度和高度
    file >> width >> height;
    if (width <= 0 || height <= 0) {
        cerr << "图像尺寸读取错误！宽度: " << width << ", 高度: " << height << endl;
        return nullptr;
    }

    // 读取最大像素值
    int maxVal;
    file >> maxVal;
    if (maxVal != 255) {
        cerr << "只支持最大像素值为 255 的图像！" << endl;
        return nullptr;
    }

    // 跳过换行符
    file.get();

    // 分配像素数据
    int n = width * height;
    int* p = new int[n + 1]; // 下标从 1 开始
    for (int i = 1; i <= n; ++i) {
        unsigned char pixel;
        file.read(reinterpret_cast<char*>(&pixel), 1);
        p[i] = static_cast<int>(pixel); // 存储像素值
    }

    file.close();
    return p;
}

// 压缩函数（这里只是简单模拟压缩后的大小）
void simpleCompression(int* p, int n) {
    int originalSize = n * 8; // 原图像大小（比特）
    int compressedSize = n * 4; // 假设简单压缩成原图大小的四分之一

    cout << "未压缩图像大小: " << originalSize << " 比特" << endl;
    cout << "压缩后的大小: " << compressedSize << " 比特" << endl;

    double compressionRatio = static_cast<double>(originalSize) / compressedSize;
    cout << "压缩比：原始 " << originalSize << " 比特 / 压缩 " << compressedSize << " 比特 = " << compressionRatio << endl;
}

// 将整数数组写为PGM图像
void writePGM(const char* filename, int* p, int width, int height) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "无法写入文件！" << endl;
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

// === 主函数 ===
int main() {
    const char* inputFile = "C:\\Users\\xy\\Pictures\\bridge.pgm";  // 输入图像路径
    const char* outputFile = "C:\\Users\\xy\\Pictures\\compressed_bridge.pgm";  // 输出图像路径

    int width, height;

    // 读取 PGM 图像数据
    int* p = readPGM(inputFile, width, height);
    if (!p) return -1;

    // 输出图像的原始大小
    int n = width * height;
    cout << "图像宽度: " << width << ", 高度: " << height << endl;
    cout << "图像大小: " << n << " 像素" << endl;

    // 执行压缩
    simpleCompression(p, n);

    // 写出压缩后的图像（这里只是简单模拟压缩过程，写回原图像数据）
    writePGM(outputFile, p, width, height);

    // 释放内存
    delete[] p;

    return 0;
}
