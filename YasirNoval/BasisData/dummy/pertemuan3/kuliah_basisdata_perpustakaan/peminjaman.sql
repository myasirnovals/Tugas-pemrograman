create table peminjaman
(
    peminjaman_id        int(10) auto_increment
        primary key,
    anggota_id           int(10) null,
    buku_id              int(10) null,
    petugas_id           int(10) null,
    tanggal_peminjaman   date    not null,
    tanggal_pengembalian date    not null,
    constraint peminjaman_ibfk_1
        foreign key (anggota_id) references anggota (anggota_id),
    constraint peminjaman_ibfk_2
        foreign key (buku_id) references buku (buku_id),
    constraint peminjaman_ibfk_3
        foreign key (petugas_id) references petugas (petugas_id)
);

create index anggota_id
    on peminjaman (anggota_id);

create index buku_id
    on peminjaman (buku_id);

create index petugas_id
    on peminjaman (petugas_id);

