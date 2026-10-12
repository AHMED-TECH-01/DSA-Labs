
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Call {
public:
    int callID;
    int arrivalTime;
    int processingTime;
    string customerName;

    Call(int id, int arrival, string name, int duration) {
        callID = id;
        arrivalTime = arrival;
        customerName = name;
        processingTime = duration;
    }
};

class CallCenter {
private:
    queue<Call> calls;
    int CSR;
    vector<bool> available;
    vector<int> busyUntil;
    vector<string> currentCustomer;

public:
    CallCenter(int numberOfCSR) {
        CSR = numberOfCSR;
        available.resize(CSR, true);
        busyUntil.resize(CSR, 0);
        currentCustomer.resize(CSR, "");
    }

    void addCall(Call c) {
        calls.push(c);
    }

    void processCalls(int currentTime) {
        for (int i = 0; i < CSR; i++) {
            if (!available[i] && busyUntil[i] <= currentTime) {
                available[i] = true;
                cout << "CSR " << i + 1
                     << " completed call for "
                     << currentCustomer[i]
                     << " at time " << currentTime << endl;
            }
        }

        for (int i = 0; i < CSR; i++) {
            if (available[i] && !calls.empty()
                && calls.front().arrivalTime <= currentTime) {

                Call c = calls.front();
                calls.pop();

                available[i] = false;
                busyUntil[i] = currentTime + c.processingTime;
                currentCustomer[i] = c.customerName;

                cout << "CSR " << i + 1
                     << " handling Call " << c.callID
                     << " for " << c.customerName
                     << " at time " << currentTime << endl;
            }
        }
    }
};

int main() {
    CallCenter center(2);

    center.addCall(Call(1, 0, "Ali", 3));
    center.addCall(Call(2, 1, "Sara", 2));
    center.addCall(Call(3, 2, "Ahmed", 2));
    center.addCall(Call(4, 3, "Zara", 1));

    for (int time = 0; time <= 6; time++) {
        cout << "\nTime: " << time << endl;
        center.processCalls(time);
    }

    return 0;
}
