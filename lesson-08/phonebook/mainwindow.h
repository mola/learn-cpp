#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

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
    void  on_pushButton_clicked();

    void  on_tableView_clicked(const QModelIndex &index);

    void  on_pushButton_4_clicked();

private:
    Ui::MainWindow     *ui;
    QStandardItemModel *mModel;
};
#endif // MAINWINDOW_H
