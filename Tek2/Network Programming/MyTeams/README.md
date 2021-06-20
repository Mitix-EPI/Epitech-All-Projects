<p align="center"><img src="../../../images/Teams.png" style="max-width: 100px; max-height: 100px" alt="teams"></p>

# My Teams

![Badge Mark](https://img.shields.io/badge/Module%20Mark-A-%2372FA08.svg?&style=for-the-badge&logoColor=black)

## Overview

The goal of this project is to create a **server** and a **CLI client**.
The project MUST have his own protocol described in a RFC’s style documentation.
The project MUST have his own data model in compliance with the given library technical properties.
The network communication is achieved through the use of TCP sockets.

The client handles the following command from the standard input :

```
• /help : show help
• /login [“user_name”] : set the user_name used by client
• /logout : disconnect the client from the server
• /users : get the list of all users that exist on the domain
• /user [“user_uuid”] : get information about a user
• /send [“user_uuid”] [“message_body”] : send a message to a user
• /messages [“user_uuid”] : list all messages exchange with an user
• /subscribe [“team_uuid”] : subscribe to the event of a team and its sub directories (enable reception
of all events from a team)
• /subscribed ?[“team_uuid”] : list all subscribed teams or list all users subscribed to a team
• /unsubscribe [“team_uuid”] : unsubscribe from a team
• /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : use specify a context team/channel/thread
• /create : based on what is being used create the sub resource
• /list : based on what is being used list all the sub resources
• /info : based on what is being used list the current
```

## How to use

The entire project is corrected from a .so file (library file). So, before building the project, you must add the path of the lib into your environment.

```bash
> export LD_LIBRARY_PATH=$PDW/libs/myteams/
> make
```

## Opinion

I loved the start of the project creating architecture of client and server with documentations for the API. But the main problem with this project is that the correction bot is very strange and with low description to help you to improve your code.

## COLLABORATION
- [Jean Louis Deurveilher](https://github.com/Narraxxas)
