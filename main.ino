// ================== STRUKTUR DATA ==================
// Struktur untuk menyimpan pin LED pada satu simpang
struct Lampu {
  int merah;   // pin LED merah
  int kuning;  // pin LED kuning
  int hijau;   // pin LED hijau
};

// Array simpang (4 arah: Utara, Timur, Selatan, Barat)
Lampu simpang[4] = {
  {2, 3, 4},    // Utara
  {5, 6, 7},    // Timur
  {8, 9, 10},   // Selatan
  {11, 12, 13}  // Barat
};

// ================== DURASI ==================
// Waktu lampu hijau (ms)
const int DURASI_HIJAU = 5000;

// Waktu lampu kuning menyala dan mati saat kedip (ms)
const int KEDIP_ON  = 300;
const int KEDIP_OFF = 300;

// Total durasi lampu kuning (ms)
const int DURASI_KUNING = 2000;

// ================== SETUP ==================
void setup() {
  // Set semua pin LED sebagai OUTPUT
  for (int i = 0; i < 4; i++) {
    pinMode(simpang[i].merah, OUTPUT);
    pinMode(simpang[i].kuning, OUTPUT);
    pinMode(simpang[i].hijau, OUTPUT);
  }

  // Kondisi awal: semua lampu merah
  resetSemua();

  // Delay awal agar sistem stabil
  delay(1000);
}

// ================== LOOP ==================
void loop() {
  // Jalankan tiap simpang secara berurutan
  for (int i = 0; i < 4; i++) {
    jalankanLampu(i);
  }
}

// ================== FUNCTION ==================

// Fungsi untuk mengatur semua lampu menjadi merah
void resetSemua() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(simpang[i].merah, HIGH);   // nyalakan merah
    digitalWrite(simpang[i].kuning, LOW);   // matikan kuning
    digitalWrite(simpang[i].hijau, LOW);    // matikan hijau
  }
}

// Fungsi untuk menjalankan 1 siklus lampu pada satu simpang
void jalankanLampu(int index) {
  resetSemua(); // pastikan semua merah dulu

  // ================= HIJAU =================
  digitalWrite(simpang[index].merah, LOW);   // matikan merah
  digitalWrite(simpang[index].hijau, HIGH);  // nyalakan hijau
  delay(DURASI_HIJAU);                       // tunggu 5 detik

  // ================= KUNING =================
  digitalWrite(simpang[index].hijau, LOW);   // matikan hijau

  int kedip = 3; // jumlah kedipan

  // Hitung waktu tiap ON/OFF agar total = 2 detik
  int waktuPerKedip = DURASI_KUNING / (kedip * 2);

  for (int i = 0; i < kedip; i++) {
    digitalWrite(simpang[index].kuning, HIGH); // nyala kuning
    delay(waktuPerKedip);

    digitalWrite(simpang[index].kuning, LOW);  // mati kuning
    delay(waktuPerKedip);
  }

  // ================= MERAH =================
  digitalWrite(simpang[index].merah, HIGH); // kembali ke merah
}
