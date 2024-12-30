# Dokumentasi MainActivity.java

## Deskripsi Umum
`MainActivity.java` adalah kelas utama yang menangani tampilan dan interaksi utama aplikasi TodoList. Kelas ini menampilkan daftar tugas dan menyediakan fungsi-fungsi dasar seperti menambah, mengedit, dan menghapus tugas.

## Komponen Utama

### 1. Variabel dan Inisialisasi
```java
private TextView date;
private RecyclerView tasks_list;
private Switch done_tasks;
private LocalDate liveDate;
private DateTimeFormatter shortDate;
private DateTimeFormatter displayDate;
private Database database;
private ArrayList<Task> tasksList;
private TaskAdapter adapter;
```

### 2. Metode-metode Utama

#### 2.1. onCreate()
```java
@RequiresApi(api = Build.VERSION_CODES.O)
protected void onCreate(Bundle savedInstanceState)
```
- Inisialisasi komponen UI
- Set format tanggal
- Inisialisasi database
- Setup listener untuk tombol tambah
- Setup switch untuk filter tugas selesai

#### 2.2. loadTasks()
```java
@RequiresApi(api = Build.VERSION_CODES.O)
private void loadTasks()
```
- Mengambil daftar tugas dari database
- Filter tugas berdasarkan status (jika switch aktif)
- Setup adapter untuk RecyclerView
- Mengatur swipe-to-delete

### 3. Fitur-fitur Utama

#### 3.1. Tampilan Tugas
- Menggunakan RecyclerView untuk menampilkan daftar
- Warna berbeda untuk status berbeda:
    - Active: Hijau
    - Done: Biru
    - Delayed: Merah

#### 3.2. Filter Tugas
```java
done_tasks.setOnCheckedChangeListener((buttonView, isChecked) -> loadTasks());
```
- Switch untuk menampilkan/menyembunyikan tugas selesai
- Refresh otomatis saat switch diubah

#### 3.3. Swipe to Delete
```java
private void setupSwipeToDelete()
```
- Swipe kiri untuk menghapus tugas
- Konfirmasi dialog sebelum menghapus
- Animasi dan ikon delete saat swipe
- Background merah saat swipe

#### 3.4. Navigasi ke TaskEditor
```java
// Untuk menambah tugas baru
Intent intent = new Intent(MainActivity.this, TaskEditor.class);
intent.putExtra("mode", "add");

// Untuk mengedit tugas
intent.putExtra("mode", "edit");
intent.putExtra("taskId", task.getID());
```

### 4. Adapter Kustom (ListAdapter)

```java
public class ListAdapter extends BaseAdapter
```
- Menangani tampilan individual item tugas
- Mengatur warna dan ikon berdasarkan status
- Setup onClick listener untuk edit tugas

### 5. Format Tampilan

#### 5.1. Tanggal
- Short format: "yyyy-MM-dd"
- Display format: "E dd, LLL yyyy"

#### 5.2. Item Tugas
- Judul tugas
- Deskripsi (opsional)
- Status dengan warna yang sesuai
- Tanggal jatuh tempo

### 6. Interaksi Pengguna

1. **Menambah Tugas**
    - Klik tombol tambah
    - Navigasi ke TaskEditor mode "add"

2. **Mengedit Tugas**
    - Klik pada item tugas
    - Navigasi ke TaskEditor mode "edit"

3. **Menghapus Tugas**
    - Swipe kiri pada item
    - Konfirmasi penghapusan

4. **Filter Tugas**
    - Toggle switch untuk melihat/sembunyikan tugas selesai

### 7. Penanganan Event

1. **onResume()**
    - Refresh daftar tugas saat activity kembali aktif

2. **onActivityResult()**
    - Menangani hasil dari TaskEditor
    - Menampilkan toast konfirmasi

### 8. Fitur UI/UX

1. **Visual Feedback**
    - Warna berbeda untuk setiap status
    - Animasi swipe
    - Dialog konfirmasi

2. **Layout Responsif**
    - RecyclerView untuk scrolling efisien
    - Tampilan adaptif untuk deskripsi opsional

### 9. Keamanan
- Pengecekan versi Android (RequiresApi)
- Validasi null untuk data opsional
- Konfirmasi sebelum penghapusan

Apakah Anda membutuhkan penjelasan lebih detail tentang bagian tertentu dari MainActivity ini?