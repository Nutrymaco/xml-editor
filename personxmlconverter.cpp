#include "personxmlconverter.h"

#include <QDomDocument>
#include <QDebug>
//#include "XMLUtils.cpp";

PersonXMLConverter::PersonXMLConverter()
{

}

QString PersonXMLConverter::convertToText(QList<PersonDTO> *dtoList)
{
    QDomDocument doc;
    QDomElement listElem = doc.createElement("personList");
    for (int i = 0; i < dtoList->size(); i++) {
        QDomElement personElem = doc.createElement("person");

        QDomElement name = doc.createElement("name");
        name.appendChild(doc.createTextNode(dtoList->at(i).getName()));
        personElem.appendChild(name);

        QDomElement surname = doc.createElement("surname");
        surname.appendChild(doc.createTextNode(dtoList->at(i).getSurname()));
        personElem.appendChild(surname);

        QDomElement age = doc.createElement("age");
        age.appendChild(doc.createTextNode(QString("%1").arg(dtoList->at(i).getAge())));
        personElem.appendChild(age);

        listElem.appendChild(personElem);
    }
    doc.appendChild(listElem);
    return doc.toString();
}

QList<PersonDTO>* PersonXMLConverter::convertToDTO(QString text)
{
    QList<PersonDTO> *list = new QList<PersonDTO>();
    QDomDocument doc;
    doc.setContent(text);
    QDomNodeList nodeList = doc.elementsByTagName("personList").at(0).toElement().elementsByTagName("person");
    QDomNode node;
    QString name, surname, age;

    for (int i = 0; i < nodeList.size(); i++) {
        node = nodeList.at(i);
        name = node.toElement().elementsByTagName("name").at(0).toElement().text();
        surname = node.toElement().elementsByTagName("surname").at(0).toElement().text();
        age = node.toElement().elementsByTagName("age").at(0).toElement().text();
        PersonDTO person(name, surname, age.toInt());
        list->append(person);
    }

    return list;
}
