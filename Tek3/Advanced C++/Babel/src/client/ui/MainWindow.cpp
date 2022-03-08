/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** MainWindow
*/

#include "MainWindow.hpp"
#include "WindowManager.hpp"

GUI::MainWindow::MainWindow(WindowManager *parent)
   : QWidget(&parent->_win)
   , _parent(parent)
   , _scrollArea(this)
   , _frame(this)
   , _box(&_frame)
   , _refreshButton("Refresh", this)
{
   setFixedSize(WIDTH, HEIGHT);

   _refreshButton.setGeometry(10, 10, 150, 50);
   _refreshButton.setObjectName("refreshButton");
   _refreshButton.setStyleSheet("QPushButton#refreshButton { "
                                 "background-color: skyblue;"
                                 "border: 5px solid blue;"
                                 "border-radius: 10px;"
                                 "font-size: 24px;"
                                 "}"
                                 );

   _scrollArea.setWidget(&_frame);
   _scrollArea.setWidgetResizable(true);
   _scrollArea.setGeometry(0, 70, WIDTH, HEIGHT - 70);
   _scrollArea.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

   _scrollArea.setStyleSheet("QScrollBar:vertical {"              
                              "    border: 3px solid gray;"
                              "    border-radius: 10px;"
                              "    background: darkgray;"
                              "    width: 30px;"
                              "}"
                              "QScrollBar::handle:vertical {"
                              "    border: 0px;"
                              "    border-radius: 10px;"
                              "    background: blue"
                              "}"
                              "QScrollBar::add-line:vertical {"
                              "    height: 0px;"
                              "}"
                              "QScrollBar::sub-line:vertical {"
                              "    height: 0 px;"
                              "}"
                              );

   _box.setSpacing(10);
   _box.addStretch();

   connect(&_refreshButton, SIGNAL(clicked()), this, SLOT(resfreshFunc()));
   connect(_parent->getClient(), SIGNAL(userSignal(UserContact)), this, SLOT(contactFuncResponse(UserContact)));
   connect(_parent->getClient(), SIGNAL(statusSignal(StatusResponse)), this, SLOT(statusFuncResponse(StatusResponse)));
}

GUI::MainWindow::~MainWindow()
{
}

void GUI::MainWindow::resfreshFunc()
{
   while(_box.count() > 0) {
      QLayoutItem *item = _box.takeAt(0);
      delete item->widget();
      delete item;
   }
   _box.addStretch();
   _parent->getClient()->getContactList();
}

void GUI::MainWindow::statusFuncResponse(StatusResponse res)
{
   while(_box.count() > 0) {
      QLayoutItem *item = _box.takeAt(0);
      delete item->widget();
      delete item;
   }
   _box.addStretch();
   _parent->getClient()->getContactList();
}

void GUI::MainWindow::callFunc(TalkingWith tw)
{
   // _parent->setState(State::Call);
   _parent->showCallPopUp();
   _parent->setTalkingWith(tw);
}

void GUI::MainWindow::messageFunc(TalkingWith tw)
{
   _parent->getClient()->getMessageWithUser(tw.id);
   _parent->setState(State::Message);
   _parent->setTalkingWith(tw);
}

void GUI::MainWindow::contactFuncResponse(UserContact user)
{
   TalkingWith tw;
   tw.username = user.username;
   tw.id = user.id;
   QWidget *contact = new QWidget;
   contact->setFixedHeight(100);
   contact->setObjectName("contact");
   contact->setStyleSheet("QWidget#contact {"              
                           "    border: 3px solid gray;"
                           "    border-radius: 10px;"
                           "}"
                           );

   QHBoxLayout *Hlayout = new QHBoxLayout(contact);
   {
      QWidget *connected = new QWidget;
      connected->setFixedHeight(50);
      connected->setFixedWidth(50);
      connected->setObjectName("connected");
      std::string color;
      switch (user.status) {
         case (Babel::Common::UserState::ONLINE):
            color = "green";
            break;
         case (Babel::Common::UserState::INCALL):
            color = "orange";
            break;
         case (Babel::Common::UserState::OFFLINE):
            color = "red";
            break;
         case (Babel::Common::UserState::UNKNOWN):
            color = "gray";
            break;
      }
      connected->setStyleSheet(QString::fromStdString("QWidget#connected {" 
                                                      "    border: 0px;"
                                                      "    border-radius: 25px;"
                                                      "    background: " + color + ";"
                                                      "}"
                                                      ));

      QLabel *username = new QLabel(QString::fromStdString(user.username));
      username->setStyleSheet("QLabel{ "
                              "font-size: 24px;}"
                              );
      QTextEdit *lastmessage = new QTextEdit(""); 
      lastmessage->setReadOnly(true);
      QPushButton *callButton = new QPushButton;
      callButton->setFixedHeight(50);
      callButton->setFixedWidth(50);
      callButton->setObjectName("callImage");
      callButton->setStyleSheet(QString::fromStdString("QPushButton#callImage {" 
                                                      "    background-image: url(./src/client/ui/call_image.png);"
                                                      "    border: 0px;"
                                                      "}"
                                                      ));
      connect(callButton, &QPushButton::clicked, [=]{callFunc(tw);});
      QPushButton *messageButton = new QPushButton;
      messageButton->setFixedHeight(50);
      messageButton->setFixedWidth(50);
      messageButton->setObjectName("messageButton");
      messageButton->setStyleSheet(QString::fromStdString("QPushButton#messageButton {" 
                                                      "    background-image: url(./src/client/ui/message_image.png);"
                                                      "    border: 0px;"
                                                      "}"
                                                      ));
      connect(messageButton, &QPushButton::clicked, this, [=]{messageFunc(tw);});

      Hlayout->addWidget(connected);
      Hlayout->addWidget(username);
      Hlayout->addWidget(lastmessage);
      Hlayout->addWidget(callButton);
      Hlayout->addWidget(messageButton);
   }
   _box.insertWidget(_box.count() - 1, contact);
}