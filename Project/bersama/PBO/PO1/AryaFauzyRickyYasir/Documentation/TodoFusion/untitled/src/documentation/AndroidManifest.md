# Dokumentasi AndroidManifest.xml

## Deskripsi Umum
AndroidManifest.xml adalah file konfigurasi utama aplikasi Android yang berisi informasi penting tentang aplikasi seperti nama package, komponen-komponen aplikasi, permissions, dan konfigurasi lainnya.

## Struktur Kode

### 1. Deklarasi Manifest
```xml
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="org.kelompok3.todolistapp">
```
- Mendeklarasikan namespace Android
- Mendefinisikan package name aplikasi

### 2. Konfigurasi Aplikasi
```xml
<application
    android:name=".TodoApp"
    android:allowBackup="true"
    android:icon="@mipmap/ic_launcher"
    android:label="@string/app_name"
    android:roundIcon="@mipmap/ic_launcher_round"
    android:supportsRtl="true"
    android:theme="@style/Base.Theme.ToDoApp">
```

#### Atribut-atribut:
- `android:name=".TodoApp"`: Menentukan kelas aplikasi utama
- `android:allowBackup="true"`: Mengizinkan backup data aplikasi
- `android:icon`: Icon aplikasi yang akan ditampilkan
- `android:label`: Nama aplikasi yang akan ditampilkan
- `android:roundIcon`: Icon bulat untuk device yang mendukung
- `android:supportsRtl="true"`: Mendukung layout Right-to-Left
- `android:theme`: Tema UI yang digunakan aplikasi

### 3. Deklarasi Activity

#### MainActivity
```xml
<activity
    android:name=".MainActivity"
    android:exported="true">
    <intent-filter>
        <action android:name="android.intent.action.MAIN" />
        <category android:name="android.intent.category.LAUNCHER" />
    </intent-filter>
</activity>
```
- Activity utama yang menjadi entry point aplikasi
- `exported="true"`: Dapat diakses dari luar aplikasi
- Intent filter menandakan ini adalah activity launcher

#### TaskEditor Activity
```xml
<activity
    android:name=".TaskEditor"
    android:exported="false"
    android:parentActivityName=".MainActivity" />
```
- Activity untuk mengedit task
- `exported="false"`: Hanya dapat diakses dari dalam aplikasi
- `parentActivityName`: Menentukan parent activity untuk navigasi back

## Fungsi Penting

1. **Package Identification**
    - Mendefinisikan identitas unik aplikasi
    - Digunakan untuk publikasi di Play Store

2. **Component Declaration**
    - Mendaftarkan semua komponen aplikasi
    - Menentukan cara komponen dapat diakses

3. **Security Configuration**
    - Mengatur permission dan akses komponen
    - Menentukan visibility komponen

4. **UI Configuration**
    - Menentukan tema dan tampilan aplikasi
    - Mengatur icon dan label aplikasi

## Best Practices yang Diterapkan

1. **Security**
    - Activity yang tidak perlu diakses dari luar di-set `exported="false"`
    - Menggunakan parent activity untuk navigasi yang proper

2. **Organization**
    - Struktur manifest yang rapi dan terorganisir
    - Pengelompokan komponen yang jelas

3. **User Experience**
    - Mendukung RTL layout
    - Menyediakan round icon untuk device yang mendukung

4. **Navigation**
    - Implementasi proper back navigation melalui `parentActivityName`
    - Clear entry point melalui launcher activity

File manifest ini merupakan komponen crucial dalam aplikasi Android karena mendefinisikan struktur dasar dan konfigurasi aplikasi yang diperlukan oleh sistem Android.