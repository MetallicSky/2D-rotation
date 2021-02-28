#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myPicture   = new MyGraphicView();

    connect(myPicture, SIGNAL(dotChanged()), this, SLOT(on_scene_dotChanged()));

    ui->graphicsView->setViewport(myPicture);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_autoRestart_stateChanged(int arg1)
{
    bool activate = ui->checkBox_autoRestart->isChecked();
    myPicture->setAutoRepeat(activate);
}

void MainWindow::on_pushButton_restart_clicked()
{
    myPicture->restart();
    ui->spinBox_RotDeg->setValue(0);
}

void MainWindow::on_scene_dotChanged()
{
    ui->spinBox_RotDeg->setValue(0);
}

void MainWindow::on_spinBox_RotDeg_valueChanged(int arg1)
{
    myPicture->setDeg(ui->spinBox_RotDeg->value());
}
