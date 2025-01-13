Berikut adalah penjelasan kode program dari file `ContactMessageDAO.java`:

---

### **Tujuan Kode**
Kode ini adalah implementasi **Data Access Object (DAO)** untuk mengelola data terkait pesan kontak (contact messages) dalam aplikasi. DAO ini bertanggung jawab untuk menyimpan dan mengambil data dari tabel `contact_messages` di database.

---

### **Struktur Kode**
1. **Paket dan Import**
    - Paket: `dao` (kode ini berada dalam paket `dao`).
    - Import:
        - `model.ContactMessage`: Kelas model untuk representasi data pesan kontak.
        - `database.DBConnection`: Kelas untuk mengelola koneksi ke database.
        - `java.sql.*`: Digunakan untuk operasi database seperti koneksi (`Connection`), pernyataan SQL (`Statement`, `PreparedStatement`), dan hasil query (`ResultSet`).
        - `java.util.ArrayList` dan `java.util.List`: Struktur data untuk menyimpan daftar pesan.

2. **Atribut**
    - **`Connection connection`**: Objek koneksi ke database yang diperoleh dari kelas `DBConnection`.

3. **Konstruktor**
    - **`ContactMessageDAO()`**: Konstruktor yang menginisialisasi atribut `connection` dengan koneksi dari `DBConnection`.

4. **Metode Utama**
    - **`save(ContactMessage message)`**
        - Fungsi: Menyimpan pesan baru ke tabel `contact_messages`.
    - **`getAllMessages()`**
        - Fungsi: Mengambil semua pesan dari tabel `contact_messages`, diurutkan berdasarkan waktu pembuatan secara menurun (terbaru di atas).

---

### **Penjelasan Detail Setiap Metode**

#### 1. **`save(ContactMessage message)`**
- **Tujuan**: Menyimpan data pesan kontak baru ke tabel database.
- **Query SQL**:
  ```sql
  INSERT INTO contact_messages (name, phone, email, message) VALUES (?, ?, ?, ?)
  ```
- **Penjelasan Proses**:
    1. Membuat pernyataan SQL `INSERT` untuk menambahkan data ke tabel `contact_messages`.
    2. Menggunakan `PreparedStatement` untuk menghindari SQL Injection.
    3. Mengatur nilai parameter:
        - `message.getName()`: Nama pengirim pesan.
        - `message.getPhone()`: Nomor telepon pengirim.
        - `message.getEmail()`: Email pengirim.
        - `message.getMessage()`: Isi pesan.
    4. Menjalankan pernyataan SQL dengan `executeUpdate()`.
    5. Mengembalikan nilai `true` jika operasi berhasil (jumlah baris yang dimodifikasi > 0).

#### 2. **`getAllMessages()`**
- **Tujuan**: Mengambil semua pesan kontak dari tabel database.
- **Query SQL**:
  ```sql
  SELECT * FROM contact_messages ORDER BY created_at DESC
  ```
- **Penjelasan Proses**:
    1. Membuat pernyataan SQL `SELECT` untuk mengambil semua data dari tabel `contact_messages`, diurutkan berdasarkan kolom `created_at` secara menurun (DESC).
    2. Menjalankan query menggunakan `Statement` dan mengambil hasilnya dalam objek `ResultSet`.
    3. Iterasi melalui setiap baris data dalam `ResultSet`:
        - Membuat objek `ContactMessage` berdasarkan data dari kolom:
            - `message_id`: ID pesan (primary key).
            - `name`: Nama pengirim.
            - `phone`: Nomor telepon pengirim.
            - `email`: Email pengirim.
            - `message`: Isi pesan.
            - `created_at`: Waktu pesan dibuat.
        - Menambahkan objek `ContactMessage` ke dalam daftar (`List<ContactMessage>`).
    4. Mengembalikan daftar pesan (`List<ContactMessage>`).

---

### **Kelebihan Kode**
1. **Keamanan Query**:
    - Menggunakan `PreparedStatement` pada metode `save()` untuk mencegah serangan SQL Injection.
2. **Modular dan Reusable**:
    - Metode-metode dalam DAO ini dapat digunakan kembali di berbagai bagian aplikasi, seperti menyimpan pesan dari form kontak atau menampilkan daftar pesan di dashboard admin.
3. **Pengurutan Data**:
    - Metode `getAllMessages()` mengurutkan pesan berdasarkan waktu pembuatan (`created_at`), sehingga pesan terbaru akan muncul lebih dulu.

---

### **Potensi Perbaikan**
1. **Error Handling**:
    - Saat ini, metode tidak memiliki mekanisme untuk menangani kesalahan secara spesifik (misalnya, logging saat terjadi SQLException).
    - Disarankan untuk menambahkan blok `catch` atau mekanisme logging agar kesalahan dapat dilacak.
2. **Koneksi Database**:
    - Koneksi database (`connection`) diinisialisasi di konstruktor, tetapi tidak ditutup setelah selesai digunakan. Sebaiknya tambahkan mekanisme untuk menutup koneksi, misalnya menggunakan `try-with-resources` juga untuk `connection`.
3. **Pagination untuk `getAllMessages()`**:
    - Jika tabel `contact_messages` memiliki banyak data, metode ini dapat menjadi tidak efisien. Disarankan untuk menambahkan fitur pagination (misalnya, membatasi jumlah pesan yang diambil dalam satu kali query).

---

### **Kesimpulan**
Kode `ContactMessageDAO` adalah implementasi DAO yang sederhana dan efektif untuk mengelola data pesan kontak. Dengan metode `save()` dan `getAllMessages()`, kode ini memungkinkan aplikasi untuk menyimpan pesan baru dan mengambil daftar semua pesan dari tabel database. Namun, ada beberapa area untuk perbaikan, seperti penanganan kesalahan dan pengelolaan koneksi database.