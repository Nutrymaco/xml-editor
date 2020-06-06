#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "persontablemodel.h"

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <persondto.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_updateButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_actionOpenFile_triggered();

    void on_actionSaveFileAs_triggered();

private:

    Ui::MainWindow *ui;
    PersonTableModel *tableModel;
    PersonFileRepository *repository;

};
#endif // MAINWINDOW_H
