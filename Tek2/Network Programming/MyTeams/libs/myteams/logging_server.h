/*
** EPITECH PROJECT, XXXX
** NWP_myteams_XXXX
** File description:
** a file containing libs functions that should be called in myteams_server
*/

#ifndef LIB_MYTEAMS_LOGGING_SERVER_H
#define LIB_MYTEAMS_LOGGING_SERVER_H

/*
** As the server never initialize an action all function here are called events
*/

/**
** @brief Must be called when a new team is created
** @param team_uuid The id of the team that was created
** @param team_name The name of the team that was created
** @param user_uuid The id of the user who created the new team
**
** Commands:
** /create "team_name" "team_description"
**/
int server_event_team_created(
    char const *team_uuid,
    char const *team_name,
    char const *user_uuid);

/**
** @brief Must be called when a new channel is created
** @param team_uuid The id of the team this channel is in
** @param channel_uuid The id of the created channel
** @param channel_name The name of the new channel
**
** Commands:
** /create "channel_name" "channel_description"
**/
int server_event_channel_created(
    char const *team_uuid,
    char const *channel_uuid,
    char const *channel_name);

/**
** @brief Must be called when a new thread is created
** @param channel_uuid The id of the channel this thread was created in
** @param thread_uuid The id of the created thread
** @param user_uuid The id of the user who created the thread
** @param thread_title The title of the created thread
** @param thread_body The body of the created thread
**
** Commands:
** /create "thread_title" "thread_body"
**/
int server_event_thread_created(
    char const *channel_uuid,
    char const *thread_uuid,
    char const *user_uuid,
    char const *thread_title,
    char const *thread_body);

/**
** @brief Must be called when a new reply is created in a thread
** @param thread_uuid The id of the thread this message was created in
** @param user_uuid The id of the user who created the reply
** @param reply_body The body of the created reply
**
** Commands:
** /create "reply_body"
**/
int server_event_reply_created(
    char const *thread_uuid,
    char const *user_uuid,
    char const *reply_body);

/**
** @brief Must be called when a user subscribe to a team
** @param team_uuid The id of the subscribed team
** @param user_uuid The id of the subscribed user
**
** Commands:
** /subscribe "team_uuid"
**/
int server_event_user_subscribed(char const *team_uuid, char const *user_uuid);

/**
** @brief Must be called when a user unsubscribe from a team
** @param team_uuid The id of the unsubscribed team
** @param user_uuid The id of the unsubscribed user
**
** Commands:
** /unsubscribe "team_uuid"
**/
int server_event_user_unsubscribed(char const *team_uuid, \
char const *user_uuid);

/**
** @brief Must be called when a user didn't existed in save and was created
** @param user_uuid The id of the user that was created
** @param user_name The name of the user that was created
**
** Commands:
** /login "user_name"
**/
int server_event_user_created(char const *user_uuid, char const *user_name);

/**
** @brief Must be called when a user was loaded from the save file
** Should be called at the start of the server once per user loaded
** It should display all users that were saved
** @param user_uuid The id of the saved user
** @param user_name The name of the saved user
**
** Commands:
** None, should be used at server start
**/
int server_event_user_loaded(char const *user_uuid, char const *user_name);

/**
** @brief Must be called when a user logged in
** @param user_uuid The id of the user that logged in
**
** Commands:
** /login
**/
int server_event_user_logged_in(char const *user_uuid);

/**
** @brief Must be called when a user logged out
** @param user_uuid The id of the user that logged out
**
** Commands:
** /logout
** When a user lost connexion to the server
**/
int server_event_user_logged_out(char const *user_uuid);

/**
** @brief Must be called when a private message was sent between users
** @param sender_uuid The id of the user that sent the message
** @param receiver_uuid The if of the user that receive the message
** @param message_body The message body
**
** Commands:
** /send "user_uuid" "message_body"
**/
int server_event_private_message_sended(
    char const *sender_uuid,
    char const *receiver_uuid,
    char const *message_body);



#endif /* LIB_MYTEAMS_LOGGING_SERVER_H */
