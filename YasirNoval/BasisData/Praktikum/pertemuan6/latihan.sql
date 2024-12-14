show databases;

use kuliah_basisdata_perpustakaan;

show tables;

select upper(anggota.nama_anggota) as nama_anggota_uppercase
from anggota;

delimiter $$
create function HitungDenda(hari_telat int)
    returns int
    deterministic
begin
    declare denda int;
    set denda = hari_telat * 5000;
    return denda;
end $$

create trigger hitung_denda
    after update
    on peminjaman
    for each row
begin
    declare hari_telat int;
    declare denda int;
    set hari_telat = datediff(current_date, new.tanggal_pengembalian);
    if hari_telat > 0 then
        set denda = hari_telat * 5000;
        insert into denda (peminjaman_id, jumlah_denda) values (new.peminjaman_id, denda);
    end if
    $$
end $$

create function ValidasiNomorHP(no_hp varchar(20))
    returns bit
    deterministic
begin
    if length(no_hp) = 12 then
        return 1;
    else
        return 0;
    end if;
end$$

create table log_anggota
(
    log_id            int auto_increment primary key,
    anggota_id        int,
    nama_anggota_lama varchar(255),
    nama_anggota_baru varchar(255),
    waktu_perubahan   timestamp
) engine = innodb$$

create trigger log_perubahan_anggota
    after update
    on anggota
    for each row
begin
    insert into log_anggota (anggota_id, nama_anggota_lama, nama_anggota_baru, waktu_perubahan)
    values (new.anggota_id, new.nama_anggota, current_timestamp);
end
$$

delimiter ;

delimiter $$
create function HitungTotalPembayaran(jumlah_kamar int, harga_per_kamar decimal(10, 2))
    returns decimal(10, 2)
    deterministic
begin
    declare total_pembayaran decimal(10, 2);
    set total_pembayaran = jumlah_kamar * harga_per_kamar;
    return total_pembayaran;
end $$

select HitungTotalPembayaran(5, 200000) as TotalPembayaran;

create trigger hitung_total_pembayaran
    before insert
    on reservasi
    for each row
begin
    set new.total_pembayaran = HitungTotalPembayaran(
            new.jumlah_kamar, new.harga_per_kamar);
end $$


