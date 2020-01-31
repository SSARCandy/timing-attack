#include <iostream>
#include <string>
#include <vector>
#include <chrono>

/**
 * strcmp source code.
 * https://code.woboq.org/userspace/glibc/string/strcmp.c.html
 */
int strcmp(const char *p1, const char *p2) {
    const unsigned char *s1 = (const unsigned char *) p1;
    const unsigned char *s2 = (const unsigned char *) p2;
    unsigned char c1, c2;
    do {
        c1 = (unsigned char) *s1++;
        c2 = (unsigned char) *s2++;
        if (c1 == '\0')
            return c1 - c2;
    } while (c1 == c2);
    return c1 - c2;
}

int main() {
    std::vector<std::string> str{
        "x2345",
        "1x345",
        "12x45",
        "123x5",
        "1234x"
    };

    for (auto ss: str) {
        auto start = std::chrono::system_clock::now();
        for (int i = 0; i < 1e9; i++) {
            strcmp("12345", ss.c_str());
        }
        std::chrono::duration<double> diff{std::chrono::system_clock::now() - start};
        std::cout << ss << ": " << diff.count() << " s\n";
    }
    return 0;
}
