#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(300,160);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int weekday = ui->lineEdit->text().toInt();
    switch (weekday) {
    case 1: ui->label->setText("Понеділок");
        break;
    case 2: ui->label->setText("Вівторок");
        break;
    case 3: ui->label->setText("Середа");
        break;
    case 4: ui->label->setText("Четвер");
        break;
    case 5: ui->label->setText("П'ятниця");
        break;
    case 6: ui->label->setText("Субота");
        break;
    case 7: ui->label->setText("Неділя");
        break;
    }
}
void MainWindow::message(QString title, QString text){
    QMessageBox msgbox;
    msgbox.setWindowTitle(title);
    msgbox.setText(text);
    msgbox.exec();
}
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString text = arg1;
    foreach(QChar c, arg1)
        {
            if(!c.isNumber())
            {
                message("Помилка", "Ви повинні ввести число");
                text.chop(1);
                ui->lineEdit->setText(text);
                return;
            }
            if(arg1.toInt() < 1 || arg1.toInt() > 7)
            {
                message("Помилка", "В тижні 7 днів");
                text.chop(1);
                ui->lineEdit->setText(text);
                return;
            }
    }
}
