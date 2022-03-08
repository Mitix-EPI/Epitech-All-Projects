/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** CallWindow
*/

#ifndef CALLWINDOW_HPP_
#define CALLWINDOW_HPP_

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

    class CallWindow : public QWidget {
        Q_OBJECT

        public:
            CallWindow(WindowManager *parent = nullptr);
            ~CallWindow();

        protected:
        private:
            WindowManager *_parent;

            QWidget _background;
            QWidget _avatarImage;
            QPushButton _cancelCall;

        private slots:
            void cancelCallFunc();
    };
}

#endif /* !CALLWINDOW_HPP_ */
