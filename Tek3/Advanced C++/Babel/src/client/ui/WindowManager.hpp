/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** WindowManager
*/

#ifndef WINDOWMANAGER_HPP_
#define WINDOWMANAGER_HPP_

#include <iostream>
#include <unordered_map>
#include <memory>
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

#include "AWindowManager.hpp"
#include "../../../include/client/Client.hpp"

#include "MainWindow.hpp"
#include "LoginWindow.hpp"
#include "RegisterWindow.hpp"
#include "MessageWindow.hpp"
#include "CallWindow.hpp"
#include "CallPopUp.hpp"

#include "Sound.hpp"

namespace GUI {
    class WindowManager : public AWindowManager {
        public:
            WindowManager(int &ac, char **&av, Client *client, QWidget *parent = nullptr);
            ~WindowManager();

            void setState(GUI::State state);
            GUI::State getState() const;
            void setTalkingWith(TalkingWith tw);
            TalkingWith getTalkingWith() const;

            void showCallPopUp();
            void hideCallPopUp();

            void update();
            bool isOpen();

            Client *getClient();

            QMainWindow _win;
        protected:
        private:
            Client *_client;

            State _actualState = Login;
            TalkingWith _talkingWith;
            std::vector<std::pair<std::unique_ptr<QWidget>, std::string>> _windows;

            CallPopUp _callPopUp;
            Sound _callSound;

    };
}

#endif /* !WINDOWMANAGER_HPP_ */
