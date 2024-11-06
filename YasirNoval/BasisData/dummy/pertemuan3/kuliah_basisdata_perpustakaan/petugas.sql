create table petugas
(
    petugas_id    int(10) auto_increment
        primary key,
    nama_petugas  varchar(30) not null,
    jenis_kelamin char        not null,
    no_hp         varchar(15) not null
);

