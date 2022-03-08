/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** MessageWindow
*/

#ifndef MESSAGEWINDOW_HPP_
#define MESSAGEWINDOW_HPP_

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
#include <QScrollBar>

#include "../../../include/commons/common.h"

namespace GUI {
    class WindowManager;

    class MessageWindow : public QWidget {
        Q_OBJECT

        public:
            MessageWindow(WindowManager *parent = nullptr);
            ~MessageWindow();

        protected:
        private:
            WindowManager *_parent;

            QLabel _usernameLabel;
            QPushButton _backButton;
            QPushButton _callButton;

            QScrollArea _scrollArea;
            QFrame _frame;
            QVBoxLayout _box;

            QTextEdit _messageTextEdit;
            QPushButton _messageButton;

        private slots:
            void backFunc();
            void callFunc();
            void sendMessageFunc();
            void messageFuncResponse(bool res);
            void messageReceiveFuncResponse(MessagesTransfert mess);
    };
}

#endif /* !MESSAGEWINDOW_HPP_ */
