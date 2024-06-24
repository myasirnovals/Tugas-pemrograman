show databases;

create database kuliah_php_wpu_datamhs;

use kuliah_php_wpu_datamhs;

show tables;

create table mahasiswa
(
    id     int          not null auto_increment,
    nim    char(10)     not null,
    nama   varchar(255) not null,
    email  varchar(255) not null,
    club   text,
    gambar varchar(255) not null,
    primary key (id)
) engine = "InnoDB";

desc mahasiswa;

insert into mahasiswa (nim, nama, email, club, gambar)
# values ('2350081023', 'Sorasaki Hina', 'hina@example.com', 'Perfect Team', 'Sorasaki-Hina.jpg'),
values ('2350081044', 'Asagi Mutsuki', 'mutsuki@example.com', 'Problem Solver 68', 'Asagi-Mutsuki.jpg');

select * from mahasiswa;