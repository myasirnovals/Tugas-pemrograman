show databases;

show databases;

create database kelompok_pemweb_webpage;

use kelompok_pemweb_webpage;

create table data_formulir
(
    nim    char(10)     not null,
    nama   varchar(100) not null,
    alamat text,
    hobby  varchar(100),
    primary key (nim)
) engine = innodb;

desc data_formulir;

drop table data_formulir;

select * from data_formulir;

