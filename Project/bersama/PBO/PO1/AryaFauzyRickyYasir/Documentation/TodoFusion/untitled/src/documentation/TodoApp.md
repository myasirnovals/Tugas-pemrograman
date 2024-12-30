# Dokumentasi TodoApp.java

## Deskripsi Umum
`TodoApp.java` adalah kelas aplikasi utama yang meng-extend `Application`. Kelas ini bertanggung jawab untuk inisialisasi komponen-komponen dasar aplikasi yang diperlukan saat aplikasi pertama kali dijalankan.

## Struktur Kode

```java
package org.kelompok3.todolistapp;

import android.app.Application;
import com.jakewharton.threetenabp.AndroidThreeTen;

public class TodoApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        AndroidThreeTen.init(this);
    }
}
```

## Komponen Utama

### 1. Inheritance
- Extends `Application` class yang merupakan base class untuk menjaga state aplikasi global

### 2. Library Initialization
- Menggunakan `AndroidThreeTen` untuk menangani operasi tanggal dan waktu
- Inisialisasi dilakukan di `onCreate()`

## Fungsi

1. **Inisialisasi AndroidThreeTen**
    - Library ini adalah backport dari Java 8 Time API
    - Menyediakan fungsionalitas modern untuk penanganan tanggal dan waktu
    - Penting untuk aplikasi yang membutuhkan manipulasi tanggal yang akurat

2. **Application Lifecycle**
    - `onCreate()` dipanggil saat aplikasi pertama kali dijalankan
    - Memastikan library tanggal tersedia di seluruh aplikasi

## Penggunaan

1. Dideklarasikan di `AndroidManifest.xml`:
```xml
<application
    android:name=".TodoApp"
    ...
    >
```

2. Memungkinkan penggunaan kelas-kelas seperti:
    - `LocalDate`
    - `LocalTime`
    - `LocalDateTime`
    - Dan kelas-kelas terkait waktu lainnya

## Pentingnya File Ini

1. **Inisialisasi Global**
    - Menyediakan titik masuk untuk inisialisasi komponen aplikasi
    - Memastikan library date/time tersedia sebelum digunakan

2. **Konsistensi Data**
    - Menjamin konsistensi penanganan tanggal di seluruh aplikasi
    - Menghindari masalah kompatibilitas dengan versi Android yang berbeda

3. **Best Practice**
    - Mengikuti praktik terbaik dalam pengembangan Android
    - Memisahkan konfigurasi aplikasi dari logika bisnis

File ini meskipun sederhana, namun sangat penting untuk fungsionalitas aplikasi TodoList, terutama dalam penanganan tanggal dan waktu yang digunakan dalam manajemen tugas.