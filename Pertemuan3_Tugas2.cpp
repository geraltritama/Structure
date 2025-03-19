#include <iostream>
#include <iomanip>

using namespace std;

struct Waktu {
    int jam, menit, detik;
};

int totalDetik(Waktu w) {
    return w.jam * 3600 + w.menit * 60 + w.detik;
}

int hitungBiaya(int detik) {
    return (detik / 30) * 130;
}

void inputWaktu(Waktu &w) {
    cout << "==========================================" << endl;
    cout << "\nMasukkan waktu (format 00.00.00)\n";
    cout << "Jam yang bisa dimasukkan: 00.00.00 - 23.59.59\n";
    cout << "Input: ";
    scanf("%d.%d.%d", &w.jam, &w.menit, &w.detik);
}

int main() {
    cout << "==========================================" << endl;
    cout << "Selamat datang di Warnet Cinta Mati :)" << endl;
    cout << "==========================================" << endl;
    Waktu mulai, selesai, selisih;

    cout << "\nMasukkan waktu mulai:\n";
    inputWaktu(mulai);
    cout << "\nMasukkan waktu selesai:\n";
    inputWaktu(selesai);

    int totalMulai = totalDetik(mulai);
    int totalSelesai = totalDetik(selesai);

    if (totalSelesai < totalMulai) {
        totalSelesai += 24 * 3600;
    }

    int durasi = totalSelesai - totalMulai;

    selisih.jam = durasi / 3600;
    selisih.menit = (durasi % 3600) / 60;
    selisih.detik = durasi % 60;

    cout << "\nDurasi bermain: " << setfill('0') << setw(2) << selisih.jam << " jam "
         << setw(2) << selisih.menit << " menit " << setw(2) << selisih.detik << " detik \n";
    cout << "Total biaya: Rp. " << hitungBiaya(durasi) << " ,-\n";

    return 0;
}
