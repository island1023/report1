#include <iostream>
#include <string>
#include <cctype>

// ʮ�������ַ���תʮ��������
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

// ʮ��������תʮ�������ַ���
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

    std::cout << "�������һ��ʮ��������: ";
    std::cin >> hex1;

    std::cout << "������ڶ���ʮ��������: ";
    std::cin >> hex2;

    // ��ʮ�������ַ���ת��Ϊʮ������
    int dec1 = hexToDec(hex1);
    int dec2 = hexToDec(hex2);

    std::cout << "��ѡ�������aa: ���, bb: ��ˣ�: ";
    std::cin >> choice;

    if (choice == "aa") {
        int sum = dec1 + dec2;
        std::string hexSum = decToHex(sum);
        std::cout << "��ӽ����ʮ�����ƣ�: 0x" << hexSum << std::endl;
    } else if (choice == "bb") {
        int product = dec1 * dec2;
        std::string hexProduct = decToHex(product);
        std::cout << "��˽����ʮ�����ƣ�: 0x" << hexProduct << std::endl;
    } else {
        std::cout << "��Ч��ѡ�������� 'aa' �� 'bb'��" << std::endl;
    }

    return 0;
}
