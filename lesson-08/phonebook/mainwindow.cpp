#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <iostream>
#include "dialogadduser.h"

#include <QTableView>
#include <QListView>
#include <QTreeView>
#include <QMessageBox>

#define MAGIC_NUMBER 0XAA55AA55

struct Personal
{
    int32_t  magicNumber;
    char     name[5];
    int32_t  age;
};

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mModel = new QStandardItemModel();


    ui->tableView->setModel(mModel);
    ui->listView->setModel(mModel);
    ui->treeView->setModel(mModel);


// for (int i = 0; i < 10; i++)
// {
// auto                    name = new QStandardItem("Ali_" + QString::number(i));
// auto                    tel  = new QStandardItem(QString("0912-%1000-000").arg(i));
// QList<QStandardItem *>  items;

// items << name;
// items.append(tel);

// mModel->appendRow(items);
// }

// auto  name = new QStandardItem("Akbar");

// mModel->item(0, 0)->appendRow(QList<QStandardItem *>() << name);

    {
// QByteArray   data;
        QFile  file("sample.dat");

        file.open(QIODevice::WriteOnly);

        QByteArray  rawPersonal;
        rawPersonal.resize(sizeof(Personal));
        Personal *p       = (Personal *)rawPersonal.data();
        char      name[5] = { 0x62, 0x62, 0x62, 0x62, 0x62 };
        p->magicNumber = 0xAA55;

        strcpy(p->name, name);
// p->name        = name;
        p->age = 2;


        QDataStream  a(&file);
        QList<int>   b = { 2, 4, 6, 8 };
        a << MAGIC_NUMBER << QString("ali") << QString("ali");

        a << rawPersonal;

        // a << MAGIC_NUMBER << QString("aaaaaaaaaa") << ";" << 2;


        file.close();
    }

    {
        QFile  file("sample.dat");
        file.open(QIODevice::ReadOnly);

        QByteArray   data = file.readAll();
        QDataStream  a(&data, QIODevice::ReadOnly);
        quint32      magic;
        QString      name;
        QString      name2;
// QList<int>   b;

        a >> magic;
        a >> name;
        a >> name2;

        file.close();
    }
//// std::cout << "DATA : " << data.toHex().toStdString() << std::endl;
// {
//// QString      data;
// QFile  file("sample.csv");
// file.open(QIODevice::WriteOnly);

// QTextStream  a(&file);

// a << "a" << ";" << 2 << "\n";
// a << "b" << ";" << 3 << "\n";
// a << "c" << ";" << 4 << "\n";

// file.close();
//// std::cout << "DATA : " << data.toStdString() << std::endl;
// }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::on_pushButton_clicked()
{
    DialogAddUser  diag;

    diag.setName("Enter name");
    auto  res = diag.exec();

    if (res == QDialog::Accepted)
    {
        std::cout << "Name : " << diag.name().toStdString() << std::endl;

        auto                    name = new QStandardItem(diag.name());
        auto                    tel  = new QStandardItem(diag.tel());
        QList<QStandardItem *>  items;

        items << name;
        items.append(tel);

        mModel->appendRow(items);
    }
}

void  MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    auto  item = mModel->item(index.row(), index.column());

    std::cout << item->text().toStdString() << std::endl;
}

void  MainWindow::on_pushButton_4_clicked()
{
    QMessageBox  msgBox;

    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int  ret = msgBox.exec();

    if (ret == QMessageBox::Save)
    {
        for (int i = 0; i < mModel->rowCount(); i++)
        {
            auto  item = mModel->item(i);
            std::cout << item->text().toStdString() << std::endl;
        }
    }
}
