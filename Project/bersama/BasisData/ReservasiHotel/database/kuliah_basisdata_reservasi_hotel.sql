-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 16, 2025 at 05:17 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `kuliah_basisdata_reservasi_hotel`
--

-- --------------------------------------------------------

--
-- Table structure for table `alamat`
--

CREATE TABLE `alamat` (
                          `kode_alamat` varchar(10) NOT NULL,
                          `jalan` varchar(50) DEFAULT NULL,
                          `desa` varchar(50) DEFAULT NULL,
                          `kota` varchar(50) DEFAULT NULL,
                          `provinsi` varchar(50) DEFAULT NULL,
                          `negara` varchar(50) DEFAULT 'Indonesia',
                          `kode_pos` int(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `alamat`
--

INSERT INTO `alamat` (`kode_alamat`, `jalan`, `desa`, `kota`, `provinsi`, `negara`, `kode_pos`) VALUES
                                                                                                    ('A002', 'Jl. Sudirman No. 25', 'Menteng', 'Jakarta Pusat', 'DKI Jakarta', 'Indonesia', 10310),
                                                                                                    ('A003', 'Jl. Malioboro No. 15', 'Danurejan', 'Yogyakarta', 'DI Yogyakarta', 'Indonesia', 55271),
                                                                                                    ('A004', 'Jl. Pemuda No. 45', 'Gubeng', 'Surabaya', 'Jawa Timur', 'Indonesia', 60271),
                                                                                                    ('A005', 'Jl. Gatot Subroto No. 33', 'Setiabudi', 'Jakarta Selatan', 'DKI Jakarta', 'Indonesia', 12930),
                                                                                                    ('A006', 'Jl. Asia Afrika No. 77', 'Sumur Bandung', 'Bandung', 'Jawa Barat', 'Indonesia', 40111),
                                                                                                    ('A007', 'Jl. Diponegoro No. 12', 'Tegalsari', 'Surabaya', 'Jawa Timur', 'Indonesia', 60264),
                                                                                                    ('A008', 'Jl. Veteran No. 88', 'Banjarsari', 'Solo', 'Jawa Tengah', 'Indonesia', 57131),
                                                                                                    ('A009', 'Jl. Ahmad Yani No. 55', 'Wonokromo', 'Surabaya', 'Jawa Timur', 'Indonesia', 60243),
                                                                                                    ('A010', 'Jl. Pahlawan No. 23', 'Semarang Selatan', 'Semarang', 'Jawa Tengah', 'Indonesia', 50241),
                                                                                                    ('A011', 'Jl Banyuwangi', 'Sugama', 'Amagus', 'Amagus', 'Indonesia', 40561),
                                                                                                    ('A759', 'Jl Banyuwangi', 'Sugama', 'Amagus', 'Amagus', 'Indonesia', 40561),
                                                                                                    ('A760', 'Jl. Test No. 123', 'Desa Test', 'Kota Test', 'Provinsi Test', 'Indonesia', 12345),
                                                                                                    ('A761', 'Jl. Test No. 123', 'Desa Test', 'Kota Test', 'Provinsi Test', 'Indonesia', 12345);

-- --------------------------------------------------------

--
-- Table structure for table `fasilitas`
--

CREATE TABLE `fasilitas` (
                             `kode_fasilitas` int(11) NOT NULL,
                             `nama_fasilitas` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `fasilitas`
--

INSERT INTO `fasilitas` (`kode_fasilitas`, `nama_fasilitas`) VALUES
                                                                 (1, 'WiFi Gratis'),
                                                                 (2, 'TV LED 42 inch'),
                                                                 (3, 'Mini Bar'),
                                                                 (4, 'Kamar Mandi Shower'),
                                                                 (5, 'AC'),
                                                                 (6, 'Kolam Renang'),
                                                                 (7, 'Restoran'),
                                                                 (8, 'Gym'),
                                                                 (9, 'Spa'),
                                                                 (10, 'Room Service 24 Jam');

-- --------------------------------------------------------

--
-- Table structure for table `kamar`
--

CREATE TABLE `kamar` (
                         `id_kamar` int(11) NOT NULL,
                         `id_reservasi` int(11) DEFAULT NULL,
                         `id_tipe` int(11) NOT NULL,
                         `nomor_kamar` char(3) NOT NULL,
                         `status` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `kamar`
--

INSERT INTO `kamar` (`id_kamar`, `id_reservasi`, `id_tipe`, `nomor_kamar`, `status`) VALUES
                                                                                         (12, 2, 2, '201', 'Occupied'),
                                                                                         (13, 3, 3, '301', 'Reserved'),
                                                                                         (14, 4, 4, '401', 'Occupied'),
                                                                                         (15, 12, 5, '501', 'Reserved'),
                                                                                         (16, 6, 6, '601', 'Occupied'),
                                                                                         (17, 7, 7, '701', 'Reserved'),
                                                                                         (18, 8, 8, '801', 'Occupied'),
                                                                                         (19, 9, 9, '901', 'Occupied'),
                                                                                         (20, 10, 10, '102', 'Reserved'),
                                                                                         (21, 12, 5, '747', 'Reserved');

-- --------------------------------------------------------

--
-- Table structure for table `metode_pembayaran`
--

CREATE TABLE `metode_pembayaran` (
                                     `kode_mp` int(11) NOT NULL,
                                     `nama_metode` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `metode_pembayaran`
--

INSERT INTO `metode_pembayaran` (`kode_mp`, `nama_metode`) VALUES
                                                               (1, 'Transfer Bank BCA'),
                                                               (2, 'Transfer Bank Mandiri'),
                                                               (3, 'Transfer Bank BNI'),
                                                               (4, 'DANA'),
                                                               (5, 'OVO'),
                                                               (6, 'GoPay'),
                                                               (7, 'Credit Card'),
                                                               (8, 'Debit Card'),
                                                               (9, 'Cash'),
                                                               (10, 'PayPal');

-- --------------------------------------------------------

--
-- Table structure for table `pelanggan`
--

CREATE TABLE `pelanggan` (
                             `id_pelanggan` int(11) NOT NULL,
                             `nama_pelanggan` varchar(100) NOT NULL,
                             `kode_alamat` varchar(10) NOT NULL,
                             `no_hp` varchar(13) NOT NULL,
                             `email` varchar(100) NOT NULL,
                             `user_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pelanggan`
--

INSERT INTO `pelanggan` (`id_pelanggan`, `nama_pelanggan`, `kode_alamat`, `no_hp`, `email`, `user_id`) VALUES
                                                                                                           (2, 'Ani Wijaya', 'A002', '082345678901', 'ani@email.com', 3),
                                                                                                           (3, 'Citra Dewi', 'A003', '083456789012', 'citra@email.com', 4),
                                                                                                           (4, 'Dedi Kurniawan', 'A004', '084567890123', 'dedi@email.com', 5),
                                                                                                           (5, 'Eva Susanti', 'A005', '085678901234', 'eva@email.com', 6),
                                                                                                           (6, 'Fajar Pratama', 'A006', '086789012345', 'fajar@email.com', 7),
                                                                                                           (7, 'Gita Putri', 'A007', '087890123456', 'gita@email.com', 8),
                                                                                                           (8, 'Hadi Nugroho', 'A008', '088901234567', 'hadi@email.com', 9),
                                                                                                           (9, 'Indah Sari', 'A009', '089012345678', 'indah@email.com', 10),
                                                                                                           (10, 'Joko Widodo', 'A010', '081123456789', 'joko@email.com', 11),
                                                                                                           (13, 'Agus Coplock', 'A759', '123443213241', 'customer9@example.com', 10),
                                                                                                           (14, 'Test User', 'A760', '081234567890', 'testuser123@example.com', 12),
                                                                                                           (15, 'Test User 4', 'A761', '081234567890', 'testuser124@example.com', 13);

-- --------------------------------------------------------

--
-- Table structure for table `pembayaran`
--

CREATE TABLE `pembayaran` (
                              `id_pembayaran` int(11) NOT NULL,
                              `id_reservasi` int(11) NOT NULL,
                              `kode_mp` int(11) NOT NULL,
                              `total_bayar` double NOT NULL,
                              `tanggal_pembayaran` date NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `pembayaran`
--

INSERT INTO `pembayaran` (`id_pembayaran`, `id_reservasi`, `kode_mp`, `total_bayar`, `tanggal_pembayaran`) VALUES
                                                                                                               (2, 2, 2, 750000, '2024-01-11'),
                                                                                                               (3, 3, 3, 1000000, '2024-01-12'),
                                                                                                               (4, 4, 4, 1500000, '2024-01-13'),
                                                                                                               (5, 5, 5, 2000000, '2024-01-14'),
                                                                                                               (6, 6, 6, 2500000, '2024-01-15'),
                                                                                                               (7, 7, 7, 5000000, '2024-01-16'),
                                                                                                               (8, 8, 8, 600000, '2024-01-17'),
                                                                                                               (9, 9, 9, 450000, '2024-01-18'),
                                                                                                               (10, 10, 10, 800000, '2024-01-19'),
                                                                                                               (11, 12, 6, 56000000, '2025-01-16');

-- --------------------------------------------------------

--
-- Table structure for table `reservasi`
--

CREATE TABLE `reservasi` (
                             `id_reservasi` int(11) NOT NULL,
                             `id_pelanggan` int(11) NOT NULL,
                             `nama_pemesan` varchar(100) DEFAULT NULL,
                             `tanggal_reservasi` date NOT NULL DEFAULT current_timestamp(),
                             `tanggal_checkin` date NOT NULL DEFAULT current_timestamp(),
                             `tanggal_checkout` date NOT NULL DEFAULT current_timestamp(),
                             `status` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `reservasi`
--

INSERT INTO `reservasi` (`id_reservasi`, `id_pelanggan`, `nama_pemesan`, `tanggal_reservasi`, `tanggal_checkin`, `tanggal_checkout`, `status`) VALUES
                                                                                                                                                   (2, 2, 'A Gus', '2024-01-11', '2024-01-16', '2024-01-18', 'Confirmed'),
                                                                                                                                                   (3, 3, 'Derek', '2024-01-12', '2024-01-17', '2024-01-19', 'Pending'),
                                                                                                                                                   (4, 4, 'Budi', '2024-01-13', '2024-01-18', '2024-01-20', 'Confirmed'),
                                                                                                                                                   (5, 5, 'Nugrahas', '2024-01-14', '2024-01-19', '2024-01-21', 'Cancelled'),
                                                                                                                                                   (6, 6, 'Am Agus', '2024-01-15', '2024-01-20', '2024-01-22', 'Confirmed'),
                                                                                                                                                   (7, 7, 'Lariv', '2024-01-16', '2024-01-21', '2024-01-23', 'Pending'),
                                                                                                                                                   (8, 8, 'Siti', '2024-01-17', '2024-01-22', '2024-01-24', 'Confirmed'),
                                                                                                                                                   (9, 9, 'Situ', '2024-01-18', '2024-01-23', '2024-01-25', 'Confirmed'),
                                                                                                                                                   (10, 10, 'Sata', '2024-01-19', '2024-01-24', '2024-01-26', 'Pending'),
                                                                                                                                                   (12, 13, 'Agus Coplock', '2025-01-16', '2025-01-17', '2025-01-31', 'Pending');

-- --------------------------------------------------------

--
-- Table structure for table `tipe_kamar`
--

CREATE TABLE `tipe_kamar` (
                              `id_tipe` int(11) NOT NULL,
                              `nama_tipe` varchar(100) NOT NULL,
                              `kode_fasilitas` int(11) NOT NULL,
                              `biaya` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tipe_kamar`
--

INSERT INTO `tipe_kamar` (`id_tipe`, `nama_tipe`, `kode_fasilitas`, `biaya`) VALUES
                                                                                 (1, 'Standard Room', 1, 500000),
                                                                                 (2, 'Deluxe Room', 2, 750000),
                                                                                 (3, 'Superior Room', 3, 1000000),
                                                                                 (4, 'Suite Room', 4, 1500000),
                                                                                 (5, 'Executive Room', 5, 2000000),
                                                                                 (6, 'Family Room', 6, 2500000),
                                                                                 (7, 'Presidential Suite', 7, 5000000),
                                                                                 (8, 'Twin Room', 8, 600000),
                                                                                 (9, 'Single Room', 9, 450000),
                                                                                 (10, 'Double Room', 10, 800000);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
                         `id` int(11) NOT NULL,
                         `username` varchar(50) NOT NULL,
                         `password` varchar(255) NOT NULL,
                         `role` enum('admin','customer') NOT NULL DEFAULT 'customer',
                         `created_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `password`, `role`, `created_at`) VALUES
                                                                             (1, 'admin1', '$2y$10$qPCFhBH/rzQWXTenxvTBlOJjdO3vDyDFCMLJDyYELySVM6.yizYky', 'admin', '2025-01-14 07:32:10'),
                                                                             (2, 'customer1', '$2y$10$abcdefghijk123456789', 'customer', '2025-01-14 07:32:10'),
                                                                             (3, 'customer2', '$2y$10$abcdefghijk123456789', 'customer', '2025-01-14 07:32:10'),
                                                                             (4, 'customer3', '$2y$10$abcdefghijk123456789', 'customer', '2025-01-14 07:32:10'),
                                                                             (5, 'customer4', '$2y$10$abcdefghijk123456789', 'customer', '2025-01-14 07:32:10'),
                                                                             (6, 'customer5', '$2y$10$abcdefghijk123456789', 'customer', '2025-01-14 07:32:10'),
                                                                             (7, 'customer6', '$2y$10$abcdefghijk123456789', 'customer', '2025-01-14 07:32:10'),
                                                                             (8, 'customer7', '$2y$10$abcdefghijk123456789', 'customer', '2025-01-14 07:32:10'),
                                                                             (9, 'customer8', '$2y$10$abcdefghijk123456789', 'customer', '2025-01-14 07:32:10'),
                                                                             (10, 'customer9', '$2y$10$Bka4OCS7fHzQTf6mqSZm8uhf14tY7eRVEVtIDrNYN77.NIlaeDY4K', 'customer', '2025-01-14 07:32:10'),
                                                                             (11, 'customer10', '$2y$10$dCWwnpLqtQzNVG/aiZ6fJ.9Q5Hyu1v75v5/wZyFxcQxJyTdQWsNoK', 'customer', '2025-01-15 23:05:45'),
                                                                             (12, 'testuser123', '$2y$10$sJcOqRx4GY9TwluLiTZ8o.p8hoV08RSwNn0jEYbq2eejcxUxBui6G', 'customer', '2025-01-16 02:26:58'),
                                                                             (13, 'testuser124', '$2y$10$YBht3sMfQNL6JJS3LCspvenvg0owHF31Lih0vNyRy2PyINqIUkhIy', 'customer', '2025-01-16 02:47:20');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `alamat`
--
ALTER TABLE `alamat`
    ADD PRIMARY KEY (`kode_alamat`);

--
-- Indexes for table `fasilitas`
--
ALTER TABLE `fasilitas`
    ADD PRIMARY KEY (`kode_fasilitas`);

--
-- Indexes for table `kamar`
--
ALTER TABLE `kamar`
    ADD PRIMARY KEY (`id_kamar`),
  ADD KEY `kamar_reservasi` (`id_reservasi`),
  ADD KEY `kamar_tipe_kamar` (`id_tipe`);

--
-- Indexes for table `metode_pembayaran`
--
ALTER TABLE `metode_pembayaran`
    ADD PRIMARY KEY (`kode_mp`);

--
-- Indexes for table `pelanggan`
--
ALTER TABLE `pelanggan`
    ADD PRIMARY KEY (`id_pelanggan`),
  ADD KEY `alamat_pelanggan` (`kode_alamat`),
  ADD KEY `user_id` (`user_id`);

--
-- Indexes for table `pembayaran`
--
ALTER TABLE `pembayaran`
    ADD PRIMARY KEY (`id_pembayaran`),
  ADD KEY `pembayaran_reservasi` (`id_reservasi`),
  ADD KEY `pembayaran_mp` (`kode_mp`);

--
-- Indexes for table `reservasi`
--
ALTER TABLE `reservasi`
    ADD PRIMARY KEY (`id_reservasi`),
  ADD KEY `reservasi_pelanggan` (`id_pelanggan`);

--
-- Indexes for table `tipe_kamar`
--
ALTER TABLE `tipe_kamar`
    ADD PRIMARY KEY (`id_tipe`),
  ADD KEY `tipe_kamar_fasilitas` (`kode_fasilitas`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
    ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `username` (`username`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `fasilitas`
--
ALTER TABLE `fasilitas`
    MODIFY `kode_fasilitas` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `kamar`
--
ALTER TABLE `kamar`
    MODIFY `id_kamar` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;

--
-- AUTO_INCREMENT for table `metode_pembayaran`
--
ALTER TABLE `metode_pembayaran`
    MODIFY `kode_mp` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `pelanggan`
--
ALTER TABLE `pelanggan`
    MODIFY `id_pelanggan` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `pembayaran`
--
ALTER TABLE `pembayaran`
    MODIFY `id_pembayaran` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `reservasi`
--
ALTER TABLE `reservasi`
    MODIFY `id_reservasi` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT for table `tipe_kamar`
--
ALTER TABLE `tipe_kamar`
    MODIFY `id_tipe` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
    MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `kamar`
--
ALTER TABLE `kamar`
    ADD CONSTRAINT `kamar_reservasi` FOREIGN KEY (`id_reservasi`) REFERENCES `reservasi` (`id_reservasi`) ON DELETE SET NULL ON UPDATE CASCADE,
  ADD CONSTRAINT `kamar_tipe_kamar` FOREIGN KEY (`id_tipe`) REFERENCES `tipe_kamar` (`id_tipe`);

--
-- Constraints for table `pelanggan`
--
ALTER TABLE `pelanggan`
    ADD CONSTRAINT `alamat_pelanggan` FOREIGN KEY (`kode_alamat`) REFERENCES `alamat` (`kode_alamat`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `pelanggan_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`);

--
-- Constraints for table `pembayaran`
--
ALTER TABLE `pembayaran`
    ADD CONSTRAINT `pembayaran_mp` FOREIGN KEY (`kode_mp`) REFERENCES `metode_pembayaran` (`kode_mp`),
  ADD CONSTRAINT `pembayaran_reservasi` FOREIGN KEY (`id_reservasi`) REFERENCES `reservasi` (`id_reservasi`) ON DELETE CASCADE;

--
-- Constraints for table `reservasi`
--
ALTER TABLE `reservasi`
    ADD CONSTRAINT `reservasi_pelanggan` FOREIGN KEY (`id_pelanggan`) REFERENCES `pelanggan` (`id_pelanggan`) ON DELETE CASCADE;

--
-- Constraints for table `tipe_kamar`
--
ALTER TABLE `tipe_kamar`
    ADD CONSTRAINT `tipe_kamar_fasilitas` FOREIGN KEY (`kode_fasilitas`) REFERENCES `fasilitas` (`kode_fasilitas`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
