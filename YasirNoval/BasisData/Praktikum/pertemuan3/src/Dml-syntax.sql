show databases;

create database kuliah_basisdata_perpustakaan;

use kuliah_basisdata_perpustakaan;

# INSERT
INSERT INTO kategori_buku
VALUES ('1', 'Sains');

# Latihan INSERT
INSERT INTO kategori_buku
VALUES ('2', ''),
       ('3', 'Fantasi'),
       ('4', 'Misteri'),
       ('5', 'Sejarah'),
       ('6', 'Biografi dan Autografi'),
       ('7', 'Romantis'),
       ('8', 'Fiksi Sastra'),
       ('9', 'Thriller dan Suspense'),
       ('10', 'Realisme Magis'),
       ('11', 'Puisi');

select *
from kategori_buku;

# UPDATE
UPDATE kategori_buku
SET nama_kategori = 'Pendidikan'
WHERE kategori_id = 1;

select *
from kategori_buku;

# Menghapus Data (DELETE)
DELETE
FROM kategori_buku
WHERE kategori_id = 1;

select *
from kategori_buku;

# TUGAS AKHIR
# tampilkan tabel untuk melihat seluruh data
show tables;

# 1. mengubah data alamat dan nomor hp 3 anggota
desc anggota;

select *
from anggota;

INSERT INTO anggota (nama_anggota, alamat, jenis_kelamin, no_hp)
VALUES ('Derek Westbrook', 'Jl. Merpati No. 12, Kel. Cempaka Putih, Kec. Cempaka Putih, Jakarta Pusat, DKI Jakarta',
        'L', '0884xxxxxx'),
       ('Simon Riley', 'Jl. Raya Semangka No. 45, Kel. Sukamaju, Kec. Medan Selayang, Medan, Sumatera Utara', 'L',
        '0884xxxxxx'),
       ('Mac Tavish', 'Jl. Bunga Melati No. 8, Kel. Harapan Jaya, Kec. Bekasi Utara, Bekasi, Jawa Barat', 'L',
        '0884xxxxxx'),
       ('James Ramirez', 'Jl. Pahlawan No. 99, Kel. Sidoarjo, Kec. Sidoarjo, Sidoarjo, Jawa Timur', 'L', '0884xxxxxx'),
       ('Gary Sanderson', 'Jl. Cendana No. 33, Kel. Tanjung Duren, Kec. Grogol Petamburan, Jakarta Barat, DKI Jakarta',
        'L', '0884xxxxxx'),
       ('Takanashi Hoshino', 'Jl. Anggrek No. 21, Kel. Cibubur, Kec. Ciracas, Jakarta Timur, DKI Jakarta', 'P',
        '0884xxxxxx'),
       ('Kuraue Hinata', 'Jl. Raya Merdeka No. 77, Kel. Ngaliyan, Kec. Ngaliyan, Semarang, Jawa Tengah', 'P',
        '0884xxxxxx'),
       ('Yukimura Aoi', 'Jl. Kuningan No. 56, Kel. Kuningan, Kec. Setiabudi, Jakarta Selatan, DKI Jakarta', 'P',
        '0884xxxxxx'),
       ('Sorasaki Hina', 'Jl. Bintaro No. 10, Kel. Bintaro, Kec. Pesanggrahan, Jakarta Selatan, DKI Jakarta', 'P',
        '0884xxxxxx'),
       ('Tanga Ibuki', 'Jl. Srikandi No. 5, Kel. Srikandi, Kec. Taman, Sidoarjo, Jawa Timur', 'P', '0884xxxxxx');

select *
from anggota;

UPDATE anggota
SET alamat = 'Jl. Cimahi',
    no_hp  = '0885xxxxxxxx'
WHERE anggota_id = 1;

UPDATE anggota
SET alamat = 'Jl. Coba lagi',
    no_hp  = '0886xxxxxxxx'
WHERE anggota_id = 2;

UPDATE anggota
SET alamat = 'Jl. Coba itu',
    no_hp  = '0888xxxxxxxx'
WHERE anggota_id = 3;

select *
from anggota;

# 2. mengubah nama kategori buku
desc kategori_buku;

select *
from kategori_buku;

UPDATE kategori_buku
SET nama_kategori = 'Slice of Life'
WHERE kategori_id = 4;

# 3. mengubah 3 tanggal pengembalian buku
show tables;

desc petugas;

select *
from petugas;

INSERT INTO petugas (nama_petugas, jenis_kelamin, no_hp)
VALUES ('Mac Millan', 'L', '0883xxxxxxxx'),
       ('Natsume Iroha', 'P', '0883xxxxxxxx'),
       ('Takashi Natsume', 'L', '0883xxxxxxxx'),
       ('Sunaookami Shiroko', 'P', '0883xxxxxxxx'),
       ('Kuromi Serika', 'P', '0883xxxxxxxx');

desc peminjaman;

select *
from peminjaman;

INSERT INTO buku (judul_buku, pengarang, tahun_terbit, kategori_id)
VALUES ('judul 1', 'Apa', '2000-10-01', '2'),
       ('judul 2', 'Apa', '2001-11-02', '3'),
       ('judul 3', 'Kai', '2002-12-03', '4'),
       ('judul 4', 'Kai', '2003-01-04', '5'),
       ('judul 5', 'Lecrec', '2004-02-05', '6'),
       ('judul 6', 'Lecrec', '2005-03-06', '7'),
       ('judul 7', 'Ana', '2006-04-07', '8'),
       ('judul 8', 'Ana', '2007-05-08', '9'),
       ('judul 9', 'Tobor', '2008-06-09', '10'),
       ('judul10', 'Tobor', '2009-07-10', '11');

select *
from petugas;

select *
from anggota;

select *
from buku;

select *
from kategori_buku;

select *
from peminjaman;

INSERT INTO peminjaman (anggota_id, buku_id, petugas_id, tanggal_peminjaman, tanggal_pengembalian)
VALUES ('1', '1', '1', '2020-10-01', now()),
       ('2', '2', '2', '2021-11-02', now()),
       ('3', '3', '3', '2021-12-03', now()),
       ('4', '4', '4', '2020-01-04', now()),
       ('5', '5', '5', '2023-02-05', now()),
       ('6', '6', '5', '2024-03-06', now()),
       ('7', '7', '4', '2024-04-07', now()),
       ('8', '8', '3', '2023-05-07', now()),
       ('9', '9', '2', '2022-06-09', now()),
       ('10', '10', '1', '2022-07-10', now());

UPDATE peminjaman
SET tanggal_pengembalian = str_to_date('07-25-2023', '%m-%d-%Y')
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

select *
from denda;

insert into denda (peminjaman_id, jumlah_denda)
values ('1', 45000),
       ('2', 45000),
       ('3', 45000),
       ('2', 45000),
       ('3', 45000),
       ('1', 45000);

DELETE
FROM denda
WHERE peminjaman_id = 1;