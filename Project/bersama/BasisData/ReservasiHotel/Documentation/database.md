Berikut adalah analisis dan penjelasan dari file `database.txt` yang berisi struktur dan data awal untuk database `kuliah_basisdata_reservasi_hotel`. Saya akan menjelaskan struktur tabel, hubungan antar tabel, dan fungsi dari data yang ada.

---

### **1. Nama Database**
Database ini bernama `kuliah_basisdata_reservasi_hotel`. Database ini digunakan untuk sistem reservasi hotel, dan berisi beberapa tabel penting untuk mengelola data seperti alamat, pelanggan, reservasi, pembayaran, kamar, fasilitas, tipe kamar, dan pengguna.

---

### **2. Tabel dalam Database**

#### **a. Tabel `alamat`**
- **Struktur**:
    - `kode_alamat` (Primary Key): Kode unik untuk setiap alamat.
    - `jalan`: Nama jalan.
    - `desa`, `kota`, `provinsi`, `negara`: Detail lokasi.
    - `kode_pos`: Kode pos untuk alamat tersebut.
- **Fungsi**: Menyimpan informasi alamat pelanggan.

#### **b. Tabel `fasilitas`**
- **Struktur**:
    - `kode_fasilitas` (Primary Key): Kode unik untuk fasilitas.
    - `nama_fasilitas`: Nama fasilitas yang tersedia di hotel.
- **Fungsi**: Menyimpan daftar fasilitas yang tersedia di hotel, seperti WiFi, TV, AC, dll.

#### **c. Tabel `kamar`**
- **Struktur**:
    - `id_kamar` (Primary Key): ID unik untuk setiap kamar.
    - `id_reservasi` (Foreign Key): Menghubungkan kamar dengan reservasi tertentu.
    - `id_tipe` (Foreign Key): Menghubungkan kamar dengan tipe kamar.
    - `nomor_kamar`: Nomor kamar dalam hotel.
    - `status`: Status kamar (Occupied, Reserved, Available).
- **Fungsi**: Menyimpan informasi kamar yang tersedia, termasuk tipe kamar dan statusnya.

#### **d. Tabel `metode_pembayaran`**
- **Struktur**:
    - `kode_mp` (Primary Key): Kode unik untuk metode pembayaran.
    - `nama_metode`: Nama metode pembayaran (Transfer Bank, OVO, PayPal, dll.).
- **Fungsi**: Menyimpan metode pembayaran yang dapat digunakan oleh pelanggan.

#### **e. Tabel `pelanggan`**
- **Struktur**:
    - `id_pelanggan` (Primary Key): ID unik untuk pelanggan.
    - `nama_pelanggan`: Nama pelanggan.
    - `kode_alamat` (Foreign Key): Menghubungkan pelanggan dengan tabel alamat.
    - `no_hp`: Nomor telepon pelanggan.
    - `email`: Email pelanggan.
- **Fungsi**: Menyimpan informasi pelanggan yang melakukan reservasi.

#### **f. Tabel `pembayaran`**
- **Struktur**:
    - `id_pembayaran` (Primary Key): ID unik untuk setiap pembayaran.
    - `id_reservasi` (Foreign Key): Menghubungkan pembayaran dengan reservasi tertentu.
    - `kode_mp` (Foreign Key): Metode pembayaran yang digunakan.
    - `total_bayar`: Jumlah total pembayaran.
    - `tanggal_pembayaran`: Tanggal pembayaran dilakukan.
- **Fungsi**: Menyimpan informasi pembayaran untuk setiap reservasi.

#### **g. Tabel `reservasi`**
- **Struktur**:
    - `id_reservasi` (Primary Key): ID unik untuk setiap reservasi.
    - `id_pelanggan` (Foreign Key): Menghubungkan reservasi dengan pelanggan.
    - `tanggal_reservasi`: Tanggal reservasi dibuat.
    - `tanggal_checkin`: Tanggal check-in pelanggan.
    - `tanggal_checkout`: Tanggal check-out pelanggan.
    - `status`: Status reservasi (Confirmed, Pending, Cancelled).
- **Fungsi**: Menyimpan informasi reservasi yang dilakukan oleh pelanggan.

#### **h. Tabel `tipe_kamar`**
- **Struktur**:
    - `id_tipe` (Primary Key): ID unik untuk setiap tipe kamar.
    - `nama_tipe`: Nama tipe kamar (Standard Room, Deluxe Room, dll.).
    - `kode_fasilitas` (Foreign Key): Menghubungkan tipe kamar dengan fasilitas tertentu.
    - `biaya`: Biaya per malam untuk tipe kamar tersebut.
- **Fungsi**: Menyimpan informasi tipe kamar yang tersedia di hotel.

#### **i. Tabel `users`**
- **Struktur**:
    - `id` (Primary Key): ID unik untuk setiap pengguna.
    - `username`: Username pengguna.
    - `password`: Password terenkripsi pengguna.
    - `role`: Peran pengguna (admin atau customer).
    - `created_at`: Tanggal akun dibuat.
- **Fungsi**: Menyimpan informasi pengguna sistem (admin dan pelanggan).

---

### **3. Relasi Antar Tabel**
Relasi antar tabel dijelaskan sebagai berikut:
- **`alamat` ↔ `pelanggan`**:
    - `kode_alamat` di tabel `alamat` menjadi Foreign Key di tabel `pelanggan`.
    - Setiap pelanggan memiliki satu alamat.
- **`pelanggan` ↔ `reservasi`**:
    - `id_pelanggan` di tabel `pelanggan` menjadi Foreign Key di tabel `reservasi`.
    - Satu pelanggan dapat memiliki banyak reservasi.
- **`reservasi` ↔ `kamar`**:
    - `id_reservasi` di tabel `reservasi` menjadi Foreign Key di tabel `kamar`.
    - Satu reservasi dapat memesan beberapa kamar.
- **`reservasi` ↔ `pembayaran`**:
    - `id_reservasi` di tabel `reservasi` menjadi Foreign Key di tabel `pembayaran`.
    - Satu reservasi memiliki satu pembayaran.
- **`metode_pembayaran` ↔ `pembayaran`**:
    - `kode_mp` di tabel `metode_pembayaran` menjadi Foreign Key di tabel `pembayaran`.
    - Setiap pembayaran memiliki satu metode pembayaran.
- **`tipe_kamar` ↔ `kamar`**:
    - `id_tipe` di tabel `tipe_kamar` menjadi Foreign Key di tabel `kamar`.
    - Setiap kamar memiliki satu tipe kamar.
- **`fasilitas` ↔ `tipe_kamar`**:
    - `kode_fasilitas` di tabel `fasilitas` menjadi Foreign Key di tabel `tipe_kamar`.
    - Setiap tipe kamar memiliki fasilitas tertentu.

---

### **4. Data Awal (Seed Data)**
- **Tabel `alamat`**: Berisi data alamat pelanggan seperti jalan, kota, dan kode pos.
- **Tabel `fasilitas`**: Berisi daftar fasilitas hotel seperti WiFi, AC, TV, dll.
- **Tabel `kamar`**: Berisi daftar kamar, tipe kamar, dan status kamar.
- **Tabel `metode_pembayaran`**: Berisi daftar metode pembayaran yang tersedia.
- **Tabel `pelanggan`**: Berisi data pelanggan seperti nama, nomor telepon, dan email.
- **Tabel `pembayaran`**: Berisi data pembayaran untuk setiap reservasi.
- **Tabel `reservasi`**: Berisi data reservasi pelanggan termasuk tanggal check-in dan check-out.
- **Tabel `tipe_kamar`**: Berisi data tipe kamar beserta biaya per malam.
- **Tabel `users`**: Berisi data pengguna sistem (admin dan pelanggan).

---

### **5. Indeks dan Kunci**
- **Primary Key**: Setiap tabel memiliki Primary Key sebagai pengidentifikasi unik.
- **Foreign Key**: Relasi antar tabel menggunakan Foreign Key.
- **Index**: Beberapa tabel memiliki indeks tambahan untuk mempercepat pencarian (contoh: `username` di tabel `users`).

---

### **6. Kesimpulan**
Database ini dirancang untuk mengelola sistem reservasi hotel dengan fitur:
- Menyimpan data pelanggan, reservasi, dan pembayaran.
- Mengelola tipe kamar, fasilitas, dan status kamar.
- Mendukung berbagai metode pembayaran.
- Memiliki sistem pengguna dengan peran admin dan customer.

---
### **Mengapa Tabel Alamat Harus Di Pisahkan**
Memisahkan tabel `alamat` dari tabel `pelanggan` adalah keputusan desain database yang sering digunakan untuk **normalisasi data** dan memiliki beberapa kelebihan. Berikut adalah alasan mengapa tabel `alamat` dipisahkan dari tabel `pelanggan`:

---

### **1. Menghindari Duplikasi Data**
Jika tabel `alamat` digabungkan langsung ke tabel `pelanggan`, maka setiap kali pelanggan memiliki alamat yang sama (misalnya, pelanggan dari perusahaan yang sama atau keluarga), data alamat akan diulang-ulang. Hal ini mengakibatkan **redundansi data**.

Contoh:
Jika ada 100 pelanggan yang tinggal di "Jl. Merdeka No. 10, Bandung", maka data alamat tersebut akan disimpan sebanyak 100 kali di tabel `pelanggan`. Dengan memisahkan tabel `alamat`, data tersebut hanya perlu disimpan sekali di tabel `alamat`, dan pelanggan cukup merujuk ke `kode_alamat`.

---

### **2. Mempermudah Perubahan Data**
Jika alamat pelanggan berubah, misalnya nama jalan atau kode pos diperbarui, perubahan itu hanya perlu dilakukan di satu tempat, yaitu tabel `alamat`. Semua pelanggan yang menggunakan alamat tersebut akan secara otomatis mendapatkan data alamat yang diperbarui.

Contoh:
- Jika kode pos "40161" untuk "Jl. Merdeka No. 10, Bandung" berubah, Anda cukup mengubahnya di tabel `alamat`, tanpa harus memperbarui data di seluruh tabel `pelanggan`.

---

### **3. Mendukung Relasi Banyak ke Banyak (Many-to-Many)**
Pada beberapa sistem, satu pelanggan mungkin memiliki lebih dari satu alamat (misalnya, alamat rumah dan alamat kantor). Dengan memisahkan tabel `alamat`, Anda dapat membuat relasi **banyak ke banyak** antara pelanggan dan alamat jika diperlukan.

Contoh:
- Pelanggan `A` memiliki dua alamat: rumah dan kantor.
- Pelanggan `B` juga menggunakan alamat kantor yang sama dengan pelanggan `A`.

Dengan tabel `alamat` yang terpisah, relasi seperti ini dapat dikelola dengan tabel relasi tambahan jika diperlukan.

---

### **4. Mengurangi Ukuran Tabel `pelanggan`**
Tabel `pelanggan` menjadi lebih kecil karena hanya menyimpan `kode_alamat` sebagai referensi, bukan seluruh detail alamat (seperti jalan, kota, provinsi, negara, dan kode pos). Tabel yang lebih kecil lebih cepat diproses oleh database, terutama jika jumlah pelanggan sangat besar.

---

### **5. Fleksibilitas untuk Mengelola Data Alamat**
Dengan tabel `alamat` yang terpisah, Anda dapat:
- Menambahkan kolom baru terkait alamat tanpa memengaruhi tabel `pelanggan`.
- Menggunakan tabel `alamat` untuk entitas lain di sistem, seperti alamat hotel, kantor cabang, atau vendor.

---

### **6. Praktik Desain Database yang Baik (Normalisasi)**
Memisahkan tabel `alamat` dari tabel `pelanggan` adalah bagian dari proses **normalisasi database**, khususnya **normal form ke-3 (3NF)**. Normalisasi bertujuan untuk:
- Mengurangi redundansi data.
- Memastikan integritas data.
- Mempermudah pemeliharaan database.

---

### **Contoh Perbandingan**

#### **Jika Tidak Dipisah (Redundansi Data)**
Tabel `pelanggan`:
| id_pelanggan | nama_pelanggan | jalan               | kota     | provinsi     | kode_pos |
|--------------|----------------|---------------------|----------|--------------|----------|
| 1            | Budi Santoso   | Jl. Merdeka No. 10 | Bandung  | Jawa Barat   | 40161    |
| 2            | Ani Wijaya     | Jl. Merdeka No. 10 | Bandung  | Jawa Barat   | 40161    |
| 3            | Citra Dewi     | Jl. Malioboro No. 15 | Yogyakarta | DI Yogyakarta | 55271 |

- Data alamat "Jl. Merdeka No. 10, Bandung" diulang beberapa kali.
- Jika alamat berubah, semua baris terkait harus diperbarui.

#### **Jika Dipisah (Relasi dengan `kode_alamat`)**
Tabel `pelanggan`:
| id_pelanggan | nama_pelanggan | kode_alamat |
|--------------|----------------|-------------|
| 1            | Budi Santoso   | A001        |
| 2            | Ani Wijaya     | A001        |
| 3            | Citra Dewi     | A003        |

Tabel `alamat`:
| kode_alamat | jalan               | kota     | provinsi     | kode_pos |
|-------------|---------------------|----------|--------------|----------|
| A001        | Jl. Merdeka No. 10 | Bandung  | Jawa Barat   | 40161    |
| A003        | Jl. Malioboro No. 15 | Yogyakarta | DI Yogyakarta | 55271    |

- Tidak ada duplikasi data di tabel `alamat`.
- Jika alamat "Jl. Merdeka No. 10" berubah, Anda hanya perlu mengubahnya di tabel `alamat`.

---

### **Kesimpulan**
Memisahkan tabel `alamat` dari tabel `pelanggan` memberikan banyak keuntungan, seperti mengurangi redundansi data, mempermudah pemeliharaan, mendukung fleksibilitas relasi, dan meningkatkan efisiensi database. Ini adalah praktik desain database yang baik, terutama untuk sistem yang kompleks seperti sistem reservasi hotel.