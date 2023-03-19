#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString m_ascii;

private slots:
    void on_ascii_text_textChanged();

    void on_hex_text_textChanged();

    void on_bin_text_textChanged();

    void on_refresh_button_clicked();

    void output(int setoutput);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
