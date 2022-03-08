/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** CallPopUp
*/

#ifndef CALLPOPUP_HPP_
#define CALLPOPUP_HPP_

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
#include <QPropertyAnimation>

namespace GUI {
    class WindowManager;

    class CallPopUp : public QMainWindow {
        Q_OBJECT

        public:
            CallPopUp(WindowManager *parent = nullptr);
            ~CallPopUp();

        protected:
        private:
            WindowManager *_parent;

            QWidget _background;
            QPushButton _acceptCall;
            QPushButton _declineCall;

            QPropertyAnimation _acceptAnimation;

        private slots:
            void acceptFunc();
            void declineFunc();
    };
}

#endif /* !CALLPOPUP_HPP_ */
