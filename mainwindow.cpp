#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_ascii = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ascii_text_textChanged()
{
   m_ascii = ui->ascii_text->toPlainText();

   if(ui->ascii_text->hasFocus()) output(1);
   else return;
}

void MainWindow::on_hex_text_textChanged()
{
    QString hex = ui->hex_text->toPlainText();
    QStringList hexlist = hex.split(' ');

    QString toAscii = 0;

   for(QString i : hexlist)
   {
       i.remove("0x");
       toAscii.append((char) i.toInt(nullptr, 16));
   }

    m_ascii = toAscii;

    if(ui->hex_text->hasFocus()) output(2);
    else return;
}

void MainWindow::on_bin_text_textChanged()
{
    QString bin = ui->bin_text->toPlainText();
    QStringList binlist = bin.split(' ');

    QString toAscii = 0;

    for(QString i: binlist)
    {
        toAscii.append((char) i.toInt(nullptr, 2));
    }

    m_ascii = toAscii;

    if(ui->bin_text->hasFocus()) output(3);
    else return;
}

void MainWindow::on_refresh_button_clicked()
{
   output(0);
}

void MainWindow::output(int setoutput)
{
    qDebug() << m_ascii;
    //Ascii Output
    if(setoutput != 1) ui->ascii_text->setPlainText(m_ascii);

    //Hex Output
    if(setoutput!= 2)
    {
        QString toHex = 0;
        for(QChar i : m_ascii)
        {
            char c = i.toLatin1();
            toHex.append(QString::number(c, 16) + ' ');
        }

        toHex = toHex.toUpper();

        QStringList toHexList = toHex.split(' ');
        toHexList.removeLast();
        QString toHexAdded = 0;
        for(QString i : toHexList)
        {
            if(i != '0') toHexAdded.append("0x" + i + ' ');
        }

        ui->hex_text->setPlainText(toHexAdded);
    }

    //Bin Output
    if(setoutput != 3)
    {
        QString toBin = 0;
        for(QChar i : m_ascii)
        {
            char c = i.toLatin1();
            toBin.append(QString::number(c, 2) + ' ');
        }

        QStringList toBinList = toBin.split(' ');
        QString toBinAdded = 0;
        for(QString i : toBinList)
        {
            if(i != '0') toBinAdded.append(i + ' ');
        }

        ui->bin_text->setPlainText(toBinAdded);
    }
}
