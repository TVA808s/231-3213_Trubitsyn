#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include <QObject>
#include <QNetworkAccessManager>


class Cloth {
public:
    Cloth() = default;
    int id = -1; // заглушка
    QString brand;
    QString category;
    double price;
    QString color;
    bool used;
    QString description;
    QString season;
    void display() const {
        qDebug()
        << "Cloth: id = " << id
        << "\nCloth: brand = " << brand
        << "\nCloth: category = " << category
        << "\nCloth: price = " << price
        << "\nCloth: color = " << color
        << "\nCloth: used = " << used
        << "\nCloth: description = " << description
        << "\nCloth: season = " << season
        << "\n";
    }
};

class ClientInterface : public QObject
{
    Q_OBJECT
public:
    static ClientInterface * getInstance();
    static ClientInterface * instance;
    ~ClientInterface();

    Cloth getCloth(const int id);
    void extracted(QList<Cloth> &clothList, QJsonArray &jsonArray);
    QList<Cloth> getCloths();
    Cloth createCloth();
    Cloth updateCloth(const int id);
    bool deleteCloth(const int id);
// адаптер к серверу

public slots:
    // void responseReceived(QNetworkReply *reply);
signals:
private:
    explicit ClientInterface(QObject *parent = nullptr);
    QNetworkAccessManager * m_client = nullptr;
};



#endif // CLIENTINTERFACE_H
