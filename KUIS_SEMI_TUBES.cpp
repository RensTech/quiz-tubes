#include <iostream>
#include <string>
using namespace std;

// Fungsi rekursif untuk menghitung rata-rata nilai
float hitungRataRata(int reno[], int renoJumlah, int renoIndeks = 0, int renoTotal = 0) {
    if (renoIndeks == renoJumlah)
        return (float)renoTotal / renoJumlah; // Basis rekursif
    return hitungRataRata(reno, renoJumlah, renoIndeks + 1, renoTotal + reno[renoIndeks]); // Rekurens
}

// Fungsi untuk menentukan grade berdasarkan rata-rata
char tentukanGrade(float renoRataRata) {
    if (renoRataRata >= 85) return 'A';
    else if (renoRataRata >= 75) return 'B';
    else if (renoRataRata >= 65) return 'C';
    else if (renoRataRata >= 50) return 'D';
    else return 'E';
}

// Fungsi untuk mencari indeks nilai tertinggi
int cariIndeksNilaiTertinggi(float renoRataRata[], int renoJumlahMahasiswa) {
    int renoIndeksTertinggi = 0;
    for (int reno = 1; reno < renoJumlahMahasiswa; reno++) {
        if (renoRataRata[reno] > renoRataRata[renoIndeksTertinggi]) {
            renoIndeksTertinggi = reno;
        }
    }
    return renoIndeksTertinggi;
}

int main() {
    // Data mahasiswa dan nilai (array multidimensi)
    string renoNama[] = {"razak", "rai", "reno", "krisna", "ucok"};
    int renoNilai[][5] = {
        {85, 90, 80, 70, 88}, // Nilai Razak
        {60, 70, 65, 75, 80}, // Nilai Rai
        {95, 92, 88, 85, 90}, // Nilai Reno
        {50, 55, 60, 65, 70}, // Nilai Krisna
        {75, 78, 80, 82, 85}  // Nilai Ucok
    };

    int renoJumlahMahasiswa = 5;
    int renoJumlahMatkul = 5;
    float renoRataRata[renoJumlahMahasiswa];
    char renoGrade[renoJumlahMahasiswa];

    // Menghitung rata-rata dan grade setiap mahasiswa
    for (int reno = 0; reno < renoJumlahMahasiswa; reno++) {
        renoRataRata[reno] = hitungRataRata(renoNilai[reno], renoJumlahMatkul);
        renoGrade[reno] = tentukanGrade(renoRataRata[reno]);
    }

    // Menampilkan data mahasiswa
    cout << "Data Mahasiswa dan Nilai:\n";
    for (int reno = 0; reno < renoJumlahMahasiswa; reno++) {
        cout << "\nNama: " << renoNama[reno] << endl;
        cout << "Nilai: ";
        for (int renoMatkul = 0; renoMatkul < renoJumlahMatkul; renoMatkul++) {
            cout << renoNilai[reno][renoMatkul] << " ";
        }
        cout << "\nRata-rata: " << renoRataRata[reno] << endl;
        cout << "Grade: " << renoGrade[reno] << endl;
    }

    // Mencari dan menampilkan mahasiswa dengan nilai tertinggi
    int renoIndeksTertinggi = cariIndeksNilaiTertinggi(renoRataRata, renoJumlahMahasiswa);
    cout << "\nMahasiswa dengan nilai tertinggi:\n";
    cout << "Nama: " << renoNama[renoIndeksTertinggi] << endl;
    cout << "Rata-rata: " << renoRataRata[renoIndeksTertinggi] << endl;
    cout << "Grade: " << renoGrade[renoIndeksTertinggi] << endl;

    cin.get();
}
