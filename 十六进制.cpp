#include <iostream>
#include <string>
#include <cctype>

// 十六进制字符串转十进制整数
int hexToDec(const std::string& hex) {
    int decimal = 0;
    for (char c : hex) {
        if (std::isdigit(c)) {
            decimal = decimal * 16 + (c - '0');
        } else if (std::isupper(c)) {
            decimal = decimal * 16 + (c - 'A' + 10);
        } else if (std::islower(c)) {
            decimal = decimal * 16 + (c - 'a' + 10);
        }
    }
    return decimal;
}

// 十进制整数转十六进制字符串
std::string decToHex(int decimal) {
    if (decimal == 0) return "0";
    std::string hex = "";
    const std::string hexChars = "0123456789ABCDEF";
    while (decimal > 0) {
        int remainder = decimal % 16;
        hex = hexChars[remainder] + hex;
        decimal /= 16;
    }
    return hex;
}

int main() {
    std::string hex1, hex2;
    std::string choice;

    std::cout << "请输入第一个十六进制数: ";
    std::cin >> hex1;

    std::cout << "请输入第二个十六进制数: ";
    std::cin >> hex2;

    // 将十六进制字符串转换为十进制数
    int dec1 = hexToDec(hex1);
    int dec2 = hexToDec(hex2);

    std::cout << "请选择操作（aa: 相加, bb: 相乘）: ";
    std::cin >> choice;

    if (choice == "aa") {
        int sum = dec1 + dec2;
        std::string hexSum = decToHex(sum);
        std::cout << "相加结果（十六进制）: 0x" << hexSum << std::endl;
    } else if (choice == "bb") {
        int product = dec1 * dec2;
        std::string hexProduct = decToHex(product);
        std::cout << "相乘结果（十六进制）: 0x" << hexProduct << std::endl;
    } else {
        std::cout << "无效的选择，请输入 'aa' 或 'bb'。" << std::endl;
    }

    return 0;
}
