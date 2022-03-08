/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** LoginWindow
*/

#include "LoginWindow.hpp"
#include "WindowManager.hpp"

GUI::LoginWindow::LoginWindow(WindowManager *parent)
   : QWidget(&parent->_win)
   , _parent(parent)
   , _loginButton("Login", this)
   , _registerButton("Register", this)
   , _userNameLabel("UserName :", this)
   , _passwordLabel("Password :", this)
   , _loginErrorLabel("UserName or Password not recognized, click Register if you have no account", this)
   , _userNameLineEdit(this)
   , _passwordLineEdit(this)
   , _passwordEyeButton(this)
{
    setFixedSize(WIDTH, HEIGHT);

    _userNameLabel.setStyleSheet("QLabel{ "
                                "font-size: 24px;"
                                "}"
                                );
    _passwordLabel.setStyleSheet("QLabel{ "
                                "font-size: 24px;"
                                "}"
                                );
    _loginErrorLabel.setStyleSheet("QLabel{ "
                                "font-size: 14px;"
                                "color:rgb(255, 0, 0);"
                                "}"
                                );

    _userNameLineEdit.setPlaceholderText("Your UserName");
    _userNameLineEdit.setStyleSheet("QLineEdit{ "
                                    "background-color:rgb(202, 255, 227);"
                                    "border: 2px solid gray;"
                                    "border-radius: 10px;"
                                    "padding: 0 8px;"
                                    "selection-background-color: darkgray;"
                                    "font-size: 28px;}"
                                    "QLineEdit:focus { "
                                    "background-color:rgb(192, 192, 255);"
                                    "}"
                                    );
    _passwordLineEdit.setPlaceholderText("Your Password");
    _passwordLineEdit.setStyleSheet("QLineEdit{ "
                                    "background-color:rgb(202, 255, 227);"
                                    "border: 2px solid gray;"
                                    "border-radius: 10px;"
                                    "padding: 0 8px;"
                                    "selection-background-color: darkgray;"
                                    "font-size: 28px;}"
                                    "QLineEdit:focus { "
                                    "background-color:rgb(192, 192, 255);"
                                    "}"
                                    );
    _passwordLineEdit.setEchoMode(QLineEdit::EchoMode::Password);
    _passwordEyeButton.setObjectName("passwordEye");
    _passwordEyeButton.setStyleSheet(QString::fromStdString("QPushButton#passwordEye {" 
                                                            "    background-image: url(./src/client/ui/close_eye_image.png);"
                                                            "border: 0px solid;"
                                                            "}"
                                                            ));

    _userNameLabel.setGeometry(200, 150, 400, 50);
    _userNameLineEdit.setGeometry(200, 200, 400, 50);
    _passwordLabel.setGeometry(200, 300, 400, 50);
    _passwordLineEdit.setGeometry(200, 350, 400, 50);
    _passwordEyeButton.setGeometry(620, 350, 100, 50);

    _loginErrorLabel.setGeometry(100, 450, 600, 50);
    _loginErrorLabel.hide();

    _loginButton.setGeometry(50, 565, 700, 100);
    _loginButton.setObjectName("loginButton");
    _loginButton.setStyleSheet("QPushButton#loginButton { "
                                    "background-color: green;"
                                    "border: 5px solid darkgreen;"
                                    "border-radius: 10px;"
                                    "font-size: 36px;"
                                    "}"
                                    );
    _registerButton.setGeometry(50, 690, 700, 100);
    _registerButton.setObjectName("registerButton");
    _registerButton.setStyleSheet("QPushButton#registerButton { "
                                    "background-color: blue;"
                                    "border: 5px solid darkblue;"
                                    "border-radius: 10px;"
                                    "font-size: 36px;"
                                    "}"
                                    );
    connect(&_loginButton, SIGNAL(clicked()), this, SLOT(loginFunc()));
    connect(&_registerButton, SIGNAL(clicked()), this, SLOT(registerFunc()));
    connect(&_passwordEyeButton, SIGNAL(clicked()), this, SLOT(changeEyeFunc()));

    connect(_parent->getClient(), SIGNAL(loginSignal(bool)), this, SLOT(loginFuncResponse(bool)));
}

GUI::LoginWindow::~LoginWindow()
{
}

void GUI::LoginWindow::loginFunc()
{
    std::string username = _userNameLineEdit.text().toStdString();
    std::string password = _passwordLineEdit.text().toStdString();

    if (password.length() < 3 || password.length() > 20 || username.length() < 3 || username.length() > 20) {
        _loginErrorLabel.setText("UserName or Password not recognized, click Register if you have no account");
        _loginErrorLabel.show();
        return;
    }
    _parent->getClient()->loginUser(username, password);
}

void GUI::LoginWindow::loginFuncResponse(bool res)
{
    if (res) {
        _loginErrorLabel.hide();
        _parent->setState(State::Main);
    } else {
        _loginErrorLabel.setText("UserName or Password not recognized, click Register if you have no account");
        _loginErrorLabel.show();
        return;
    }
}

void GUI::LoginWindow::registerFunc()
{
    _loginErrorLabel.hide();
    _parent->setState(State::Register);
}

void GUI::LoginWindow::changeEyeFunc()
{
    if (_eyeState == false) {
        _passwordLineEdit.setEchoMode(QLineEdit::EchoMode::Normal);
        _passwordEyeButton.setStyleSheet(QString::fromStdString("QPushButton#passwordEye {" 
                                                                "    background-image: url(./src/client/ui/open_eye_image.png);"
                                                                "border: 0px solid;"
                                                                "}"
                                                                ));
        _eyeState = true;
    } else {
        _passwordLineEdit.setEchoMode(QLineEdit::EchoMode::Password);
        _passwordEyeButton.setStyleSheet(QString::fromStdString("QPushButton#passwordEye {" 
                                                                "    background-image: url(./src/client/ui/close_eye_image.png);"
                                                                "border: 0px solid;"
                                                                "}"
                                                                ));
        _eyeState = false;
    }
}