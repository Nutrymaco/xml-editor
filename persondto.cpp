#include "persondto.h"


PersonDTO::PersonDTO()
{

}

PersonDTO::PersonDTO(QString name, QString surname, int age)
{
    this->surname = surname;
    this->name = name;
    this->age = age;
}

QString PersonDTO::getSurname() const
{
    return surname;
}

QString PersonDTO::getName() const
{
    return name;
}

int PersonDTO::getAge() const
{
    return age;
}

QList<QString> PersonDTO::getColumnNames()
{
    return {"name", "surname", "age"};
}

QString PersonDTO::toString()
{
    return QString("Person {"
           "name = %1, "
           "surname = %2, "
           "age = %3}").arg(name).arg(surname).arg(age);
}

void PersonDTO::merge(PersonDTO &other)
{
    if (other.getName() != "") {
        this->setName(other.getName());
    }
    if (other.getSurname() != "") {
        this->setSurname(other.getSurname());
    }
    if (other.getAge() != 0) {
        this->setAge(other.getAge());
    }
}

void PersonDTO::setSurname(const QString &value)
{
    surname = value;
}

void PersonDTO::setName(const QString &value)
{
    name = value;
}

void PersonDTO::setAge(const int value)
{
    age = value;
}
