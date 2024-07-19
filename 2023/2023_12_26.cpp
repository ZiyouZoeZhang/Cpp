#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

void printAlphabet() {
    for (int repeat = 0; repeat < 10; ++repeat) {
        for (char c = 'A'; c <= 'Z'; ++c) {
            std::cout << c << std::flush;
            // 减速
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(50 * exp(0.05 * c))));
        }

        // 等待一段时间
        std::this_thread::sleep_for(std::chrono::seconds(1));

        for (char c = 'Z'; c >= 'A'; --c) {
            std::cout << c << std::flush;
            // 加速
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(50 * exp(0.05 * (25 - c)))));
        }

        // 等待一段时间
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::thread t(printAlphabet);

    // 等待线程结束
    t.join();

    return 0;
}
