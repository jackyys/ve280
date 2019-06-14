#include <iostream>
#include <cassert>

using namespace std;

namespace zianke {
    bool is_jordan_polya(int num) {
        if (num == 1) {
            return true;
        } else {
            int i = 2;
            int factorial = i;
            while (factorial <= num) {
                if (num % factorial == 0 && is_jordan_polya(num / factorial)) {
                    return true;
                }
                factorial *= ++i;
            }
            return false;
        }
    }
}

namespace wangsoap {
    int factorial(int num) {
        if (num == 1) return 1;
        return (factorial(num - 1) * num);
    }

    bool is_jordan_polya(int num) {
        int n = 2;
        if (num == 1) return true;
        while (factorial(n) <= num) {
            if (num % factorial(n) == 0 && is_jordan_polya(num / factorial(n)))
                return true;
            n++;
        }
        return false;
    }
}

namespace item084 {
    bool is_jordan_polya(int num) {
        int var = num, i = 2;
        bool flag = false;

        if (num == 1) return true;

        while ((var % i) == 0) {
            var /= i;
            i++;
            flag |= is_jordan_polya(var);
        }

        return flag;
    }
}

void test_jordan_polya() {
    assert(zianke::is_jordan_polya(1));
    assert(wangsoap::is_jordan_polya(2));
    assert(item084::is_jordan_polya(4));
    assert(!zianke::is_jordan_polya(5));
    assert(wangsoap::is_jordan_polya(6));
    assert(item084::is_jordan_polya(24));
    assert(zianke::is_jordan_polya(48));
    assert(!wangsoap::is_jordan_polya(60));
    assert(item084::is_jordan_polya(72));
    assert(zianke::is_jordan_polya(120));
    assert(wangsoap::is_jordan_polya(144));
    assert(item084::is_jordan_polya(256));
    assert(zianke::is_jordan_polya(480));
    assert(wangsoap::is_jordan_polya(512));
    assert(item084::is_jordan_polya(576));
    assert(zianke::is_jordan_polya(960));
    assert(wangsoap::is_jordan_polya(1152));
    assert(item084::is_jordan_polya(1536));
    assert(zianke::is_jordan_polya(1920));
    assert(wangsoap::is_jordan_polya(4096));
    assert(item084::is_jordan_polya(5184));
    assert(zianke::is_jordan_polya(11520));
    assert(wangsoap::is_jordan_polya(12288));
    assert(item084::is_jordan_polya(20736));
    assert(zianke::is_jordan_polya(24576));
    assert(wangsoap::is_jordan_polya(25920));
    assert(item084::is_jordan_polya(30240));
    assert(zianke::is_jordan_polya(30720));
    assert(wangsoap::is_jordan_polya(32768));
    assert(item084::is_jordan_polya(57600));
    assert(zianke::is_jordan_polya(61440));
    assert(wangsoap::is_jordan_polya(62208));
    assert(item084::is_jordan_polya(65536));
    assert(zianke::is_jordan_polya(73728));
    assert(wangsoap::is_jordan_polya(92160));
    assert(item084::is_jordan_polya(93312));
    assert(zianke::is_jordan_polya(122880));
    assert(!wangsoap::is_jordan_polya(165129));
    assert(item084::is_jordan_polya(184320));
    assert(zianke::is_jordan_polya(230400));
    assert(wangsoap::is_jordan_polya(276480));
    assert(item084::is_jordan_polya(279936));
    assert(zianke::is_jordan_polya(294912));
    assert(wangsoap::is_jordan_polya(322560));
    assert(item084::is_jordan_polya(345600));
    assert(!zianke::is_jordan_polya(489657));
    assert(wangsoap::is_jordan_polya(497664));
    assert(item084::is_jordan_polya(518400));
    assert(!zianke::is_jordan_polya(533884));
    assert(wangsoap::is_jordan_polya(589824));
    assert(item084::is_jordan_polya(604800));
    assert(zianke::is_jordan_polya(663552));
    assert(wangsoap::is_jordan_polya(725760));
    assert(item084::is_jordan_polya(746496));
    assert(!zianke::is_jordan_polya(781564));
    assert(wangsoap::is_jordan_polya(884736));
    assert(item084::is_jordan_polya(921600));
    assert(zianke::is_jordan_polya(933120));
    assert(wangsoap::is_jordan_polya(967680));
    assert(item084::is_jordan_polya(983040));
    assert(zianke::is_jordan_polya(1088640));
    assert(wangsoap::is_jordan_polya(1119744));
    assert(item084::is_jordan_polya(1209600));
    assert(zianke::is_jordan_polya(1244160));
    assert(wangsoap::is_jordan_polya(1290240));
    assert(item084::is_jordan_polya(1382400));
    assert(zianke::is_jordan_polya(1658880));
    assert(wangsoap::is_jordan_polya(1679616));
    assert(item084::is_jordan_polya(1935360));
    assert(zianke::is_jordan_polya(1966080));
    assert(!wangsoap::is_jordan_polya(2088701));
    assert(!item084::is_jordan_polya(2364175));
    assert(!zianke::is_jordan_polya(2419424));
    assert(!wangsoap::is_jordan_polya(2427103));
    assert(item084::is_jordan_polya(2488320));
    assert(!zianke::is_jordan_polya(2500689));
    assert(!wangsoap::is_jordan_polya(2612670));
    assert(!item084::is_jordan_polya(2711799));
    assert(!zianke::is_jordan_polya(2889131));
    assert(wangsoap::is_jordan_polya(2949120));
    assert(!item084::is_jordan_polya(3284085));
    assert(zianke::is_jordan_polya(3456000));
    assert(!wangsoap::is_jordan_polya(3789614));
    assert(!item084::is_jordan_polya(3998740));
    assert(zianke::is_jordan_polya(4423680));
    assert(wangsoap::is_jordan_polya(4976640));
    assert(!item084::is_jordan_polya(5539397));
    assert(zianke::is_jordan_polya(5806080));
    assert(wangsoap::is_jordan_polya(6291456));
    assert(!item084::is_jordan_polya(6340713));
    assert(zianke::is_jordan_polya(6635520));
    assert(!wangsoap::is_jordan_polya(6713244));
    assert(!item084::is_jordan_polya(6837321));
    assert(!zianke::is_jordan_polya(7353895));
    assert(!wangsoap::is_jordan_polya(7791375));
    assert(!item084::is_jordan_polya(8091183));
    assert(!zianke::is_jordan_polya(8591851));
    assert(wangsoap::is_jordan_polya(9676800));
    assert(item084::is_jordan_polya(9953280));
    assert(!zianke::is_jordan_polya(10000000));
    cout << "Jordan-Polya number tests passed!" << endl;
}
