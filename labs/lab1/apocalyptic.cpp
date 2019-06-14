#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

namespace item084 {
    bool is_apocalyptic(int num) {
        vector<int> vec(1, 1);

        for (int i = 1; i <= num; i++) {
            for (int j = 0; j <= vec.size() - 1; vec[j] *= 2, j++);

            for (int j = 0; (vec.size() >= 2) && (j <= vec.size() - 2); j++) {
                vec[j + 1] += vec[j] / 10;
                vec[j] = vec[j] % 10;
            }

            if (vec[vec.size() - 1] >= 10) {
                vec.push_back(vec[vec.size() - 1] / 10);
                vec[vec.size() - 2] = vec[vec.size() - 2] % 10;
            }
        }

        for (int i = 0; (vec.size() > 3) && (i <= vec.size() - 3); i++) {
            if ((vec[i] == 6) && (vec[i + 1] == 6) && vec[i + 2] == 6) return true;
        }

        return false;
    }
}

namespace TimothyGe {
	#define BASE 10
	typedef vector<int> Bign;

	Bign& self_times(Bign &a, int b) {
		int c = 0;
		for (int i = 0; i < a.size() || c != 0; ++i) {
			if (i >= a.size()) a.push_back(0); // carry 1
			a[i] = a[i] * b + c;
			c = a[i] / BASE;
			a[i] %= BASE;
		}
		return a;
	}

	bool is_apocalyptic(int num) {
		Bign a;
		a.push_back(1); // init as 1

		for (int i = 0; i < num; ++i) {
			self_times(a, 2);
		}

		if (a.size() <= 2) return false;
		for (int i = 0; i < a.size() - 2; ++i) {
			if (a[i] == 6 && a[i+1] == 6 && a[i+2] == 6) {
				return true;
			}
		}
		return false;
	}
}

void test_apocalyptic() {
    assert(!item084::is_apocalyptic(1));
    assert(!TimothyGe::is_apocalyptic(1));
    assert(item084::is_apocalyptic(157));
    assert(TimothyGe::is_apocalyptic(157));
    assert(!item084::is_apocalyptic(200));
    assert(!TimothyGe::is_apocalyptic(200));
    assert(item084::is_apocalyptic(220));
    assert(TimothyGe::is_apocalyptic(220));
    assert(item084::is_apocalyptic(931));
    assert(TimothyGe::is_apocalyptic(931));
    assert(!item084::is_apocalyptic(1700));
    assert(!TimothyGe::is_apocalyptic(1700));
    assert(item084::is_apocalyptic(1701));
    assert(TimothyGe::is_apocalyptic(1701));
    cout << "Apocalyptic number tests passed!" << endl;
}