/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** CallPopUp
*/

#include "CallPopUp.hpp"
#include "WindowManager.hpp"

GUI::CallPopUp::CallPopUp(WindowManager *parent)
   : QMainWindow(&parent->_win)
   , _parent(parent)
   , _background(this)
   , _acceptCall(this)
   , _declineCall(this)
   , _acceptAnimation(&_acceptCall, "geometry", this)
{
    setFixedSize(400, 200);

    _background.setGeometry(0, 0, 400, 200);
    _background.setObjectName("callPopUp");
    _background.setStyleSheet(QString::fromStdString("QWidget#callPopUp {" 
                                                    "background-color: lightskyblue;"
                                                    "}"
                                                    ));

    _acceptCall.setGeometry(50, 50, 100, 100);
    _acceptCall.setObjectName("acceptCall");
    _acceptCall.setStyleSheet(QString::fromStdString("QPushButton#acceptCall {" 
                                                    "border-image: url(./src/client/ui/accept_call_image.png) 0 0 0 0 stretch stretch;"
                                                    "border: 0px;"
                                                    "}"
                                                    ));

    _declineCall.setGeometry(250, 50, 100, 100);
    _declineCall.setObjectName("declineCall");
    _declineCall.setStyleSheet(QString::fromStdString("QPushButton#declineCall {" 
                                                    "border-image: url(./src/client/ui/decline_call_image.png) 0 0 0 0 stretch stretch;"
                                                    "border: 0px;"
                                                    "}"
                                                    ));

    _acceptAnimation.setDuration(1000);
    _acceptAnimation.setKeyValueAt(0, QRect(50, 50, 100, 100));
    _acceptAnimation.setKeyValueAt(0.5, QRect(25, 25, 150, 150));
    _acceptAnimation.setKeyValueAt(1, QRect(50, 50, 100, 100));
    _acceptAnimation.setLoopCount(-1);
    _acceptAnimation.start();

    connect(&_acceptCall, SIGNAL(clicked()), this, SLOT(acceptFunc()));
    connect(&_declineCall, SIGNAL(clicked()), this, SLOT(declineFunc()));
}

GUI::CallPopUp::~CallPopUp()
{
}

void GUI::CallPopUp::acceptFunc()
{
    _parent->hideCallPopUp();
    _parent->setState(State::Call);
}

void GUI::CallPopUp::declineFunc()
{
    _parent->hideCallPopUp();
}