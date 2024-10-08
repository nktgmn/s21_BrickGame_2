#include "desktop_view.h"
#include "./ui_desktop_view.h"

namespace s21 {

DesktopView::DesktopView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DesktopView)
{
    ui->setupUi(this);

    this->resize(300, 600);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QGridLayout *gridLayout = new QGridLayout(centralWidget);

    gridLayout->setObjectName("MyLayout");
    gridLayout->setHorizontalSpacing(1); // Adjust column spacing
    gridLayout->setVerticalSpacing(1);

    for (int i = 0; i < FIELD_W; ++i) {
        for (int j = 0; j < FIELD_H; ++j) {
            QLabel *label = new QLabel(this);
            label->setAlignment(Qt::AlignCenter);
            label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            label->setStyleSheet("background-color: white;");
            gridLayout->addWidget(label, j, i);
        }
    }
}

void DesktopView::render(GameInfo& game_info) {
    QGridLayout *gridLayout = centralWidget()->findChild<QGridLayout*>("MyLayout");

    if (game_info.field != nullptr) {
        for (int i = 0; i < FIELD_H; ++i) {
            for (int j = 0; j < FIELD_W; ++j) {
                QLayoutItem *item = gridLayout->itemAtPosition(j, i);
                QWidget *widget = item->widget();
                widget->setStyleSheet("background-color: black;");
            }
        }
    }

    this->show();
}

Input DesktopView::get_input(double time_left) {
    return Input(UserAction_t::Up, false, false);
}

DesktopView::~DesktopView()
{
    delete ui;
}

}
