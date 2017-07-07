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
    int suiShu;
    VellBibi() : suiShu(21){}
    virtual void getAge() {
        qDebug() << "VellBibi: " << suiShu;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person p;
    VellBibi v;

    Person *pptr = &p;

    int *pp = (int *)&p;
    int *vp = (int *)&v;

    *pp = *vp;

    pptr->getAge();

    return a.exec();
}
