/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** LoginWindow
*/

#ifndef LOGINWINDOW_HPP_
#define LOGINWINDOW_HPP_

#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QActionGroup>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QScrollArea>
#include <QFrame>
#include <QSignalMapper>
#include <QMap>
#include <QPalette>
#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QSlider>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>

namespace GUI {
    class WindowManager;

    class LoginWindow : public QWidget {
        Q_OBJECT

        public:
            LoginWindow(WindowManager *parent = nullptr);
            ~LoginWindow();


        protected:
        private:
            WindowManager *_parent;

            QPushButton _loginButton;
            QPushButton _registerButton;
            QLabel _userNameLabel;
            QLabel _passwordLabel;
            QLabel _loginErrorLabel;
            QLineEdit _userNameLineEdit;
            QLineEdit _passwordLineEdit;
            QPushButton _passwordEyeButton;

            bool _eyeState = false;

        private slots:
            void loginFunc();
            void loginFuncResponse(bool res);
            void registerFunc();
            void changeEyeFunc();
    };
}

#endif /* !LOGINWINDOW_HPP_ */
