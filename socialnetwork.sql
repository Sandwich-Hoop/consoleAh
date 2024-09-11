SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

CREATE DATABASE IF NOT EXISTS `socialnetwork` DEFAULT CHARACTER SET utf16 COLLATE utf16_general_ci;
USE `socialnetwork`;

DROP TABLE IF EXISTS `post`;
CREATE TABLE IF NOT EXISTS `post` (
  `postid` int(11) NOT NULL AUTO_INCREMENT,
  `posttitle` varchar(40) DEFAULT NULL,
  `userid` int(9) DEFAULT NULL,
  `postbody` int(500) DEFAULT NULL,
  PRIMARY KEY (`postid`)
) ENGINE=InnoDB AUTO_INCREMENT=632 DEFAULT CHARSET=utf8;

INSERT INTO `post` (`postid`, `posttitle`, `userid`, `postbody`) VALUES
(00000000000, 'the first post title', 000000001, iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii),
(00000000001, 'new post title', 000000002, jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj),
(00000000002, 'my post tiel', 000000001, fffffffffffffffffffffffff),
(00000000003, 'title444', 000000003, kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk),
(00000000004, 'bigtitle', 000000003, ccccccccccccccccccccccccccccccccccccccccccc),
(00000000005, 'titles', 000000001, nnnnnnnnnnnnnnnnnnnnnnnnnnnnn),
(00000000006, 'meowtitle', 000000002, wwwwwwwwwwwwwwwwwwwwwwwwwwwwwww);

DROP TABLE IF EXISTS `user`;
CREATE TABLE IF NOT EXISTS `user` (
  
  `userid` int(9) NOT NULL,
  `username` varchar(16) DEFAULT NULL,
  `password` varchar(9) DEFAULT NULL,
  `email` varchar(16) DEFAULT NULL,
  PRIMARY KEY (`userid`)
 
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `user` (`userid`, `username`, `password`, `email`) VALUES
('000000001', 'buster', 'shadow99', 'chloe@coders.org'),
('000000002', 'SallyTheBally', 'trustme1', 'sally@scott.com'),
('000000003', 'Heisenberg', 'pink10red', 'paul@gamers.org');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;