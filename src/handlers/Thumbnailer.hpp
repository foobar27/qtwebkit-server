#pragma once

#include <QNetworkAccessManager>
#include <QWebPage>

class Thumbnailer : public QObject
{
    Q_OBJECT

public:
    Thumbnailer(QNetworkAccessManager* manager, const QUrl &url);

signals:
    void finished();

private slots:
    void render();

private:
    QWebPage page;

};
