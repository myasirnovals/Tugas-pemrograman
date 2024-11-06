create table anggota
(
    anggota_id    int(10) auto_increment
        primary key,
    nama_anggota  varchar(30) not null,
    alamat        text        not null,
    jenis_kelamin char        not null,
    no_hp         varchar(15) not null
);

