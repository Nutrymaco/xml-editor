#ifndef PERSONDTO_H
#define PERSONDTO_H

#include <QList>
#include <QString>



class PersonDTO
{
public:
    PersonDTO();
    PersonDTO(QString name, QString surname, int age);
    QString getSurname() const;
    QString getName() const;
    int getAge() const;
    static QList<QString> getColumnNames();
    QString toString();
    void merge(PersonDTO &other);
    void setSurname(const QString &value) ;
    void setName(const QString &value) ;
    void setAge(const int value);

private:
    QString surname;
    QString name;
    int age;
};

#endif // PERSONDTO_H
