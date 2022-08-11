#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class QTimer;
class QPushButton;

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:
    void  changeName();

    void  timeout();

private:
    Ui::MainWindow *ui;
    QPushButton    *mPushButton = nullptr;
    int             mCounter    = 0;
    QTimer         *mTimer      = nullptr;
    QElapsedTimer   mETimer;
};
#endif // MAINWINDOW_H
