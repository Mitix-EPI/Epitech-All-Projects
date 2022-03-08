/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** CallWindow
*/

#include "CallWindow.hpp"
#include "WindowManager.hpp"

GUI::CallWindow::CallWindow(WindowManager *parent)
   : QWidget(&parent->_win)
   , _parent(parent)
   , _background(this)
   , _avatarImage(this)
   , _cancelCall(this)
{
   setFixedSize(WIDTH, HEIGHT);

   _background.setGeometry(0, 0, WIDTH, HEIGHT);
   _background.setObjectName("callWindow");
   _background.setStyleSheet(QString::fromStdString("QWidget#callWindow {" 
                                                   "  background-color: green;"
                                                   "}"
                                                   ));

   _avatarImage.setGeometry(250, 200, 300, 300);
   _avatarImage.setObjectName("avatarImage");
   _avatarImage.setStyleSheet(QString::fromStdString("QWidget#avatarImage {" 
                                                   "  background-image: url(./src/client/ui/avatar_image.png);"
                                                   "}"
                                                   ));

   _cancelCall.setGeometry(500, 600, 100, 100);
   _cancelCall.setObjectName("cancelCall");
   _cancelCall.setStyleSheet(QString::fromStdString("QPushButton#cancelCall {" 
                                                   "  background-image: url(./src/client/ui/decline_call_image.png);"
                                                   "  border: 0px;"
                                                   "}"
                                                   ));

   connect(&_cancelCall, SIGNAL(clicked()), this, SLOT(cancelCallFunc()));
}

GUI::CallWindow::~CallWindow()
{
}

void GUI::CallWindow::cancelCallFunc()
{
   _parent->setState(State::Main);
}
