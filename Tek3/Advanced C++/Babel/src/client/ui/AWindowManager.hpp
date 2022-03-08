/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** AWindowManager
*/

#ifndef AWINDOWMANAGER_HPP_
#define AWINDOWMANAGER_HPP_

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

#include "Sound.hpp"
#include "CallPopUp.hpp"

namespace GUI {
    inline int WIDTH = 800;
    inline int HEIGHT = 800;

    enum State : int {
        Login,
        Register,
        Main,
        Message,
        Call,
        NumOfState
    };
    
    class AWindowManager {
        public:
            AWindowManager(int &ac, char **&av) : _app(ac, av) {};
            virtual ~AWindowManager() = default;

            virtual void setState(State state) = 0;
            virtual State getState() const = 0;

            virtual void showCallPopUp() = 0;
            virtual void hideCallPopUp() = 0;

            virtual void update() = 0;
            virtual bool isOpen() = 0;

        protected:
            QApplication _app;
        private:
    };
}

#endif /* !AWINDOWMANAGER_HPP_ */
