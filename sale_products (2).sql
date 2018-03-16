-- phpMyAdmin SQL Dump
-- version 4.7.7
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 16, 2018 at 05:10 PM
-- Server version: 10.1.30-MariaDB
-- PHP Version: 7.2.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `sale_products`
--

-- --------------------------------------------------------

--
-- Table structure for table `account`
--

CREATE TABLE `account` (
  `id` int(11) NOT NULL,
  `username` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `account`
--

INSERT INTO `account` (`id`, `username`, `password`) VALUES
(1, 'mohamad', '123'),
(2, '', ''),
(3, '', ''),
(4, '', ''),
(5, '', ''),
(6, 'rola', '123'),
(7, 'tamer', '1234'),
(8, 'jasmin', '123'),
(9, 'mazen', '123'),
(10, 'taher', '1234'),
(11, 'maher', '123'),
(12, 'maggi', '123'),
(13, 'jasss', '123'),
(14, 'nnn', '22');

-- --------------------------------------------------------

--
-- Table structure for table `account_admin`
--

CREATE TABLE `account_admin` (
  `id` int(11) NOT NULL,
  `admin_name` varchar(50) NOT NULL,
  `admin_pass` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `ID` int(11) NOT NULL,
  `name` varchar(40) NOT NULL,
  `age` int(11) NOT NULL,
  `phone` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`ID`, `name`, `age`, `phone`) VALUES
(1, 'mohamad', 45, 721251234),
(2, 'yasser', 43, 734554321),
(3, 'gabriel', 26, 2147483647),
(4, 'ttt', 33, 54322333),
(5, 'gggg', 22, 322222),
(6, 'tttt', 44, 667654),
(7, 'maha', 33, 22221223),
(8, 'jjj', 99, 2147483647),
(9, 'yyyppp', 66, 98675764),
(10, 'yyyy', 44, 67584653),
(11, 'mjjji', 99, 87675876),
(12, 'uguygyu', 666, 788756),
(13, 'ggg', 444, 56474654),
(14, 'hgchgc', 65, 5555),
(15, 'jhbhj', 6666, 765746534),
(16, 'hvjh', 776, 87766),
(17, 'wrfwe', 123, 21323),
(18, 'gyftyftrhg', 4444, 76545),
(19, 'tftrdtr', 555, 88),
(20, 'mazen', 30, 765656),
(21, 'wewre', 33, 2222),
(22, 'qewfwe', 22, 444),
(23, 'yasen', 22, 1112223),
(24, '2', 0, 2222),
(25, 'ayman', 45, 777),
(26, 'taher', 22, 223333333),
(27, 'maher', 22, 3444),
(28, 'maggi', 23, 22222222),
(29, 'jasss', 12, 111111),
(30, 'nnn', 12, 11111);

-- --------------------------------------------------------

--
-- Table structure for table `order_t`
--

CREATE TABLE `order_t` (
  `ID` int(11) NOT NULL,
  `cust_ID` int(11) NOT NULL,
  `prod_ID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `order_t`
--

INSERT INTO `order_t` (`ID`, `cust_ID`, `prod_ID`) VALUES
(2, 1, 2),
(4, 7, 3),
(5, 20, 7),
(6, 25, 9),
(7, 3, 10),
(8, 3, 10),
(9, 3, 5),
(10, 1, 2),
(12, 1, 11),
(13, 20, 3);

-- --------------------------------------------------------

--
-- Table structure for table `products`
--

CREATE TABLE `products` (
  `ID` int(11) NOT NULL,
  `product_name` varchar(255) NOT NULL,
  `price` int(11) NOT NULL,
  `quantity` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `products`
--

INSERT INTO `products` (`ID`, `product_name`, `price`, `quantity`) VALUES
(1, '', 0, 0),
(2, 'camera', 344, 28),
(3, 'car', 230000, 3),
(5, 'laptop', 2000, 1),
(7, 'test', 88, 0),
(8, 'test2', 22, 333),
(9, 'qq', 22, 1),
(10, 'cow', 10000, 8),
(11, 'car', 1222, 2),
(12, 'www', 0, 0),
(13, 'rrr', 333, 3),
(14, 'efd', 0, 0),
(15, 'dddd', 23, 22),
(16, 'eee', 33, 2),
(17, 'yyy', 55, 88),
(18, 'uuu', 77, 88),
(19, 'uuu', 676, 99),
(20, 'trtr', 555, 33),
(21, 'vaat', 22, 44),
(22, 'ee', 22, 3),
(23, 'camera', 9998, 55),
(24, 'tre', 88, 9),
(25, 'rrr', 23, 44),
(26, 'yashhh', 55, 9),
(27, 'eee', 22, 3);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `account`
--
ALTER TABLE `account`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `account_admin`
--
ALTER TABLE `account_admin`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `order_t`
--
ALTER TABLE `order_t`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `orderfk1` (`cust_ID`),
  ADD KEY `orderfk2` (`prod_ID`);

--
-- Indexes for table `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `account`
--
ALTER TABLE `account`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=31;

--
-- AUTO_INCREMENT for table `order_t`
--
ALTER TABLE `order_t`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT for table `products`
--
ALTER TABLE `products`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=28;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `account`
--
ALTER TABLE `account`
  ADD CONSTRAINT `accountfk` FOREIGN KEY (`id`) REFERENCES `customer` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `order_t`
--
ALTER TABLE `order_t`
  ADD CONSTRAINT `orderfk1` FOREIGN KEY (`cust_ID`) REFERENCES `customer` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `orderfk2` FOREIGN KEY (`prod_ID`) REFERENCES `products` (`ID`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
