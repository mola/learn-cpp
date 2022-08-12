#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void  on_comboBox_currentIndexChanged(int index);

    void  on_comboAligment_currentIndexChanged(int index);

    void  on_CreateWindow_clicked();

    void  on_toolButton_clicked();

    void  closeWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
