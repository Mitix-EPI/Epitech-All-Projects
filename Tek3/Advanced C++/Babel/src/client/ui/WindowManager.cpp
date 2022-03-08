/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** WindowManager
*/

#include "WindowManager.hpp"

GUI::WindowManager::WindowManager(int &ac, char **&av, Client *client, QWidget *parent)
    : AWindowManager(ac, av)
    , _win(parent)
    , _client(client)
    , _windows(State::NumOfState)
    , _callPopUp(this)
    , _callSound("./src/client/ui/call_sound.wav")
{
    _windows[State::Login] = std::make_pair(std::make_unique<LoginWindow>(this), "Login Window");
    _windows[State::Register] = std::make_pair(std::make_unique<RegisterWindow>(this), "Register Window");
    _windows[State::Main] = std::make_pair(std::make_unique<MainWindow>(this), "Main Window");
    _windows[State::Message] = std::make_pair(std::make_unique<MessageWindow>(this), "Message Window");
    _windows[State::Call] = std::make_pair(std::make_unique<CallWindow>(this), "Call Window");

    _windows[State::Login].first->hide();
    _windows[State::Register].first->hide();
    _windows[State::Main].first->hide();
    _windows[State::Message].first->hide();
    _windows[State::Call].first->hide();

    _callPopUp.hide();

    _windows[_actualState].first->show();

    _win.setFixedSize(WIDTH, HEIGHT);
    _win.setWindowTitle(QString::fromStdString(_windows[_actualState].second));
    _win.show();
}

GUI::WindowManager::~WindowManager()
{
}

void GUI::WindowManager::setState(State state)
{
    if (state == NumOfState)
        return;
    _windows[_actualState].first->hide();
    _actualState = state;
    _win.setWindowTitle(QString::fromStdString(_windows[_actualState].second));
    _windows[_actualState].first->show();
}

GUI::State GUI::WindowManager::getState() const
{
    return _actualState;
}

void GUI::WindowManager::setTalkingWith(GUI::TalkingWith tw)
{
    _talkingWith = tw;
}

GUI::TalkingWith GUI::WindowManager::getTalkingWith() const
{
    return _talkingWith;
}

void GUI::WindowManager::showCallPopUp()
{
    _callPopUp.show();
    _callSound.playSong();
}

void GUI::WindowManager::hideCallPopUp()
{
    _callPopUp.hide(); 
    _callSound.stopSong();
}

void GUI::WindowManager::update()
{
    _app.processEvents();
}

bool GUI::WindowManager::isOpen()
{
    return _win.isVisible();
}

Client *GUI::WindowManager::getClient()
{
    return _client;
}