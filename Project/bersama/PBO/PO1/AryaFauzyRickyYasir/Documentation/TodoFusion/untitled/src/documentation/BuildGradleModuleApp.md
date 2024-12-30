# Dokumentasi build.gradle (App Level)

## Deskripsi Umum
File ini adalah konfigurasi Gradle untuk level aplikasi yang mendefinisikan pengaturan build dan dependencies untuk project Android.

## Struktur Kode

### 1. Plugins
```gradle
plugins {
    alias(libs.plugins.android.application)
}
```
- Menggunakan plugin Android application
- Menggunakan version catalog (`libs`) untuk manajemen versi

### 2. Konfigurasi Android
```gradle
android {
    namespace 'org.kelompok3.todolistapp'
    compileSdk 34

    defaultConfig {
        applicationId "org.kelompok3.todolistapp"
        minSdk 21
        targetSdk 34
        versionCode 1
        versionName "1.0"
        testInstrumentationRunner "androidx.test.runner.AndroidJUnitRunner"
    }
```

#### Pengaturan Utama:
- `namespace & applicationId`: Identifikasi unik aplikasi
- `compileSdk`: Level API untuk kompilasi (Android 14)
- `minSdk`: Versi Android minimum yang didukung (Android 5.0)
- `targetSdk`: Versi Android target (Android 14)
- `versionCode & versionName`: Versi aplikasi

### 3. Build Types
```gradle
buildTypes {
    release {
        minifyEnabled false
        proguardFiles getDefaultProguardFile('proguard-android-optimize.txt'), 'proguard-rules.pro'
    }
}
```
- Konfigurasi untuk build release
- Setting minifikasi kode dan ProGuard

### 4. Compile Options
```gradle
compileOptions {
    sourceCompatibility JavaVersion.VERSION_1_8
    targetCompatibility JavaVersion.VERSION_1_8
}
```
- Mengatur kompatibilitas Java ke versi 1.8

### 5. Dependencies
```gradle
dependencies {
    // AndroidX dan Material Design
    implementation libs.appcompat
    implementation libs.material
    implementation libs.activity
    implementation libs.constraintlayout
    
    // Library untuk JSON
    implementation libs.gson
    implementation libs.jackson.databind
    
    // Library untuk responsive design
    implementation libs.sdp.android
    
    // Library untuk date/time
    implementation 'com.jakewharton.threetenabp:threetenabp:1.4.6'
    
    // RecyclerView
    implementation 'androidx.recyclerview:recyclerview:1.3.2'
    
    // Testing
    testImplementation libs.junit
    androidTestImplementation libs.ext.junit
    androidTestImplementation libs.espresso.core
}
```

## Penjelasan Dependencies

### 1. UI Components
- `appcompat`: Kompatibilitas UI untuk versi Android lama
- `material`: Material Design components
- `constraintlayout`: Layout manager yang fleksibel
- `recyclerview`: Untuk menampilkan list data

### 2. Data Processing
- `gson`: Konversi JSON ke objek Java
- `jackson.databind`: JSON processor alternatif

### 3. Utilities
- `threetenabp`: Backport Java 8 date/time API
- `sdp-android`: Scaling dimension untuk responsive design

### 4. Testing
- `junit`: Unit testing
- `ext.junit`: Extended JUnit untuk Android
- `espresso`: UI testing framework

## Best Practices yang Diterapkan

1. **Version Management**
    - Menggunakan version catalog untuk manajemen versi
    - Konsisten dalam penggunaan versi SDK

2. **Compatibility**
    - MinSDK 21 menjangkau ~98% device Android
    - Menggunakan Java 8 untuk fitur modern

3. **Build Configuration**
    - Konfigurasi ProGuard untuk release build
    - Namespace yang terorganisir

4. **Dependencies**
    - Pemisahan dependencies berdasarkan fungsi
    - Penggunaan library standar dan terpercaya

5. **Testing**
    - Setup lengkap untuk unit testing dan UI testing
    - Menggunakan AndroidJUnitRunner

File build.gradle ini sangat penting karena mengatur seluruh konfigurasi build aplikasi dan dependencies yang dibutuhkan untuk development.