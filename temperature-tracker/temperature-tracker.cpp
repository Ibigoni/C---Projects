#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class TemperatureTracker {
private:
    vector<double> readings;

public:
    void addReading(double temp) {
        if (readings.size() < 100)
            readings.push_back(temp);
    }

    double average() const {
        if (readings.empty()) return 0.0;
        double sum = 0.0;
        for (double t : readings) sum += t;
        return sum / readings.size();
    }

    void printReadings() const {
        cout << "Readings: ";
        for (double t : readings) cout << t << " ";
        cout << endl;
    }
};

int main() {
    TemperatureTracker tracker;
    int n;

    do {
        cout << "How many temperature readings? ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid number of readings. Must be between 1 and 100." << endl;
    } while (n < 1 || n > 100);

    for (int i = 0; i < n; ++i) {
        double temp;
        cout << "Enter temperature #" << i + 1 << ": ";
        cin >> temp;
        tracker.addReading(temp);
    }

    tracker.printReadings();
    cout << fixed << setprecision(2);
    cout << "Average temperature: " << tracker.average() << endl;

    return 0;
}
