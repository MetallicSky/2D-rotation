#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <mygraphicview.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_checkBox_autoRestart_stateChanged(int arg1);

    void on_pushButton_restart_clicked();

    void on_scene_dotChanged();

    void on_spinBox_RotDeg_valueChanged(int arg1);

private:
    Ui::MainWindow  *ui;
    MyGraphicView   *myPicture;
};

#endif // MAINWINDOW_H
