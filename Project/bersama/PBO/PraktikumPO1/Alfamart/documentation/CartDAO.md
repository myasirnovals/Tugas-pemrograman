Berikut adalah penjelasan kode program dari file `CartDAO.java`:

---

### **Tujuan Kode**
Kode ini adalah implementasi Data Access Object (DAO) untuk mengelola data terkait keranjang belanja (cart) dalam aplikasi. DAO bertanggung jawab untuk melakukan operasi database terkait entitas `CartItem`, seperti mengambil, menambahkan, memperbarui, dan menghapus item dalam keranjang.

---

### **Struktur Kode**
1. **Paket dan Import**
    - Paket: `dao` (kode ini berada dalam paket `dao`).
    - Import:
        - `model.CartItem` dan `model.Product`: Model data untuk item keranjang dan produk.
        - `database.DBConnection`: Kelas untuk mendapatkan koneksi ke database.
        - `java.sql.*`: Digunakan untuk operasi database seperti koneksi (`Connection`), pernyataan SQL (`Statement`), dan hasil query (`ResultSet`).

2. **Atribut**
    - **`ProductDAO productDAO`**: Objek DAO lain yang digunakan untuk mengambil data produk berdasarkan ID produk.

3. **Konstruktor**
    - **`CartDAO()`**: Konstruktor yang menginisialisasi atribut `productDAO`.

4. **Metode Utama**
    - **`getAllCartItems()`**
        - Fungsi: Mengambil semua item dalam keranjang dari tabel `cart_items`.
        - Proses:
            1. Menjalankan query SQL untuk mengambil semua data dari tabel `cart_items`.
            2. Mengambil informasi seperti `cart_item_id`, `product_id`, dan `quantity`.
            3. Menggunakan metode `getProductById` dari `ProductDAO` untuk mendapatkan data produk berdasarkan `product_id`.
            4. Jika produk ditemukan, membuat objek `CartItem` dan menambahkannya ke daftar `cartItems`.
        - Return: Daftar semua item dalam keranjang (`ArrayList<CartItem>`).

    - **`updateQuantity(int cartItemId, int newQuantity)`**
        - Fungsi: Memperbarui jumlah (quantity) suatu item dalam keranjang berdasarkan `cart_item_id`.
        - Proses:
            1. Menjalankan query SQL `UPDATE` untuk memperbarui kolom `quantity` pada tabel `cart_items`.
            2. Menggunakan parameter `cartItemId` untuk menentukan item yang akan diperbarui.

    - **`deleteItem(int cartItemId)`**
        - Fungsi: Menghapus item dari keranjang berdasarkan `cart_item_id`.
        - Proses:
            1. Menjalankan query SQL `DELETE` untuk menghapus data dari tabel `cart_items`.
            2. Menggunakan parameter `cartItemId` untuk menentukan item yang akan dihapus.

    - **`addToCart(CartItem item)`**
        - Fungsi: Menambahkan item baru ke dalam keranjang.
        - Proses:
            1. Menjalankan query SQL `INSERT INTO` untuk menambahkan data ke tabel `cart_items`.
            2. Menggunakan data produk (`product_id`) dan jumlah (`quantity`) dari objek `CartItem`.

---

### **Penjelasan Detail Setiap Metode**

#### 1. **`getAllCartItems()`**
- **Query SQL**: `SELECT * FROM cart_items`
- **Fungsi Utama**:
    - Mengambil semua data dari tabel `cart_items`.
    - Menggunakan DAO lain (`ProductDAO`) untuk mendapatkan detail produk yang terkait dengan setiap item keranjang.
- **Pengecekan Produk**:
    - Jika produk ditemukan, item keranjang akan dibuat dan ditambahkan ke daftar.
    - Jika produk tidak ditemukan, item tersebut tidak akan dimasukkan ke daftar.

#### 2. **`updateQuantity(int cartItemId, int newQuantity)`**
- **Query SQL**: `UPDATE cart_items SET quantity = ? WHERE cart_item_id = ?`
- **Fungsi Utama**:
    - Memperbarui jumlah barang dalam keranjang berdasarkan ID item (`cart_item_id`).
    - Menggunakan `PreparedStatement` untuk menghindari SQL Injection.

#### 3. **`deleteItem(int cartItemId)`**
- **Query SQL**: `DELETE FROM cart_items WHERE cart_item_id = ?`
- **Fungsi Utama**:
    - Menghapus item dari keranjang berdasarkan ID item (`cart_item_id`).
    - Menggunakan `PreparedStatement` untuk keamanan query.

#### 4. **`addToCart(CartItem item)`**
- **Query SQL**: `INSERT INTO cart_items (product_id, quantity) VALUES (?, ?)`
- **Fungsi Utama**:
    - Menambahkan item baru ke keranjang.
    - Menggunakan data produk (`product_id`) dan jumlah barang (`quantity`) dari objek `CartItem`.

---

### **Kelebihan Kode**
1. **Pemanfaatan DAO Lain**: Menggunakan `ProductDAO` untuk mendapatkan data produk, sehingga kode lebih modular.
2. **Keamanan Query**: Menggunakan `PreparedStatement` untuk mencegah SQL Injection.
3. **Reusable**: Metode-metode ini dapat digunakan kembali di berbagai bagian aplikasi.

---

### **Potensi Perbaikan**
1. **Error Handling**:
    - Saat produk tidak ditemukan dalam `getAllCartItems`, sebaiknya ada log atau mekanisme untuk menangani kondisi ini.
2. **Transaksi Database**:
    - Jika ada operasi yang melibatkan beberapa query (misalnya menambahkan item dan memperbarui stok), sebaiknya menggunakan transaksi untuk menjaga konsistensi data.
3. **Optimasi Query**:
    - Dalam `getAllCartItems`, query dapat dioptimalkan dengan menggunakan `JOIN` antara tabel `cart_items` dan tabel `products`, sehingga tidak perlu memanggil `ProductDAO` berulang kali.

---

### **Kesimpulan**
Kode `CartDAO` ini adalah implementasi DAO yang berfungsi untuk mengelola data keranjang belanja. Dengan metode seperti `getAllCartItems`, `updateQuantity`, `deleteItem`, dan `addToCart`, kode ini memungkinkan aplikasi untuk melakukan operasi CRUD (Create, Read, Update, Delete) terhadap data keranjang.