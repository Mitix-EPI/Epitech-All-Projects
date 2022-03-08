/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** RegisterWindow
*/

#ifndef REGISTERWINDOW_HPP_
#define REGISTERWINDOW_HPP_

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

    class RegisterWindow : public QWidget {
        Q_OBJECT

        public:
            RegisterWindow(WindowManager *parent = nullptr);
            ~RegisterWindow();

        protected:
        private:
            WindowManager *_parent;

            QPushButton _registerButton;
            QPushButton _backButton;
            QLabel _userNameLabel;
            QLabel _passwordLabel;
            QLabel _passwordConfirmLabel;
            QLabel _loginErrorLabel;
            QLineEdit _userNameLineEdit;
            QLineEdit _passwordLineEdit;
            QLineEdit _passwordConfirmLineEdit;
            QPushButton _passwordEyeButton;
            QPushButton _passwordConfirmEyeButton;

            bool _eyeState = false;
            bool _eyeConfirmState = false;

        private slots:
            void registerFunc();
            void registerFuncResponse(bool res);
            void changeEyeFunc();
            void changeEyeConfirmFunc();
            void backFunc();
    };
}

#endif /* !REGISTERWINDOW_HPP_ */
