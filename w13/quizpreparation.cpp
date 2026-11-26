#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// 1. Pendefinisian Struktur Data (struct)
struct Mahasiswa {
    string nrp;
    string nama;
    char kelasParalel;
    double nilaiKuis;
    double nilaiETS;
    double nilaiEAS;
    double nilaiAkhir;
};

// Fungsi bantu validasi input numerik dalam rentang 0 - 100
double inputNilaiValid(const string& label) {
    double nilai;
    while (true) {
        cout << label;
        if (cin >> nilai && nilai >= 0.0 && nilai <= 100.0) {
            cin.ignore(1000, '\n');
            return nilai;
        }
        cout << "  [Error] Masukkan angka valid antara 0 hingga 100.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

// 2. Penginputan Data Mahasiswa ke Array of Struct
void inputDataMahasiswa(Mahasiswa mhs[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "\n--- Input Data Mahasiswa ke-" << (i + 1) << " ---\n";

        while (true) {
            cout << "NRP           : ";
            getline(cin, mhs[i].nrp);
            if (!mhs[i].nrp.empty()) break;
            cout << "  [Error] NRP tidak boleh kosong.\n";
        }

        while (true) {
            cout << "Nama          : ";
            getline(cin, mhs[i].nama);
            if (!mhs[i].nama.empty()) break;
            cout << "  [Error] Nama tidak boleh kosong.\n";
        }

        while (true) {
            cout << "Kelas Paralel : ";
            string kelasInput;
            getline(cin, kelasInput);

            if (kelasInput.length() == 1) {
                char c = kelasInput[0];
                if (c >= 'a' && c <= 'z') {
                    c = c - ('a' - 'A');
                }
                if (c >= 'A' && c <= 'Z') {
                    mhs[i].kelasParalel = c;
                    break;
                }
            }
            cout << "  [Error] Masukkan 1 huruf kelas paralel (misal: A, B, C).\n";
        }

        mhs[i].nilaiKuis = inputNilaiValid("Nilai Kuis    : ");
        mhs[i].nilaiETS  = inputNilaiValid("Nilai ETS     : ");
        mhs[i].nilaiEAS  = inputNilaiValid("Nilai EAS     : ");
        mhs[i].nilaiAkhir = 0.0;
    }
}

// 3. Perhitungan Nilai Akhir
void hitungNilaiAkhir(Mahasiswa mhs[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        mhs[i].nilaiAkhir = (0.2 * mhs[i].nilaiKuis) +
                            (0.4 * mhs[i].nilaiETS) +
                            (0.4 * mhs[i].nilaiEAS);
    }
}

// 4. Penampilan Data dalam Format Tabel
void tampilkanTabel(const Mahasiswa mhs[], int jumlah) {
    cout << "\n=========================================================================================\n";
    cout << left
         << setw(14) << "NRP"
         << setw(22) << "Nama"
         << setw(8)  << "Kelas"
         << right
         << setw(10) << "Kuis"
         << setw(10) << "ETS"
         << setw(10) << "EAS"
         << setw(15) << "Nilai Akhir" << '\n';
    cout << "=========================================================================================\n";

    cout << fixed << setprecision(2);
    for (int i = 0; i < jumlah; i++) {
        cout << left
             << setw(14) << mhs[i].nrp
             << setw(22) << mhs[i].nama
             << setw(8)  << mhs[i].kelasParalel
             << right
             << setw(10) << mhs[i].nilaiKuis
             << setw(10) << mhs[i].nilaiETS
             << setw(10) << mhs[i].nilaiEAS
             << setw(15) << mhs[i].nilaiAkhir << '\n';
    }
    cout << "=========================================================================================\n";
}

// 5. Analisis Data: Rata-rata Nilai Akhir
double hitungRataRataAkhir(const Mahasiswa mhs[], int jumlah) {
    if (jumlah <= 0) return 0.0;
    double total = 0.0;
    for (int i = 0; i < jumlah; i++) {
        total += mhs[i].nilaiAkhir;
    }
    return total / jumlah;
}

// 6. Penyimpanan Data ke Dalam File (Format CSV dipisah koma)
bool simpanKeFile(const string& namaFile, const Mahasiswa mhs[], int jumlah) {
    ofstream outFile(namaFile);
    if (!outFile.is_open()) {
        cerr << "[Error] Gagal membuka file '" << namaFile << "' untuk penyimpanan.\n";
        return false;
    }

    outFile << fixed << setprecision(2);
    for (int i = 0; i < jumlah; i++) {
        outFile << mhs[i].nrp << ","
                << mhs[i].nama << ","
                << mhs[i].kelasParalel << ","
                << mhs[i].nilaiKuis << ","
                << mhs[i].nilaiETS << ","
                << mhs[i].nilaiEAS << ","
                << mhs[i].nilaiAkhir << '\n';
    }

    if (outFile.fail()) {
        cerr << "[Error] Terjadi kesalahan saat menulis data ke file.\n";
        outFile.close();
        return false;
    }

    outFile.close();
    cout << "\n[Sukses] Seluruh data berhasil disimpan ke '" << namaFile << "'.\n";
    return true;
}

// 7. Pembacaan Data dari File CSV Sederhana (tanpa <sstream>)
int bacaDariFile(const string& namaFile, Mahasiswa mhs[], int kapasitasMaks) {
    ifstream inFile(namaFile);
    if (!inFile.is_open()) {
        cerr << "[Error] Gagal membuka file '" << namaFile << "' untuk pembacaan.\n";
        return 0;
    }

    int indeks = 0;
    char koma;

    while (indeks < kapasitasMaks && getline(inFile, mhs[indeks].nrp, ',')) {
        if (mhs[indeks].nrp.empty()) break;

        getline(inFile, mhs[indeks].nama, ',');

        if (!(inFile >> mhs[indeks].kelasParalel >> koma
                     >> mhs[indeks].nilaiKuis >> koma
                     >> mhs[indeks].nilaiETS >> koma
                     >> mhs[indeks].nilaiEAS >> koma
                     >> mhs[indeks].nilaiAkhir)) {
            break;
        }

        // Buang sisa karakter newline ('\n') di akhir baris sebelum baca record berikutnya
        inFile.ignore(1000, '\n');
        indeks++;
    }

    inFile.close();
    return indeks;
}

int main() {
    const int JUMLAH_MHS = 7;
    const string NAMA_FILE = "data_nilai_mahasiswa.csv";

    Mahasiswa daftarMhs[JUMLAH_MHS];

    inputDataMahasiswa(daftarMhs, JUMLAH_MHS);
    hitungNilaiAkhir(daftarMhs, JUMLAH_MHS);

    cout << "\n>>> DATA NILAI MAHASISWA <<<";
    tampilkanTabel(daftarMhs, JUMLAH_MHS);

    double rataAkhir = hitungRataRataAkhir(daftarMhs, JUMLAH_MHS);
    cout << fixed << setprecision(2);
    cout << "Rata-rata Nilai Akhir Kelas : " << rataAkhir << '\n';

    if (simpanKeFile(NAMA_FILE, daftarMhs, JUMLAH_MHS)) {
        Mahasiswa dataTerbaca[JUMLAH_MHS];
        int jumlahTerbaca = bacaDariFile(NAMA_FILE, dataTerbaca, JUMLAH_MHS);

        cout << "\n>>> DATA HASIL PEMBACAAN DARI FILE (" << jumlahTerbaca << " baris) <<<";
        tampilkanTabel(dataTerbaca, jumlahTerbaca);
    }

    return 0;
}