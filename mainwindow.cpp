#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tableModel = new PersonTableModel();
    ui->tableView->setModel(tableModel);
}



MainWindow::~MainWindow()
{
    delete repository;
    delete tableModel;
    delete ui;
}

void MainWindow::on_updateButton_clicked()
{
    QString name, surname, age;
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();

    name = ui->textEditName->toPlainText();
    surname = ui->textEditSurname->toPlainText();
    age = ui->textEditAge->toPlainText();

    PersonDTO newPerson(name, surname, age.toInt());
    tableModel->updatePersonByIdRange(selection, newPerson);
}

void MainWindow::on_addButton_clicked()
{
    QString name, surname, age;

    name = ui->textEditName->toPlainText();
    surname = ui->textEditSurname->toPlainText();
    age = ui->textEditAge->toPlainText();

    PersonDTO newPerson(name, surname, age.toInt());

    tableModel->addPerson(newPerson);
}

void MainWindow::on_deleteButton_clicked()
{
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();

    tableModel->deletePersonByIdRange(selection);
}


void MainWindow::on_actionOpenFile_triggered()
{  
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    try {
        tableModel->loadFromFile(fileName);
    } catch(OpenFileException& e) {
        QMessageBox::critical(this, tr(""), "can't open file");
    }
}

void MainWindow::on_actionSaveFileAs_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save the file");
    try {
        tableModel->saveToFile(fileName);
    } catch(OpenFileException& e) {
        QMessageBox::critical(this, tr(""), "can't open file");
    }
}
