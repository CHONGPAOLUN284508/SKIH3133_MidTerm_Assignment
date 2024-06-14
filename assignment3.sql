-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 14, 2024 at 08:10 AM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.0.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `assignment3`
--

-- --------------------------------------------------------

--
-- Table structure for table `readings`
--

CREATE TABLE `readings` (
  `id` int(11) NOT NULL,
  `temperature` float DEFAULT NULL,
  `humidity` float DEFAULT NULL,
  `distance` float DEFAULT NULL,
  `timestamp` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `readings`
--

INSERT INTO `readings` (`id`, `temperature`, `humidity`, `distance`, `timestamp`) VALUES
(10, 23.9, 44, 1200, '2024-06-14 04:01:29'),
(11, 23.9, 44, 6, '2024-06-14 04:02:47'),
(12, 23.9, 44, 1200, '2024-06-14 04:04:27'),
(13, 23.9, 44, 1199, '2024-06-14 04:06:08'),
(14, 23.7, 44, 8, '2024-06-14 04:08:32'),
(15, 23.6, 44, 1200, '2024-06-14 04:10:12'),
(16, 23.8, 47, 1200, '2024-06-14 04:11:53'),
(17, 25, 46, 1199, '2024-06-14 04:43:50'),
(18, 24.9, 46, 6, '2024-06-14 04:45:30'),
(20, 23.6, 44, 49, '2024-06-14 05:14:48'),
(21, 24.3, 52, 45, '2024-06-14 05:16:47'),
(22, 25, 57, 83, '2024-06-14 05:18:27'),
(23, 30.2, 46, 49, '2024-06-14 05:50:07'),
(25, 30.5, 46, 11, '2024-06-14 05:52:35'),
(27, 30.7, 47, 186, '2024-06-14 05:54:42'),
(28, 30.7, 47, 186, '2024-06-14 05:55:32');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `readings`
--
ALTER TABLE `readings`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `readings`
--
ALTER TABLE `readings`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
