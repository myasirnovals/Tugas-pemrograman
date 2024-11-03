# membuat database
CREATE DATABASE perpustakaan;

# melihat seluruh database
SHOW DATABASES;

# menghapus database
DROP DATABASE perpustakaan;

# menggunakan database perpustakaan
USE perpustakaan;

# membuat tabel
CREATE TABLE kategori_buku
(
    kategori_id   INT,
    nama_kategori VARCHAR(100) NOT NULL
) ENGINE = InnoDB;

# menghapus tabel
DROP TABLE kategori_buku;

# menambahkan primary key
CREATE TABLE kategori_buku
(
    kategori_id   INT AUTO_INCREMENT PRIMARY KEY,
    nama_kategori VARCHAR(100) NOT NULL
) ENGINE = InnoDB;

# menambahkan kolom unik
CREATE TABLE anggota
(
    anggota_id   INT AUTO_INCREMENT,
    nama_anggota VARCHAR(255) NOT NULL,
    alamat       TEXT,
    no_hp        VARCHAR(20),
    PRIMARY KEY (anggota_id),
    UNIQUE (no_hp)
) ENGINE = InnoDB;

# mengganti nama tabel
RENAME TABLE anggota TO user;

# menambah field pada tabel
ALTER TABLE user
    ADD email VARCHAR(50);

# menghapus primary key pada tabel
ALTER TABLE user
    DROP PRIMARY KEY;

# menambahkan foreign key
CREATE TABLE buku
(
    buku_id      INT AUTO_INCREMENT,
    judul_buku   VARCHAR(255) NOT NULL,
    pengarang    VARCHAR(255) NOT NULL,
    tahun_terbit YEAR         NOT NULL,
    id_kategori  INT,
    PRIMARY KEY (buku_id),
    FOREIGN KEY (id_kategori) REFERENCES kategori_buku (kategori_id)
) ENGINE = InnoDB;

# menghapus foreign key
ALTER TABLE buku
    DROP FOREIGN KEY buku_ibfk_1;

show create table buku;