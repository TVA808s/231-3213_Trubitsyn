#include "clientinterface.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QEventLoop>
#include <QJsonArray>
// #include <QThread>
#include <QVector>
ClientInterface * ClientInterface::instance = nullptr;


ClientInterface::ClientInterface(QObject *parent)
    : QObject{parent}
{
    m_client = new QNetworkAccessManager();
    // QObject::connect(
    //     m_client, &QNetworkAccessManager::finished,
    //     this, &ClientInterface::responseReceived);
}


ClientInterface *ClientInterface::getInstance()
{
    // проверить создан ли объект да вернуть ссылку, нет создать и вернуть ссылку
    if(!instance){
        instance = new ClientInterface();
    }

    return instance;
}

ClientInterface::~ClientInterface()
{
    m_client->deleteLater();
}

// void ClientInterface::responseReceived(QNetworkReply *reply)
// {
//     qDebug() << "Server response:\n" << reply->readAll();
// }

Cloth ClientInterface::getCloth(const int id)
{
    Cloth result;
    QNetworkReply * repl = m_client->get(QNetworkRequest(QUrl(QString("http://localhost/api/cloths.get/") + QString::number(id))));
    // ожидание ответа от сервера чтобы прога не висла при запросе - Ассинхронная реализация
    QEventLoop evtLoop;
    QObject::connect(
        m_client, &QNetworkAccessManager::finished,
        &evtLoop, &QEventLoop::quit);
    evtLoop.exec();

    // while(!repl->isFinished()){  // это синхронная реализация ХАРАМ
    //     qDebug() << "* waiting";
    //     QThread::msleep(100);
    // };

    QJsonParseError jsonErr;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(
        repl->readAll(), &jsonErr);
    QJsonObject jsonRootObj = jsonDoc.object();


    result.id = jsonRootObj["id"].toInt();
    result.brand = jsonRootObj["brand"].toString();
    result.category = jsonRootObj["category"].toString();
    result.color = jsonRootObj["color"].toString();
    result.description = jsonRootObj["description"].toString();
    result.price = jsonRootObj["price"].toDouble();
    result.season = jsonRootObj["season"].toString();
    result.used = jsonRootObj["used"].toBool();


    if (result.id == 0){
        qDebug() << "Does not exist";
    } else {
        result.display();
    }

    return result;
}

void ClientInterface::extracted(QList<Cloth> &clothList,
                                QJsonArray &jsonArray) {
    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        Cloth cloth;
        cloth.id = obj["id"].toInt();
        cloth.brand = obj["brand"].toString();
        cloth.category = obj["category"].toString();
        cloth.color = obj["color"].toString();
        cloth.description = obj["description"].toString();
        cloth.price = obj["price"].toDouble();
        cloth.season = obj["season"].toString();
        cloth.used = obj["used"].toBool();
        clothList.append(cloth);
    }
}

QList<Cloth> ClientInterface::getCloths() {
    QList<Cloth> clothList;

    QNetworkReply *repl = m_client->get(
        QNetworkRequest(QUrl(QString("http://localhost/api/cloths.get"))));

    QEventLoop evtLoop;
    QObject::connect(m_client, &QNetworkAccessManager::finished, &evtLoop,
                     &QEventLoop::quit);
    evtLoop.exec();

    QJsonParseError jsonErr;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(repl->readAll(), &jsonErr);
    // QJsonObject jsonRootObj = jsonDoc.object();

    if (jsonDoc.isArray()) {
        QJsonArray jsonArray = jsonDoc.array();
        extracted(clothList, jsonArray);
    }

    int i = 1;
    for(const Cloth& cloth : clothList) {
        qDebug() << i << "шмотка";
        i++;
        cloth.display();
    }

    return clothList;
}

Cloth ClientInterface::createCloth()
{
    Cloth result;
    QJsonObject clothData;
    clothData["price"] = "666";
    clothData["brand"] = "ADIDAS";
    clothData["category"] = "snickers";
    clothData["color"] = "green";
    clothData["used"] = true;
    clothData["description"] = "SELF MADE SELF MADE SELF MADE";
    clothData["season"] = "2000-01-01";

    QJsonDocument doc(clothData);
    QByteArray data = doc.toJson();
    QNetworkRequest request(QUrl(QString("http://localhost/api/cloths.create")));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *repl = m_client->post(
        request, data);

    QEventLoop evtLoop;
    QObject::connect(
        m_client, &QNetworkAccessManager::finished,
        &evtLoop, &QEventLoop::quit);
    evtLoop.exec();

    QJsonParseError jsonErr;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(repl->readAll(), &jsonErr);
    QJsonObject jsonRootObj = jsonDoc.object();
    result.id = jsonRootObj["id"].toInt();
    result.brand = jsonRootObj["brand"].toString();
    result.category = jsonRootObj["category"].toString();
    result.color = jsonRootObj["color"].toString();
    result.description = jsonRootObj["description"].toString();
    result.price = jsonRootObj["price"].toDouble();
    result.season = jsonRootObj["season"].toString();
    result.used = jsonRootObj["used"].toBool();
    result.display();

    return result;
}

Cloth ClientInterface::updateCloth(const int id)
{
    Cloth result;
    QJsonObject clothData;
    clothData["brand"] = "GUCCI";
    clothData["price"] = "999";
    clothData["description"] = "SELF MADE SELF MADE SELF MADE";
    clothData["season"] = "2000-01-01";
    QJsonDocument doc(clothData);
    QByteArray data = doc.toJson();
    QNetworkRequest request(QUrl(QString("http://localhost/api/cloths.update/") + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply * repl = m_client->post(request, data);

    QEventLoop evtLoop;
    QObject::connect(
        m_client, &QNetworkAccessManager::finished,
        &evtLoop, &QEventLoop::quit);
    evtLoop.exec();

    QJsonParseError jsonErr;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(repl->readAll(), &jsonErr);
    QJsonObject jsonRootObj = jsonDoc.object();
    result.id = jsonRootObj["id"].toInt();
    result.brand = jsonRootObj["brand"].toString();
    result.category = jsonRootObj["category"].toString();
    result.color = jsonRootObj["color"].toString();
    result.description = jsonRootObj["description"].toString();
    result.price = jsonRootObj["price"].toDouble();
    result.season = jsonRootObj["season"].toString();
    result.used = jsonRootObj["used"].toBool();

    if(result.id == 0) {
        qDebug() << "Does not exist";
    } else {
        result.display();
        qDebug() << "lol";
    }

    return result;
}

bool ClientInterface::deleteCloth(const int id)
{
    Cloth result;
    QNetworkReply * repl = m_client->deleteResource(QNetworkRequest(QUrl(QString("http://localhost/api/cloths.delete/") + QString::number(id))));
    QEventLoop evtLoop;
    QObject::connect(
        m_client, &QNetworkAccessManager::finished,
        &evtLoop, &QEventLoop::quit);
    evtLoop.exec();
    QJsonParseError jsonErr;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(repl->readAll(), &jsonErr);
    QJsonObject jsonRootObj = jsonDoc.object();
    result.id = jsonRootObj["id"].toInt();
    result.brand = jsonRootObj["brand"].toString();
    result.category = jsonRootObj["category"].toString();
    result.color = jsonRootObj["color"].toString();
    result.description = jsonRootObj["description"].toString();
    result.price = jsonRootObj["price"].toDouble();
    result.season = jsonRootObj["season"].toString();
    result.used = jsonRootObj["used"].toBool();
    if (result.id == 0) {
        qDebug() << "Obj was deleted";
        return 1;
    } else {
        qDebug() << "Does not exist";
        return 0;
    }
}
