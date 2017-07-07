#include <QCoreApplication>
#include <QDebug>
class Person {
public :
    int age;
    Person() : age(10){}
    void getAge() {
        qDebug() << "Person: " << age;
    }
};

class VellBibi : public Person {
public :
    int age;
    VellBibi() : age(21){}
    void getAge() {
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

    qDebug() << "PersonSize: " << sizeof(p);
    qDebug() << "VellBibiSize: " << sizeof(v);

    return a.exec();
}
