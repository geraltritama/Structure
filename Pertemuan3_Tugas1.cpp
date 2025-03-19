#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Nilai {
    float absen, tugas, uts, uas, akhir;
    char huruf;
};

struct Mahasiswa {
    string npm, nama;
    Nilai nilai;
};

const int MAX_MAHASISWA = 20;
Mahasiswa dataMahasiswa[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void clearScreen() {
    system("CLS");
}

char hitungNilaiHuruf(float nilaiAkhir) {
    if (nilaiAkhir > 80) return 'A';
    else if (nilaiAkhir > 70) return 'B';
    else if (nilaiAkhir > 60) return 'C';
    else return 'D';
}

void inputData() {
    clearScreen();
    if (jumlahMahasiswa >= MAX_MAHASISWA) {
        cout << "Data sudah penuh!\n";
        return;
    }
    Mahasiswa mhs;
    cout << "Masukkan NPM: "; cin >> mhs.npm;
    cin.ignore();
    cout << "Masukkan Nama: "; getline(cin, mhs.nama);
    cout << "Masukkan Nilai Absen: "; cin >> mhs.nilai.absen;
    cout << "Masukkan Nilai Tugas: "; cin >> mhs.nilai.tugas;
    cout << "Masukkan Nilai UTS: "; cin >> mhs.nilai.uts;
    cout << "Masukkan Nilai UAS: "; cin >> mhs.nilai.uas;

    mhs.nilai.akhir = 0.1 * mhs.nilai.absen + 0.2 * mhs.nilai.tugas + 0.3 * mhs.nilai.uts + 0.4 * mhs.nilai.uas;
    mhs.nilai.huruf = hitungNilaiHuruf(mhs.nilai.akhir);

    dataMahasiswa[jumlahMahasiswa++] = mhs;
    cout << "Data berhasil ditambahkan!\n";
    cout << "\nTekan enter untuk kembali";
    cin.ignore(); cin.get();
}

void tampilData() {
    clearScreen();
    cout << "=======================================================================================================\n";
    cout << "| " << setw(13) << "NPM" << " | " << setw(30) << "Nama" << " | " << setw(6) << "Absen"
         << " | " << setw(6) << "Tugas" << " | " << setw(6) << "UTS" << " | " << setw(6) << "UAS"
         << " | " << setw(6) << "Akhir" << " | " << setw(6) << "Huruf" << " |\n";
    cout << "=======================================================================================================\n";
    for (int i = 0; i < jumlahMahasiswa; i++) {
        Mahasiswa &mhs = dataMahasiswa[i];
        cout << "| " << setw(13) << mhs.npm << " | " << setw(30) << mhs.nama << " | " << setw(6) << mhs.nilai.absen
             << " | " << setw(6) << mhs.nilai.tugas << " | " << setw(6) << mhs.nilai.uts << " | " << setw(6) << mhs.nilai.uas
             << " | " << setw(6) << fixed << setprecision(2) << mhs.nilai.akhir << " | " << setw(6) << mhs.nilai.huruf << " |\n";
    }
    cout << "=======================================================================================================\n";
    cin.ignore(); cin.get();
}

void editData() {
    clearScreen();
    string npm;
    tampilData();
    cout << "Masukkan NPM mahasiswa yang akan diedit: "; cin >> npm;
    cin.ignore();
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (dataMahasiswa[i].npm == npm) {
            cout << "Masukkan Nama Baru: "; getline(cin, dataMahasiswa[i].nama);
            cout << "Masukkan Nilai Absen: "; cin >> dataMahasiswa[i].nilai.absen;
            cout << "Masukkan Nilai Tugas: "; cin >> dataMahasiswa[i].nilai.tugas;
            cout << "Masukkan Nilai UTS: "; cin >> dataMahasiswa[i].nilai.uts;
            cout << "Masukkan Nilai UAS: "; cin >> dataMahasiswa[i].nilai.uas;

            dataMahasiswa[i].nilai.akhir = 0.1 * dataMahasiswa[i].nilai.absen + 0.2 * dataMahasiswa[i].nilai.tugas +
                                            0.3 * dataMahasiswa[i].nilai.uts + 0.4 * dataMahasiswa[i].nilai.uas;
            dataMahasiswa[i].nilai.huruf = hitungNilaiHuruf(dataMahasiswa[i].nilai.akhir);
            cout << "Data berhasil diperbarui!\n";
            cout << "\nTekan enter untuk kembali";
            cin.ignore(); cin.get();
            return;
        }
    }
    cout << "Data tidak ditemukan!\n";
    cout << "\nTekan enter untuk kembali";
    cin.ignore(); cin.get();
}

void hapusData() {
    clearScreen();
    tampilData();
    string npm;
    cout << "Masukkan NPM mahasiswa yang akan dihapus: "; cin >> npm;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (dataMahasiswa[i].npm == npm) {
            for (int j = i; j < jumlahMahasiswa - 1; j++) {
                dataMahasiswa[j] = dataMahasiswa[j + 1];
            }
            jumlahMahasiswa--;
            cout << "Data berhasil dihapus!\n";
            cout << "\nTekan enter untuk kembali";
            cin.ignore(); cin.get();
            return;
        }
    }
    cout << "\nData tidak ditemukan!";
    cout << "\nTekan enter untuk kembali";
    cin.ignore(); cin.get();
}

int main() {
    int pilihan;
    do {
        clearScreen();
        cout << "================================\n";
        cout << "Program Manajemen Data Mahasiswa\n";
        cout << "================================\n";
        cout << "1. Input Data Mahasiswa\n";
        cout << "2. Tampilkan Data Mahasiswa\n";
        cout << "3. Edit Data Mahasiswa\n";
        cout << "4. Hapus Data Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: inputData(); break;
            case 2: tampilData(); break;
            case 3: editData(); break;
            case 4: hapusData(); break;
            case 5: cout << "\nKeluar dari program. Have a Nice day!!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
            cin.ignore(); cin.get();
        }
    } while (pilihan != 5);

    return 0;
}
