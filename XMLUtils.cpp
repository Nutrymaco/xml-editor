#include <QHash>
#include <QDebug>

QList<QHash<QString, QString>> listFromXMLString(QString string) {
    QRegExp rx("<(\\w*)>([\\w]*)</\\w*>"); // <field>value</field>
    QRegExp rx2("<\\w*>([\\w<>/]*)</\\w*>"); //<list>(all)</list>
    QList<QHash<QString, QString>> list;
    QString objString;
    int pos = 0;
    int pos2 = 0;
    pos = rx2.indexIn(string, pos);
    string = rx2.cap(1);
    pos = 0;
    qDebug() << string;
    while ((pos = rx2.indexIn(string, pos)) != -1) {
        pos += rx2.matchedLength();
        objString = rx2.cap(1);
        pos2 = 0;
        qDebug() << objString;
        QHash<QString, QString> map;
        while ((pos2 = rx.indexIn(objString, pos2)) != -1) {
            map.insert(rx.cap(1), rx.cap(2));
            pos2 += rx.matchedLength();
            list.append(map);
        }

    }
    return list;
}
