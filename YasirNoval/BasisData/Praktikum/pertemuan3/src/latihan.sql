show databases;

use kuliah_basisdata_perpustakaan;

# Tabel kategori_buku
CREATE TABLE kategori_buku
(
    kategori_id   INT(10) AUTO_INCREMENT,
    nama_kategori VARCHAR(20),
    PRIMARY KEY (kategori_id)
) ENGINE = InnoDB;

desc kategori_buku;

# Tabel Buku
CREATE TABLE buku
(
    buku_id      INT(10) AUTO_INCREMENT,
    judul_buku   VARCHAR(50) NOT NULL,
    pengarang    VARCHAR(20) NOT NULL,
    tahun_terbit VARCHAR(10) NOT NULL,
    kategori_id  INT,
    PRIMARY KEY (buku_id),
    FOREIGN KEY (kategori_id) REFERENCES kategori_buku (kategori_id)
) ENGINE = InnoDB;

desc buku;

# Tabel Anggota
CREATE TABLE anggota
(
    anggota_id    INT(10) AUTO_INCREMENT,
    nama_anggota  VARCHAR(30) NOT NULL,
    alamat        TEXT        NOT NULL,
    jenis_kelamin CHAR(1)     NOT NULL,
    no_hp         VARCHAR(15) NOT NULL,
    primary key (anggota_id)
) ENGINE = InnoDB;

desc anggota;

# Tabel Petugas
CREATE TABLE petugas
(
    petugas_id    INT(10) AUTO_INCREMENT,
    nama_petugas  VARCHAR(30) NOT NULL,
    jenis_kelamin CHAR(1)     NOT NULL,
    no_hp         VARCHAR(15) NOT NULL,
    primary key (petugas_id)
) ENGINE = InnoDB;

desc petugas;

# Tabel peminjaman
CREATE TABLE peminjaman
(
    peminjaman_id        INT(10) AUTO_INCREMENT,
    anggota_id           INT(10),
    buku_id              INT(10),
    petugas_id           INT(10),
    tanggal_peminjaman   DATE NOT NULL,
    tanggal_pengembalian DATE NOT NULL,
    primary key (peminjaman_id),
    FOREIGN KEY (anggota_id) REFERENCES anggota (anggota_id),
    FOREIGN KEY (buku_id) REFERENCES buku (buku_id),
    FOREIGN KEY (petugas_id) REFERENCES petugas (petugas_id)
) ENGINE = InnoDB;

desc peminjaman;

# Tabel Denda
CREATE TABLE denda
(
    denda_id      INT(10) AUTO_INCREMENT,
    peminjaman_id INT(10),
    jumlah_denda  VARCHAR(50),
    PRIMARY KEY (denda_id),
    FOREIGN KEY (peminjaman_id) REFERENCES peminjaman (peminjaman_id)
) ENGINE = InnoDB;

desc denda;

show tables;