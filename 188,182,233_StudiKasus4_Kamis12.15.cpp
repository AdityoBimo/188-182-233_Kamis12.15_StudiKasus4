#include <iostream>
using namespace std;

class Keuangan {
    friend ostream &operator<<(ostream &out, const Keuangan &keluar);
    friend istream &operator>>(istream &in, Keuangan &masuk);

private:
    int uangSaku;
    int pengeluaran[12];
    int tabungan[12];

public:
    void inputData() {
        cout << "Masukkan jumlah uang saku tetap per bulan: ";
        cin >> uangSaku;
        for (int i = 0; i < 12; i++) {
            cout << "Masukkan pengeluaran bulan ke-" << i + 1 << ": ";
            cin >> pengeluaran[i];
            tabungan[i] = uangSaku - pengeluaran[i];
        }
    }

    void tampilkanIteratif() const{
        cout << "\n--- Data Keuangan Andi ---\n";
        for (int i = 0; i < 12; i++) {
            cout << "Bulan " << i + 1 << ": Pengeluaran = Rp." << pengeluaran[i] << " , Tabungan    = Rp." << tabungan[i] << endl;
        }
    }

    int hitungTotalPengeluaran(int bulan) const{
        if (bulan == 0) return pengeluaran[0];
        return pengeluaran[bulan] + hitungTotalPengeluaran(bulan - 1);
    }

    int hitungTotalPengeluaran() const {
        return hitungTotalPengeluaran(11);
    }

    int hitungTotalTabungan(int bulan) const{
        if (bulan == 0) return tabungan[0];
        return tabungan[bulan] + hitungTotalTabungan(bulan - 1);
    }

    int hitungTotalTabungan() const {
        return hitungTotalTabungan(11);
    }

    void tampilkanTotal() const{
        int totalPengeluaran = hitungTotalPengeluaran();
        int totalTabungan = hitungTotalTabungan();
        cout << "\n>> Total Pengeluaran selama 12 bulan: " << totalPengeluaran << endl;
        cout << ">> Total Tabungan selama 12 bulan: " << totalTabungan << endl;
    }
};

istream &operator>>(istream &in, Keuangan &masuk) {
    masuk.inputData();
    return in;
}

ostream &operator<<(ostream &out, const Keuangan &keluar) {
    keluar.tampilkanIteratif();
    keluar.tampilkanTotal();
    return out;
}

int main() {
    Keuangan andi;
    cin >> andi;
    cout << andi;
    return 0; 
}

