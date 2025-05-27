//磁带最优存储问题
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

// 磁带结构体
struct Tape {
    int length;  // 磁带长度
    int prob;    // 磁带概率
    double weight; // 磁带权重 = length * prob

    // 构造函数初始化并计算权重
    Tape(int l = 0, int p = 0) : length(l), prob(p), weight(l * p) {}
};

// 比较函数，用于排序
bool cmp(Tape a, Tape b) {
    return a.weight < b.weight;  // 按权重从小到大排序
}

// 计算最小查找时间
double greedy(int N, Tape* tapes, long long sum) {
    double totalTime = 0.0;  // 总时间
    double accumulatedTime = 0.0;  // 累积时间

    // 遍历排序后的磁带，计算加权平均查找时间
    for (int i = 0; i < N; i++) {
        accumulatedTime += tapes[i].weight / (double)sum;  // 累计访问代价
        totalTime += accumulatedTime;  // 总时间
    }

    return totalTime;
}

int main() {
    int N;
    long long sum = 0;

    // 输入文件路径（绝对路径）
    string inputFilePath = "C:\\Users\\islan\\Desktop\\input.txt";
    string outputFilePath = "C:\\Users\\islan\\Desktop\\output.txt";

    // 打开输入文件
    ifstream inputFile(inputFilePath);
    if (!inputFile) {
        cout << "无法打开输入文件!" << endl;
        return 1; // 退出程序
    }

    // 读取磁带数量
    inputFile >> N;

    // 创建磁带数组
    Tape tapes[100];  // 假设最多有100个磁带

    // 读取每个磁带的长度和概率
    for (int i = 0; i < N; i++) {
        int length, prob;
        inputFile >> length >> prob;
        tapes[i] = Tape(length, prob);
        sum += prob;  // 累加概率
    }

    inputFile.close(); // 关闭输入文件

    // 将磁带按权重（length * prob）排序
    sort(tapes, tapes + N, cmp);

    // 使用贪心算法计算最小查找时间
    double result = greedy(N, tapes, sum);

    // 打开输出文件
    ofstream outputFile(outputFilePath);
    if (!outputFile) {
        cout << "无法打开输出文件!" << endl;
        return 1; // 退出程序
    }

    // 输出结果到文件，并设置输出精度
    outputFile << fixed << setprecision(4) << result;
    outputFile.close(); // 关闭输出文件

    // 控制台提示
    cout << "输出完成" << endl;

    system("pause");
    return 0;
}
