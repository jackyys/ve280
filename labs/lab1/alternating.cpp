#include <iostream>
#include <cassert>

using namespace std;

namespace TZTsai {
    bool is_alternating_helper(int num, int base, int is_odd) {
        if (num == 0)
            return true;
        if ((num % base) % 2 == is_odd)
            return false;
        return is_alternating_helper(num / base, base, !is_odd);
    }

    bool is_alternating(int num, int base) {
        return is_alternating_helper(num / base, base, (num % base) % 2);
    }
}

namespace MxMoss3 {
    bool is_alternating(int num, int base) {

        // convert to base b
        int new_number[10];
        int new_index = 0;
        while (num != 0) {
            int digit = num % base;
            new_number[new_index] = digit;
            new_index++;

            num /= base;
        }

        //check for alternating even and odd
        for (int i = 0; i <= new_index - 2; ++i) {
            if (new_number[i] % 2 == new_number[i + 1] % 2) {
                return false;
            }
        }

        return true;
    }
}

namespace chenty0704 {
    bool is_alternating(int num, int base) {
        int digit, last_digit;
        last_digit = num % base;
        num /= base;
        while (num > 0) {
            digit = num % base;
            if ((digit + last_digit) % 2 == 0)
                return false;
            last_digit = digit;
            num /= base;
        }
        return true;
    }
}

namespace zhaomuhan {
    bool same_sign(int num1, int num2) {
        return (num1 % 2 == num2 % 2);
    }

    bool is_alternating(int num, int base) {
        int flag = 1;
        int b = base;
        while (num > 0) {
            int temp1, temp2;
            temp1 = num % b;
            num = num / b;
            if (num == 0) { break; }
            temp2 = num % b;
            if (same_sign(temp1, temp2)) { flag = 0; }
        }
        return (flag == 1);
    }
}

namespace item084 {
    bool is_alternating(int num, int base) {
        if (num < base) return true;
        else return (((num % base) + (num / base % base)) % 2) && is_alternating(num / base, base);
    }
}

void test_alternating() {
    assert(!TZTsai::is_alternating(7, 2));
    assert(MxMoss3::is_alternating(21, 2));
    assert(chenty0704::is_alternating(1521, 8));
    assert(zhaomuhan::is_alternating(2529, 8));
    assert(!item084::is_alternating(4529, 8));
    assert(TZTsai::is_alternating(1725654, 16));
    assert(!MxMoss3::is_alternating(1529046, 16));
    assert(chenty0704::is_alternating(1197057, 15));
    assert(zhaomuhan::is_alternating(1, 10));
    assert(item084::is_alternating(16, 10));
    assert(TZTsai::is_alternating(21, 10));
    assert(!MxMoss3::is_alternating(22, 10));
    assert(chenty0704::is_alternating(23, 10));
    assert(!zhaomuhan::is_alternating(24, 10));
    assert(item084::is_alternating(56, 10));
    assert(TZTsai::is_alternating(72, 10));
    assert(MxMoss3::is_alternating(74, 10));
    assert(chenty0704::is_alternating(96, 10));
    assert(zhaomuhan::is_alternating(101, 10));
    assert(item084::is_alternating(103, 10));
    assert(!TZTsai::is_alternating(177, 10));
    assert(MxMoss3::is_alternating(212, 10));
    assert(!chenty0704::is_alternating(217, 10));
    assert(zhaomuhan::is_alternating(294, 10));
    assert(item084::is_alternating(303, 10));
    assert(TZTsai::is_alternating(307, 10));
    assert(MxMoss3::is_alternating(325, 10));
    assert(!chenty0704::is_alternating(374, 10));
    assert(!zhaomuhan::is_alternating(403, 10));
    assert(item084::is_alternating(458, 10));
    assert(TZTsai::is_alternating(523, 10));
    assert(MxMoss3::is_alternating(563, 10));
    assert(!chenty0704::is_alternating(611, 10));
    assert(zhaomuhan::is_alternating(612, 10));
    assert(item084::is_alternating(638, 10));
    assert(!TZTsai::is_alternating(664, 10));
    assert(MxMoss3::is_alternating(672, 10));
    assert(!chenty0704::is_alternating(688, 10));
    assert(zhaomuhan::is_alternating(703, 10));
    assert(!item084::is_alternating(728, 10));
    assert(TZTsai::is_alternating(729, 10));
    assert(!MxMoss3::is_alternating(737, 10));
    assert(chenty0704::is_alternating(787, 10));
    assert(zhaomuhan::is_alternating(838, 10));
    assert(item084::is_alternating(874, 10));
    assert(TZTsai::is_alternating(890, 10));
    assert(MxMoss3::is_alternating(907, 10));
    assert(chenty0704::is_alternating(967, 10));
    assert(zhaomuhan::is_alternating(987, 10));
    assert(item084::is_alternating(1016, 10));
    assert(TZTsai::is_alternating(1052, 10));
    assert(MxMoss3::is_alternating(1094, 10));
    assert(!chenty0704::is_alternating(1246, 10));
    assert(zhaomuhan::is_alternating(1412, 10));
    assert(item084::is_alternating(1414, 10));
    assert(TZTsai::is_alternating(1418, 10));
    assert(MxMoss3::is_alternating(1456, 10));
    assert(chenty0704::is_alternating(1470, 10));
    assert(zhaomuhan::is_alternating(1498, 10));
    assert(item084::is_alternating(1618, 10));
    assert(TZTsai::is_alternating(1650, 10));
    assert(MxMoss3::is_alternating(1670, 10));
    assert(chenty0704::is_alternating(1694, 10));
    assert(zhaomuhan::is_alternating(1698, 10));
    assert(!item084::is_alternating(1798, 10));
    assert(TZTsai::is_alternating(1836, 10));
    assert(!MxMoss3::is_alternating(1849, 10));
    assert(chenty0704::is_alternating(1872, 10));
    assert(zhaomuhan::is_alternating(1896, 10));
    assert(!item084::is_alternating(1920, 10));
    assert(!TZTsai::is_alternating(1937, 10));
    assert(!MxMoss3::is_alternating(2033, 10));
    assert(!chenty0704::is_alternating(2098, 10));
    assert(zhaomuhan::is_alternating(2101, 10));
    assert(item084::is_alternating(2163, 10));
    assert(TZTsai::is_alternating(2189, 10));
    assert(!MxMoss3::is_alternating(2190, 10));
    assert(!chenty0704::is_alternating(2201, 10));
    assert(zhaomuhan::is_alternating(2301, 10));
    assert(!item084::is_alternating(2316, 10));
    assert(TZTsai::is_alternating(2323, 10));
    assert(MxMoss3::is_alternating(2361, 10));
    assert(!chenty0704::is_alternating(2448, 10));
    assert(!zhaomuhan::is_alternating(2454, 10));
    assert(!item084::is_alternating(2476, 10));
    assert(TZTsai::is_alternating(2523, 10));
    assert(MxMoss3::is_alternating(2563, 10));
    assert(chenty0704::is_alternating(2569, 10));
    assert(!zhaomuhan::is_alternating(2570, 10));
    assert(item084::is_alternating(2585, 10));
    assert(!TZTsai::is_alternating(2586, 10));
    assert(!MxMoss3::is_alternating(2646, 10));
    assert(chenty0704::is_alternating(2721, 10));
    assert(zhaomuhan::is_alternating(2747, 10));
    assert(item084::is_alternating(2767, 10));
    assert(TZTsai::is_alternating(2905, 10));
    assert(!MxMoss3::is_alternating(2926, 10));
    assert(!chenty0704::is_alternating(2972, 10));
    assert(zhaomuhan::is_alternating(3018, 10));
    assert(item084::is_alternating(3030, 10));
    assert(TZTsai::is_alternating(3052, 10));
    assert(MxMoss3::is_alternating(3096, 10));
    assert(!chenty0704::is_alternating(3099, 10));
    assert(!zhaomuhan::is_alternating(3241, 10));
    assert(!item084::is_alternating(3305, 10));
    assert(!TZTsai::is_alternating(3323, 10));
    assert(MxMoss3::is_alternating(3416, 10));
    assert(!chenty0704::is_alternating(3447, 10));
    cout << "Alternating number tests passed!" << endl;
}
