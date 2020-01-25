#include <string>
#include <iostream>


bool strcmp(std::string s1, std::string s2) {
    return s1 == s2;
}

int main() {
    std::string ans{"abcdefghijklmn"};
    std::string s1{"abcdefghijklmm"};
    std::string s2{"bbcdefghijklmn"};

    for (int i = 0; i < 1e8; i++) {
        strcmp(s1, ans);
    }
    return 0;
}
