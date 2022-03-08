/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** MessageWindow
*/

#include "MessageWindow.hpp"
#include "WindowManager.hpp"

GUI::MessageWindow::MessageWindow(WindowManager *parent)
    : QWidget(&parent->_win)
    , _parent(parent)
    , _usernameLabel("", this)
    , _backButton("Back", this)
    , _callButton(this)
    , _scrollArea(this)
    , _frame(this)
    , _box(&_frame)
    , _messageTextEdit(this)
    , _messageButton(">", this)
{
    setFixedSize(WIDTH, HEIGHT);

    _backButton.setGeometry(10, 10, 100, 50);
    _backButton.setObjectName("backButton");
    _backButton.setStyleSheet("QPushButton#backButton { "
                            "background-color: orange;"
                            "border: 5px solid red;"
                            "border-radius: 10px;"
                            "font-size: 24px;"
                            "}"
                            );

    _usernameLabel.setGeometry(120, 10, 500, 50);
    _usernameLabel.setObjectName("usernameLabel");
    _usernameLabel.setStyleSheet("QLabel#usernameLabel { "
                                "font-size: 32px;"
                                "}"
                                );

    _callButton.setGeometry(740, 10, 50, 50);
    _callButton.setObjectName("callImage");
    _callButton.setStyleSheet(QString::fromStdString("QPushButton#callImage {" 
                                                    "    background-image: url(./src/client/ui/call_image.png);"
                                                    "    border: 0px;"
                                                    "}"
                                                    ));
    
    _scrollArea.setWidget(&_frame);
    _scrollArea.setWidgetResizable(true);
    _scrollArea.setGeometry(10, 70, 780, 580);
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

    _messageTextEdit.setPlaceholderText("Your message");
    _messageTextEdit.setGeometry(10, 660, 640, 130);
    _messageTextEdit.setObjectName("messageTextEdit");
    _messageTextEdit.setStyleSheet(QString::fromStdString("QTextEdit#messageTextEdit {" 
                                                        "border: 2px solid;"
                                                        "border-radius: 10px;"
                                                        "font-size: 38px;"
                                                        "}"
                                                        "QScrollBar:vertical {"              
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
                                                        ));

    _messageButton.setGeometry(660, 660, 130, 130);
    _messageButton.setObjectName("messageButton");
    _messageButton.setStyleSheet(QString::fromStdString("QPushButton#messageButton {" 
                                                   "  background-image: url(./src/client/ui/send_message_image.png);"
                                                   "  border: 0px;"
                                                   "}"
                                                   ));

    connect(_scrollArea.verticalScrollBar(), &QScrollBar::rangeChanged, this, [this](int min, int max){_scrollArea.verticalScrollBar()->setValue(max);});
    connect(&_backButton, SIGNAL(clicked()), this, SLOT(backFunc()));
    connect(&_callButton, SIGNAL(clicked()), this, SLOT(callFunc()));
    connect(&_messageButton, SIGNAL(clicked()), this, SLOT(sendMessageFunc()));

    connect(_parent->getClient(), SIGNAL(messageSignal(bool)), this, SLOT(messageFuncResponse(bool)));
    connect(_parent->getClient(), SIGNAL(messageReceiveSignal(MessagesTransfert)), this, SLOT(messageReceiveFuncResponse(MessagesTransfert)));
}

GUI::MessageWindow::~MessageWindow()
{
}

void GUI::MessageWindow::backFunc()
{
    _parent->setState(State::Main);
}

void GUI::MessageWindow::callFunc()
{
    _parent->setState(State::Call);
}

void GUI::MessageWindow::sendMessageFunc()
{
    std::string mess = _messageTextEdit.toPlainText().toStdString();

    if (mess.length() <= 0) {
        return;
    }
    if (mess.length() > 399) {
        mess.resize(399);
    }
    _parent->getClient()->sendMessage(mess, _parent->getTalkingWith().id);
    _messageTextEdit.clear();
}

void GUI::MessageWindow::messageFuncResponse(bool res)
{
    _usernameLabel.setText(QString::fromStdString(_parent->getTalkingWith().username));
    while(_box.count() > 0) {
        QLayoutItem *item = _box.takeAt(0);
        delete item->widget();
        delete item;
    }
    _box.addStretch();
}

void GUI::MessageWindow::messageReceiveFuncResponse(MessagesTransfert mess)
{
    QFont font("Arial", 18);
    QTextEdit *message = new QTextEdit(QString::fromStdString(mess.message));
    message->setFont(font);
    QString text = QString::fromStdString(mess.message);
    QFontMetrics fm(font);
    QSize textSize = fm.size(0, text);
    int width = textSize.width();
    int height = textSize.height();
    if (width > 500) {
        message->setFixedWidth(500 + 10);
        message->show();
        QSize size = message->document()->size().toSize();
        message->setFixedHeight(size.height() + 10);
    } else {
        message->setFixedWidth(width + 20);
        message->setFixedHeight(height + 15);
    }
    message->setReadOnly(true);
    std::string name = std::to_string(mess.messageId);
    message->setObjectName(QString::fromStdString(name));
    if (mess.receiverId == _parent->getTalkingWith().id) {
        message->setStyleSheet(QString::fromStdString("QTextEdit#" + name + " {" 
                                                    "background-color: blue;"
                                                    "border: 2px solid;"
                                                    "border-radius: 10px;"
                                                    "}"
                                                    ));
        _box.insertWidget(_box.count() - 1, message);
        _box.setAlignment(message, Qt::AlignRight);
    } else {
        message->setStyleSheet(QString::fromStdString("QTextEdit#" + name + " {" 
                                                    "background-color: gray;"
                                                    "border: 2px solid;"
                                                    "border-radius: 10px;"
                                                    "}"
                                                    ));
        _box.insertWidget(_box.count() - 1, message);
        _box.setAlignment(message, Qt::AlignLeft);
    }
}