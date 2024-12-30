# Dokumentasi Database.java

## Deskripsi Umum
`Database.java` adalah kelas yang menangani operasi penyimpanan data untuk aplikasi TodoList. Kelas ini menggunakan format JSON untuk menyimpan data tugas di penyimpanan internal Android.

## Komponen Utama

### 1. Variabel dan Konstanta
```java
private final Context context;
private static final String FILE_PREFIX = "tasks_";
private final DateTimeFormatter dateFormatter;
```
- `context`: Konteks Android untuk akses file
- `FILE_PREFIX`: Prefix untuk nama file JSON
- `dateFormatter`: Format tanggal "yyyy-MM-dd"

### 2. Metode-metode Utama

#### 2.1. Konstruktor
```java
public Database(Context context) {
    this.context = context;
}
```
Inisialisasi database dengan konteks Android.

#### 2.2. Operasi File
1. **createDatabase(String date)**
    - Membuat file JSON baru jika belum ada
    - Format file: "tasks_[tanggal].json"
    - Struktur awal: `{"tasks": []}`

2. **getFileName(String date)**
    - Menghasilkan nama file berdasarkan tanggal
    - Format: "tasks_[tanggal].json"

#### 2.3. Operasi CRUD

##### Create
```java
public boolean insertTask(String date, Task task)
```
- Menambah tugas baru ke database
- Mengatur ID otomatis
- Mengatur status default "Active"
- Return: `true` jika berhasil

##### Read
1. **getTasks(String date)**
    - Mengambil semua tugas dari tanggal tertentu
    - Return: ArrayList<Task>

2. **readTask(String date, int ID)**
    - Mengambil satu tugas berdasarkan ID
    - Return: Task object atau null

##### Update
```java
public boolean updateTask(String date, Task task)
```
- Memperbarui tugas yang ada
- Mencari berdasarkan ID
- Return: `true` jika berhasil

##### Delete
```java
public void deleteTask(String date, int ID)
```
- Menghapus tugas berdasarkan ID
- Membuat array baru tanpa tugas yang dihapus

### 3. Metode Utilitas

#### 3.1. File Operations
1. **readJsonFile(String date)**
    - Membaca file JSON
    - Menggunakan FileInputStream
    - Penanganan resource dengan try-finally

2. **writeJsonFile(String date, JSONObject jsonData)**
    - Menulis ke file JSON
    - Menggunakan FileOutputStream
    - Penanganan resource dengan try-finally

3. **ensureFileExists(String date)**
    - Memastikan file database ada
    - Membuat file baru jika belum ada

### 4. Format Data JSON
```json
{
    "tasks": [
        {
            "id": integer,
            "title": string,
            "description": string,
            "priority": boolean,
            "status": string,
            "dueDate": "yyyy-MM-dd"
        }
    ]
}
```

### 5. Penanganan Error
- Menggunakan try-catch untuk operasi file
- Logging error dengan Log.e
- Proper resource cleanup dengan try-finally

### 6. Dependensi
- org.threeten.bp.LocalDate: Penanganan tanggal
- org.json: Manipulasi JSON
- android.util.Log: Logging
- java.io: Operasi file

## Penggunaan

```java
// Inisialisasi
Database db = new Database(context);

// Membuat database untuk tanggal tertentu
db.createDatabase("2024-12-30");

// Menambah tugas
Task task = new Task();
// Set properti task
db.insertTask("2024-12-30", task);

// Mengambil semua tugas
ArrayList<Task> tasks = db.getTasks("2024-12-30");

// Mengupdate tugas
task.setTitle("New Title");
db.updateTask("2024-12-30", task);

// Menghapus tugas
db.deleteTask("2024-12-30", taskId);
```

## Catatan Penting
1. Selalu gunakan try-catch untuk menangani IOException
2. Pastikan menutup file streams
3. Validasi input sebelum operasi database
4. Perhatikan format tanggal yang konsisten

Apakah Anda membutuhkan penjelasan lebih detail tentang bagian tertentu dari kelas Database ini?