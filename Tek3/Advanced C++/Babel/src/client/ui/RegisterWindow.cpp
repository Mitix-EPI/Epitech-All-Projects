/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** RegisterWindow
*/

#include "RegisterWindow.hpp"
#include "WindowManager.hpp"

GUI::RegisterWindow::RegisterWindow(WindowManager *parent)
    : QWidget(&parent->_win)
    , _parent(parent)
    , _backButton("Back", this)
    , _registerButton("Register", this)
    , _userNameLabel("UserName :", this)
    , _passwordLabel("Password :", this)
    , _passwordConfirmLabel("Confirm Password :", this)
    , _loginErrorLabel("PassWords are not the same", this)
    , _userNameLineEdit(this)
    , _passwordLineEdit(this)
    , _passwordConfirmLineEdit(this)
    , _passwordEyeButton(this)
    , _passwordConfirmEyeButton(this)
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

    _userNameLabel.setStyleSheet("QLabel{ "
                                "font-size: 24px;"
                                "}"
                                );
    _passwordLabel.setStyleSheet("QLabel{ "
                                "font-size: 24px;"
                                "}"
                                );
    _passwordConfirmLabel.setStyleSheet("QLabel{ "
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
    _passwordConfirmLineEdit.setPlaceholderText("Confirm your Password");
    _passwordConfirmLineEdit.setStyleSheet("QLineEdit{ "
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
    _passwordConfirmLineEdit.setEchoMode(QLineEdit::EchoMode::Password);
    _passwordConfirmEyeButton.setObjectName("passwordConfirmEye");
    _passwordConfirmEyeButton.setStyleSheet(QString::fromStdString("QPushButton#passwordConfirmEye {" 
                                                            "    background-image: url(./src/client/ui/close_eye_image.png);"
                                                            "border: 0px solid;"
                                                            "}"
                                                            ));
                                                            
    _userNameLabel.setGeometry(200, 150, 400, 50);
    _userNameLineEdit.setGeometry(200, 200, 400, 50);
    _passwordLabel.setGeometry(200, 300, 400, 50);
    _passwordLineEdit.setGeometry(200, 350, 400, 50);
    _passwordEyeButton.setGeometry(620, 350, 100, 50);
    _passwordConfirmLabel.setGeometry(200, 450, 400, 50);
    _passwordConfirmLineEdit.setGeometry(200, 500, 400, 50);
    _passwordConfirmEyeButton.setGeometry(620, 500, 100, 50);

    _loginErrorLabel.setGeometry(100, 600, 600, 50);
    _loginErrorLabel.hide();

    _registerButton.setGeometry(50, 690, 700, 100);
    _registerButton.setObjectName("registerButton");
    _registerButton.setStyleSheet("QPushButton#registerButton { "
                                    "background-color: blue;"
                                    "border: 2px solid gray;"
                                    "border-radius: 10px;"
                                    "font-size: 36px;"
                                    "}"
                                    );

    connect(&_backButton, SIGNAL(clicked()), this, SLOT(backFunc()));
    connect(&_registerButton, SIGNAL(clicked()), this, SLOT(registerFunc()));
    connect(&_passwordEyeButton, SIGNAL(clicked()), this, SLOT(changeEyeFunc()));
    connect(&_passwordConfirmEyeButton, SIGNAL(clicked()), this, SLOT(changeEyeConfirmFunc()));

    connect(_parent->getClient(), SIGNAL(registerSignal(bool)), this, SLOT(registerFuncResponse(bool)));
}

GUI::RegisterWindow::~RegisterWindow()
{
}

void GUI::RegisterWindow::registerFunc()
{
    std::string username = _userNameLineEdit.text().toStdString();
    std::string password = _passwordLineEdit.text().toStdString();
    std::string passwordConfirm = _passwordConfirmLineEdit.text().toStdString();

    if (password != passwordConfirm) {
        _loginErrorLabel.setText("PassWords are not the same");
        _loginErrorLabel.show();
        return;
    }
    if (password.length() < 3 || password.length() > 20 || username.length() < 3 || username.length() > 20) {
        _loginErrorLabel.setText("PassWords or Username must be between 3 and 20 characters");
        _loginErrorLabel.show();
        return;
    }
    _parent->getClient()->registerUser(username, password);
}

void GUI::RegisterWindow::registerFuncResponse(bool res)
{
    if (res) {
        _loginErrorLabel.hide();
        _parent->setState(State::Login);
    } else {
        _loginErrorLabel.setText("Username or Password already exist");
        _loginErrorLabel.show();
        return;
    }
}

void GUI::RegisterWindow::changeEyeFunc()
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

void GUI::RegisterWindow::changeEyeConfirmFunc()
{
    if (_eyeConfirmState == false) {
        _passwordConfirmLineEdit.setEchoMode(QLineEdit::EchoMode::Normal);
        _passwordConfirmEyeButton.setStyleSheet(QString::fromStdString("QPushButton#passwordConfirmEye {" 
                                                                        "    background-image: url(./src/client/ui/open_eye_image.png);"
                                                                        "border: 0px solid;"
                                                                        "}"
                                                                        ));
        _eyeConfirmState = true;
    } else {
        _passwordConfirmLineEdit.setEchoMode(QLineEdit::EchoMode::Password);
        _passwordConfirmEyeButton.setStyleSheet(QString::fromStdString("QPushButton#passwordConfirmEye {" 
                                                                        "    background-image: url(./src/client/ui/close_eye_image.png);"
                                                                        "border: 0px solid;"
                                                                        "}"
                                                                        ));
        _eyeConfirmState = false;
    }
}

void GUI::RegisterWindow::backFunc()
{
    _parent->setState(State::Login);
}