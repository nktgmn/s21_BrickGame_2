#ifndef DESKTOP_VIEW_H
#define DESKTOP_VIEW_H

#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QWidget>

#include "../../game_params.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DesktopView;
}
QT_END_NAMESPACE

namespace s21 {

class DesktopView : public QMainWindow
{
    Q_OBJECT

public:
    DesktopView(QWidget *parent = nullptr);
    ~DesktopView();

    void render(GameInfo& game_info);
    Input get_input(double time_left);

private:
    Ui::DesktopView *ui;
};
}
#endif // DESKTOP_VIEW_H
