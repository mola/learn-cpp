#ifndef DIALOGADDUSER_H
#define DIALOGADDUSER_H

#include <QDialog>

namespace Ui
{
class DialogAddUser;
}

class DialogAddUser: public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddUser(QWidget *parent = nullptr);

    ~DialogAddUser();

    QString  name();

    QString  tel();

    void     setName(QString name);

private:
    Ui::DialogAddUser *ui;
};

#endif // DIALOGADDUSER_H
