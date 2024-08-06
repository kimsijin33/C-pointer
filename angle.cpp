#include <complex>
#include <vector>

// Function to compute phase angles for a complex matrix
std::vector<std::vector<double>> angle(const std::vector<std::vector<std::complex<double>>>& h) {
    int numRows = h.size();
    int numCols = h[0].size();

    std::vector<std::vector<double>> p(numRows, std::vector<double>(numCols, 0.0));

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            p[i][j] = std::atan2(h[i][j].imag(), h[i][j].real());
        }
    }

    return p;
}

int main() {
    // Example usage of the angle function
    std::vector<std::vector<std::complex<double>>> complexMatrix = {
        {std::complex<double>(1.0, 2.0), std::complex<double>(-2.0, 3.0)},
        {std::complex<double>(0.0, -1.0), std::complex<double>(3.0, 0.0)}
    };

    // Compute phase angles
    std::vector<std::vector<double>> phaseAngles = angle(complexMatrix);

    // Output phase angles (replace with your own processing)
    // ...

    return 0;
}
