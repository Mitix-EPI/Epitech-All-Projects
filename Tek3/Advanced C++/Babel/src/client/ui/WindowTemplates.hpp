/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** WindowTemplates
*/

#ifndef WINDOWTEMPLATES_HPP_
#define WINDOWTEMPLATES_HPP_

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

    class WindowTemplates : public QWidget {
        Q_OBJECT

        public:
            WindowTemplates(WindowManager *parent = nullptr);
            ~WindowTemplates();

        protected:
        private:
            WindowManager *_parent;

        private slots:
    };
}

#endif /* !WINDOWTEMPLATES_HPP_ */
