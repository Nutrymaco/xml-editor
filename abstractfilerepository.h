#ifndef ABSTRACTFILEREPOSITORY_H
#define ABSTRACTFILEREPOSITORY_H

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <OpenFileException.h>


template <class DTO, class Converter> class AbstractFileRepository
{
public:
    int add(DTO dto) const {
        dtoList->append(dto);
        return dtoList->size();
    }

    void update(int index, DTO newDTO) const {
        dtoList->at(index).merge(newDTO);
    }

    void updateByIdRange(QList<int> idList, DTO newDTO) const {
        QListIterator<int> iter(idList);
        int id;
        DTO p;
        while (iter.hasNext()) {
            id = iter.next();
            p = dtoList->at(id);
            p.merge(newDTO);
            dtoList->replace(id, p);
        }
    }

    void deleteById(int index) const {
        dtoList->removeAt(index);

    }

    void deleteByIdRange(QList<int> idList) {
        while (!idList.isEmpty()) {
            dtoList->removeAt(idList.last());
            idList.removeLast();
        }
    }

    DTO getById(int index) const {
        return dtoList->at(index);
    }

    QList<DTO>* all() const {
        return dtoList;
    }

    //хз куда это впихнуть еще
    QList<QString> getColumnNames() const {
       return DTO::getColumnNames();
    }

    void saveToFile(QString fileName) const{
        QString data = Converter::convertToText(dtoList);
        writeFileData(data, fileName);
    }

    void loadFromFile(QString fileName) {
        QString data = getFileData(fileName);
        delete dtoList;
        dtoList = Converter::convertToDTO(data);
    }

    ~AbstractFileRepository() {
        delete dtoList;
    }

protected:
    QString getFileData(QString fileName) const {
        QString data;
        QFile file(fileName);
        if(!file.open(QFile::ReadOnly | QFile::Text)){
            throw OpenFileException();
        }
        QTextStream in(&file);
        data = in.readAll();
        file.close();
        return data;
    }

    void writeFileData(QString fileData, QString fileName) const {
        QFile file(fileName);
        if(!file.open(QFile::WriteOnly | QFile::Text)) {
            throw OpenFileException();
        }
        QTextStream out(&file);
        out << fileData;
        file.close();
    }
    QList<DTO> *dtoList = new QList<DTO>();
};

#endif // ABSTRACTFILEREPOSITORY_H
