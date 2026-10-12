
#include <iostream>
using namespace std;

class DataStream {
private:
    int value;
    int k;
    int count;

public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        count = 0;
    }

    bool consec(int num) {
        if (num == value) {
            count++;
        } else {
            count = 0;
        }

        return count >= k;
    }
};

int main() {
    DataStream dataStream(4, 3);

    cout << boolalpha;
    cout << dataStream.consec(4) << endl;
    cout << dataStream.consec(4) << endl;
    cout << dataStream.consec(4) << endl;
    cout << dataStream.consec(3) << endl;

    return 0;
}
