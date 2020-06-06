#include "persontablemodel.h"

PersonTableModel::PersonTableModel() {
    repository = new PersonFileRepository;
}

void PersonTableModel::addPerson(PersonDTO person)
{
    int index = repository->add(person);
    insertRow(index, QModelIndex());
}

void PersonTableModel::updatePersonByIdRange(QModelIndexList modelIndexList, PersonDTO person)
{
    QList<int> idList;
    for (int i = 0; i < modelIndexList.count(); i++) {
        idList.append(modelIndexList.at(i).row());
    }
    repository->updateByIdRange(idList, person);
    emit layoutChanged();
}

void PersonTableModel::deletePersonByIdRange(QModelIndexList modelIndexList)
{
    QList<int> idList;
    for (int i = 0; i < modelIndexList.count(); i++) {
        idList.append(modelIndexList.at(i).row());
    }
    repository->deleteByIdRange(idList);
    removeRows(idList.at(0), idList.size(), QModelIndex());
}

void PersonTableModel::loadFromFile(QString fileName)
{
    repository->loadFromFile(fileName);
    emit layoutChanged();
}

void PersonTableModel::saveToFile(QString fileName)
{
    repository->saveToFile(fileName);
}

int PersonTableModel::rowCount(const QModelIndex &parent) const
{
    return repository->all()->size();
}

int PersonTableModel::columnCount(const QModelIndex &parent) const
{
    return PersonDTO::getColumnNames().size();
}

bool PersonTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row+count-1);
    setHeaderData(row, Qt::Horizontal, QVariant(row));
    emit headerDataChanged(Qt::Vertical, row, row + count - 1);
    endInsertRows();
    return true;
}

bool PersonTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    endRemoveRows();
    return true;
}

QVariant PersonTableModel::data(const QModelIndex &index, int role) const
{
    PersonDTO person = repository->getById(index.row());
    QString answer;


    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            answer = person.getName();
        } else if(index.column() == 1) {
            answer = person.getSurname();
        } else if(index.column() == 2) {
            answer = QString("%1").arg(person.getAge());
        } else {
            answer = "None";
        }

        return QVariant(answer);
    }
    return QVariant();
}



QVariant PersonTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        QList<QString> names = PersonDTO::getColumnNames();
        return QVariant(names.at(section));
    } else if(role == Qt::DisplayRole && orientation == Qt::Vertical) {
        return QVariant(section);
    }
    return QVariant();
}

bool PersonTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    emit headerDataChanged(orientation, section, section + 1);
    return true;
}


