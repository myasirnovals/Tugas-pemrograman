create table buku
(
    buku_id      int(10) auto_increment
        primary key,
    judul_buku   varchar(50) not null,
    pengarang    varchar(20) not null,
    tahun_terbit varchar(10) not null,
    kategori_id  int         null,
    constraint buku_ibfk_1
        foreign key (kategori_id) references kategori_buku (kategori_id)
);

create index kategori_id
    on buku (kategori_id);

