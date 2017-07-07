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
    p.getAge();

    VellBibi v;
    v.getAge();

    Person *pPtr = &v;
    pPtr->getAge();

    return a.exec();
}
