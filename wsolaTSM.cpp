#include <vector>
#include <cmath>
#include <corecrt_math_defines.h>

// Function to calculate the Hann window
std::vector<double> hann(int len) {
    std::vector<double> window(len);

    for (int i = 0; i < len; ++i) {
        window[i] = 0.5 * (1 - cos(2 * M_PI * i / (len - 1)));
    }

    return window;
}

// Function to perform cross correlation
std::vector<double> crossCorr(const std::vector<double>& x, const std::vector<double>& y, int winLen) {
    int resultLen = x.size() + y.size() - 1;
    std::vector<double> cc(resultLen, 0.0);

    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < y.size(); ++j) {
            cc[i + j] += x[i] * y[j];
        }
    }

    // Restrict the result to the relevant values
    cc.erase(cc.begin(), cc.begin() + winLen - 1);
    cc.erase(cc.begin() + x.size(), cc.end() - winLen + 1);

    return cc;
}

// Function to perform WSOLA time-scale modification
void wsolaTSM(const std::vector<double>& x, const std::vector<std::vector<double>>& s, std::vector<double>& y, int synHop, const std::vector<double>& win, int tolerance) {
    int winLen = win.size();
    int winLenHalf = winLen / 2;

    std::vector<double> xC = x;
    int numOfChan = s[0].size();
    int synWinPos = 0;
    int del = 0;

    for (int i = 0; i < s.size() - 1; ++i) {
        int currSynWinRan = synWinPos;
        int currAnaWinRan = s[i][1] + del;

        for (int j = 0; j < winLen; ++j) {
            y[currSynWinRan] += xC[currAnaWinRan] * win[j];
            ++synWinPos;
            ++currSynWinRan;
            ++currAnaWinRan;
        }

        int natProg = xC[currAnaWinRan + synHop];

        int nextAnaWinRan = s[i + 1][0] - tolerance;
        int xNextAnaWinRanEnd = s[i + 1][0] + winLen - 1 + tolerance;

        std::vector<double> xNextAnaWinRan(xC.begin() + nextAnaWinRan, xC.begin() + xNextAnaWinRanEnd);
        std::vector<double> natProgSegment(xC.begin() + currAnaWinRan, xC.begin() + currAnaWinRan + synHop);

        std::vector<double> cc = crossCorr(xNextAnaWinRan, natProgSegment, winLen);

        int maxIndex = 0;
        double maxCC = 0;
        for (int k = 0; k < cc.size(); ++k) {
            if (cc[k] > maxCC) {
                maxCC = cc[k];
                maxIndex = k;
            }
        }

        del = tolerance - maxIndex + 1;
    }

    int lastFrameStart = synWinPos;
    int lastFrameEnd = lastFrameStart + winLen - 1;

    for (int i = lastFrameStart; i <= lastFrameEnd; ++i) {
        y[i] += xC[s[i + del][1]] * win[i - lastFrameStart];
    }

    for (int i = 0; i < y.size(); ++i) {
        y[i] /= win[i - lastFrameStart];
    }
}

int main() {
    // Input signal x (replace with your own data)
    std::vector<double> x;

    // Time-stretch factor s (replace with your own data)
    std::vector<std::vector<double>> s;

    // Parameters
    int synHop = 512;
    std::vector<double> win = hann(1024);
    int tolerance = 512;

    // Initialize the output signal y
    int outputLength = s[s.size() - 1][1];
    std::vector<double> y(outputLength, 0.0);

    // Perform WSOLA time-scale modification
    wsolaTSM(x, s, y, synHop, win, tolerance);

    // Output the final signal y (replace with your own processing)
    // ...

    return 0;
}
