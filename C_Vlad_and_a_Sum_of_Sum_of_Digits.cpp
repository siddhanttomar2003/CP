#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> ii() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::vector<int> result;
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

const int mxn = 200010;
int SS[mxn];

int dp(int n) {
    int ans = 0;
    std::string num_str = std::to_string(n);
    for (char digit : num_str) {
        ans += digit - '0';
    }
    return ans;
}

int main() {
    std::vector<int> inputs = ii();
    int t = inputs[0];

    for (int i = 0; i < mxn - 1; i++) {
        SS[i + 1] = dp(i + 1) + SS[i];
    }

    for (int i = 0; i < t; i++) {
        std::vector<int> M;
        std::vector<int> input = ii();
        int n = input[0];
        std::cout << SS[n] << std::endl;
    }

    return 0;
}
