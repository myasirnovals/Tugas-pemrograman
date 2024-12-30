# Dokumentasi Task.java

## Deskripsi Umum
`Task.java` adalah kelas model yang merepresentasikan sebuah tugas (task) dalam aplikasi TodoList. Kelas ini menggunakan anotasi `@RequiresApi(api = Build.VERSION_CODES.O)` karena menggunakan fitur LocalDate yang tersedia pada Android API level O (26) ke atas.

## Struktur Kelas

### 1. Atribut
```java
private int ID;                  // ID unik tugas
private String title;           // Judul tugas
private String description;     // Deskripsi tugas
private boolean priority;       // Status prioritas
private String status;         // Status tugas (Active/Done/Delayed)
private LocalDate dueDate;     // Tanggal jatuh tempo
private final DateTimeFormatter dateFormatter;  // Format tanggal
```

### 2. Format Tanggal
```java
private final DateTimeFormatter dateFormatter = 
    DateTimeFormatter.ofPattern("E dd, LLL yyyy", Locale.UK);
```
- Format: "Day dd, Month yyyy"
- Contoh: "Mon 30, Dec 2024"
- Menggunakan locale UK untuk format standar

### 3. Metode-metode

#### 3.1. Konstruktor
```java
public Task() {
    // Empty constructor
}
```

#### 3.2. Getter dan Setter Dasar
```java
// ID
public int getID()
public void setID(int ID)

// Title
public String getTitle()
public void setTitle(String title)

// Description
public String getDescription()
public void setDescription(String description)

// Priority
public boolean isPriority()
public void setPriority(boolean priority)

// Status
public String getStatus()
public void setStatus(String status)
```

#### 3.3. Penanganan Tanggal
```java
// Get/Set LocalDate object
public LocalDate getDueDate()
public void setDueDate(LocalDate dueDate)

// Get tanggal dalam format string
public String getDueDateToString()

// Set tanggal dari string
public void setDueDate(String dueDate)
```

### 4. Fitur-fitur Khusus

#### 4.1. Konversi Tanggal
- **getDueDateToString()**
    - Mengkonversi LocalDate ke String terformat
    - Format: "E dd, LLL yyyy"

- **setDueDate(String)**
    - Mengkonversi String terformat ke LocalDate
    - Menggunakan parser dengan format yang sama

### 5. Tipe Data yang Digunakan

1. **Primitif**
    - `int`: untuk ID
    - `boolean`: untuk priority

2. **String**
    - title: judul tugas
    - description: deskripsi tugas
    - status: status tugas

3. **LocalDate**
    - dueDate: tanggal jatuh tempo
    - Memerlukan Android API level O atau lebih tinggi

### 6. Status Tugas
Status tugas dapat berupa:
- "Active": Tugas aktif
- "Done": Tugas selesai
- "Delayed": Tugas terlambat

### 7. Penggunaan

```java
// Membuat task baru
Task task = new Task();
task.setID(1);
task.setTitle("Belajar Java");
task.setDescription("Mempelajari OOP dalam Java");
task.setPriority(true);
task.setStatus("Active");
task.setDueDate(LocalDate.now());

// Mengakses data task
String taskTitle = task.getTitle();
boolean isPriority = task.isPriority();
String formattedDate = task.getDueDateToString();
```

### 8. Best Practices yang Diterapkan

1. **Enkapsulasi**
    - Semua atribut private
    - Akses melalui getter/setter

2. **Pemisahan Concerns**
    - Format tanggal konsisten
    - Konversi tanggal terpusat

3. **Validasi API Level**
    - Penggunaan @RequiresApi
    - Kompatibilitas Android O+

4. **Immutable DateFormatter**
    - Formatter didefinisikan sebagai final
    - Thread-safe untuk penggunaan konkuren

Apakah Anda membutuhkan penjelasan lebih detail tentang bagian tertentu dari kelas Task ini?