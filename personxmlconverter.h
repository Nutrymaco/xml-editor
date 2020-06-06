#ifndef PERSONXMLCONVERTER_H
#define PERSONXMLCONVERTER_H

#include "persondto.h"

#include <QString>
#include <QList>



class PersonXMLConverter
{
public:
    PersonXMLConverter();
    static QString convertToText(QList<PersonDTO> *dto);
    static QList<PersonDTO>* convertToDTO(QString text);
};

#endif // PERSONXMLCONVERTER_H
