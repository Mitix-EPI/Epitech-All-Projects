CREATE DATABASE IF NOT EXISTS `epytodo` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `epytodo`;

CREATE TABLE IF NOT EXISTS `user` (
    `user_id` int(11) NOT NULL AUTO_INCREMENT,
    `username` varchar(255) NOT NULL,
    `password` varchar(255) NOT NULL,
    PRIMARY KEY (`user_id`),
    UNIQUE KEY `username` (`username`)
)DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `task` (
    `task_id` int(11) NOT NULL AUTO_INCREMENT,
    `title` varchar(255) NOT NULL,
    `begin` VARCHAR(255),
    `end` VARCHAR(255),
    `status` enum('not started','in progress','done') NOT NULL DEFAULT 'not started',
    PRIMARY KEY (`task_id`)
)DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `user_has_task` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `fk_user_id` int(11) NOT NULL,
    `fk_task_id` int(11) NOT NULL,
    PRIMARY KEY (`id`)
)DEFAULT CHARSET=utf8;
