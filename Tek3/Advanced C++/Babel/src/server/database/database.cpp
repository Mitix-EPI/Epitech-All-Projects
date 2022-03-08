/*
** EPITECH PROJECT, 2021
** database.cpp
** File description:
** database.cpp
*/

#include "server/database/database.hpp"
#include <exception>
#include <vector>
#include "commons/exceptions.hpp"

Babel::Database::MySQLiteDatabase::MySQLiteDatabase(const std::string &dbName): Babel::Database::IDatabase(), _db(nullptr)
{
    try
    {
        std::cout << "[MySQLiteDatabase]" << std::endl;
        openDatabase(dbName);
    }
    catch (const Errors &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Babel::Database::MySQLiteDatabase::~MySQLiteDatabase()
{
    closeDatabase();
}

void Babel::Database::MySQLiteDatabase::openDatabase(const std::string &dbname)
{
    if (sqlite3_open(dbname.c_str(), &_db)) {
        throw Errors("Error while opening the database");
    }
}

void Babel::Database::MySQLiteDatabase::closeDatabase()
{
    sqlite3_close(_db);
}

void Babel::Database::MySQLiteDatabase::executeRequest(const std::string &command, void *toModify, int (*callback)(void *, int, char **, char **))
{
    try
    {
        executeCommand(command.c_str(), callback, toModify, nullptr);
    }
    catch (const Errors &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int Babel::Database::MySQLiteDatabase::executeCommand(const std::string &cmd,
                                            int (*callback)(void*,int,char**,char**),
                                            void *frst,
                                            char **errmsg)
{
    if (sqlite3_exec(_db, cmd.c_str(), callback, frst, errmsg))
        throw Errors("Error while executing command");
    return 0;
}

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                              SERVICES                               //
//                                                                     //
////////////////////////////////////////////////////////////////////////


Babel::Database::AServices::AServices(const std::string &tableName): IServices(), _tableName(tableName)
{
}

Babel::Database::UserServices::UserServices(): AServices("USERS")
{
}

Babel::Database::UserServices::~UserServices()
{
}

void Babel::Database::UserServices::createTableIfNotExists(Babel::Database::IDatabase *db)
{
    std::string createTableCommand = std::string("CREATE TABLE IF NOT EXISTS ") + _tableName + "(" \
                                     "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, " \
                                     "USERNAME TEXT NOT NULL, " \
                                     "PASSWORD TEXT NOT NULL);";

    std::cout << "[createTableIfNotExists]" << std::endl;
    std::cout << "[createTableIfNotExists] == " << createTableCommand << std::endl;
    // std::string userTable = "CREATE TABLE IF NOT EXISTS USERS (" \
    //                         "ID INTEGER PRIMARY KEY AUTOINCREMENT,"\
    //                         "USERNAME TEXT NOT NULL," \
    //                         "PASSWORD TEXT NOT NULL);";

    db->executeRequest(createTableCommand, nullptr, nullptr);
}

void Babel::Database::UserServices::getAllUsers(IDatabase *db, std::vector<UserDB> &userList) const
{
    std::string getUsersCommand = std::string("SELECT * FROM ") + _tableName + ";";

    db->executeRequest(getUsersCommand, &userList, &callbackGetAllUsers);
}

void Babel::Database::UserServices::addUser(IDatabase *db, UserDB &user) const
{
    std::string command = std::string("INSERT INTO ") + _tableName + " (USERNAME, PASSWORD) VALUES ("
                                + "'" + user.username + "', '" + user.password + "')";

    std::cout << "[addUser]" << std::endl;
    std::cout << "[addUser] == " << command << std::endl;
    db->executeRequest(command, nullptr, nullptr);    
}

void Babel::Database::UserServices::getUserByInformations(IDatabase *db, UserDB &user, const std::string &username, const std::string &password) const
{
    std::string command = std::string("SELECT * FROM ") + _tableName + " WHERE USERNAME = '" + username + "'"
                        + " AND PASSWORD = '" + password + "';";

    std::cout << "[getUserByInformations]" << std::endl;
    std::cout << "[getUserByInformations] == " << command << std::endl;
    db->executeRequest(command, &user, &callbackGetUser);
}

void Babel::Database::UserServices::getUserById(IDatabase *db, UserDB &user, const int &id) const
{
    std::string command = std::string("SELECT * FROM ") + _tableName + " WHERE ID = '" + std::to_string(id) + "';";

    db->executeRequest(command, &user, &callbackGetUser);
}

void Babel::Database::UserServices::getUserByUsername(IDatabase *db, UserDB &user, const std::string &username) const
{
    std::string command = std::string("SELECT * FROM ") + _tableName + " WHERE USERNAME = '" + username + "';";

    db->executeRequest(command, &user, &callbackGetUser);
}

int Babel::Database::UserServices::callbackGetAllUsers(void *toModify, int argc, char **argv, char **azColName)
{
    std::vector<Babel::Database::UserDB> *listUser = (std::vector<Babel::Database::UserDB> *)toModify;
    if (listUser && argc == 3) { // changer avec le nombre de champs présent dans la table USERS
        Babel::Database::UserDB usr = { id: std::stoi(std::string(argv[0])), username: std::string(argv[1]), password: std::string(argv[2]) };
        listUser->push_back(usr);
    }
    return 0;
}

int Babel::Database::UserServices::callbackGetUser(void *toModify, int argc, char **argv, char **azColName)
{
    std::cout << "[callbackGetUser]" << std::endl;
    for (int i = 0; i < argc; i++)
        std::cout << "av[" << i << "] == " << argv[i] << std::endl;

    Babel::Database::UserDB *user = (Babel::Database::UserDB *)toModify;
    if (user && argc == 3) {
        user->id = std::stoi(std::string(argv[0]));
        user->username = std::string(argv[1]);
        user->password = std::string(argv[2]);
    } else {
        user->id = -1;
        user->username = "";
        user->password = "";
    }
    return 0;
}

Babel::Database::MessagesServices::MessagesServices(): AServices("MESSAGES")
{
}

Babel::Database::MessagesServices::~MessagesServices()
{
}

void Babel::Database::MessagesServices::createTableIfNotExists(Babel::Database::IDatabase *db)
{
    std::string MessageTable = std::string("CREATE TABLE IF NOT EXISTS ") + _tableName + "(" \
                            "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, " \
                            "SENDERID INTEGER NOT NULL, " \
                            "RECEIVERID INTEGER NOT NULL, " \
                            "MESSAGETEXT TEXT NOT NULL);";

    db->executeRequest(MessageTable, nullptr, nullptr);
}

void Babel::Database::MessagesServices::addMessage(IDatabase *db, Message &msg) const
{
    std::string command = std::string("INSERT INTO ") + _tableName + " (SENDERID, RECEIVERID, MESSAGETEXT) VALUES ("
                        + "'" + std::to_string(msg.senderId) + "', '" + std::to_string(msg.receiverId) + "', '" + msg.message + "')";

    std::cout << "[addMessage] == " << command << std::endl;
    db->executeRequest(command, nullptr, nullptr);    
}

void Babel::Database::MessagesServices::getAllMessages(IDatabase *db, std::vector<Message> &messageList) const
{
    const std::string command = std::string("SELECT * FROM ") + _tableName + ";";

    db->executeRequest(command, &messageList, &callbackGetMessages);
}

void Babel::Database::MessagesServices::getMessagesByInformations(IDatabase *db, std::vector<Message> &messageList, const int &id1, const int &id2) const
{
    const std::string command = std::string("SELECT * FROM ") + _tableName + " WHERE ( SENDERID = '"
                                + std::to_string(id1) + "' AND RECEIVERID = '" + std::to_string(id2)
                                + "' ) OR ( SENDERID = '" + std::to_string(id2) + "' AND RECEIVERID = '"
                                + std::to_string(id1) + "' );";

    db->executeRequest(command, &messageList, &callbackGetMessages);
}

int Babel::Database::MessagesServices::callbackGetMessages(void *toModify, int argc, char **argv, char **azColName)
{
    std::vector<Babel::Database::Message> *listUser = (std::vector<Babel::Database::Message> *)toModify;
    if (listUser && argc == 4) { // changer avec le nombre de champs présent dans la table USERS
        Babel::Database::Message msg = { messageId: std::stoi(std::string(argv[0])), senderId: std::stoi(std::string(argv[1])), receiverId: std::stoi(std::string(argv[2])), message: std::string(argv[3]) };
        listUser->push_back(msg);
    }
    return 0;
}

// void Babel::Database::SDatabase::openDatabase(const std::string &dbname, sqlite3 **ppDb)
// {
//     if (sqlite3_open(dbname.c_str(), ppDb)) {
//         throw Errors("Error while opening the database");
//     }
// }

// void Babel::Database::SDatabase::closeDatabase(sqlite3 *ppDb)
// {
//     sqlite3_close(ppDb);
// }

// int Babel::Database::SDatabase::executeCommand(sqlite3 *db, const std::string &cmd, int (*callback)(void*,int,char**,char**), void *frst, char **errmsg)
// {
//     if (sqlite3_exec(db, cmd.c_str(), callback, frst, errmsg))
//         throw Errors("Error while executing command");
//     return 0;
// }

// Babel::Database::MyDatabase::MyDatabase(): _db(nullptr)
// {
// //     std::string userTable = "CREATE TABLE IF NOT EXISTS USERS (" \
// //                             "ID INTEGER PRIMARY KEY AUTOINCREMENT,"\
// //                             "USERNAME TEXT NOT NULL," \
// //                             "PASSWORD TEXT NOT NULL);";
//     try
//     {
//         Babel::Database::SDatabase::openDatabase("dabase.db", &_db);
// //         executeCommand(userTable, nullptr, nullptr);
//     }
//     catch(const Errors &e)
//     {
//         std::cout << e.what() << std::endl;
//     }
// }

// Babel::Database::MyDatabase::~MyDatabase()
// {
//     Babel::Database::SDatabase::closeDatabase(_db);
// }

// void Babel::Database::MyDatabase::executeCommand(std::string command, void *toModify, int (*callback)(void *, int, char **, char **)) const
// {
//     try
//     {
//         Babel::Database::SDatabase::executeCommand(_db, command.c_str(), callback, toModify, nullptr);
//     }
//     catch (const Errors &e)
//     {
//         std::cout << e.what() << std::endl;
//     }
// }

// // void Babel::Database::MyDatabase::addUser(Babel::Database::UserDB &user) const
// // {
// //     std::string command = std::string("INSERT INTO USERS (ID, USERNAME, PASSWORD) VALUES (")
// //                         + std::to_string(user.id) + ", '" + user.username + "', '"
// //                         + user.password + "')";

// //     try
// //     {
// //         executeCommand(command, nullptr, nullptr);
// //     }
// //     catch(const Errors &e)
// //     {
// //         std::cout << e.what() << std::endl;
// //     }
// // }

// // void Babel::Database::MyDatabase::getAllUsers(std::vector<Babel::Database::UserDB> &userList) const
// // {
// //     std::string getUsers = "SELECT * FROM USERS";

// //     try
// //     {
// //         executeCommand(getUsers, &userList, &callbackGetAllUsers);
// //     }
// //     catch(const Errors &e)
// //     {
// //         std::cout << e.what() << std::endl;
// //     }
// // }

// // void Babel::Database::MyDatabase::getUserByInformations(Babel::Database::UserDB &user, const std::string &username, const std::string &password) const
// // {
// //     std::string command = std::string("SELECT * FROM USERS WHERE USERNAME = '")
// //                         + username + "' AND PASSWORD = '" + password + "';";

// //     try
// //     {
// //         executeCommand(command, &user, &callbackGetUser);
// //     }
// //     catch(const Errors &e)
// //     {
// //         std::cout << e.what() << std::endl;
// //     }
// // }

// // void Babel::Database::MyDatabase::getUserById(Babel::Database::UserDB &user, const int &id) const
// // {
// //     std::string command = std::string("SELECT * FROM USERS WHERE ID = '")
// //                         + std::to_string(id) + "';";

// //     try
// //     {
// //         executeCommand(command, &user, &callbackGetUser);
// //     }
// //     catch(const Errors &e)
// //     {
// //         std::cout << e.what() << std::endl;
// //     }
// // }

// // void Babel::Database::MyDatabase::getUserByUsername(Babel::Database::UserDB &user, const std::string &username) const
// // {
// //     std::string command = std::string("SELECT * FROM USERS WHERE USERNAME = '")
// //                         + username + "';";

// //     try
// //     {
// //         executeCommand(command, &user, &callbackGetUser);
// //     }
// //     catch(const Errors &e)
// //     {
// //         std::cout << e.what() << std::endl;
// //     }
// // }

// // int Babel::Database::MyDatabase::callbackGetAllUsers(void *toModify, int argc, char **argv, __attribute__((unused))char **azColName)
// // {
// //     std::vector<Babel::Database::UserDB> *listUser = (std::vector<Babel::Database::UserDB> *)toModify;
// //     if (listUser && argc == 3) { // changer avec le nombre de champs présent dans la table USERS
// //         Babel::Database::UserDB usr = { id: std::stoi(std::string(argv[0])), username: std::string(argv[1]), password: std::string(argv[2]) };
// //         listUser->push_back(usr);
// //     }
// //     return 0;
// // }

// // int Babel::Database::MyDatabase::callbackGetUser(void *toModify, int argc, char **argv, __attribute__((unused))char **azColName)
// // {
// //     Babel::Database::UserDB *user = (Babel::Database::UserDB *)toModify;
// //     if (user && argc == 3) {
// //         user->id = std::stoi(std::string(argv[0]));
// //         user->username = std::string(argv[1]);
// //         user->password = std::string(argv[2]);
// //     }
// //     return 0;
// // }


// //////////////////////////////////////////////////

// // Babel::Database::AServices::AServices(sqlite3 *db): _db(db)
// // {
// //     std::string userTable = "CREATE TABLE IF NOT EXISTS USERS (" \
// //                             "ID INTEGER PRIMARY KEY AUTOINCREMENT,"\
// //                             "USERNAME TEXT NOT NULL," \
// //                             "PASSWORD TEXT NOT NULL);";
// //     try
// //     {
// //         Babel::Database::SDatabase::openDatabase("dabase.db", &_db);
// //         executeCommand(userTable, nullptr, nullptr);
// //     }
// //     catch(const Errors &e)
// //     {
// //         std::cout << e.what() << std::endl;
// //     }
// // }

// Babel::Database::AServices::AServices(Babel::Database::MyDatabase *db)
// {
//     _db = db;
// }

