show databases;

create database kelompok_pemweb_navigation_bar;

use kelompok_pemweb_navigation_bar;

create table mahasiswa
(
    nim       char(10)     not null primary key,
    nama      varchar(200) not null,
    kelas     char(1)      not null,
    angkatan  char(4)      not null,
    image     varchar(255),
    deskripsi text
) engine = innodb;

show tables ;

desc mahasiswa;

select * from mahasiswa;