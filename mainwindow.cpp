#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* initWidgetBackgroundColor */
    ui->lable_1->setAttribute(Qt::WA_StyledBackground,true);
    ui->lable_1->setStyleSheet("background-color: rgb(100,100,100)");

    ui->lable_2->setAttribute(Qt::WA_StyledBackground,true);
    ui->lable_2->setStyleSheet("background-color: rgb(255,0,0)");

    ui->lable_3->setAttribute(Qt::WA_StyledBackground,true);
    ui->lable_3->setStyleSheet("background-color: rgb(0,255,0)");

    ui->lable_4->setAttribute(Qt::WA_StyledBackground,true);
    ui->lable_4->setStyleSheet("background-color: rgb(0,0,255)");

    /* initActionGroup */
    actionGroup = new QActionGroup(this);
    actionGroup->addAction(ui->actionHorizontal);
    actionGroup->addAction(ui->actionVertical);
    actionGroup->addAction(ui->actionGrid);

    /* initConnect */
    connect(actionGroup, SIGNAL(triggered(QAction*)), this, SLOT(updateLayout(QAction*)));

    /* initLayout */
    ui->actionHorizontal->triggered(true);
    ui->actionHorizontal->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLayout(QAction *checkedAction) {
    delete ui->centralWidget->layout();
    if (checkedAction->objectName() == "actionHorizontal") {
        qDebug() << "h";
        ui->widget_1->show();
        ui->widget_2->hide();
        ui->widget_3->hide();
        ui->widget_4->show();
        QHBoxLayout *hLayout = new QHBoxLayout();
        hLayout->addWidget(ui->widget_1);
        hLayout->addWidget(ui->widget_4);
        ui->centralWidget->setLayout(hLayout);
    } else if (checkedAction->objectName() == "actionVertical") {
        qDebug() << "v";
        ui->widget_1->hide();
        ui->widget_2->show();
        ui->widget_3->show();
        ui->widget_4->hide();
        QVBoxLayout *vLayout = new QVBoxLayout();
        vLayout->addWidget(ui->widget_2);
        vLayout->addWidget(ui->widget_3);
        ui->centralWidget->setLayout(vLayout);
    } else if (checkedAction->objectName() == "actionGrid") {
        qDebug() << "g";
        ui->widget_1->show();
        ui->widget_2->show();
        ui->widget_3->show();
        ui->widget_4->show();
        QGridLayout *gLayout = new QGridLayout();
        gLayout->addWidget(ui->widget_1, 0, 0);
        gLayout->addWidget(ui->widget_2, 0, 1);
        gLayout->addWidget(ui->widget_3, 1, 0);
        gLayout->addWidget(ui->widget_4, 1, 1);
        ui->centralWidget->setLayout(gLayout);
    }
}
