#include <iostream>
#include <string>


using namespace std;

struct Pelanggan {
    string nama;
    int berat;
    string jenis_layanan;
    Pelanggan* next;
};


Pelanggan* buatNode(string nama, int berat, string jenis_layanan) {
    Pelanggan* nodeBaru = new Pelanggan();
    nodeBaru->nama = nama;
    nodeBaru->berat = berat;
    nodeBaru->jenis_layanan = jenis_layanan;
    nodeBaru->next = nullptr;
    return nodeBaru;
}

void sisipkanPelanggan(Pelanggan*& head, string nama, int berat, string jenis_layanan) {
    Pelanggan* nodeBaru = buatNode(nama, berat, jenis_layanan);


    if (head == nullptr) {
        head = nodeBaru;
        return;
    }


    Pelanggan* current = head;
    Pelanggan* previous = nullptr;


    if (jenis_layanan == "express") {
        while (current != nullptr && current->jenis_layanan == "express") {
            previous = current;
            current = current->next;
        }
        if (previous == nullptr) { 
            nodeBaru->next = head;
            head = nodeBaru;
        } else { 
            previous->next = nodeBaru;
            nodeBaru->next = current;
        }
    } else { 
        while (current != nullptr && current->jenis_layanan == "express") {
            previous = current;
            current = current->next;
        }
        while (current != nullptr && current->jenis_layanan == "reguler") {
            previous = current;
            current = current->next;
        }
        if (previous == nullptr) { 
            nodeBaru->next = head;
            head = nodeBaru;
        } else { 
            previous->next = nodeBaru;
            nodeBaru->next = current;
        }
    }
}

void prosesCucian(Pelanggan* head) {
    if (head == nullptr) {
        cout << "Tidak ada cucian untuk diproses." << endl;
        return;
    }

    int totalWaktu = 0;
    cout << "Urutan yang dicuci dan lama waktunya:" << endl;
    cout << "--------------------" << endl;

    Pelanggan* current = head;
    while (current != nullptr) {
        int waktuProses;
        if (current->jenis_layanan == "express") {
            waktuProses = current->berat * 5;
        } else {
            waktuProses = current->berat * 10;
        }
        totalWaktu += waktuProses;
        cout << current->nama << " (" << current->jenis_layanan << ", " << current->berat << " kg) -> Waktu: " << waktuProses << " menit" << endl;
        current = current->next;
    }

    cout << "--------------------" << endl;
    cout << "Total waktu yang dibutuhkan: " << totalWaktu << " menit" << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah pelanggan: ";
    cin >> n;
    cin.ignore(); 

    Pelanggan* head = nullptr;

    for (int i = 0; i < n; i++) {
        string nama, jenis;
        int berat;
        cout << "\nPelanggan ke-" << i + 1 << ":" << endl;
        cout << "Nama: ";
        getline(cin, nama);
        cout << "Berat (kg): ";
        cin >> berat;
        cin.ignore();
        cout << "Jenis layanan (express/reguler): ";
        getline(cin, jenis);

        sisipkanPelanggan(head, nama, berat, jenis);
    }

    cout << "\n===================================" << endl;
    prosesCucian(head);
    cout << "===================================" << endl;


    Pelanggan* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
