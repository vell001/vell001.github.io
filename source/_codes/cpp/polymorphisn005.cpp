#include <QCoreApplication>
#include <QDebug>
class Person {
public :
    int age;
    Person() : age(10){}
    virtual void getAge() {
        qDebug() << "Person: " << age;
    }
};

class VellBibi : public Person {
public :
    int age;
    VellBibi() : age(21){}
    virtual void getAge() {
        qDebug() << "VellBibi: " << age;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person p;
    VellBibi v;

    int *pfv = (int *)&p;
    int *vfv = (int *)&v;
    qDebug() << "PersonFirstValue: " << *pfv;
    qDebug() << "VellBibiFirstValue: " << *vfv;

    qDebug() << "PersonSecondValue: " << *(pfv + 1);
    qDebug() << "VellBibiSecondValue: " << *(vfv + 1);

    qDebug() << "PersonThirdValue: " << *(pfv + 2);
    qDebug() << "VellBibiSThirdValue: " << *(vfv + 2);

    int *pt = (int *)*pfv;
    int *vt = (int *)*vfv;
    qDebug() << "PersonVTableFirstValue: " << *pt;
    qDebug() << "VellBibiVTableFirstValue: " << *vt;

    qDebug() << "PersonVTableSecondValue: " << *(pt + 1);
    qDebug() << "VellBibiVTableSecondValue: " << *(vt + 1);
    return a.exec();
}
