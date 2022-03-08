/*
** EPITECH PROJECT, 2021
** database.hpp
** File description:
** database.hpp
*/

#ifndef DATABASE_HPP_
#define DATABASE_HPP_

#include <sqlite3.h>
#include <iostream>
#include <vector>

namespace Babel
{
    namespace Database
    {
        enum UserState: int {
            OFFLINE,
            INCALL,
            ONLINE,
            UNKNOWN,
        };

        struct Message {
            int messageId;
            int senderId;
            int receiverId;
            std::string message;
        };

        struct UserDB {
            int id;
            std::string username;
            std::string password;
        };

        class IDatabase {
            public:
                virtual void openDatabase(const std::string &dbname) = 0;
                virtual void closeDatabase() = 0;
                virtual int executeCommand(const std::string &cmd,
                        int (*callback)(void*,int,char**,char**),
                        void *frst,
                        char **errmsg) = 0;
                virtual void executeRequest(const std::string &command, void *toModify, int (*callback)(void *, int, char **, char **)) = 0;
            protected:
        };

        class MySQLiteDatabase: public IDatabase {
            public:
                MySQLiteDatabase(const std::string &dbName);
                ~MySQLiteDatabase();
                // void executeCommand(std::string command, void *toModify, int (*callback)(void *, int, char **, char **)) const;
                void openDatabase(const std::string &dbname) override;
                void closeDatabase() override;
                int executeCommand(const std::string &cmd,
                        int (*callback)(void*,int,char**,char**),
                        void *frst,
                        char **errmsg) override;
                void executeRequest(const std::string &command, void *toModify, int (*callback)(void *, int, char **, char **)) override;
            protected:
            private:
                sqlite3 *_db;
        };

        class IServices {
            public:
                virtual ~IServices() {};
                virtual void createTableIfNotExists(IDatabase *db) = 0;
            protected:
                // virtual void getAllRecords()
        };

        class AServices: public IServices {
            public:
                AServices(const std::string &tableName);
                virtual ~AServices() {};
            private:
            protected:
                // sqlite3 *_db;
                std::string _tableName;
        };

        class UserServices: public AServices {
            public:
                UserServices();
                ~UserServices();
                void getAllUsers(IDatabase *db, std::vector<UserDB> &userList) const;
                void addUser(IDatabase *db, UserDB &user) const;
                void getUserByInformations(IDatabase *db, UserDB &user, const std::string &username, const std::string &password) const;
                void getUserById(IDatabase *db, UserDB &user, const int &id) const;
                void getUserByUsername(IDatabase *db, UserDB &user, const std::string &username) const;
                void createTableIfNotExists(IDatabase *db) override;
            private:
                static int callbackGetAllUsers(void *toModify, int argc, char **argv, char **azColName);
                static int callbackGetUser(void *toModify, int argc, char **argv, char **azColName);
            protected:
        };

        class MessagesServices: public AServices {
            public:
                MessagesServices();
                ~MessagesServices();
                void getAllMessages(IDatabase *db, std::vector<Message> &messageList) const;
                void addMessage(IDatabase *db, Message &msg) const;
                void getMessagesByInformations(IDatabase *db, std::vector<Message> &messageList, const int &id1, const int &id2) const;
                void createTableIfNotExists(IDatabase *db) override;
            private:
                static int callbackGetMessages(void *toModify, int argc, char **argv, char **azColName);
            protected:
        };
    }
}

#endif /* !DATABASE_HPP_ */
