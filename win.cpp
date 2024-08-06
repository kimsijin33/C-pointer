#include <iostream>
#include <vector>
#include <cmath>
#include "win.h"
#include <corecrt_math_defines.h>

std::vector<double> win(int len, double beta) {
    std::vector<double> w(len);

    for (int i = 0; i < len; i++) {
        double value = sin(M_PI * static_cast<double>(i) / len);
        w[i] = pow(value, beta);
    }

    return w;
}

int main() {
    int len = 256;        // â�� ���� ����
    double beta = 2.0;    // ��Ÿ �� ����

    std::vector<double> window = win(len, beta);

    // ������ â ���� ���
    for (int i = 0; i < len; i++) {
        std::cout << window[i] << " ";
    }

    return 0;
}
