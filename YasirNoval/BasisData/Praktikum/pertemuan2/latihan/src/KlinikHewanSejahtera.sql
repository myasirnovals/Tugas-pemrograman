show databases;

create database kuliah_basisdata_klinikhewansejahtera;

use kuliah_basisdata_klinikhewansejahtera;

# membuat tabel pemilik
create table pemilik
(
    id_pemilik varchar(5),
    nama       varchar(100) not null,
    alamat     text         not null,
    no_telp    varchar(12)  not null,
    email      varchar(100) not null,
    primary key (id_pemilik)
) engine = InnoDB;

# membuat tabel hewan
create table hewan
(
    id_hewan   varchar(5),
    nama       varchar(100) not null,
    jenis      varchar(100),
    umur       int(3),
    id_pemilik varchar(5),
    primary key (id_hewan),
    foreign key (id_pemilik) references pemilik (id_pemilik)
) engine = InnoDB;

# membuat tabel janji
create table janji
(
    id_janji      varchar(5),
    tanggal_waktu datetime default current_timestamp,
    status        enum ('selesai', 'belum selesai'),
    id_hewan      varchar(5),
    id_layanan    varchar(5),
    primary key (id_janji),
    foreign key (id_hewan) references hewan (id_hewan),
    foreign key (id_layanan) references layanan (id_layanan)
) engine = InnoDB;

# membuat tabel layanan
create table layanan
(
    id_layanan   varchar(5),
    nama_layanan varchar(200) not null,
    deskripsi    text,
    harga        int          not null,
    primary key (id_layanan)
) engine = InnoDB;

# membuat tabel pembayaran
create table pembayaran
(
    id_pembayaran      varchar(5),
    tanggal_pembayaran datetime default current_timestamp,
    jumlah             int,
    metode_pembayaran  enum ('cash', 'm-banking'),
    id_janji           varchar(5),
    primary key (id_pembayaran),
    foreign key (id_janji) references janji (id_janji)
) engine = InnoDB;