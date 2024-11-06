create table denda
(
    denda_id      int(10) auto_increment
        primary key,
    peminjaman_id int(10) null,
    jumlah_denda  int(10) not null,
    constraint denda_ibfk_1
        foreign key (peminjaman_id) references peminjaman (peminjaman_id)
);

create index peminjaman_id
    on denda (peminjaman_id);

