#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int interpolationSearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {

        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + static_cast<int>(
            static_cast<double>(high - low) / (arr[high] - arr[low]) * (target - arr[low])
        );

        if (arr[pos] == target) {
            return pos;
        }

        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}


void findClosestSeats(const vector<int>& arr, int target) {
    int closest_less = INT_MIN;
    int closest_greater = INT_MAX;
    bool found_less = false;
    bool found_greater = false;


    for (int seat : arr) {
        if (seat < target) {
            closest_less = max(closest_less, seat);
            found_less = true;
        } else if (seat > target) {
            closest_greater = min(closest_greater, seat);
            found_greater = true;
        }
    }

    cout << "Kursi tidak tersedia. Opsi kursi terdekat:" << endl;
    if (found_less) {
        cout << "- " << closest_less << endl;
    }
    if (found_greater) {
        cout << "- " << closest_greater << endl;
    }
    if (!found_less && !found_greater) {
        cout << "Tidak ada kursi terdekat yang tersedia." << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah kursi yang tersedia: ";
    cin >> n;

    vector<int> available_seats(n);
    cout << "Masukkan " << n << " nomor kursi yang tersedia (terurut ascending): ";
    for (int i = 0; i < n; ++i) {
        cin >> available_seats[i];
    }

    int search_seat;
    cout << "Masukkan nomor kursi yang dicari: ";
    cin >> search_seat;

    int index = interpolationSearch(available_seats, search_seat);

    if (index != -1) {
        cout << "Nomor kursi yang dicari: " << search_seat << endl;
        cout << "Status: TERSEDIA" << endl;
        cout << "Posisi index: " << index << ", Nomor kursi: " << available_seats[index] << endl;
    } else {
        cout << "Nomor kursi yang dicari: " << search_seat << endl;
        cout << "Status: TIDAK TERSEDIA" << endl;
        findClosestSeats(available_seats, search_seat);
    }

    return 0;
}
