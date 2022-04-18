#include <iostream>
#include <limits>

std::string to_binary_string(unsigned int n)
{
    std::string buffer;
    buffer.reserve(std::numeric_limits<unsigned int>::digits);
    do
    {
        buffer += char('0' + n % 2);
        n = n / 2;
    } while (n > 0);
    return std::string(buffer.crbegin(), buffer.crend());
}

int hash(std::string string) {
    int result = 0;
/*    if (string.length() == 1) {
        std::cout << to_binary_string(int(string[0]));
        return std::stoi(to_binary_string(int(string[0])));
    }*/
    std::string arr[string.length()];

    for (int i = 0; i < string.length(); i++) {
        arr[i] = to_binary_string(int(string[i]));
    }

    for (int i = 0; i < 7; i++) {
        int flag = 0;
        for (int j = 0; j < string.length(); j++) {
            flag += arr[j][i] - '0';
        }
        if (flag % 2 == 1) {
            result += 1;
            result = result << 1;
        } else {
            result = result << 1;
        }
    }
    return result >> 1;

}

int main() {
    std::cout << to_binary_string(hash("asdqwerty")) << std::endl;

    return 0;
}
