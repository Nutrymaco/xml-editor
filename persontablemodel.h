#ifndef PERSONTABLEMODEL_H
#define PERSONTABLEMODEL_H

#include <QObject>

#include "QAbstractTableModel"
#include "persondto.h"
#include "personfilerepository.h"
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

class PersonTableModel : public QAbstractTableModel
{
public:
    PersonTableModel();
    void addPerson(PersonDTO person);
    void updatePersonByIdRange(QModelIndexList modelIndexList, PersonDTO person);
    void deletePersonByIdRange(QModelIndexList modelIndexList);
    void loadFromFile(QString fileName);
    void saveToFile(QString fileName);

private:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    QVariant data(const QModelIndex &index, int role) const;
    //bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setHeaderData( int section, Qt::Orientation orientation, const QVariant & value, int role = Qt::EditRole );
    PersonFileRepository *repository;
};

#endif // PERSONTABLEMODEL_H
