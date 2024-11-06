show databases;

create database kuliah_basisdata_perpustakaan;

use kuliah_basisdata_perpustakaan;

# INSERT
INSERT INTO kategori_buku
VALUES ('1', 'Sains');

# Latihan INSERT
INSERT INTO kategori_buku
VALUES ('2', 'Sastra Klasik'),
       ('3', 'Fantasi'),
       ('4', 'Misteri'),
       ('5', 'Sejarah'),
       ('6', 'Biografi dan Autografi'),
       ('7', 'Romantis'),
       ('8', 'Fiksi Sastra'),
       ('9', 'Thriller dan Suspense'),
       ('10', 'Realisme Magis'),
       ('11', 'Puisi');

# UPDATE
UPDATE kategori_buku
SET nama_kategori = 'Pendidikan'
WHERE kategori_id = 1;

# Menghapus Data (DELETE)
DELETE
FROM kategori_buku
WHERE kategori_id = 1;

# TUGAS AKHIR
# tampilkan tabel untuk melihat seluruh data
show tables;

# 1. mengubah data alamat dan nomor hp 3 anggota
desc anggota;

UPDATE anggota
SET alamat = 'Jl. Coba aja',
    no_hp  = '0884xxxxxxxx'
WHERE anggota_id = 1;

UPDATE anggota
SET alamat = 'Jl. Coba lagi',
    no_hp  = '0884xxxxxxxx'
WHERE anggota_id = 2;

UPDATE anggota
SET alamat = 'Jl. Coba itu',
    no_hp  = '0884xxxxxxxx'
WHERE anggota_id = 3;

# 2. mengubah nama kategori buku
desc kategori_buku;

UPDATE kategori_buku
SET nama_kategori = 'Slice of Life'
WHERE kategori_id = 4;

# 3. mengubah 3 tanggal pengembalian buku
show tables;

desc peminjaman;

UPDATE peminjaman
SET tanggal_pengembalian = CURRENT_DATE
WHERE peminjaman_id = 1;

UPDATE peminjaman
SET tanggal_pengembalian = CURRENT_DATE
WHERE peminjaman_id = 2;

UPDATE peminjaman
SET tanggal_pengembalian = CURRENT_DATE
WHERE peminjaman_id = 3;

# 4. menghapus denda
show tables;

desc denda;

DELETE
FROM denda
WHERE denda_id = 1;