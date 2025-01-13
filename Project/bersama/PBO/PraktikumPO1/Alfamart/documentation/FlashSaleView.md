Berikut adalah analisis dan penjelasan kode program dari file **`FlashSaleView.java`**:

---

### **Tujuan Program**
Kode ini adalah implementasi antarmuka grafis (GUI) untuk fitur flash sale pada aplikasi e-commerce Alfamart berbasis Java Swing. Fitur ini memungkinkan pengguna untuk:
1. Melihat daftar produk yang sedang diskon dalam format grid.
2. Menavigasi halaman produk menggunakan tombol "Previous" dan "Next".
3. Menambahkan produk ke keranjang belanja.
4. Menampilkan informasi produk, termasuk nama, kategori, harga asli, harga diskon, dan persentase diskon.

---

### **Struktur Kode**

#### **1. Paket dan Impor**
- **Paket**:
    - Tidak ada definisi paket eksplisit, tetapi kode ini menggunakan model `Product` untuk merepresentasikan data produk.
- **Impor**:
    - **`javax.swing.*`**: Untuk membuat komponen GUI seperti panel, tombol, label, dan dialog.
    - **`java.awt.*`**: Untuk tata letak dan pengaturan tampilan GUI.
    - **`java.sql.*`**: Untuk koneksi dan query ke database.
    - **`java.util.ArrayList`**: Untuk menyimpan daftar produk dalam memori.

---

#### **2. Atribut**
- **`products`**:
    - Menyimpan daftar produk yang sedang diskon.
- **`productsPanel`**:
    - Panel untuk menampilkan produk dalam format grid.
- **`currentPage`**:
    - Halaman produk yang sedang ditampilkan.
- **`PRODUCTS_PER_PAGE`**:
    - Jumlah produk yang ditampilkan per halaman (default: 20).
- **`COLUMNS`**:
    - Jumlah kolom dalam grid produk (default: 4).

---

### **Metode Utama**

#### **1. Konstruktor (`FlashSaleView()`)**
- **Fungsi**:
    - Menginisialisasi tampilan flash sale.
- **Proses**:
    1. Membuat daftar produk (`products`) sebagai `ArrayList`.
    2. Memanggil metode `initializeProducts()` untuk memuat data produk dari database.
    3. Membuat header, tab kategori, dan grid produk.
    4. Menambahkan semua komponen ke layout utama.

---

#### **2. `initializeProducts()`**
- **Fungsi**:
    - Memuat daftar produk diskon dari database.
- **Proses**:
    1. Membuka koneksi ke database `kuliah_basisdata_alfamart_ecommerce`.
    2. Menjalankan query untuk mengambil produk dengan diskon (`discount_percentage > 0`) dan mengurutkannya berdasarkan persentase diskon.
    3. Membuat objek `Product` untuk setiap hasil query dan menambahkannya ke `products`.
    4. Menutup koneksi database.
- **Error Handling**:
    - Menampilkan pesan error jika terjadi masalah dengan koneksi atau query database.

---

#### **3. `createHeader()`**
- **Fungsi**:
    - Membuat header aplikasi dengan logo Alfamart, kolom pencarian, dan tombol keranjang.
- **Proses**:
    1. Menampilkan logo Alfamart di sebelah kiri.
    2. Menambahkan kolom pencarian di tengah.
    3. Menambahkan tombol keranjang di sebelah kanan.
    4. Membuat panel navigasi dengan tombol seperti "Produk", "Promosi", "Keranjang", dan "Hubungi Kami".

---

#### **4. `createCategoryTabs(JPanel mainContentPanel)`**
- **Fungsi**:
    - Membuat tab kategori untuk memfilter produk berdasarkan kategori.
- **Proses**:
    1. Membuat tombol untuk setiap kategori, seperti "All", "Segera Habis", "Makanan", "Sembako", dan "Lainnya".
    2. Menambahkan event listener pada setiap tombol untuk mengatur filter kategori (belum diimplementasikan sepenuhnya).

---

#### **5. `createProductsGrid(JPanel mainContentPanel)`**
- **Fungsi**:
    - Membuat grid untuk menampilkan produk.
- **Proses**:
    1. Membuat panel utama dengan scroll pane untuk menampilkan grid produk.
    2. Menambahkan tombol pagination ("Previous" dan "Next") di bagian bawah.
    3. Memanggil `updateProductsDisplay()` untuk memuat produk ke dalam grid.
    4. Mengatur tombol pagination agar aktif atau nonaktif berdasarkan halaman saat ini.

---

#### **6. `updateProductsDisplay()`**
- **Fungsi**:
    - Memperbarui tampilan grid produk berdasarkan halaman saat ini.
- **Proses**:
    1. Menghapus semua komponen di `productsPanel`.
    2. Menentukan indeks awal dan akhir produk yang akan ditampilkan berdasarkan halaman.
    3. Menambahkan produk ke grid menggunakan metode `createProductCard`.
    4. Menambahkan panel kosong jika jumlah produk kurang dari jumlah maksimum per halaman.
    5. Melakukan revalidasi dan repaint pada `productsPanel`.

---

#### **7. `updatePaginationButtons(JButton prevButton, JButton nextButton)`**
- **Fungsi**:
    - Mengaktifkan atau menonaktifkan tombol pagination berdasarkan halaman saat ini.
- **Proses**:
    - Tombol "Previous" dinonaktifkan jika halaman saat ini adalah halaman pertama.
    - Tombol "Next" dinonaktifkan jika halaman terakhir sudah ditampilkan.

---

#### **8. `createProductCard(Product product)`**
- **Fungsi**:
    - Membuat kartu produk untuk ditampilkan di grid.
- **Proses**:
    1. Menampilkan informasi produk, seperti nama, kategori, harga asli, harga diskon, dan persentase diskon.
    2. Menambahkan tombol "Tambah ke Keranjang" dengan event listener untuk menyimpan produk ke keranjang.
    3. Menambahkan efek hover pada kartu produk (border berubah warna saat mouse masuk atau keluar).

---

#### **9. `addToCart(int productId, int quantity)`**
- **Fungsi**:
    - Menambahkan produk ke keranjang belanja di database.
- **Proses**:
    1. Membuka koneksi ke database.
    2. Menjalankan query `INSERT` untuk menambahkan produk ke tabel `cart_items`.
    3. Menutup koneksi database.
- **Error Handling**:
    - Menampilkan pesan error jika terjadi masalah dengan query atau koneksi database.

---

#### **10. `getCategoryName(int categoryId)`**
- **Fungsi**:
    - Mendapatkan nama kategori berdasarkan ID kategori dari database.
- **Proses**:
    1. Membuka koneksi ke database.
    2. Menjalankan query untuk mengambil nama kategori berdasarkan ID.
    3. Mengembalikan nama kategori atau "Unknown Category" jika ID tidak ditemukan.
    4. Menutup koneksi database.

---

### **Keunggulan Kode**
1. **Struktur Modular**:
    - Kode dibagi menjadi metode-metode kecil yang menangani tugas tertentu, seperti `initializeProducts` untuk memuat data produk dan `createProductCard` untuk membuat kartu produk.

2. **Pagination**:
    - Mendukung navigasi produk dengan tombol "Previous" dan "Next", sehingga cocok untuk menampilkan banyak produk.

3. **Interaksi dengan Database**:
    - Menggunakan query SQL untuk mengambil data produk diskon dan menyimpan data ke keranjang.

4. **Desain Responsif**:
    - Grid produk otomatis menyesuaikan jumlah produk yang ditampilkan berdasarkan halaman.

5. **Efek Visual**:
    - Menambahkan efek hover pada kartu produk untuk meningkatkan pengalaman pengguna.

---

### **Potensi Perbaikan**
1. **Validasi Input**:
    - Tambahkan validasi untuk memastikan data yang dimasukkan ke keranjang valid, seperti jumlah produk tidak melebihi stok.

2. **Optimasi Query Database**:
    - Gunakan pagination langsung di query SQL untuk mengurangi jumlah data yang diambil dari database.

3. **Pemisahan Logika Database**:
    - Pindahkan logika database ke kelas DAO untuk memisahkan logika tampilan dan akses data.

4. **Desain Modern**:
    - Gunakan JavaFX untuk tampilan yang lebih modern dan fleksibel.

5. **Dukungan Multibahasa**:
    - Simpan teks seperti "Produk berhasil ditambahkan ke keranjang!" dalam file properti untuk mendukung multibahasa.

6. **Filter Kategori**:
    - Implementasikan filter kategori pada tab kategori untuk menyaring produk berdasarkan kategori.

---

### **Kesimpulan**
Kode ini adalah implementasi yang baik untuk fitur flash sale pada aplikasi e-commerce. Dengan struktur modular, pagination, dan interaksi database, program ini cukup fungsional. Namun, beberapa area seperti validasi input, optimasi query, dan desain GUI dapat ditingkatkan untuk pengalaman pengguna yang lebih baik.