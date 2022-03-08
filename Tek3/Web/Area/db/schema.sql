CREATE DATABASE IF NOT EXISTS area;

USE area;

CREATE TABLE IF NOT EXISTS users (
    id INT NOT NULL AUTO_INCREMENT,
    mail VARCHAR(200) UNIQUE,
    password VARCHAR(200),
    google_mail VARCHAR(200) UNIQUE,
    google_token VARCHAR(3072),
    office_mail VARCHAR(200) UNIQUE,
    office_token VARCHAR(3072),
    facebook_mail VARCHAR(200) UNIQUE,
    facebook_token VARCHAR(3072),
    token VARCHAR(3072),
    token_created_at DATETIME,
    PRIMARY KEY (id)
);

USE area;

CREATE TABLE IF NOT EXISTS actions_reactions (
    id INT NOT NULL AUTO_INCREMENT,
    user_id INT NOT NULL,
    action TEXT(16383) NOT NULL,
    reaction TEXT(16383) NOT NULL,
    last_updated_at DATETIME,
    PRIMARY KEY (id),
    FOREIGN KEY (user_id) REFERENCES users(id)
);

USE area;

CREATE TABLE IF NOT EXISTS user_tokens(
    id INT NOT NULL AUTO_INCREMENT,
    user_id INT NOT NULL,
    google_token TEXT,
    google_token_refreshed_at DATETIME,
    office_token TEXT,
    office_token_refreshed_at DATETIME,
    facebook_token TEXT,
    facebook_token_refreshed_at DATETIME,
    epitech_intra_token TEXT,
    epitech_intra_token_refreshed_at DATETIME,
    reddit_token TEXT,
    reddit_token_refreshed_at DATETIME,
    spotify_token TEXT,
    spotify_token_refreshed_at DATETIME,
    PRIMARY KEY (id),
    FOREIGN KEY (user_id) REFERENCES users(id)
);


-- CREATE TABLE IF NOT EXISTS user_tokens (
--     id INT NOT NULL AUTO_INCREMENT,
--     user_id INT NOT NULL,
--     access_token VARCHAR(3072),
--     refresh_token VARCHAR(3072),
--     api_type INT NOT NULL,
--     token_refreshed_at DATETIME,
--     PRIMARY KEY(id),
--     FOREIGN KEY (user_id) REFERENCES users(id)
-- );
