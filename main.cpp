#include <iostream>   // Library untuk input/output
#include <fstream>    // Library untuk bekerja dengan file
#include <limits>     // Library untuk mengatasi input yang tidak valid

using namespace std;

int main() {
    // Deklarasi variabel
    double celcius, fahrenheit, kelvin, reamur;
    char choice;

    // Input dari pengguna dengan validasi input
    cout << "Masukkan suhu dalam Celcius: ";
    while (!(cin >> celcius)) {
        // Jika input tidak valid, berikan pesan kesalahan dan bersihkan input
        cout << "Input tidak valid! Masukkan angka untuk suhu dalam Celcius: ";
        cin.clear();  // Menghapus kesalahan
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Mengabaikan input yang salah
    }

    // Proses konversi
    fahrenheit = (celcius * 9/5) + 32;  // Konversi ke Fahrenheit
    kelvin = celcius + 273;          // Konversi ke Kelvin
    reamur = celcius * 4/5;  //Konversi ke Reamur

    // Conditional statement
    cout << "Apakah kamu ingin menyimpan hasil ke file? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        // Menyimpan hasil ke file dengan pengecekan
        ofstream outfile("konversi_suhu.txt");
        if (outfile.is_open()) {
            outfile << "Suhu dalam Celcius: " << celcius << "°C" << endl;
            outfile << "Suhu dalam Fahrenheit: " << fahrenheit << "°F" << endl;
            outfile << "Suhu dalam Kelvin: " << kelvin << "K" << endl;
            outfile << "Suhu dalam Reamur: " << reamur << "°Re" << endl;
            outfile.close();
            cout << "Hasil telah disimpan ke file 'konversi_suhu.txt'." << endl;
        } else {
            cout << "Gagal membuka file untuk menulis hasil." << endl;
        }
    } else {
        // Output hasil ke terminal
        cout << "Suhu dalam Celcius: " << celcius << "°C" << endl;
        cout << "Suhu dalam Fahrenheit: " << fahrenheit << "°F" << endl;
        cout << "Suhu dalam Kelvin: " << kelvin << "K" << endl;
        cout << "Suhu dalam Reamur: " << reamur << "°Re" << endl;
    }

    return 0;
}
