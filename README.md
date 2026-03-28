# 🚦 Traffic Light 4 Arah - Arduino

## Deskripsi
Project ini merupakan simulasi sistem lampu lalu lintas (traffic light) 4 arah menggunakan Arduino. Sistem dirancang untuk mengatur nyala lampu secara otomatis dan bergiliran pada setiap simpang: **Utara → Timur → Selatan → Barat**, lalu mengulang terus (looping).

Simulasi dilakukan menggunakan Tinkercad, sehingga project ini dapat dijalankan tanpa menggunakan hardware secara langsung.

---

## Tujuan Project
- Menerapkan konsep GPIO pada Arduino Uno  
- Membuat sistem traffic light otomatis 4 arah  
- Menghindari konflik lampu hijau (hanya satu arah aktif)  
- Melatih logika pemrograman Arduino (fungsi & looping)  

---

## Cara Kerja Sistem
Sistem bekerja dengan urutan sebagai berikut:

1. Semua lampu dalam kondisi **MERAH** (default)
2. Salah satu arah aktif:
   - 🟢 Hijau menyala selama **5 detik**
   - 🟡 Kuning berkedip **3 kali (total 2 detik)**
   - 🔴 Kembali ke merah
3. Sistem berpindah ke arah berikutnya
4. Proses berjalan terus menerus (looping)

---

## Komponen yang Digunakan
- Arduino Uno  
- Breadboard  
- 12 LED (Merah, Kuning, Hijau × 4 arah)  
- Resistor (220Ω – 330Ω)  
- Kabel jumper  

---

## 🔌 Konfigurasi Pin

| Arah    | Merah | Kuning | Hijau |
|---------|------|--------|-------|
| Utara   | 2    | 3      | 4     |
| Timur   | 5    | 6      | 7     |
| Selatan | 8    | 9      | 10    |
| Barat   | 11   | 12     | 13    |

---

## Struktur Program
Program dibuat dengan pendekatan modular agar lebih rapi dan mudah dipahami:

- `struct Lampu` → menyimpan data pin tiap simpang  
- `resetSemua()` → mengatur semua lampu menjadi merah  
- `jalankanLampu(index)` → menjalankan 1 siklus lampu  
- `loop()` → mengatur urutan simpang secara berulang  

---

## Cara Menjalankan

### Via Tinkercad
1. Buka link simulasi
2. Klik **Start Simulation**
3. Amati perubahan lampu

### Via Arduino IDE
1. Hubungkan Arduino ke laptop
2. Upload kode ke board
3. Pastikan wiring sesuai konfigurasi pin

---

## Dokumentasi & Link Simulasi
https://www.tinkercad.com/things/grsoeJjgQGT-tugas-3-psth1d023035?sharecode=nO8LD_zUN39QV2fiSa5nZtPowEGhcIRYNZdUZE8BiBI
<img width="1920" height="814" alt="TUGAS 3 PST_H1D023035" src="https://github.com/user-attachments/assets/f09cc2cc-09f6-4206-98a1-5aaea67dcaac" />

