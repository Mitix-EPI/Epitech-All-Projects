/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** MainWindow
*/

#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <iostream>
#include <vector>
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
#include "../../../include/commons/common.h"

namespace GUI {
    struct TalkingWith {
        std::string username;
        int id;
    };
    class WindowManager;

    class MainWindow : public QWidget {
        Q_OBJECT

        public:
            MainWindow(WindowManager *parent = nullptr);
            ~MainWindow();
            
        protected:
        private:
            WindowManager *_parent;

            QScrollArea _scrollArea;
            QFrame _frame;
            QVBoxLayout _box;

            QPushButton _refreshButton;

        private slots:
            void resfreshFunc();
            void callFunc(TalkingWith tw);
            void messageFunc(TalkingWith tw);
            void contactFuncResponse(UserContact contact);
            void statusFuncResponse(StatusResponse res);
    };
}

#endif /* !MAINWINDOW_HPP_ */
